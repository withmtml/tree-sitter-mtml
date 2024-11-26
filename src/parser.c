#include "tree_sitter/parser.h"

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 14
#define STATE_COUNT 102
#define LARGE_STATE_COUNT 2
#define SYMBOL_COUNT 44
#define ALIAS_COUNT 0
#define TOKEN_COUNT 25
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 5
#define MAX_ALIAS_SEQUENCE_LENGTH 8
#define PRODUCTION_ID_COUNT 9

enum ts_symbol_identifiers {
  aux_sym__function_tag_slash_token1 = 1,
  anon_sym_SLASH_GT = 2,
  anon_sym_GT = 3,
  aux_sym__function_tag_dollar_token1 = 4,
  anon_sym_DOLLAR_GT = 5,
  aux_sym_block_tag_token1 = 6,
  aux_sym_comment_tag_token1 = 7,
  aux_sym_comment_tag_token2 = 8,
  anon_sym_EQ = 9,
  anon_sym_replace = 10,
  anon_sym_COMMA = 11,
  anon_sym_regex_replace = 12,
  anon_sym_field = 13,
  anon_sym_COLON = 14,
  anon_sym_DQUOTE = 15,
  anon_sym_SLASH = 16,
  aux_sym_regex_pattern_token1 = 17,
  sym_identifier = 18,
  aux_sym_string_token1 = 19,
  anon_sym_SQUOTE = 20,
  aux_sym_string_token2 = 21,
  sym_escape_sequence = 22,
  sym_text = 23,
  sym_ERROR = 24,
  sym_source_file = 25,
  sym__node = 26,
  sym_function_tag = 27,
  sym__function_tag_slash = 28,
  sym__function_tag_none = 29,
  sym__function_tag_dollar = 30,
  sym_block_tag = 31,
  sym_comment_tag = 32,
  sym_modifier = 33,
  sym__standard_modifier = 34,
  sym__replace_modifier = 35,
  sym__regex_modifier = 36,
  sym__field_modifier = 37,
  sym_regex_pattern = 38,
  sym_string = 39,
  aux_sym_source_file_repeat1 = 40,
  aux_sym__function_tag_slash_repeat1 = 41,
  aux_sym_string_repeat1 = 42,
  aux_sym_string_repeat2 = 43,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [aux_sym__function_tag_slash_token1] = "_function_tag_slash_token1",
  [anon_sym_SLASH_GT] = "/>",
  [anon_sym_GT] = ">",
  [aux_sym__function_tag_dollar_token1] = "_function_tag_dollar_token1",
  [anon_sym_DOLLAR_GT] = "$>",
  [aux_sym_block_tag_token1] = "block_tag_token1",
  [aux_sym_comment_tag_token1] = "comment_tag_token1",
  [aux_sym_comment_tag_token2] = "comment_tag_token2",
  [anon_sym_EQ] = "=",
  [anon_sym_replace] = "replace",
  [anon_sym_COMMA] = ",",
  [anon_sym_regex_replace] = "regex_replace",
  [anon_sym_field] = "field",
  [anon_sym_COLON] = ":",
  [anon_sym_DQUOTE] = "\"",
  [anon_sym_SLASH] = "/",
  [aux_sym_regex_pattern_token1] = "regex_pattern_token1",
  [sym_identifier] = "identifier",
  [aux_sym_string_token1] = "string_token1",
  [anon_sym_SQUOTE] = "'",
  [aux_sym_string_token2] = "string_token2",
  [sym_escape_sequence] = "escape_sequence",
  [sym_text] = "text",
  [sym_ERROR] = "ERROR",
  [sym_source_file] = "source_file",
  [sym__node] = "_node",
  [sym_function_tag] = "function_tag",
  [sym__function_tag_slash] = "_function_tag_slash",
  [sym__function_tag_none] = "_function_tag_none",
  [sym__function_tag_dollar] = "_function_tag_dollar",
  [sym_block_tag] = "block_tag",
  [sym_comment_tag] = "comment_tag",
  [sym_modifier] = "modifier",
  [sym__standard_modifier] = "_standard_modifier",
  [sym__replace_modifier] = "_replace_modifier",
  [sym__regex_modifier] = "_regex_modifier",
  [sym__field_modifier] = "_field_modifier",
  [sym_regex_pattern] = "regex_pattern",
  [sym_string] = "string",
  [aux_sym_source_file_repeat1] = "source_file_repeat1",
  [aux_sym__function_tag_slash_repeat1] = "_function_tag_slash_repeat1",
  [aux_sym_string_repeat1] = "string_repeat1",
  [aux_sym_string_repeat2] = "string_repeat2",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [aux_sym__function_tag_slash_token1] = aux_sym__function_tag_slash_token1,
  [anon_sym_SLASH_GT] = anon_sym_SLASH_GT,
  [anon_sym_GT] = anon_sym_GT,
  [aux_sym__function_tag_dollar_token1] = aux_sym__function_tag_dollar_token1,
  [anon_sym_DOLLAR_GT] = anon_sym_DOLLAR_GT,
  [aux_sym_block_tag_token1] = aux_sym_block_tag_token1,
  [aux_sym_comment_tag_token1] = aux_sym_comment_tag_token1,
  [aux_sym_comment_tag_token2] = aux_sym_comment_tag_token2,
  [anon_sym_EQ] = anon_sym_EQ,
  [anon_sym_replace] = anon_sym_replace,
  [anon_sym_COMMA] = anon_sym_COMMA,
  [anon_sym_regex_replace] = anon_sym_regex_replace,
  [anon_sym_field] = anon_sym_field,
  [anon_sym_COLON] = anon_sym_COLON,
  [anon_sym_DQUOTE] = anon_sym_DQUOTE,
  [anon_sym_SLASH] = anon_sym_SLASH,
  [aux_sym_regex_pattern_token1] = aux_sym_regex_pattern_token1,
  [sym_identifier] = sym_identifier,
  [aux_sym_string_token1] = aux_sym_string_token1,
  [anon_sym_SQUOTE] = anon_sym_SQUOTE,
  [aux_sym_string_token2] = aux_sym_string_token2,
  [sym_escape_sequence] = sym_escape_sequence,
  [sym_text] = sym_text,
  [sym_ERROR] = sym_ERROR,
  [sym_source_file] = sym_source_file,
  [sym__node] = sym__node,
  [sym_function_tag] = sym_function_tag,
  [sym__function_tag_slash] = sym__function_tag_slash,
  [sym__function_tag_none] = sym__function_tag_none,
  [sym__function_tag_dollar] = sym__function_tag_dollar,
  [sym_block_tag] = sym_block_tag,
  [sym_comment_tag] = sym_comment_tag,
  [sym_modifier] = sym_modifier,
  [sym__standard_modifier] = sym__standard_modifier,
  [sym__replace_modifier] = sym__replace_modifier,
  [sym__regex_modifier] = sym__regex_modifier,
  [sym__field_modifier] = sym__field_modifier,
  [sym_regex_pattern] = sym_regex_pattern,
  [sym_string] = sym_string,
  [aux_sym_source_file_repeat1] = aux_sym_source_file_repeat1,
  [aux_sym__function_tag_slash_repeat1] = aux_sym__function_tag_slash_repeat1,
  [aux_sym_string_repeat1] = aux_sym_string_repeat1,
  [aux_sym_string_repeat2] = aux_sym_string_repeat2,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
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
  [aux_sym__function_tag_dollar_token1] = {
    .visible = false,
    .named = false,
  },
  [anon_sym_DOLLAR_GT] = {
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
  [aux_sym_comment_tag_token2] = {
    .visible = false,
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
  [anon_sym_field] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_COLON] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_DQUOTE] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_SLASH] = {
    .visible = true,
    .named = false,
  },
  [aux_sym_regex_pattern_token1] = {
    .visible = false,
    .named = false,
  },
  [sym_identifier] = {
    .visible = true,
    .named = true,
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
  [sym__function_tag_slash] = {
    .visible = false,
    .named = true,
  },
  [sym__function_tag_none] = {
    .visible = false,
    .named = true,
  },
  [sym__function_tag_dollar] = {
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
  [sym__field_modifier] = {
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
  [aux_sym__function_tag_slash_repeat1] = {
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
  [5] = {.index = 9, .length = 2},
  [6] = {.index = 11, .length = 3},
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
    {field_name, 1},
    {field_name, 5},
  [11] =
    {field_key, 0},
    {field_pattern, 2},
    {field_replacement, 4},
  [14] =
    {field_key, 0},
    {field_value, 4},
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
  [7] = 7,
  [8] = 6,
  [9] = 3,
  [10] = 2,
  [11] = 5,
  [12] = 7,
  [13] = 13,
  [14] = 14,
  [15] = 15,
  [16] = 14,
  [17] = 15,
  [18] = 18,
  [19] = 19,
  [20] = 19,
  [21] = 18,
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
  [33] = 33,
  [34] = 34,
  [35] = 35,
  [36] = 36,
  [37] = 37,
  [38] = 38,
  [39] = 39,
  [40] = 36,
  [41] = 35,
  [42] = 38,
  [43] = 34,
  [44] = 44,
  [45] = 45,
  [46] = 46,
  [47] = 37,
  [48] = 33,
  [49] = 39,
  [50] = 45,
  [51] = 46,
  [52] = 44,
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
  [63] = 63,
  [64] = 64,
  [65] = 65,
  [66] = 66,
  [67] = 66,
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
  [87] = 87,
  [88] = 88,
  [89] = 89,
  [90] = 70,
  [91] = 84,
  [92] = 87,
  [93] = 88,
  [94] = 89,
  [95] = 95,
  [96] = 80,
  [97] = 83,
  [98] = 86,
  [99] = 79,
  [100] = 100,
  [101] = 69,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(37);
      ADVANCE_MAP(
        '"', 57,
        '$', 8,
        '\'', 84,
        ',', 53,
        '/', 58,
        ':', 56,
        '<', 3,
        '=', 51,
        '>', 43,
        '\\', 10,
        'f', 74,
        'r', 67,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 1:
      if (lookahead == '"') ADVANCE(57);
      if (lookahead == '\\') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0) ADVANCE(83);
      END_STATE();
    case 2:
      if (lookahead == '$') ADVANCE(8);
      if (lookahead == ',') ADVANCE(53);
      if (lookahead == '/') ADVANCE(7);
      if (lookahead == '>') ADVANCE(43);
      if (lookahead == 'f') ADVANCE(74);
      if (lookahead == 'r') ADVANCE(67);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(2);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 3:
      if (lookahead == '$') ADVANCE(16);
      if (lookahead == '/') ADVANCE(17);
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(25);
      END_STATE();
    case 4:
      if (lookahead == '\'') ADVANCE(84);
      if (lookahead == '\\') ADVANCE(10);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(85);
      if (lookahead != 0) ADVANCE(86);
      END_STATE();
    case 5:
      if (lookahead == '/') ADVANCE(91);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(92);
      END_STATE();
    case 6:
      if (lookahead == ':') ADVANCE(15);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 7:
      if (lookahead == '<') ADVANCE(18);
      if (lookahead == '>') ADVANCE(42);
      END_STATE();
    case 8:
      if (lookahead == '>') ADVANCE(46);
      END_STATE();
    case 9:
      if (lookahead == '>') ADVANCE(50);
      END_STATE();
    case 10:
      ADVANCE_MAP(
        'u', 33,
        '"', 87,
        '\'', 87,
        '\\', 87,
        'b', 87,
        'f', 87,
        'n', 87,
        'r', 87,
        't', 87,
      );
      END_STATE();
    case 11:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(49);
      END_STATE();
    case 12:
      if (lookahead == 'E' ||
          lookahead == 'e') ADVANCE(9);
      END_STATE();
    case 13:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(19);
      END_STATE();
    case 14:
      if (lookahead == 'G' ||
          lookahead == 'g') ADVANCE(20);
      END_STATE();
    case 15:
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(14);
      END_STATE();
    case 16:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(26);
      END_STATE();
    case 17:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(27);
      END_STATE();
    case 18:
      if (lookahead == 'M' ||
          lookahead == 'm') ADVANCE(28);
      END_STATE();
    case 19:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(21);
      END_STATE();
    case 20:
      if (lookahead == 'N' ||
          lookahead == 'n') ADVANCE(22);
      END_STATE();
    case 21:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(23);
      END_STATE();
    case 22:
      if (lookahead == 'O' ||
          lookahead == 'o') ADVANCE(24);
      END_STATE();
    case 23:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(11);
      END_STATE();
    case 24:
      if (lookahead == 'R' ||
          lookahead == 'r') ADVANCE(12);
      END_STATE();
    case 25:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(38);
      END_STATE();
    case 26:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(45);
      END_STATE();
    case 27:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(48);
      END_STATE();
    case 28:
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(6);
      END_STATE();
    case 29:
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(29);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 30:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(87);
      END_STATE();
    case 31:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(30);
      END_STATE();
    case 32:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(31);
      END_STATE();
    case 33:
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'F') ||
          ('a' <= lookahead && lookahead <= 'f')) ADVANCE(32);
      END_STATE();
    case 34:
      if (eof) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(88);
      if (lookahead == '<') ADVANCE(94);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 35:
      if (eof) ADVANCE(37);
      if (lookahead == '\n') ADVANCE(88);
      if (lookahead == '<') ADVANCE(93);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0) ADVANCE(89);
      END_STATE();
    case 36:
      if (eof) ADVANCE(37);
      ADVANCE_MAP(
        '"', 57,
        '$', 8,
        '\'', 84,
        ',', 53,
        '/', 58,
        ':', 56,
        '<', 3,
        '=', 51,
        '>', 43,
        'f', 74,
        'r', 67,
      );
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') SKIP(36);
      if (('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 37:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 38:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == ':') ADVANCE(40);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(13);
      END_STATE();
    case 39:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == ':') ADVANCE(41);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 40:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(13);
      END_STATE();
    case 41:
      ACCEPT_TOKEN(aux_sym__function_tag_slash_token1);
      if (lookahead == 'I' ||
          lookahead == 'i') ADVANCE(96);
      END_STATE();
    case 42:
      ACCEPT_TOKEN(anon_sym_SLASH_GT);
      END_STATE();
    case 43:
      ACCEPT_TOKEN(anon_sym_GT);
      END_STATE();
    case 44:
      ACCEPT_TOKEN(aux_sym__function_tag_dollar_token1);
      END_STATE();
    case 45:
      ACCEPT_TOKEN(aux_sym__function_tag_dollar_token1);
      if (lookahead == ':') ADVANCE(44);
      END_STATE();
    case 46:
      ACCEPT_TOKEN(anon_sym_DOLLAR_GT);
      END_STATE();
    case 47:
      ACCEPT_TOKEN(aux_sym_block_tag_token1);
      END_STATE();
    case 48:
      ACCEPT_TOKEN(aux_sym_block_tag_token1);
      if (lookahead == ':') ADVANCE(47);
      END_STATE();
    case 49:
      ACCEPT_TOKEN(aux_sym_comment_tag_token1);
      END_STATE();
    case 50:
      ACCEPT_TOKEN(aux_sym_comment_tag_token2);
      END_STATE();
    case 51:
      ACCEPT_TOKEN(anon_sym_EQ);
      END_STATE();
    case 52:
      ACCEPT_TOKEN(anon_sym_replace);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 53:
      ACCEPT_TOKEN(anon_sym_COMMA);
      END_STATE();
    case 54:
      ACCEPT_TOKEN(anon_sym_regex_replace);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 55:
      ACCEPT_TOKEN(anon_sym_field);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 56:
      ACCEPT_TOKEN(anon_sym_COLON);
      END_STATE();
    case 57:
      ACCEPT_TOKEN(anon_sym_DQUOTE);
      END_STATE();
    case 58:
      ACCEPT_TOKEN(anon_sym_SLASH);
      END_STATE();
    case 59:
      ACCEPT_TOKEN(aux_sym_regex_pattern_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(59);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(60);
      END_STATE();
    case 60:
      ACCEPT_TOKEN(aux_sym_regex_pattern_token1);
      if (lookahead != 0 &&
          lookahead != '/') ADVANCE(60);
      END_STATE();
    case 61:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == '_') ADVANCE(79);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 62:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(64);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 63:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'a') ADVANCE(65);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('b' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 64:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(70);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 65:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'c') ADVANCE(72);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 66:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'd') ADVANCE(55);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 67:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(73);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 68:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(75);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 69:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(80);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 70:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(52);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 71:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(78);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 72:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'e') ADVANCE(54);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 73:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'g') ADVANCE(69);
      if (lookahead == 'p') ADVANCE(76);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 74:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'i') ADVANCE(68);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 75:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(66);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 76:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(62);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 77:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'l') ADVANCE(63);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 78:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'p') ADVANCE(77);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 79:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'r') ADVANCE(71);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 80:
      ACCEPT_TOKEN(sym_identifier);
      if (lookahead == 'x') ADVANCE(61);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 81:
      ACCEPT_TOKEN(sym_identifier);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(81);
      END_STATE();
    case 82:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(82);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(83);
      END_STATE();
    case 83:
      ACCEPT_TOKEN(aux_sym_string_token1);
      if (lookahead != 0 &&
          lookahead != '"' &&
          lookahead != '\\') ADVANCE(83);
      END_STATE();
    case 84:
      ACCEPT_TOKEN(anon_sym_SQUOTE);
      END_STATE();
    case 85:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(85);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(86);
      END_STATE();
    case 86:
      ACCEPT_TOKEN(aux_sym_string_token2);
      if (lookahead != 0 &&
          lookahead != '\'' &&
          lookahead != '\\') ADVANCE(86);
      END_STATE();
    case 87:
      ACCEPT_TOKEN(sym_escape_sequence);
      END_STATE();
    case 88:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\n') ADVANCE(88);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(88);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(89);
      END_STATE();
    case 89:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '\n') ADVANCE(92);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(89);
      END_STATE();
    case 90:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '/') ADVANCE(91);
      if (('\t' <= lookahead && lookahead <= '\r') ||
          lookahead == ' ') ADVANCE(90);
      if (lookahead != 0 &&
          lookahead != '<') ADVANCE(92);
      END_STATE();
    case 91:
      ACCEPT_TOKEN(sym_text);
      if (lookahead == '<') ADVANCE(18);
      if (lookahead != 0) ADVANCE(92);
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
          lookahead == 'e') ADVANCE(49);
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
          lookahead == 't') ADVANCE(45);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 103:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(48);
      if (lookahead != 0 &&
          lookahead != '\n') ADVANCE(105);
      END_STATE();
    case 104:
      ACCEPT_TOKEN(sym_ERROR);
      if (lookahead == 'T' ||
          lookahead == 't') ADVANCE(39);
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
  [1] = {.lex_state = 34},
  [2] = {.lex_state = 35},
  [3] = {.lex_state = 35},
  [4] = {.lex_state = 34},
  [5] = {.lex_state = 35},
  [6] = {.lex_state = 34},
  [7] = {.lex_state = 35},
  [8] = {.lex_state = 35},
  [9] = {.lex_state = 35},
  [10] = {.lex_state = 35},
  [11] = {.lex_state = 35},
  [12] = {.lex_state = 35},
  [13] = {.lex_state = 2},
  [14] = {.lex_state = 2},
  [15] = {.lex_state = 2},
  [16] = {.lex_state = 2},
  [17] = {.lex_state = 2},
  [18] = {.lex_state = 0},
  [19] = {.lex_state = 0},
  [20] = {.lex_state = 0},
  [21] = {.lex_state = 0},
  [22] = {.lex_state = 2},
  [23] = {.lex_state = 2},
  [24] = {.lex_state = 2},
  [25] = {.lex_state = 2},
  [26] = {.lex_state = 2},
  [27] = {.lex_state = 2},
  [28] = {.lex_state = 2},
  [29] = {.lex_state = 2},
  [30] = {.lex_state = 2},
  [31] = {.lex_state = 2},
  [32] = {.lex_state = 2},
  [33] = {.lex_state = 34},
  [34] = {.lex_state = 34},
  [35] = {.lex_state = 34},
  [36] = {.lex_state = 34},
  [37] = {.lex_state = 34},
  [38] = {.lex_state = 34},
  [39] = {.lex_state = 34},
  [40] = {.lex_state = 35},
  [41] = {.lex_state = 35},
  [42] = {.lex_state = 35},
  [43] = {.lex_state = 35},
  [44] = {.lex_state = 35},
  [45] = {.lex_state = 35},
  [46] = {.lex_state = 35},
  [47] = {.lex_state = 35},
  [48] = {.lex_state = 35},
  [49] = {.lex_state = 35},
  [50] = {.lex_state = 34},
  [51] = {.lex_state = 34},
  [52] = {.lex_state = 34},
  [53] = {.lex_state = 4},
  [54] = {.lex_state = 1},
  [55] = {.lex_state = 4},
  [56] = {.lex_state = 4},
  [57] = {.lex_state = 1},
  [58] = {.lex_state = 1},
  [59] = {.lex_state = 0},
  [60] = {.lex_state = 0},
  [61] = {.lex_state = 0},
  [62] = {.lex_state = 0},
  [63] = {.lex_state = 0},
  [64] = {.lex_state = 0},
  [65] = {.lex_state = 0},
  [66] = {.lex_state = 5},
  [67] = {.lex_state = 5},
  [68] = {.lex_state = 0},
  [69] = {.lex_state = 29},
  [70] = {.lex_state = 2},
  [71] = {.lex_state = 0},
  [72] = {.lex_state = 29},
  [73] = {.lex_state = 0},
  [74] = {.lex_state = 0},
  [75] = {.lex_state = 0},
  [76] = {.lex_state = 59},
  [77] = {.lex_state = 0},
  [78] = {.lex_state = 0},
  [79] = {.lex_state = 29},
  [80] = {.lex_state = 0},
  [81] = {.lex_state = 0},
  [82] = {.lex_state = 0},
  [83] = {.lex_state = 29},
  [84] = {.lex_state = 0},
  [85] = {.lex_state = 0},
  [86] = {.lex_state = 29},
  [87] = {.lex_state = 0},
  [88] = {.lex_state = 0},
  [89] = {.lex_state = 29},
  [90] = {.lex_state = 2},
  [91] = {.lex_state = 0},
  [92] = {.lex_state = 0},
  [93] = {.lex_state = 0},
  [94] = {.lex_state = 29},
  [95] = {.lex_state = 0},
  [96] = {.lex_state = 0},
  [97] = {.lex_state = 29},
  [98] = {.lex_state = 29},
  [99] = {.lex_state = 29},
  [100] = {.lex_state = 0},
  [101] = {.lex_state = 29},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [aux_sym__function_tag_slash_token1] = ACTIONS(1),
    [anon_sym_GT] = ACTIONS(1),
    [aux_sym__function_tag_dollar_token1] = ACTIONS(1),
    [anon_sym_DOLLAR_GT] = ACTIONS(1),
    [aux_sym_block_tag_token1] = ACTIONS(1),
    [aux_sym_comment_tag_token1] = ACTIONS(1),
    [anon_sym_EQ] = ACTIONS(1),
    [anon_sym_replace] = ACTIONS(1),
    [anon_sym_COMMA] = ACTIONS(1),
    [anon_sym_regex_replace] = ACTIONS(1),
    [anon_sym_field] = ACTIONS(1),
    [anon_sym_COLON] = ACTIONS(1),
    [anon_sym_DQUOTE] = ACTIONS(1),
    [anon_sym_SLASH] = ACTIONS(1),
    [sym_identifier] = ACTIONS(1),
    [anon_sym_SQUOTE] = ACTIONS(1),
    [sym_escape_sequence] = ACTIONS(1),
  },
  [1] = {
    [sym_source_file] = STATE(73),
    [sym__node] = STATE(4),
    [sym_function_tag] = STATE(4),
    [sym__function_tag_slash] = STATE(36),
    [sym__function_tag_none] = STATE(36),
    [sym__function_tag_dollar] = STATE(36),
    [sym_block_tag] = STATE(4),
    [sym_comment_tag] = STATE(4),
    [aux_sym_source_file_repeat1] = STATE(4),
    [ts_builtin_sym_end] = ACTIONS(3),
    [aux_sym__function_tag_slash_token1] = ACTIONS(5),
    [aux_sym__function_tag_dollar_token1] = ACTIONS(7),
    [aux_sym_comment_tag_token1] = ACTIONS(9),
    [sym_text] = ACTIONS(11),
    [sym_ERROR] = ACTIONS(11),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 8,
    ACTIONS(13), 1,
      ts_builtin_sym_end,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(19), 1,
      aux_sym_block_tag_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(23), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(5), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [32] = 8,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(25), 1,
      ts_builtin_sym_end,
    ACTIONS(27), 1,
      aux_sym_block_tag_token1,
    ACTIONS(29), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(7), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [64] = 7,
    ACTIONS(5), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(7), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(9), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(31), 1,
      ts_builtin_sym_end,
    ACTIONS(33), 2,
      sym_text,
      sym_ERROR,
    STATE(36), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(6), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [93] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(27), 1,
      aux_sym_block_tag_token1,
    ACTIONS(35), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [122] = 7,
    ACTIONS(37), 1,
      ts_builtin_sym_end,
    ACTIONS(39), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(42), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(45), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(48), 2,
      sym_text,
      sym_ERROR,
    STATE(36), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(6), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [151] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(51), 1,
      aux_sym_block_tag_token1,
    ACTIONS(35), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [180] = 7,
    ACTIONS(53), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(56), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(59), 1,
      aux_sym_block_tag_token1,
    ACTIONS(61), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(64), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [209] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(67), 1,
      aux_sym_block_tag_token1,
    ACTIONS(69), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(12), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [238] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(71), 1,
      aux_sym_block_tag_token1,
    ACTIONS(73), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(11), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [267] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(67), 1,
      aux_sym_block_tag_token1,
    ACTIONS(35), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [296] = 7,
    ACTIONS(15), 1,
      aux_sym__function_tag_slash_token1,
    ACTIONS(17), 1,
      aux_sym__function_tag_dollar_token1,
    ACTIONS(21), 1,
      aux_sym_comment_tag_token1,
    ACTIONS(75), 1,
      aux_sym_block_tag_token1,
    ACTIONS(35), 2,
      sym_text,
      sym_ERROR,
    STATE(40), 3,
      sym__function_tag_slash,
      sym__function_tag_none,
      sym__function_tag_dollar,
    STATE(8), 5,
      sym__node,
      sym_function_tag,
      sym_block_tag,
      sym_comment_tag,
      aux_sym_source_file_repeat1,
  [325] = 10,
    ACTIONS(79), 1,
      anon_sym_replace,
    ACTIONS(82), 1,
      anon_sym_regex_replace,
    ACTIONS(85), 1,
      anon_sym_field,
    ACTIONS(88), 1,
      sym_identifier,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
    ACTIONS(77), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
  [359] = 11,
    ACTIONS(91), 1,
      anon_sym_SLASH_GT,
    ACTIONS(93), 1,
      anon_sym_GT,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(15), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [394] = 11,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(103), 1,
      anon_sym_SLASH_GT,
    ACTIONS(105), 1,
      anon_sym_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [429] = 11,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(107), 1,
      anon_sym_SLASH_GT,
    ACTIONS(109), 1,
      anon_sym_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(17), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [464] = 11,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(111), 1,
      anon_sym_SLASH_GT,
    ACTIONS(113), 1,
      anon_sym_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [499] = 10,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(115), 1,
      anon_sym_DOLLAR_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [531] = 10,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(117), 1,
      anon_sym_DOLLAR_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(18), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [563] = 10,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(119), 1,
      anon_sym_DOLLAR_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(21), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [595] = 10,
    ACTIONS(95), 1,
      anon_sym_replace,
    ACTIONS(97), 1,
      anon_sym_regex_replace,
    ACTIONS(99), 1,
      anon_sym_field,
    ACTIONS(101), 1,
      sym_identifier,
    ACTIONS(121), 1,
      anon_sym_DOLLAR_GT,
    STATE(25), 1,
      sym__field_modifier,
    STATE(30), 1,
      sym__standard_modifier,
    STATE(31), 1,
      sym__replace_modifier,
    STATE(32), 1,
      sym__regex_modifier,
    STATE(13), 2,
      sym_modifier,
      aux_sym__function_tag_slash_repeat1,
  [627] = 2,
    ACTIONS(123), 4,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
      anon_sym_COMMA,
    ACTIONS(125), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [640] = 2,
    ACTIONS(127), 4,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
      anon_sym_COMMA,
    ACTIONS(129), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [653] = 2,
    ACTIONS(131), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(133), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [665] = 2,
    ACTIONS(135), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(137), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [677] = 2,
    ACTIONS(139), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(141), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [689] = 2,
    ACTIONS(143), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(145), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [701] = 2,
    ACTIONS(147), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(149), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [713] = 2,
    ACTIONS(151), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(153), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [725] = 2,
    ACTIONS(135), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(137), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [737] = 2,
    ACTIONS(155), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(157), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [749] = 2,
    ACTIONS(155), 3,
      anon_sym_SLASH_GT,
      anon_sym_GT,
      anon_sym_DOLLAR_GT,
    ACTIONS(157), 4,
      anon_sym_replace,
      anon_sym_regex_replace,
      anon_sym_field,
      sym_identifier,
  [761] = 2,
    ACTIONS(159), 1,
      ts_builtin_sym_end,
    ACTIONS(161), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [772] = 2,
    ACTIONS(163), 1,
      ts_builtin_sym_end,
    ACTIONS(165), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [783] = 2,
    ACTIONS(167), 1,
      ts_builtin_sym_end,
    ACTIONS(169), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [794] = 2,
    ACTIONS(171), 1,
      ts_builtin_sym_end,
    ACTIONS(173), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [805] = 2,
    ACTIONS(175), 1,
      ts_builtin_sym_end,
    ACTIONS(177), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [816] = 2,
    ACTIONS(179), 1,
      ts_builtin_sym_end,
    ACTIONS(181), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [827] = 2,
    ACTIONS(183), 1,
      ts_builtin_sym_end,
    ACTIONS(185), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [838] = 1,
    ACTIONS(173), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [847] = 1,
    ACTIONS(169), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [856] = 1,
    ACTIONS(181), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [865] = 1,
    ACTIONS(165), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [874] = 1,
    ACTIONS(187), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [883] = 1,
    ACTIONS(189), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [892] = 1,
    ACTIONS(191), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [901] = 1,
    ACTIONS(177), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [910] = 1,
    ACTIONS(161), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [919] = 1,
    ACTIONS(185), 6,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_block_tag_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [928] = 2,
    ACTIONS(193), 1,
      ts_builtin_sym_end,
    ACTIONS(189), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [939] = 2,
    ACTIONS(195), 1,
      ts_builtin_sym_end,
    ACTIONS(191), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [950] = 2,
    ACTIONS(197), 1,
      ts_builtin_sym_end,
    ACTIONS(187), 5,
      aux_sym__function_tag_slash_token1,
      aux_sym__function_tag_dollar_token1,
      aux_sym_comment_tag_token1,
      sym_text,
      sym_ERROR,
  [961] = 3,
    ACTIONS(199), 1,
      anon_sym_SQUOTE,
    STATE(56), 1,
      aux_sym_string_repeat2,
    ACTIONS(201), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [972] = 3,
    ACTIONS(203), 1,
      anon_sym_DQUOTE,
    STATE(54), 1,
      aux_sym_string_repeat1,
    ACTIONS(205), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [983] = 3,
    ACTIONS(208), 1,
      anon_sym_SQUOTE,
    STATE(55), 1,
      aux_sym_string_repeat2,
    ACTIONS(210), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [994] = 3,
    ACTIONS(213), 1,
      anon_sym_SQUOTE,
    STATE(55), 1,
      aux_sym_string_repeat2,
    ACTIONS(215), 2,
      aux_sym_string_token2,
      sym_escape_sequence,
  [1005] = 3,
    ACTIONS(213), 1,
      anon_sym_DQUOTE,
    STATE(54), 1,
      aux_sym_string_repeat1,
    ACTIONS(217), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1016] = 3,
    ACTIONS(199), 1,
      anon_sym_DQUOTE,
    STATE(57), 1,
      aux_sym_string_repeat1,
    ACTIONS(219), 2,
      aux_sym_string_token1,
      sym_escape_sequence,
  [1027] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(27), 1,
      sym_string,
  [1037] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(26), 1,
      sym_string,
  [1047] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(29), 1,
      sym_string,
  [1057] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(28), 1,
      sym_string,
  [1067] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(24), 1,
      sym_string,
  [1077] = 3,
    ACTIONS(221), 1,
      anon_sym_DQUOTE,
    ACTIONS(223), 1,
      anon_sym_SQUOTE,
    STATE(74), 1,
      sym_string,
  [1087] = 2,
    ACTIONS(225), 1,
      anon_sym_DQUOTE,
    STATE(78), 1,
      sym_regex_pattern,
  [1094] = 2,
    ACTIONS(227), 1,
      aux_sym_comment_tag_token2,
    ACTIONS(229), 1,
      sym_text,
  [1101] = 2,
    ACTIONS(231), 1,
      aux_sym_comment_tag_token2,
    ACTIONS(233), 1,
      sym_text,
  [1108] = 2,
    ACTIONS(235), 1,
      anon_sym_EQ,
    ACTIONS(237), 1,
      anon_sym_COLON,
  [1115] = 1,
    ACTIONS(239), 1,
      sym_identifier,
  [1119] = 1,
    ACTIONS(241), 1,
      aux_sym_comment_tag_token2,
  [1123] = 1,
    ACTIONS(243), 1,
      anon_sym_COMMA,
  [1127] = 1,
    ACTIONS(245), 1,
      sym_identifier,
  [1131] = 1,
    ACTIONS(247), 1,
      ts_builtin_sym_end,
  [1135] = 1,
    ACTIONS(249), 1,
      anon_sym_COMMA,
  [1139] = 1,
    ACTIONS(251), 1,
      anon_sym_EQ,
  [1143] = 1,
    ACTIONS(253), 1,
      aux_sym_regex_pattern_token1,
  [1147] = 1,
    ACTIONS(255), 1,
      anon_sym_SLASH,
  [1151] = 1,
    ACTIONS(257), 1,
      anon_sym_COMMA,
  [1155] = 1,
    ACTIONS(259), 1,
      sym_identifier,
  [1159] = 1,
    ACTIONS(261), 1,
      anon_sym_GT,
  [1163] = 1,
    ACTIONS(263), 1,
      anon_sym_EQ,
  [1167] = 1,
    ACTIONS(265), 1,
      anon_sym_EQ,
  [1171] = 1,
    ACTIONS(267), 1,
      sym_identifier,
  [1175] = 1,
    ACTIONS(269), 1,
      anon_sym_GT,
  [1179] = 1,
    ACTIONS(271), 1,
      anon_sym_SLASH,
  [1183] = 1,
    ACTIONS(273), 1,
      sym_identifier,
  [1187] = 1,
    ACTIONS(275), 1,
      anon_sym_GT,
  [1191] = 1,
    ACTIONS(277), 1,
      anon_sym_GT,
  [1195] = 1,
    ACTIONS(279), 1,
      sym_identifier,
  [1199] = 1,
    ACTIONS(281), 1,
      aux_sym_comment_tag_token2,
  [1203] = 1,
    ACTIONS(283), 1,
      anon_sym_GT,
  [1207] = 1,
    ACTIONS(285), 1,
      anon_sym_GT,
  [1211] = 1,
    ACTIONS(287), 1,
      anon_sym_GT,
  [1215] = 1,
    ACTIONS(289), 1,
      sym_identifier,
  [1219] = 1,
    ACTIONS(291), 1,
      anon_sym_DQUOTE,
  [1223] = 1,
    ACTIONS(293), 1,
      anon_sym_GT,
  [1227] = 1,
    ACTIONS(295), 1,
      sym_identifier,
  [1231] = 1,
    ACTIONS(297), 1,
      sym_identifier,
  [1235] = 1,
    ACTIONS(299), 1,
      sym_identifier,
  [1239] = 1,
    ACTIONS(301), 1,
      anon_sym_EQ,
  [1243] = 1,
    ACTIONS(303), 1,
      sym_identifier,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(2)] = 0,
  [SMALL_STATE(3)] = 32,
  [SMALL_STATE(4)] = 64,
  [SMALL_STATE(5)] = 93,
  [SMALL_STATE(6)] = 122,
  [SMALL_STATE(7)] = 151,
  [SMALL_STATE(8)] = 180,
  [SMALL_STATE(9)] = 209,
  [SMALL_STATE(10)] = 238,
  [SMALL_STATE(11)] = 267,
  [SMALL_STATE(12)] = 296,
  [SMALL_STATE(13)] = 325,
  [SMALL_STATE(14)] = 359,
  [SMALL_STATE(15)] = 394,
  [SMALL_STATE(16)] = 429,
  [SMALL_STATE(17)] = 464,
  [SMALL_STATE(18)] = 499,
  [SMALL_STATE(19)] = 531,
  [SMALL_STATE(20)] = 563,
  [SMALL_STATE(21)] = 595,
  [SMALL_STATE(22)] = 627,
  [SMALL_STATE(23)] = 640,
  [SMALL_STATE(24)] = 653,
  [SMALL_STATE(25)] = 665,
  [SMALL_STATE(26)] = 677,
  [SMALL_STATE(27)] = 689,
  [SMALL_STATE(28)] = 701,
  [SMALL_STATE(29)] = 713,
  [SMALL_STATE(30)] = 725,
  [SMALL_STATE(31)] = 737,
  [SMALL_STATE(32)] = 749,
  [SMALL_STATE(33)] = 761,
  [SMALL_STATE(34)] = 772,
  [SMALL_STATE(35)] = 783,
  [SMALL_STATE(36)] = 794,
  [SMALL_STATE(37)] = 805,
  [SMALL_STATE(38)] = 816,
  [SMALL_STATE(39)] = 827,
  [SMALL_STATE(40)] = 838,
  [SMALL_STATE(41)] = 847,
  [SMALL_STATE(42)] = 856,
  [SMALL_STATE(43)] = 865,
  [SMALL_STATE(44)] = 874,
  [SMALL_STATE(45)] = 883,
  [SMALL_STATE(46)] = 892,
  [SMALL_STATE(47)] = 901,
  [SMALL_STATE(48)] = 910,
  [SMALL_STATE(49)] = 919,
  [SMALL_STATE(50)] = 928,
  [SMALL_STATE(51)] = 939,
  [SMALL_STATE(52)] = 950,
  [SMALL_STATE(53)] = 961,
  [SMALL_STATE(54)] = 972,
  [SMALL_STATE(55)] = 983,
  [SMALL_STATE(56)] = 994,
  [SMALL_STATE(57)] = 1005,
  [SMALL_STATE(58)] = 1016,
  [SMALL_STATE(59)] = 1027,
  [SMALL_STATE(60)] = 1037,
  [SMALL_STATE(61)] = 1047,
  [SMALL_STATE(62)] = 1057,
  [SMALL_STATE(63)] = 1067,
  [SMALL_STATE(64)] = 1077,
  [SMALL_STATE(65)] = 1087,
  [SMALL_STATE(66)] = 1094,
  [SMALL_STATE(67)] = 1101,
  [SMALL_STATE(68)] = 1108,
  [SMALL_STATE(69)] = 1115,
  [SMALL_STATE(70)] = 1119,
  [SMALL_STATE(71)] = 1123,
  [SMALL_STATE(72)] = 1127,
  [SMALL_STATE(73)] = 1131,
  [SMALL_STATE(74)] = 1135,
  [SMALL_STATE(75)] = 1139,
  [SMALL_STATE(76)] = 1143,
  [SMALL_STATE(77)] = 1147,
  [SMALL_STATE(78)] = 1151,
  [SMALL_STATE(79)] = 1155,
  [SMALL_STATE(80)] = 1159,
  [SMALL_STATE(81)] = 1163,
  [SMALL_STATE(82)] = 1167,
  [SMALL_STATE(83)] = 1171,
  [SMALL_STATE(84)] = 1175,
  [SMALL_STATE(85)] = 1179,
  [SMALL_STATE(86)] = 1183,
  [SMALL_STATE(87)] = 1187,
  [SMALL_STATE(88)] = 1191,
  [SMALL_STATE(89)] = 1195,
  [SMALL_STATE(90)] = 1199,
  [SMALL_STATE(91)] = 1203,
  [SMALL_STATE(92)] = 1207,
  [SMALL_STATE(93)] = 1211,
  [SMALL_STATE(94)] = 1215,
  [SMALL_STATE(95)] = 1219,
  [SMALL_STATE(96)] = 1223,
  [SMALL_STATE(97)] = 1227,
  [SMALL_STATE(98)] = 1231,
  [SMALL_STATE(99)] = 1235,
  [SMALL_STATE(100)] = 1239,
  [SMALL_STATE(101)] = 1243,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 0, 0, 0),
  [5] = {.entry = {.count = 1, .reusable = false}}, SHIFT(89),
  [7] = {.entry = {.count = 1, .reusable = false}}, SHIFT(101),
  [9] = {.entry = {.count = 1, .reusable = false}}, SHIFT(80),
  [11] = {.entry = {.count = 1, .reusable = false}}, SHIFT(4),
  [13] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_none, 3, 0, 0),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(94),
  [17] = {.entry = {.count = 1, .reusable = false}}, SHIFT(69),
  [19] = {.entry = {.count = 1, .reusable = false}}, SHIFT(83),
  [21] = {.entry = {.count = 1, .reusable = false}}, SHIFT(96),
  [23] = {.entry = {.count = 1, .reusable = false}}, SHIFT(5),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_none, 4, 0, 0),
  [27] = {.entry = {.count = 1, .reusable = false}}, SHIFT(86),
  [29] = {.entry = {.count = 1, .reusable = false}}, SHIFT(7),
  [31] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_source_file, 1, 0, 0),
  [33] = {.entry = {.count = 1, .reusable = false}}, SHIFT(6),
  [35] = {.entry = {.count = 1, .reusable = false}}, SHIFT(8),
  [37] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [39] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(89),
  [42] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(101),
  [45] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(80),
  [48] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(6),
  [51] = {.entry = {.count = 1, .reusable = false}}, SHIFT(79),
  [53] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(94),
  [56] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(69),
  [59] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0),
  [61] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(96),
  [64] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym_source_file_repeat1, 2, 0, 0), SHIFT_REPEAT(8),
  [67] = {.entry = {.count = 1, .reusable = false}}, SHIFT(98),
  [69] = {.entry = {.count = 1, .reusable = false}}, SHIFT(12),
  [71] = {.entry = {.count = 1, .reusable = false}}, SHIFT(97),
  [73] = {.entry = {.count = 1, .reusable = false}}, SHIFT(11),
  [75] = {.entry = {.count = 1, .reusable = false}}, SHIFT(99),
  [77] = {.entry = {.count = 1, .reusable = true}}, REDUCE(aux_sym__function_tag_slash_repeat1, 2, 0, 0),
  [79] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_slash_repeat1, 2, 0, 0), SHIFT_REPEAT(100),
  [82] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_slash_repeat1, 2, 0, 0), SHIFT_REPEAT(81),
  [85] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_slash_repeat1, 2, 0, 0), SHIFT_REPEAT(68),
  [88] = {.entry = {.count = 2, .reusable = false}}, REDUCE(aux_sym__function_tag_slash_repeat1, 2, 0, 0), SHIFT_REPEAT(75),
  [91] = {.entry = {.count = 1, .reusable = true}}, SHIFT(35),
  [93] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [95] = {.entry = {.count = 1, .reusable = false}}, SHIFT(100),
  [97] = {.entry = {.count = 1, .reusable = false}}, SHIFT(81),
  [99] = {.entry = {.count = 1, .reusable = false}}, SHIFT(68),
  [101] = {.entry = {.count = 1, .reusable = false}}, SHIFT(75),
  [103] = {.entry = {.count = 1, .reusable = true}}, SHIFT(52),
  [105] = {.entry = {.count = 1, .reusable = true}}, SHIFT(3),
  [107] = {.entry = {.count = 1, .reusable = true}}, SHIFT(41),
  [109] = {.entry = {.count = 1, .reusable = true}}, SHIFT(10),
  [111] = {.entry = {.count = 1, .reusable = true}}, SHIFT(44),
  [113] = {.entry = {.count = 1, .reusable = true}}, SHIFT(9),
  [115] = {.entry = {.count = 1, .reusable = true}}, SHIFT(50),
  [117] = {.entry = {.count = 1, .reusable = true}}, SHIFT(38),
  [119] = {.entry = {.count = 1, .reusable = true}}, SHIFT(42),
  [121] = {.entry = {.count = 1, .reusable = true}}, SHIFT(45),
  [123] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 3, 0, 0),
  [125] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 3, 0, 0),
  [127] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_string, 2, 0, 0),
  [129] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_string, 2, 0, 0),
  [131] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__standard_modifier, 3, 0, 3),
  [133] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__standard_modifier, 3, 0, 3),
  [135] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1, 0, 1),
  [137] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1, 0, 1),
  [139] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__field_modifier, 3, 0, 3),
  [141] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__field_modifier, 3, 0, 3),
  [143] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__replace_modifier, 5, 0, 6),
  [145] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__replace_modifier, 5, 0, 6),
  [147] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__regex_modifier, 5, 0, 6),
  [149] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__regex_modifier, 5, 0, 6),
  [151] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__field_modifier, 5, 0, 7),
  [153] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__field_modifier, 5, 0, 7),
  [155] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_modifier, 1, 0, 2),
  [157] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_modifier, 1, 0, 2),
  [159] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 7, 0, 5),
  [161] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 7, 0, 5),
  [163] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_tag, 3, 0, 0),
  [165] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_tag, 3, 0, 0),
  [167] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_slash, 3, 0, 0),
  [169] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_slash, 3, 0, 0),
  [171] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_function_tag, 1, 0, 0),
  [173] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_function_tag, 1, 0, 0),
  [175] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 6, 0, 4),
  [177] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 6, 0, 4),
  [179] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_dollar, 3, 0, 0),
  [181] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_dollar, 3, 0, 0),
  [183] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_block_tag, 8, 0, 8),
  [185] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_block_tag, 8, 0, 8),
  [187] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_slash, 4, 0, 0),
  [189] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym__function_tag_dollar, 4, 0, 0),
  [191] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_comment_tag, 4, 0, 0),
  [193] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_dollar, 4, 0, 0),
  [195] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_comment_tag, 4, 0, 0),
  [197] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym__function_tag_slash, 4, 0, 0),
  [199] = {.entry = {.count = 1, .reusable = false}}, SHIFT(23),
  [201] = {.entry = {.count = 1, .reusable = true}}, SHIFT(56),
  [203] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0),
  [205] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat1, 2, 0, 0), SHIFT_REPEAT(54),
  [208] = {.entry = {.count = 1, .reusable = false}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0),
  [210] = {.entry = {.count = 2, .reusable = true}}, REDUCE(aux_sym_string_repeat2, 2, 0, 0), SHIFT_REPEAT(55),
  [213] = {.entry = {.count = 1, .reusable = false}}, SHIFT(22),
  [215] = {.entry = {.count = 1, .reusable = true}}, SHIFT(55),
  [217] = {.entry = {.count = 1, .reusable = true}}, SHIFT(54),
  [219] = {.entry = {.count = 1, .reusable = true}}, SHIFT(57),
  [221] = {.entry = {.count = 1, .reusable = true}}, SHIFT(58),
  [223] = {.entry = {.count = 1, .reusable = true}}, SHIFT(53),
  [225] = {.entry = {.count = 1, .reusable = true}}, SHIFT(77),
  [227] = {.entry = {.count = 1, .reusable = false}}, SHIFT(34),
  [229] = {.entry = {.count = 1, .reusable = false}}, SHIFT(70),
  [231] = {.entry = {.count = 1, .reusable = false}}, SHIFT(43),
  [233] = {.entry = {.count = 1, .reusable = false}}, SHIFT(90),
  [235] = {.entry = {.count = 1, .reusable = true}}, SHIFT(60),
  [237] = {.entry = {.count = 1, .reusable = true}}, SHIFT(72),
  [239] = {.entry = {.count = 1, .reusable = true}}, SHIFT(20),
  [241] = {.entry = {.count = 1, .reusable = true}}, SHIFT(51),
  [243] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_regex_pattern, 5, 0, 0),
  [245] = {.entry = {.count = 1, .reusable = true}}, SHIFT(82),
  [247] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
  [249] = {.entry = {.count = 1, .reusable = true}}, SHIFT(59),
  [251] = {.entry = {.count = 1, .reusable = true}}, SHIFT(63),
  [253] = {.entry = {.count = 1, .reusable = true}}, SHIFT(85),
  [255] = {.entry = {.count = 1, .reusable = true}}, SHIFT(76),
  [257] = {.entry = {.count = 1, .reusable = true}}, SHIFT(62),
  [259] = {.entry = {.count = 1, .reusable = true}}, SHIFT(88),
  [261] = {.entry = {.count = 1, .reusable = true}}, SHIFT(66),
  [263] = {.entry = {.count = 1, .reusable = true}}, SHIFT(65),
  [265] = {.entry = {.count = 1, .reusable = true}}, SHIFT(61),
  [267] = {.entry = {.count = 1, .reusable = true}}, SHIFT(84),
  [269] = {.entry = {.count = 1, .reusable = true}}, SHIFT(37),
  [271] = {.entry = {.count = 1, .reusable = true}}, SHIFT(95),
  [273] = {.entry = {.count = 1, .reusable = true}}, SHIFT(87),
  [275] = {.entry = {.count = 1, .reusable = true}}, SHIFT(33),
  [277] = {.entry = {.count = 1, .reusable = true}}, SHIFT(39),
  [279] = {.entry = {.count = 1, .reusable = true}}, SHIFT(14),
  [281] = {.entry = {.count = 1, .reusable = true}}, SHIFT(46),
  [283] = {.entry = {.count = 1, .reusable = true}}, SHIFT(47),
  [285] = {.entry = {.count = 1, .reusable = true}}, SHIFT(48),
  [287] = {.entry = {.count = 1, .reusable = true}}, SHIFT(49),
  [289] = {.entry = {.count = 1, .reusable = true}}, SHIFT(16),
  [291] = {.entry = {.count = 1, .reusable = true}}, SHIFT(71),
  [293] = {.entry = {.count = 1, .reusable = true}}, SHIFT(67),
  [295] = {.entry = {.count = 1, .reusable = true}}, SHIFT(91),
  [297] = {.entry = {.count = 1, .reusable = true}}, SHIFT(92),
  [299] = {.entry = {.count = 1, .reusable = true}}, SHIFT(93),
  [301] = {.entry = {.count = 1, .reusable = true}}, SHIFT(64),
  [303] = {.entry = {.count = 1, .reusable = true}}, SHIFT(19),
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
