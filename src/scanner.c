#include "tree_sitter/parser.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// エラー情報を格納する構造体
typedef struct {
  char message[256];
  uint32_t position;
} Error;

// スキャナーの状態を保持する構造体
typedef struct {
  char **tag_stack;
  uint32_t stack_size;
  uint32_t stack_capacity;
  Error *errors;
  uint32_t error_count;
  uint32_t error_capacity;
} Scanner;

enum TokenType {
  CLOSING_TAG_NAME,
};

// スタックにタグを追加
static void push_tag(Scanner *scanner, const char *tag_name) {
  if (scanner->stack_size >= scanner->stack_capacity) {
    scanner->stack_capacity *= 2;
    scanner->tag_stack =
        realloc(scanner->tag_stack, scanner->stack_capacity * sizeof(char *));
  }

  size_t length = strlen(tag_name);
  char *tag_copy = malloc(length + 1);
  strcpy(tag_copy, tag_name);
  scanner->tag_stack[scanner->stack_size++] = tag_copy;
}

// スタックからタグを取り出す
static char *pop_tag(Scanner *scanner) {
  if (scanner->stack_size == 0)
    return NULL;
  char *tag = scanner->tag_stack[--scanner->stack_size];
  free(tag);
  return tag;
}

// エラーを追加
static void add_error(Scanner *scanner, const char *message,
                      uint32_t position) {
  if (scanner->error_count >= scanner->error_capacity) {
    scanner->error_capacity *= 2;
    scanner->errors =
        realloc(scanner->errors, scanner->error_capacity * sizeof(Error));
  }

  Error *error = &scanner->errors[scanner->error_count++];
  strncpy(error->message, message, 255);
  error->message[255] = '\0';
  error->position = position;
}

void *tree_sitter_mtml_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->stack_capacity = 32;
  scanner->tag_stack = calloc(scanner->stack_capacity, sizeof(char *));
  scanner->error_capacity = 8;
  scanner->errors = calloc(scanner->error_capacity, sizeof(Error));
  return scanner;
}

void tree_sitter_mtml_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  free(scanner->tag_stack);
  free(scanner->errors);
  free(scanner);
}

void tree_sitter_mtml_external_scanner_reset(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;
}

unsigned tree_sitter_mtml_external_scanner_serialize(void *payload,
                                                     char *buffer) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  memcpy(&buffer[size], &scanner->stack_size, sizeof(uint32_t));
  size += sizeof(uint32_t);

  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    uint32_t name_length = strlen(scanner->tag_stack[i]);
    memcpy(&buffer[size], &name_length, sizeof(uint32_t));
    size += sizeof(uint32_t);
    memcpy(&buffer[size], scanner->tag_stack[i], name_length);
    size += name_length;
  }

  return size;
}

void tree_sitter_mtml_external_scanner_deserialize(void *payload,
                                                   const char *buffer,
                                                   unsigned length) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;

  if (length == 0)
    return;

  memcpy(&scanner->stack_size, &buffer[size], sizeof(uint32_t));
  size += sizeof(uint32_t);

  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    uint32_t name_length;
    memcpy(&name_length, &buffer[size], sizeof(uint32_t));
    size += sizeof(uint32_t);

    scanner->tag_stack[i] = malloc(name_length + 1);
    memcpy(scanner->tag_stack[i], &buffer[size], name_length);
    scanner->tag_stack[i][name_length] = '\0';
    size += name_length;
  }
}

static bool read_tag_name(TSLexer *lexer, char *buffer, size_t buffer_size) {
  size_t i = 0;
  while (i < buffer_size - 1 &&
         (isalnum(lexer->lookahead) || lexer->lookahead == '_')) {
    buffer[i++] = lexer->lookahead;
    lexer->advance(lexer, false);
  }
  buffer[i] = '\0';
  return i > 0;
}

bool tree_sitter_mtml_external_scanner_scan(void *payload, TSLexer *lexer,
                                            const bool *valid_symbols) {
  Scanner *scanner = (Scanner *)payload;

  while (lexer->lookahead == ' ' || lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' || lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[CLOSING_TAG_NAME]) {
    uint32_t start_pos =
        lexer->get_column(lexer); // get_position の代わりに get_column を使用

    char tag_name[256];
    if (!read_tag_name(lexer, tag_name, sizeof(tag_name))) {
      return false;
    }

    if (scanner->stack_size > 0) {
      const char *expected_tag = scanner->tag_stack[scanner->stack_size - 1];
      if (strcmp(tag_name, expected_tag) == 0) {
        pop_tag(scanner);
        lexer->result_symbol = CLOSING_TAG_NAME;
        return true;
      } else {
        char error_message[256];
        snprintf(error_message, sizeof(error_message),
                 "Expected closing tag '%s' but found '%s'", expected_tag,
                 tag_name);
        add_error(scanner, error_message, start_pos);
      }
    } else {
      add_error(scanner, "Found closing tag without matching opening tag",
                start_pos);
    }

    // 位置のリセット
    while (isalnum(lexer->lookahead) || lexer->lookahead == '_') {
      lexer->advance(lexer, false);
    }
  }

  return false;
}
