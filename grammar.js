/**
 * @file
 * @license MIT
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "mtml",

  rules: {
    // ドキュメントのルート
    source_file: ($) => repeat($._node),

    // ノードの種類
    _node: ($) =>
      choice($.function_tag, $.block_tag, $.text, $.comment_tag, $.ERROR),

    // ファンクションタグ
    function_tag: ($) =>
      prec(
        1,
        choice(
          $._function_tag_dollar,
          $._function_tag_slash,
          $._function_tag_none,
        ),
      ),

    // <mtEntryTitle /> スタイル
    _function_tag_slash: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, repeat($.modifier), "/>"),
    // <mtEntryTitle> スタイル
    _function_tag_none: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, repeat($.modifier), ">"),
    // <$mtentrytitle$> スタイル
    _function_tag_dollar: ($) =>
      seq(/<\$[mM][tT]:?/, $.identifier, repeat($.modifier), "$>"),

    // ブロックタグ
    block_tag: ($) =>
      prec(
        2,
        seq(
          // 開始タグ
          seq(
            /<[mM][tT]:?/,
            field("name", $.identifier),
            repeat($.modifier),
            ">",
          ),
          // 内容
          repeat($._node),
          // 終了タグ
          seq(/<\/[mM][tT]:?/, field("name", $.identifier), ">"),
        ),
      ),
    /**
     * コメントタグ
     */
    comment_tag: ($) =>
      seq(
        /<[mM][tT]:?[iI][gG][nN][oO][rR][eE]/,
        ">",
        optional($.text),
        /\/<[mM][tT]:?[iI][gG][nN][oO][rR][eE]>/,
      ),

    // 修飾子の定義
    modifier: ($) =>
      choice(
        $._standard_modifier,
        $._replace_modifier,
        $._regex_modifier,
        $._field_modifier,
      ),

    // 標準的なmodifier（key="value"形式）
    _standard_modifier: ($) =>
      seq(field("key", $.identifier), "=", field("value", $.string)),

    // replace用のmodifier
    _replace_modifier: ($) =>
      seq(
        field("key", "replace"),
        "=",
        field("pattern", $.string),
        ",",
        field("replacement", $.string),
      ),

    // regex_replace用のmodifier
    _regex_modifier: ($) =>
      seq(
        field("key", "regex_replace"),
        "=",
        field("pattern", $.regex_pattern),
        ",",
        field("replacement", $.string),
      ),

    // フィールド指定用のmodifier
    _field_modifier: ($) =>
      seq(
        field("key", "field"),
        optional(seq(":", $.identifier)),
        "=",
        field("value", $.string),
      ),

    // 正規表現パターン
    regex_pattern: ($) => seq('"', "/", /[^/]*/, "/", '"'),

    // 識別子（タグ名）
    identifier: ($) => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: ($) =>
      choice(
        seq('"', repeat(choice(/[^"\\]+/, $.escape_sequence)), '"'),
        seq("'", repeat(choice(/[^'\\]+/, $.escape_sequence)), "'"),
      ),

    escape_sequence: ($) =>
      token.immediate(
        seq(
          "\\",
          choice(
            /[\\'"]/, // 基本的なエスケープ
            /[bfnrt]/, // 制御文字
            /u[0-9a-fA-F]{4}/, // Unicode
          ),
        ),
      ),

    // テキストノード
    text: ($) => /[^<]+/,

    ERROR: ($) => token(prec(-1, /.+/)),
  },
});
