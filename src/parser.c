#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 99
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 47
#define ALIAS_COUNT 0
#define TOKEN_COUNT 28
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 9

enum ts_symbol_identifiers {
  aux_sym__function_tag_dollar_token1 = 1,
  anon_sym_DOLLAR_GT = 2,
  aux_sym__function_tag_slash_token1 = 3,
  anon_sym_SLASH_GT = 4,
  anon_sym_GT = 5,
  aux_sym_block_tag_token1 = 6,
  aux_sym_comment_tag_token1 = 7,
  aux_sym__comment_start_token1 = 8,
  sym__comment_end = 9,
  anon_sym_COLON = 10,
  anon_sym_EQ = 11,
  anon_sym_replace = 12,
  anon_sym_COMMA = 13,
  anon_sym_regex_replace = 14,
  anon_sym_DQUOTE_SLASH = 15,
  aux_sym_regex_pattern_token1 = 16,
  anon_sym_SLASH_DQUOTE = 17,
  anon_sym_SQUOTE_SLASH = 18,
  anon_sym_SLASH_SQUOTE = 19,
  sym_identifier = 20,
  anon_sym_DQUOTE = 21,
  aux_sym_string_token1 = 22,
  anon_sym_SQUOTE = 23,
  aux_sym_string_token2 = 24,
  sym_escape_sequence = 25,
  sym_text = 26,
  sym_ERROR = 27,
  sym_source_file = 28,
  sym__node = 29,
  sym_function_tag = 30,
  sym__function_tag_dollar = 31,
  sym__function_tag_slash = 32,
  sym_block_tag = 33,
  sym_comment_tag = 34,
  sym__comment_start = 35,
  sym_modifier = 36,
  sym__standard_modifier = 37,
  sym__replace_modifier = 38,
  sym__regex_modifier = 39,
  sym_regex_pattern = 40,
  sym_string = 41,
  aux_sym_source_file_repeat1 = 42,
  aux_sym__function_tag_dollar_repeat1 = 43,
  aux_sym_comment_tag_repeat1 = 44,
  aux_sym_string_repeat1 = 45,
  aux_sym_string_repeat2 = 46,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__function_tag_dollar_token1] = "_function_tag_dollar_token1",
  [anon_sym_DOLLAR_GT] = "$>",
  [aux_sym__function_tag_slash_token1] = "_function_tag_slash_token1",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_GT] = ">",
  [aux_sym_block_tag_token1] = "block_tag_token1",
  [aux_sym_comment_tag_token1] = "comment_tag_token1",
  [aux_sym__comment_start_token1] = "_comment_start_token1",
  [sym__comment_end] = "_comment_end",
  [anon_sym_COLON] = ":",
  [anon_sym_EQ] = "=",
  [anon_sym_replace] = "replace",
  [anon_sym_COMMA] = ",",
  [anon_sym_regex_replace] = "regex_replace",
  [anon_sym_DQUOTE_SLASH] = "\"/",
  [aux_sym_regex_pattern_token1] = "regex_pattern_token1",
  [anon_sym_SLASH_DQUOTE] = "/\"",
  [anon_sym_SQUOTE_SLASH] = "'/",
  [anon_sym_SLASH_SQUOTE] = "/'",
  [sym_identifier] = "identifier",
  [anon_sym_DQUOTE] = "\"",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token2] = "string_token2",
  [sym_escape_sequence] = "escape_sequence",
  [sym_text] = "text",
  [sym_ERROR] = "ERROR",
  [sym_source_file] = "source_file",
  [sym__node] = "_node",
  [sym_function_tag] = "function_tag",
  [sym__function_tag_dollar] = "_function_tag_dollar",
  [sym__function_tag_slash] = "_function_tag_slash",
  [sym_block_tag] = "block_tag",
  [sym_comment_tag] = "comment_tag",
  [sym__comment_start] = "_comment_start",
  [sym_modifier] = "modifier",
  [sym__standard_modifier] = "_standard_modifier",
  [sym__replace_modifier] = "_replace_modifier",
  [sym__regex_modifier] = "_regex_modifier",
  [sym_regex_pattern] = "regex_pattern",
  [sym_string] = "string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__function_tag_dollar_repeat1] = "_function_tag_dollar_repeat1",
  [aux_sym_comment_tag_repeat1] = "comment_tag_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__function_tag_dollar_token1] = aux_sym__function_tag_dollar_token1,
  [anon_sym_DOLLAR_GT] = anon_sym_DOLLAR_GT,
  [aux_sym__function_tag_slash_token1] = aux_sym__function_tag_slash_token1,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_GT] = anon_sym_GT,
  [aux_sym_block_tag_token1] = aux_sym_block_tag_token1,
  [aux_sym_comment_tag_token1] = aux_sym_comment_tag_token1,
  [aux_sym__comment_start_token1] = aux_sym__comment_start_token1,
  [sym__comment_end] = sym__comment_end,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_replace] = anon_sym_replace,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_regex_replace] = anon_sym_regex_replace,
  [anon_sym_DQUOTE_SLASH] = anon_sym_DQUOTE_SLASH,
  [aux_sym_regex_pattern_token1] = aux_sym_regex_pattern_token1,
  [anon_sym_SLASH_DQUOTE] = anon_sym_SLASH_DQUOTE,
  [anon_sym_SQUOTE_SLASH] = anon_sym_SQUOTE_SLASH,
  [anon_sym_SLASH_SQUOTE] = anon_sym_SLASH_SQUOTE,
  [sym_identifier] = sym_identifier,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_text] = sym_text,
  [sym_ERROR] = sym_ERROR,
  [sym_source_file] = sym_source_file,
  [sym__node] = sym__node,
  [sym_function_tag] = sym_function_tag,
  [sym__function_tag_dollar] = sym__function_tag_dollar,
  [sym__function_tag_slash] = sym__function_tag_slash,
  [sym_block_tag] = sym_block_tag,
  [sym_comment_tag] = sym_comment_tag,
  [sym__comment_start] = sym__comment_start,
  [sym_modifier] = sym_modifier,
  [sym__standard_modifier] = sym__standard_modifier,
  [sym__replace_modifier] = sym__replace_modifier,
  [sym__regex_modifier] = sym__regex_modifier,
  [sym_regex_pattern] = sym_regex_pattern,
  [sym_string] = sym_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__function_tag_dollar_repeat1] = aux_sym__function_tag_dollar_repeat1,
  [aux_sym_comment_tag_repeat1] = aux_sym_comment_tag_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [aux_sym__function_tag_dollar_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOLLAR_GT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym__function_tag_slash_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_GT] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_GT] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_block_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_tag_token1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__comment_start_token1] = {
    .visible = false,
    .named = false,
  },
  [sym__comment_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_EQ] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_replace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COMMA] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_regex_replace] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_regex_pattern_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SLASH_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SQUOTE_SLASH] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_SQUOTE] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_string_token2] = {
    .visible = false,
    .named = false,
  },
  [sym_escape_sequence] = {
    .visible = true,
    .named = true,
  },
  [sym_text] = {
    .visible = true,
    .named = true,
  },
  [sym_ERROR] = {
    .visible = true,
    .named = true,
  },
  [sym_source_file] = {
    .visible = true,
    .named = true,
  },
  [sym__node] = {
    .visible = false,
    .named = true,
  },
  [sym_function_tag] = {
    .visible = true,
    .named = true,
  },
  [sym__function_tag_dollar] = {
    .visible = false,
    .named = true,
  },
  [sym__function_tag_slash] = {
    .visible = false,
    .named = true,
  },
  [sym_block_tag] = {
    .visible = true,
    .named = true,
  },
  [sym_comment_tag] = {
    .visible = true,
    .named = true,
  },
  [sym__comment_start] = {
    .visible = false,
    .named = true,
  },
  [sym_modifier] = {
    .visible = true,
    .named = true,
  },
  [sym__standard_modifier] = {
    .visible = false,
    .named = true,
  },
  [sym__replace_modifier] = {
    .visible = false,
    .named = true,
  },
  [sym__regex_modifier] = {
    .visible = false,
    .named = true,
  },
  [sym_regex_pattern] = {
    .visible = true,
    .named = true,
  },
  [sym_string] = {
    .visible = true,
    .named = true,
  },
  [aux_sym_source_file_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym__function_tag_dollar_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_comment_tag_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat1] = {
    .visible = false,
    .named = false,
  },
  [aux_sym_string_repeat2] = {
    .visible = false,
    .named = false,
  },
};

enum ts_field_identifiers {
  field_key = 1,
  field_name = 2,
  field_pattern = 3,
  field_replacement = 4,
  field_value = 5,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_key] = "key",
  [field_name] = "name",
  [field_pattern] = "pattern",
  [field_replacement] = "replacement",
  [field_value] = "value",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 3},
  [3] = {.index = 5, .length = 2},
  [4] = {.index = 7, .length = 2},
  [5] = {.index = 9, .length = 3},
  [6] = {.index = 12, .length = 2},
  [7] = {.index = 14, .length = 2},
  [8] = {.index = 16, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_key, 0, .inherited = true},
    {field_value, 0, .inherited = true},
  [2] =
    {field_key, 0, .inherited = true},
    {field_pattern, 0, .inherited = true},
    {field_replacement, 0, .inherited = true},
  [5] =
    {field_key, 0},
    {field_value, 2},
  [7] =
    {field_name, 1},
    {field_name, 4},
  [9] =
    {field_key, 0},
    {field_pattern, 2},
    {field_replacement, 4},
  [12] =
    {field_key, 0},
    {field_value, 4},
  [14] =
    {field_name, 1},
    {field_name, 5},
  [16] =
    {field_name, 1},
    {field_name, 6},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static const TSStateId ts_primary_state_ids[STATE_COUNT] = {
  [0] = 0,
  [1] = 1,
  [2] = 2,
  [3] = 3,
  [4] = 4,
  [5] = 5,
  [6] = 6,
  [7] = 2,
  [8] = 5,
  [9] = 9,
  [10] = 9,
  [11] = 6,
  [12] = 4,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 14,
  [17] = 15,
  [18] = 18,
  [19] = 18,
  [20] = 20,
  [21] = 20,
  [22] = 22,
  [23] = 23,
  [24] = 24,
  [25] = 25,
  [26] = 26,
  [27] = 27,
  [28] = 28,
  [29] = 29,
  [30] = 30,
  [31] = 31,
  [32] = 32,
  [33] = 32,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 25,
  [40] = 29,
  [41] = 30,
  [42] = 31,
  [43] = 36,
  [44] = 34,
  [45] = 45,
  [46] = 46,
  [47] = 37,
  [48] = 38,
  [49] = 35,
  [50] = 50,
  [51] = 51,
  [52] = 52,
  [53] = 53,
  [54] = 54,
  [55] = 55,
  [56] = 56,
  [57] = 57,
  [58] = 58,
  [59] = 59,
  [60] = 60,
  [61] = 61,
  [62] = 62,
  [63] = 57,
  [64] = 64,
  [65] = 62,
  [66] = 66,
  [67] = 67,
  [68] = 68,
  [69] = 69,
  [70] = 70,
  [71] = 71,
  [72] = 72,
  [73] = 73,
  [74] = 74,
  [75] = 75,
  [76] = 76,
  [77] = 77,
  [78] = 78,
  [79] = 79,
  [80] = 80,
  [81] = 81,
  [82] = 82,
  [83] = 83,
  [84] = 84,
  [85] = 85,
  [86] = 86,
  [87] = 77,
  [88] = 78,
  [89] = 84,
  [90] = 81,
  [91] = 82,
  [92] = 83,
  [93] = 70,
  [94] = 71,
  [95] = 95,
  [96] = 96,
  [97] = 97,
  [98] = 98,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(38);
      ADVANCE_MAP(
        '"', 83,
        '$', 11,
        '\'', 86,
        ',', 58,
        '/', 4,
        ':', 55,
        '<', 6,
        '=', 56,
        '>', 47,
        '\\', 13,
        'r', 71,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(37);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 1:
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '<') ADVANCE(93);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 2:
      if (lookahead == '\n') SKIP(2);
      if (lookahead == '<') ADVANCE(51);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0) ADVANCE(50);
      END_STATE();
    case 3:
      if (lookahead == '"') ADVANCE(83);
      if (lookahead == '\\') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0) ADVANCE(85);
      END_STATE();
    case 4:
      if (lookahead == '"') ADVANCE(63);
      if (lookahead == '\'') ADVANCE(65);
      if (lookahead == '>') ADVANCE(46);
      END_STATE();
    case 5:
      if (lookahead == '"') ADVANCE(8);
      if (lookahead == '\'') ADVANCE(9);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(5);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 6:
      if (lookahead == '$') ADVANCE(19);
      if (lookahead == '/') ADVANCE(20);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(28);
      END_STATE();
    case 7:
      if (lookahead == '\'') ADVANCE(86);
      if (lookahead == '\\') ADVANCE(13);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(87);
      if (lookahead != 0) ADVANCE(88);
      END_STATE();
    case 8:
      if (lookahead == '/') ADVANCE(60);
      END_STATE();
    case 9:
      if (lookahead == '/') ADVANCE(64);
      END_STATE();
    case 10:
      if (lookahead == ':') ADVANCE(18);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 11:
      if (lookahead == '>') ADVANCE(41);
      END_STATE();
    case 12:
      if (lookahead == '>') ADVANCE(54);
      END_STATE();
    case 13:
      ADVANCE_MAP(
        'u', 35,
        '"', 89,
        '\'', 89,
        '\\', 89,
        'b', 89,
        'f', 89,
        'n', 89,
        'r', 89,
        't', 89,
      );
      END_STATE();
    case 14:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(53);
      END_STATE();
    case 15:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(12);
      END_STATE();
    case 16:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(22);
      END_STATE();
    case 17:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(23);
      END_STATE();
    case 18:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(17);
      END_STATE();
    case 19:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(29);
      END_STATE();
    case 20:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(30);
      END_STATE();
    case 21:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(31);
      END_STATE();
    case 22:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(25);
      END_STATE();
    case 24:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(26);
      END_STATE();
    case 25:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(27);
      END_STATE();
    case 26:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(14);
      END_STATE();
    case 27:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(15);
      END_STATE();
    case 28:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(42);
      END_STATE();
    case 29:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(40);
      END_STATE();
    case 30:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(49);
      END_STATE();
    case 31:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(10);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(89);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(33);
      END_STATE();
    case 35:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(34);
      END_STATE();
    case 36:
      if (eof) ADVANCE(38);
      if (lookahead == '\n') ADVANCE(90);
      if (lookahead == '<') ADVANCE(94);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0) ADVANCE(91);
      END_STATE();
    case 37:
      if (eof) ADVANCE(38);
      ADVANCE_MAP(
        '"', 83,
        '$', 11,
        '\'', 86,
        ',', 58,
        '/', 4,
        ':', 55,
        '<', 6,
        '=', 56,
        '>', 47,
        'r', 71,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(37);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__function_tag_dollar_token1);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__function_tag_dollar_token1);
      if (lookahead == ':') ADVANCE(39);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(anon_sym_DOLLAR_GT);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == ':') ADVANCE(44);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == ':') ADVANCE(45);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(16);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_block_tag_token1);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_block_tag_token1);
      if (lookahead == ':') ADVANCE(48);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_comment_tag_token1);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(aux_sym_comment_tag_token1);
      if (lookahead == '/') ADVANCE(21);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(aux_sym_comment_tag_token1);
      if (lookahead == '<') ADVANCE(51);
      if (lookahead == '\t' ||
          (0x0b <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(52);
      if (lookahead != 0 &&
          (lookahead < '\t' || '\r' < lookahead)) ADVANCE(50);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(aux_sym__comment_start_token1);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(sym__comment_end);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_replace);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(anon_sym_regex_replace);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(anon_sym_DQUOTE_SLASH);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(aux_sym_regex_pattern_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(61);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(62);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(aux_sym_regex_pattern_token1);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(62);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(anon_sym_SLASH_DQUOTE);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(anon_sym_SQUOTE_SLASH);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(anon_sym_SLASH_SQUOTE);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(69);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(81);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(57);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(59);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(72);
      if (lookahead == 'p') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(67);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(74);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(82);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(84);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(85);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(85);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(87);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(88);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(88);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\n') ADVANCE(90);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(91);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\n') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(91);
      END_STATE();
    case 92:
      ACCEPT_TOKEN(sym_text);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(92);
      END_STATE();
    case 93:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == '$') ADVANCE(97);
      if (lookahead == '/') ADVANCE(98);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 94:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == '$') ADVANCE(97);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(104);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 95:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(53);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 96:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(99);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 97:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(102);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 98:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(103);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 99:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(100);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 100:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(101);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 101:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(95);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 102:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(40);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(49);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(43);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 105:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 36},
  [2] = {.lex_state = 1},
  [3] = {.lex_state = 36},
  [4] = {.lex_state = 1},
  [5] = {.lex_state = 36},
  [6] = {.lex_state = 1},
  [7] = {.lex_state = 1},
  [8] = {.lex_state = 1},
  [9] = {.lex_state = 1},
  [10] = {.lex_state = 1},
  [11] = {.lex_state = 1},
  [12] = {.lex_state = 1},
  [13] = {.lex_state = 0},
  [14] = {.lex_state = 0},
  [15] = {.lex_state = 0},
  [16] = {.lex_state = 0},
  [17] = {.lex_state = 0},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 0},
  [23] = {.lex_state = 0},
  [24] = {.lex_state = 0},
  [25] = {.lex_state = 36},
  [26] = {.lex_state = 0},
  [27] = {.lex_state = 0},
  [28] = {.lex_state = 0},
  [29] = {.lex_state = 36},
  [30] = {.lex_state = 36},
  [31] = {.lex_state = 36},
  [32] = {.lex_state = 36},
  [33] = {.lex_state = 1},
  [34] = {.lex_state = 1},
  [35] = {.lex_state = 1},
  [36] = {.lex_state = 1},
  [37] = {.lex_state = 1},
  [38] = {.lex_state = 1},
  [39] = {.lex_state = 1},
  [40] = {.lex_state = 1},
  [41] = {.lex_state = 1},
  [42] = {.lex_state = 1},
  [43] = {.lex_state = 36},
  [44] = {.lex_state = 36},
  [45] = {.lex_state = 0},
  [46] = {.lex_state = 0},
  [47] = {.lex_state = 36},
  [48] = {.lex_state = 36},
  [49] = {.lex_state = 36},
  [50] = {.lex_state = 0},
  [51] = {.lex_state = 7},
  [52] = {.lex_state = 3},
  [53] = {.lex_state = 3},
  [54] = {.lex_state = 7},
  [55] = {.lex_state = 3},
  [56] = {.lex_state = 7},
  [57] = {.lex_state = 2},
  [58] = {.lex_state = 0},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 2},
  [61] = {.lex_state = 5},
  [62] = {.lex_state = 2},
  [63] = {.lex_state = 2},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 2},
  [66] = {.lex_state = 0},
  [67] = {.lex_state = 0},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 2},
  [70] = {.lex_state = 5},
  [71] = {.lex_state = 5},
  [72] = {.lex_state = 61},
  [73] = {.lex_state = 61},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 0},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 0},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 5},
  [82] = {.lex_state = 5},
  [83] = {.lex_state = 5},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 0},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 0},
  [90] = {.lex_state = 5},
  [91] = {.lex_state = 5},
  [92] = {.lex_state = 5},
  [93] = {.lex_state = 5},
  [94] = {.lex_state = 5},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 0},
  [98] = {.lex_state = 5},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__function_tag_dollar_token1] = ACTIONS(1),
    [anon_sym_DOLLAR_GT] = ACTIONS(1),
    [aux_sym__function_tag_slash_token1] = ACTIONS(1),
    [anon_sym_SLASH_GT] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [aux_sym_block_tag_token1] = ACTIONS(1),
    [aux_sym__comment_start_token1] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_replace] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_regex_replace] = ACTIONS(1),
    [anon_sym_SLASH_DQUOTE] = ACTIONS(1),
    [anon_sym_SLASH_SQUOTE] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(96),
    [sym__node] = STATE(3),
    [sym_function_tag] = STATE(3),
    [sym__function_tag_dollar] = STATE(32),
    [sym__function_tag_slash] = STATE(32),
    [sym_block_tag] = STATE(3),
    [sym_comment_tag] = STATE(3),
    [sym__comment_start] = STATE(57),
    [aux_sym_source_file_repeat1] = STATE(3),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__function_tag_dollar_token1] = ACTIONS(5),
    [aux_sym__function_tag_slash_token1] = ACTIONS(7),
    [aux_sym__comment_start_token1] = ACTIONS(9),
    [sym_text] = ACTIONS(11),
    [sym_ERROR] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(19), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [31] = 8,
    ACTIONS(5), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(7), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(21), 1,
      ts_builtin_sym_end,
    STATE(57), 1,
      sym__comment_start,
    ACTIONS(23), 2,
      sym_text,
      sym_ERROR,
    STATE(32), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(5), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [62] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(25), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(19), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [93] = 8,
    ACTIONS(27), 1,
      ts_builtin_sym_end,
    ACTIONS(29), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(32), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(35), 1,
      aux_sym__comment_start_token1,
    STATE(57), 1,
      sym__comment_start,
    ACTIONS(38), 2,
      sym_text,
      sym_ERROR,
    STATE(32), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(5), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [124] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(41), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(43), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(4), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [155] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(45), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(19), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [186] = 8,
    ACTIONS(35), 1,
      aux_sym__comment_start_token1,
    ACTIONS(47), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(50), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(53), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(55), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [217] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(25), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(58), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(7), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [248] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(60), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(62), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(2), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [279] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(64), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(66), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(12), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [310] = 8,
    ACTIONS(9), 1,
      aux_sym__comment_start_token1,
    ACTIONS(13), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(60), 1,
      aux_sym_block_tag_token1,
    STATE(63), 1,
      sym__comment_start,
    ACTIONS(19), 2,
      sym_text,
      sym_ERROR,
    STATE(33), 2,
      sym__function_tag_dollar,
      sym__function_tag_slash,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [341] = 8,
    ACTIONS(70), 1,
      anon_sym_replace,
    ACTIONS(73), 1,
      anon_sym_regex_replace,
    ACTIONS(76), 1,
      sym_identifier,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
    ACTIONS(68), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
  [369] = 9,
    ACTIONS(79), 1,
      anon_sym_SLASH_GT,
    ACTIONS(81), 1,
      anon_sym_GT,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [398] = 9,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(89), 1,
      anon_sym_SLASH_GT,
    ACTIONS(91), 1,
      anon_sym_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(14), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [427] = 9,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(93), 1,
      anon_sym_SLASH_GT,
    ACTIONS(95), 1,
      anon_sym_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [456] = 9,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(97), 1,
      anon_sym_SLASH_GT,
    ACTIONS(99), 1,
      anon_sym_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(16), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [485] = 8,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(101), 1,
      anon_sym_DOLLAR_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(21), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [511] = 8,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(103), 1,
      anon_sym_DOLLAR_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(20), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [537] = 8,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(105), 1,
      anon_sym_DOLLAR_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [563] = 8,
    ACTIONS(83), 1,
      anon_sym_replace,
    ACTIONS(85), 1,
      anon_sym_regex_replace,
    ACTIONS(87), 1,
      sym_identifier,
    ACTIONS(107), 1,
      anon_sym_DOLLAR_GT,
    STATE(26), 1,
      sym__replace_modifier,
    STATE(46), 1,
      sym__regex_modifier,
    STATE(50), 1,
      sym__standard_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_dollar_repeat1,
  [589] = 2,
    ACTIONS(111), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
    ACTIONS(109), 4,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_COMMA,
  [601] = 2,
    ACTIONS(115), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
    ACTIONS(113), 4,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_COMMA,
  [613] = 2,
    ACTIONS(117), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(119), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [624] = 2,
    ACTIONS(121), 1,
      ts_builtin_sym_end,
    ACTIONS(123), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [635] = 2,
    ACTIONS(125), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(127), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [646] = 2,
    ACTIONS(129), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(131), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [657] = 2,
    ACTIONS(133), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(135), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [668] = 2,
    ACTIONS(137), 1,
      ts_builtin_sym_end,
    ACTIONS(139), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [679] = 2,
    ACTIONS(141), 1,
      ts_builtin_sym_end,
    ACTIONS(143), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [690] = 2,
    ACTIONS(145), 1,
      ts_builtin_sym_end,
    ACTIONS(147), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [701] = 2,
    ACTIONS(149), 1,
      ts_builtin_sym_end,
    ACTIONS(151), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [712] = 1,
    ACTIONS(151), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [721] = 1,
    ACTIONS(153), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [730] = 1,
    ACTIONS(155), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [739] = 1,
    ACTIONS(157), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [748] = 1,
    ACTIONS(159), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [757] = 1,
    ACTIONS(161), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [766] = 1,
    ACTIONS(123), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [775] = 1,
    ACTIONS(139), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [784] = 1,
    ACTIONS(143), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [793] = 1,
    ACTIONS(147), 6,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym_block_tag_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [802] = 2,
    ACTIONS(163), 1,
      ts_builtin_sym_end,
    ACTIONS(157), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [813] = 2,
    ACTIONS(165), 1,
      ts_builtin_sym_end,
    ACTIONS(153), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [824] = 2,
    ACTIONS(167), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(169), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [835] = 2,
    ACTIONS(125), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(127), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [846] = 2,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    ACTIONS(159), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [857] = 2,
    ACTIONS(173), 1,
      ts_builtin_sym_end,
    ACTIONS(161), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [868] = 2,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
    ACTIONS(155), 5,
      aux_sym__function_tag_dollar_token1,
      aux_sym__function_tag_slash_token1,
      aux_sym__comment_start_token1,
      sym_text,
      sym_ERROR,
  [879] = 2,
    ACTIONS(177), 3,
      anon_sym_DOLLAR_GT,
      anon_sym_SLASH_GT,
      anon_sym_GT,
    ACTIONS(179), 3,
      anon_sym_replace,
      anon_sym_regex_replace,
      sym_identifier,
  [890] = 3,
    ACTIONS(181), 1,
      anon_sym_SQUOTE,
    STATE(54), 1,
      aux_sym_string_repeat2,
    ACTIONS(183), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [901] = 3,
    ACTIONS(181), 1,
      anon_sym_DQUOTE,
    STATE(53), 1,
      aux_sym_string_repeat1,
    ACTIONS(185), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [912] = 3,
    ACTIONS(187), 1,
      anon_sym_DQUOTE,
    STATE(53), 1,
      aux_sym_string_repeat1,
    ACTIONS(189), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [923] = 3,
    ACTIONS(192), 1,
      anon_sym_SQUOTE,
    STATE(54), 1,
      aux_sym_string_repeat2,
    ACTIONS(194), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [934] = 3,
    ACTIONS(197), 1,
      anon_sym_DQUOTE,
    STATE(52), 1,
      aux_sym_string_repeat1,
    ACTIONS(199), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [945] = 3,
    ACTIONS(197), 1,
      anon_sym_SQUOTE,
    STATE(51), 1,
      aux_sym_string_repeat2,
    ACTIONS(201), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [956] = 3,
    ACTIONS(203), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(205), 1,
      sym__comment_end,
    STATE(62), 1,
      aux_sym_comment_tag_repeat1,
  [966] = 3,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(24), 1,
      sym_string,
  [976] = 3,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(45), 1,
      sym_string,
  [986] = 3,
    ACTIONS(211), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(214), 1,
      sym__comment_end,
    STATE(60), 1,
      aux_sym_comment_tag_repeat1,
  [996] = 3,
    ACTIONS(216), 1,
      anon_sym_DQUOTE_SLASH,
    ACTIONS(218), 1,
      anon_sym_SQUOTE_SLASH,
    STATE(74), 1,
      sym_regex_pattern,
  [1006] = 3,
    ACTIONS(220), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(222), 1,
      sym__comment_end,
    STATE(60), 1,
      aux_sym_comment_tag_repeat1,
  [1016] = 3,
    ACTIONS(224), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(226), 1,
      sym__comment_end,
    STATE(65), 1,
      aux_sym_comment_tag_repeat1,
  [1026] = 3,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(97), 1,
      sym_string,
  [1036] = 3,
    ACTIONS(220), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(228), 1,
      sym__comment_end,
    STATE(60), 1,
      aux_sym_comment_tag_repeat1,
  [1046] = 3,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(28), 1,
      sym_string,
  [1056] = 3,
    ACTIONS(207), 1,
      anon_sym_DQUOTE,
    ACTIONS(209), 1,
      anon_sym_SQUOTE,
    STATE(27), 1,
      sym_string,
  [1066] = 2,
    ACTIONS(230), 1,
      anon_sym_COLON,
    ACTIONS(232), 1,
      anon_sym_EQ,
  [1073] = 1,
    ACTIONS(234), 2,
      aux_sym_comment_tag_token1,
      sym__comment_end,
  [1078] = 1,
    ACTIONS(236), 1,
      sym_identifier,
  [1082] = 1,
    ACTIONS(238), 1,
      sym_identifier,
  [1086] = 1,
    ACTIONS(240), 1,
      aux_sym_regex_pattern_token1,
  [1090] = 1,
    ACTIONS(242), 1,
      aux_sym_regex_pattern_token1,
  [1094] = 1,
    ACTIONS(244), 1,
      anon_sym_COMMA,
  [1098] = 1,
    ACTIONS(246), 1,
      anon_sym_EQ,
  [1102] = 1,
    ACTIONS(248), 1,
      anon_sym_EQ,
  [1106] = 1,
    ACTIONS(250), 1,
      anon_sym_GT,
  [1110] = 1,
    ACTIONS(252), 1,
      anon_sym_GT,
  [1114] = 1,
    ACTIONS(254), 1,
      anon_sym_EQ,
  [1118] = 1,
    ACTIONS(256), 1,
      anon_sym_COMMA,
  [1122] = 1,
    ACTIONS(258), 1,
      sym_identifier,
  [1126] = 1,
    ACTIONS(260), 1,
      sym_identifier,
  [1130] = 1,
    ACTIONS(262), 1,
      sym_identifier,
  [1134] = 1,
    ACTIONS(264), 1,
      anon_sym_GT,
  [1138] = 1,
    ACTIONS(266), 1,
      anon_sym_GT,
  [1142] = 1,
    ACTIONS(268), 1,
      anon_sym_SLASH_DQUOTE,
  [1146] = 1,
    ACTIONS(270), 1,
      anon_sym_GT,
  [1150] = 1,
    ACTIONS(272), 1,
      anon_sym_GT,
  [1154] = 1,
    ACTIONS(274), 1,
      anon_sym_GT,
  [1158] = 1,
    ACTIONS(276), 1,
      sym_identifier,
  [1162] = 1,
    ACTIONS(278), 1,
      sym_identifier,
  [1166] = 1,
    ACTIONS(280), 1,
      sym_identifier,
  [1170] = 1,
    ACTIONS(282), 1,
      sym_identifier,
  [1174] = 1,
    ACTIONS(284), 1,
      sym_identifier,
  [1178] = 1,
    ACTIONS(268), 1,
      anon_sym_SLASH_SQUOTE,
  [1182] = 1,
    ACTIONS(286), 1,
      ts_builtin_sym_end,
  [1186] = 1,
    ACTIONS(288), 1,
      anon_sym_COMMA,
  [1190] = 1,
    ACTIONS(290), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 31,
  [SMALL_STATE(4)] = 62,
  [SMALL_STATE(5)] = 93,
  [SMALL_STATE(6)] = 124,
  [SMALL_STATE(7)] = 155,
  [SMALL_STATE(8)] = 186,
  [SMALL_STATE(9)] = 217,
  [SMALL_STATE(10)] = 248,
  [SMALL_STATE(11)] = 279,
  [SMALL_STATE(12)] = 310,
  [SMALL_STATE(13)] = 341,
  [SMALL_STATE(14)] = 369,
  [SMALL_STATE(15)] = 398,
  [SMALL_STATE(16)] = 427,
  [SMALL_STATE(17)] = 456,
  [SMALL_STATE(18)] = 485,
  [SMALL_STATE(19)] = 511,
  [SMALL_STATE(20)] = 537,
  [SMALL_STATE(21)] = 563,
  [SMALL_STATE(22)] = 589,
  [SMALL_STATE(23)] = 601,
  [SMALL_STATE(24)] = 613,
  [SMALL_STATE(25)] = 624,
  [SMALL_STATE(26)] = 635,
  [SMALL_STATE(27)] = 646,
  [SMALL_STATE(28)] = 657,
  [SMALL_STATE(29)] = 668,
  [SMALL_STATE(30)] = 679,
  [SMALL_STATE(31)] = 690,
  [SMALL_STATE(32)] = 701,
  [SMALL_STATE(33)] = 712,
  [SMALL_STATE(34)] = 721,
  [SMALL_STATE(35)] = 730,
  [SMALL_STATE(36)] = 739,
  [SMALL_STATE(37)] = 748,
  [SMALL_STATE(38)] = 757,
  [SMALL_STATE(39)] = 766,
  [SMALL_STATE(40)] = 775,
  [SMALL_STATE(41)] = 784,
  [SMALL_STATE(42)] = 793,
  [SMALL_STATE(43)] = 802,
  [SMALL_STATE(44)] = 813,
  [SMALL_STATE(45)] = 824,
  [SMALL_STATE(46)] = 835,
  [SMALL_STATE(47)] = 846,
  [SMALL_STATE(48)] = 857,
  [SMALL_STATE(49)] = 868,
  [SMALL_STATE(50)] = 879,
  [SMALL_STATE(51)] = 890,
  [SMALL_STATE(52)] = 901,
  [SMALL_STATE(53)] = 912,
  [SMALL_STATE(54)] = 923,
  [SMALL_STATE(55)] = 934,
  [SMALL_STATE(56)] = 945,
  [SMALL_STATE(57)] = 956,
  [SMALL_STATE(58)] = 966,
  [SMALL_STATE(59)] = 976,
  [SMALL_STATE(60)] = 986,
  [SMALL_STATE(61)] = 996,
  [SMALL_STATE(62)] = 1006,
  [SMALL_STATE(63)] = 1016,
  [SMALL_STATE(64)] = 1026,
  [SMALL_STATE(65)] = 1036,
  [SMALL_STATE(66)] = 1046,
  [SMALL_STATE(67)] = 1056,
  [SMALL_STATE(68)] = 1066,
  [SMALL_STATE(69)] = 1073,
  [SMALL_STATE(70)] = 1078,
  [SMALL_STATE(71)] = 1082,
  [SMALL_STATE(72)] = 1086,
  [SMALL_STATE(73)] = 1090,
  [SMALL_STATE(74)] = 1094,
  [SMALL_STATE(75)] = 1098,
  [SMALL_STATE(76)] = 1102,
  [SMALL_STATE(77)] = 1106,
  [SMALL_STATE(78)] = 1110,
  [SMALL_STATE(79)] = 1114,
  [SMALL_STATE(80)] = 1118,
  [SMALL_STATE(81)] = 1122,
  [SMALL_STATE(82)] = 1126,
  [SMALL_STATE(83)] = 1130,
  [SMALL_STATE(84)] = 1134,
  [SMALL_STATE(85)] = 1138,
  [SMALL_STATE(86)] = 1142,
  [SMALL_STATE(87)] = 1146,
  [SMALL_STATE(88)] = 1150,
  [SMALL_STATE(89)] = 1154,
  [SMALL_STATE(90)] = 1158,
  [SMALL_STATE(91)] = 1162,
  [SMALL_STATE(92)] = 1166,
  [SMALL_STATE(93)] = 1170,
  [SMALL_STATE(94)] = 1174,
  [SMALL_STATE(95)] = 1178,
  [SMALL_STATE(96)] = 1182,
  [SMALL_STATE(97)] = 1186,
  [SMALL_STATE(98)] = 1190,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(82),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(85),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [13] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(91),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [25] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [27] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [29] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [32] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(82),
  [35] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(85),
  [38] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(5),
  [41] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [43] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [45] = {.entry = {.count = 1, .reusable = false}}, SHIFT(71),
  [47] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(90),
  [50] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(91),
  [53] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [55] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [58] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [60] = {.entry = {.count = 1, .reusable = false}}, SHIFT(93),
  [62] = {.entry = {.count = 1, .reusable = false}}, SHIFT(2),
  [64] = {.entry = {.count = 1, .reusable = false}}, SHIFT(92),
  [66] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [68] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__function_tag_dollar_repeat1, 2, 0, 0),
  [70] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_dollar_repeat1, 2, 0, 0), SHIFT_REPEAT(76),
  [73] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_dollar_repeat1, 2, 0, 0), SHIFT_REPEAT(79),
  [76] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_dollar_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [79] = {.entry = {.count = 1, .reusable = true}}, SHIFT(25),
  [81] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [83] = {.entry = {.count = 1, .reusable = false}}, SHIFT(76),
  [85] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [87] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [89] = {.entry = {.count = 1, .reusable = true}}, SHIFT(43),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [95] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [97] = {.entry = {.count = 1, .reusable = true}}, SHIFT(36),
  [99] = {.entry = {.count = 1, .reusable = true}}, SHIFT(11),
  [101] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [109] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [111] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [113] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [115] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [117] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__standard_modifier, 5, 0, 6),
  [119] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__standard_modifier, 5, 0, 6),
  [121] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_slash, 4, 0, 0),
  [123] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_slash, 4, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1, 0, 2),
  [127] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1, 0, 2),
  [129] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__regex_modifier, 5, 0, 5),
  [131] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__regex_modifier, 5, 0, 5),
  [133] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__replace_modifier, 5, 0, 5),
  [135] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__replace_modifier, 5, 0, 5),
  [137] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 6, 0, 4),
  [139] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 6, 0, 4),
  [141] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 7, 0, 7),
  [143] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 7, 0, 7),
  [145] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 8, 0, 8),
  [147] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 8, 0, 8),
  [149] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_tag, 1, 0, 0),
  [151] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_tag, 1, 0, 0),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_tag, 2, 0, 0),
  [155] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_dollar, 3, 0, 0),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_slash, 3, 0, 0),
  [159] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_tag, 3, 0, 0),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_dollar, 4, 0, 0),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_slash, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_tag, 2, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__standard_modifier, 3, 0, 3),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__standard_modifier, 3, 0, 3),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_tag, 3, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_dollar, 4, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_dollar, 3, 0, 0),
  [177] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1, 0, 1),
  [179] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1, 0, 1),
  [181] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [183] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [185] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [189] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(53),
  [192] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [194] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(54),
  [197] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [199] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [203] = {.entry = {.count = 1, .reusable = false}}, SHIFT(62),
  [205] = {.entry = {.count = 1, .reusable = false}}, SHIFT(44),
  [207] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [209] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [211] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_comment_tag_repeat1, 2, 0, 0), SHIFT_REPEAT(60),
  [214] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_comment_tag_repeat1, 2, 0, 0),
  [216] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [218] = {.entry = {.count = 1, .reusable = true}}, SHIFT(73),
  [220] = {.entry = {.count = 1, .reusable = false}}, SHIFT(60),
  [222] = {.entry = {.count = 1, .reusable = false}}, SHIFT(47),
  [224] = {.entry = {.count = 1, .reusable = false}}, SHIFT(65),
  [226] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [228] = {.entry = {.count = 1, .reusable = false}}, SHIFT(37),
  [230] = {.entry = {.count = 1, .reusable = true}}, SHIFT(98),
  [232] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [234] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__comment_start, 2, 0, 0),
  [236] = {.entry = {.count = 1, .reusable = true}}, SHIFT(78),
  [238] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [240] = {.entry = {.count = 1, .reusable = true}}, SHIFT(86),
  [242] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [244] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [246] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [248] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [250] = {.entry = {.count = 1, .reusable = true}}, SHIFT(29),
  [252] = {.entry = {.count = 1, .reusable = true}}, SHIFT(30),
  [254] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [256] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regex_pattern, 3, 0, 0),
  [258] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
  [260] = {.entry = {.count = 1, .reusable = true}}, SHIFT(15),
  [262] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [264] = {.entry = {.count = 1, .reusable = true}}, SHIFT(31),
  [266] = {.entry = {.count = 1, .reusable = true}}, SHIFT(69),
  [268] = {.entry = {.count = 1, .reusable = true}}, SHIFT(80),
  [270] = {.entry = {.count = 1, .reusable = true}}, SHIFT(40),
  [272] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [274] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [276] = {.entry = {.count = 1, .reusable = true}}, SHIFT(18),
  [278] = {.entry = {.count = 1, .reusable = true}}, SHIFT(17),
  [280] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [282] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [284] = {.entry = {.count = 1, .reusable = true}}, SHIFT(89),
  [286] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [288] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [290] = {.entry = {.count = 1, .reusable = true}}, SHIFT(75),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef TREE_SITTER_HIDE_SYMBOLS
#define TS_PUBLIC
#elif defined(_WIN32)
#define TS_PUBLIC __declspec(dllexport)
#else
#define TS_PUBLIC __attribute__((visibility("default")))
#endif

TS_PUBLIC const TSLanguage *tree_sitter_mtml(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
