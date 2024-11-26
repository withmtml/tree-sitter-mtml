


<mt:TagName modifier="modifier value" >
</mt:TagName>

というような言語をパースするtree-sitterを作りたい

Tree-sitterの文法を作成するためのガイドを提供します。MTタグ（MovableType風のタグ）のような構文をパースするための基本的な文法定義を示します。

```js
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    // ドキュメントのルート
    source_file: $ => repeat($._node),

    // ノードの定義（タグまたはテキスト）
    _node: $ => choice(
      $.tag,
      $.text
    ),

    // タグの定義
    tag: $ => seq(
      '<mt:',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>',
      optional(repeat($._node)),
      '</mt:',
      field('closing_name', $.identifier),
      '>'
    ),

    // 修飾子（modifier）の定義
    modifier: $ => seq(
      field('key', $.identifier),
      '=',
      field('value', $.string)
    ),

    // 識別子（タグ名など）
    identifier: $ => /[A-Za-z][A-Za-z0-9]*/,

    // 文字列値
    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    // 通常のテキスト
    text: $ => /[^<]+/
  }
});
```

このTree-sitter文法は以下のような特徴を持っています：

1. `<mt:TagName modifier="value">...</mt:TagName>`の形式のタグをパース可能
2. 修飾子（modifier）は`key="value"`の形式をサポート
3. ネストされたタグ構造をサポート
4. タグ間のテキストもパース可能

使用例：

```
<mt:TagName modifier="modifier value">
  Some content
  <mt:NestedTag another="value">
    Nested content
  </mt:NestedTag>
</mt:TagName>
```

この文法を使用するには：

1. 新しいTree-sitterプロジェクトを作成
```bash
tree-sitter init
```

2. `grammar.js`に上記のコードを配置

3. 文法をビルド
```bash
tree-sitter generate
```

4. テストを作成（`test/corpus`ディレクトリに`.txt`ファイルとして）

文法をさらにカスタマイズするために：

- エラーリカバリーの追加
- より複雑な属性値の対応
- コメントのサポート
- その他の特殊構文の追加

などが可能です。

modifierには以下のようなものも含まれます
`regex_replave="/regex/","replacement"`
`field:content_field_hash="value"`

これらの追加のmodifier構文をサポートするように文法を拡張します。

```js
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    source_file: $ => repeat($._node),

    _node: $ => choice(
      $.tag,
      $.text
    ),

    tag: $ => seq(
      '<mt:',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>',
      optional(repeat($._node)),
      '</mt:',
      field('closing_name', $.identifier),
      '>'
    ),

    // modifierの定義を拡張
    modifier: $ => choice(
      $.standard_modifier,
      $.regex_modifier,
      $.field_modifier
    ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: $ => seq(
      field('key', $.identifier),
      '=',
      field('value', $.string)
    ),

    // regex_replace用のmodifier
    regex_modifier: $ => seq(
      'regex_replace=',
      field('pattern', $.regex_pattern),
      ',',
      field('replacement', $.string)
    ),

    // フィールド指定用のmodifier
    field_modifier: $ => seq(
      field('field_type', $.identifier),
      ':',
      field('field_name', $.identifier),
      '=',
      field('value', $.string)
    ),

    // 正規表現パターン
    regex_pattern: $ => seq(
      '"',
      '/',
      /[^/]*/,
      '/',
      '"'
    ),

    // 識別子（タグ名など）
    identifier: $ => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    // 通常のテキスト
    text: $ => /[^<]+/
  }
});
```

この拡張された文法では：

1. `modifier`ルールを3つのタイプに分割:
   - `standard_modifier`: 通常の`key="value"`形式
   - `regex_modifier`: `regex_replace="/pattern/","replacement"`形式
   - `field_modifier`: `field:content_field_hash="value"`形式

2. それぞれのmodifier形式に対して専用のルールを定義

使用例：

```
<mt:TagName
  normal_modifier="value"
  regex_replace="/pattern/","replacement"
  field:content_field="value">
  Content
</mt:TagName>
```

注意点：

1. 正規表現パターンの定義は単純化されています。必要に応じて以下のように拡張可能です：
   - エスケープされたスラッシュのサポート
   - より複雑な正規表現構文のサポート

2. フィールド指定子をより厳密にする場合は、許可される識別子のリストを制限することも可能です：

```js
field_type: $ => choice(
  'field',
  'column',
  // その他の許可される型
),
```

3. エラー処理を追加する場合：

```js
// エラーリカバリーの例
modifier: $ => choice(
  $.standard_modifier,
  $.regex_modifier,
  $.field_modifier,
  alias($.ERROR, 'error')
),

ERROR: $ => token(prec(-1, /.+/))
```

このように、文法をさらにカスタマイズして、より厳密なパースや追加の構文要素をサポートすることができます。

セルフクローズタグは以下のように`$`で囲むことで表現することもできます
`<$mtfunctiontag$>`

はい、セルフクローズタグをサポートするように文法を更新します。

```js
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    source_file: $ => repeat($._node),

    _node: $ => choice(
      $.tag,
      $.self_closing_tag,
      $.text
    ),

    // 通常のタグ
    tag: $ => seq(
      '<mt:',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>',
      optional(repeat($._node)),
      '</mt:',
      field('closing_name', $.identifier),
      '>'
    ),

    // セルフクローズタグ
    self_closing_tag: $ => seq(
      '<$',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '$>'
    ),

    // modifier定義
    modifier: $ => choice(
      $.standard_modifier,
      $.regex_modifier,
      $.field_modifier
    ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: $ => seq(
      field('key', $.identifier),
      '=',
      field('value', $.string)
    ),

    // regex_replace用のmodifier
    regex_modifier: $ => seq(
      'regex_replace=',
      field('pattern', $.regex_pattern),
      ',',
      field('replacement', $.string)
    ),

    // フィールド指定用のmodifier
    field_modifier: $ => seq(
      field('field_type', $.identifier),
      ':',
      field('field_name', $.identifier),
      '=',
      field('value', $.string)
    ),

    // 正規表現パターン
    regex_pattern: $ => seq(
      '"',
      '/',
      /[^/]*/,
      '/',
      '"'
    ),

    // 識別子（タグ名など）
    identifier: $ => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    // 通常のテキスト
    text: $ => /[^<]+/
  }
});
```

主な変更点：

1. `_node`ルールに`self_closing_tag`を追加
2. `self_closing_tag`ルールを新設
   - `<$`で開始
   - `$>`で終了
   - 通常のタグと同様にmodifierをサポート

使用例：

```
<$mtfunctiontag$>

<$mtfunctiontag modifier="value" regex_replace="/pattern/","replacement"$>

<mt:Container>
  <$mtnestedfunctiontag field:content="value"$>
  Some content
</mt:Container>
```

テストケース（`test/corpus/self_closing.txt`）の例：

```
=====================================
Self closing tags
=====================================

<$mtfunctiontag$>
<$mtfunctiontag modifier="value"$>

---

(source_file
  (self_closing_tag
    name: (identifier))
  (self_closing_tag
    name: (identifier)
    (standard_modifier
      key: (identifier)
      value: (string))))
```

この文法は以下をサポートします：

1. 通常の開始/終了タグ形式: `<mt:TagName>...</mt:TagName>`
2. セルフクローズタグ形式: `<$mtfunctiontag$>`
3. 両形式でのmodifier使用
   - 標準modifier: `modifier="value"`
   - 正規表現modifier: `regex_replace="/pattern/","replacement"`
   - フィールドmodifier: `field:content_field="value"`

必要に応じて、さらに以下のような拡張も可能です：

- より厳密な識別子の制限
- 特定のタグに特定のmodifierのみを許可
- エラーリカバリーの追加
- コメントのサポート

MTタグは以下の書き方を全て許容します
`<mttagname>`
`<mt:tagname>`
`<MTtagname>`
`<MT:tagname>`

はい、タグ名の異なる大文字小文字の組み合わせをサポートするように文法を更新します。

```js
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    source_file: $ => repeat($._node),

    _node: $ => choice(
      $.tag,
      $.self_closing_tag,
      $.text
    ),

    // 通常のタグ
    tag: $ => seq(
      choice(
        '<mt:',
        '<MT:',
        '<mt',
        '<MT'
      ),
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>',
      optional(repeat($._node)),
      choice(
        '</mt:',
        '</MT:',
        '</mt',
        '</MT'
      ),
      field('closing_name', $.identifier),
      '>'
    ),

    // セルフクローズタグ
    self_closing_tag: $ => seq(
      '<$',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '$>'
    ),

    // modifier定義
    modifier: $ => choice(
      $.standard_modifier,
      $.regex_modifier,
      $.field_modifier
    ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: $ => seq(
      field('key', $.identifier),
      '=',
      field('value', $.string)
    ),

    // regex_replace用のmodifier
    regex_modifier: $ => seq(
      'regex_replace=',
      field('pattern', $.regex_pattern),
      ',',
      field('replacement', $.string)
    ),

    // フィールド指定用のmodifier
    field_modifier: $ => seq(
      field('field_type', $.identifier),
      ':',
      field('field_name', $.identifier),
      '=',
      field('value', $.string)
    ),

    // 正規表現パターン
    regex_pattern: $ => seq(
      '"',
      '/',
      /[^/]*/,
      '/',
      '"'
    ),

    // 識別子（タグ名など）
    identifier: $ => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    // 通常のテキスト
    text: $ => /[^<]+/
  }
});
```

主な変更点：

1. タグの開始部分を4つのパターンでサポート:
   - `<mt:`
   - `<MT:`
   - `<mt`
   - `<MT`

2. 閉じタグも同様に4つのパターンをサポート:
   - `</mt:`
   - `</MT:`
   - `</mt`
   - `</MT`

使用例：

```
<mttagname>content</mttagname>
<mt:tagname>content</mt:tagname>
<MTtagname>content</MTtagname>
<MT:tagname>content</MT:tagname>

<mttagname modifier="value">
  <MT:nestedtag field:content="value">
    content
  </MT:nestedtag>
</mttagname>
```

テストケース（`test/corpus/tag_variations.txt`）の例：

```
=====================================
Tag name variations
=====================================

<mttagname>content</mttagname>
<mt:tagname>content</mt:tagname>
<MTtagname>content</MTtagname>
<MT:tagname>content</MT:tagname>

---

(source_file
  (tag
    name: (identifier)
    (text))
  (tag
    name: (identifier)
    (text))
  (tag
    name: (identifier)
    (text))
  (tag
    name: (identifier)
    (text)))
```

この文法は以下をサポートします：

1. すべての大文字小文字の組み合わせのMTタグ
2. コロン（:）の有無両方
3. すべての形式でmodifierの使用が可能
4. ネストされたタグ構造

必要に応じて、以下のような拡張も可能です：

1. タグ名の開始/終了の一致チェック
2. 特定のタグ名に対する大文字小文字の制限
3. より厳密なタグ名の制限（許可されるタグ名のリスト）
4. エラー処理の追加

また、パフォーマンスを考慮する場合は、開始タグと終了タグのパターンを正規表現で表現することも検討できます：

```js
tag_start: $ => /[<][mM][tT][:]?/,
tag_end: $ => /[<][/][mM][tT][:]?/,
```

このように実装を変更することで、より効率的なパースが可能になる場合があります。

htmlのセルフクローズのようなものにも対応してください
`<MTFunctinoTag/>`


HTMLスタイルのセルフクローズタグにも対応するように文法を更新します。

```js
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    source_file: $ => repeat($._node),

    _node: $ => choice(
      $.tag,
      $.self_closing_tag,
      $.html_style_self_closing_tag,
      $.text
    ),

    // タグの開始部分（共通）
    _tag_start: $ => choice(
      '<mt:',
      '<MT:',
      '<mt',
      '<MT'
    ),

    // タグの終了部分（共通）
    _tag_end: $ => choice(
      '</mt:',
      '</MT:',
      '</mt',
      '</MT'
    ),

    // 通常のタグ
    tag: $ => seq(
      $._tag_start,
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>',
      optional(repeat($._node)),
      $._tag_end,
      field('closing_name', $.identifier),
      '>'
    ),

    // ドル記号スタイルのセルフクローズタグ
    self_closing_tag: $ => seq(
      '<$',
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '$>'
    ),

    // HTMLスタイルのセルフクローズタグ
    html_style_self_closing_tag: $ => seq(
      $._tag_start,
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '/>'
    ),

    // modifier定義
    modifier: $ => choice(
      $.standard_modifier,
      $.regex_modifier,
      $.field_modifier
    ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: $ => seq(
      field('key', $.identifier),
      '=',
      field('value', $.string)
    ),

    // regex_replace用のmodifier
    regex_modifier: $ => seq(
      'regex_replace=',
      field('pattern', $.regex_pattern),
      ',',
      field('replacement', $.string)
    ),

    // フィールド指定用のmodifier
    field_modifier: $ => seq(
      field('field_type', $.identifier),
      ':',
      field('field_name', $.identifier),
      '=',
      field('value', $.string)
    ),

    // 正規表現パターン
    regex_pattern: $ => seq(
      '"',
      '/',
      /[^/]*/,
      '/',
      '"'
    ),

    // 識別子（タグ名など）
    identifier: $ => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: $ => choice(
      seq('"', /[^"]*/, '"'),
      seq("'", /[^']*/, "'")
    ),

    // 通常のテキスト
    text: $ => /[^<]+/
  }
});
```

主な変更点：

1. `_tag_start`と`_tag_end`を共通ルールとして抽出
2. 新しい`html_style_self_closing_tag`ルールを追加
3. セルフクローズタグの3つの形式をサポート:
   - `<$mtfunctiontag$>`
   - `<MTFunctionTag/>`
   - `<mt:functiontag/>`

使用例：

```
<!-- 通常のタグ -->
<mt:TagName>content</mt:TagName>
<MT:TagName>content</MT:TagName>

<!-- ドル記号スタイルのセルフクローズ -->
<$MTFunctionTag$>
<$MTFunctionTag modifier="value"$>

<!-- HTMLスタイルのセルフクローズ -->
<MTFunctionTag/>
<mt:FunctionTag modifier="value"/>
<MT:FunctionTag field:content="value"/>
```

テストケース（`test/corpus/self_closing_variations.txt`）の例：

```
=====================================
Self closing tag variations
=====================================

<$MTFunctionTag$>
<MTFunctionTag/>
<mt:FunctionTag modifier="value"/>

---

(source_file
  (self_closing_tag
    name: (identifier))
  (html_style_self_closing_tag
    name: (identifier))
  (html_style_self_closing_tag
    name: (identifier)
    (standard_modifier
      key: (identifier)
      value: (string))))
```

この文法は以下をサポートします：

1. すべての大文字小文字の組み合わせ
2. 3種類のセルフクローズ形式
   - ドル記号スタイル: `<$tag$>`
   - HTMLスタイル（コロンあり）: `<mt:tag/>`
   - HTMLスタイル（コロンなし）: `<mttag/>`
3. すべての形式でのmodifier使用
4. ネストされたタグ構造

追加の改善点として以下が考えられます：

1. エラー処理の追加
```js
_recover: $ => alias(/.+/, $.ERROR)
```

2. コメントのサポート
3. より厳密なタグ名の制限
4. 空白文字の取り扱いの改善
5. タグ名のケース一致チェック（開始タグと終了タグ）

また、パフォーマンス最適化のために、正規表現を使用した実装も検討できます：

```js
_tag_start: $ => /[<][mM][tT][:]?/,
_tag_end: $ => /[<][/][mM][tT][:]?/,
```

現在ルールはこのようになっています
```js
rules: {
    // ドキュメントのルート
    source_file: ($) => repeat($._node),

    // ノードの定義（タグまたはテキスト）
    _node: ($) =>
      choice($.tag, $.dollar_self_close_tag, $.slash_self_close_tag, $.text),

    // ブロックタグ
    tag: ($) =>
      seq(
        /<[mM][tT]:?/,
        field("name", $.identifier),
        optional(repeat($.modifier)),
        ">",
        optional(repeat($._node)),
        /<\/[mM][tT]:?/,
        field("closing_name", $.identifier),
        ">",
      ),

    // スラッシュセルフクローズタグ
    slash_self_close_tag: ($) =>
      seq(
        /<[mM][tT]:?/,
        field("name", $.identifier),
        optional(repeat($.modifier)),
        "/>",
      ),

    // ダラーセルフクローズタグ
    dollar_self_close_tag: ($) =>
      seq(
        /<\$[mM][tT]:?/,
        field("name", $.identifier),
        optional(repeat($.modifier)),
        "$>",
      ),

    // 修飾子の定義
    modifier: ($) =>
      choice(
        $.standard_modifier,
        $.replace_modifier,
        $.regex_modifier,
        $.field_modifier,
      ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: ($) =>
      seq(field("key", $.identifier), "=", field("value", $.string)),

    // replace用のmodifier
    replace_modifier: ($) =>
      seq(
        "replace=",
        field("pattern", $.string),
        ",",
        field("replacement", $.string),
      ),

    // regex_replace用のmodifier
    regex_modifier: ($) =>
      seq(
        "regex_replace=",
        field("pattern", $.regex_pattern),
        ",",
        field("replacement", $.string),
      ),

    // フィールド指定用のmodifier
    field_modifier: ($) =>
      seq(
        "field:",
        field("field_name", $.identifier),
        "=",
        field("value", $.string),
      ),

    // 正規表現パターン
    regex_pattern: ($) => seq('"', "/", /[^/]*/, "/", '"'),

    // 識別子（タグ名）
    identifier: ($) => /[A-Za-z][A-Za-z0-9]*/,

    // 文字列値
    string: ($) => choice(seq('"', /[^"]*/, '"'), seq("'", /[^']*/, "'")),

    // テキストノード
    text: ($) => /[^<]+/,
  },
  ```

ルールを見ました。いくつかの改善点や追加機能を提案させていただきます：

1. 識別子（identifier）のルールを拡張して、アンダースコアを許可：
```js
identifier: ($) => /[A-Za-z][A-Za-z0-9_]*/,
```

2. タグ名部分のMTプレフィックスは任意である可能性を考慮：
```js
tag: ($) =>
  seq(
    /<(?:[mM][tT]:?)?/, // MTプレフィックスを任意に
    field("name", $.identifier),
    optional(repeat($.modifier)),
    ">",
    optional(repeat($._node)),
    /<\/(?:[mM][tT]:?)?/,
    field("closing_name", $.identifier),
    ">",
  ),

slash_self_close_tag: ($) =>
  seq(
    /<(?:[mM][tT]:?)?/,
    field("name", $.identifier),
    optional(repeat($.modifier)),
    "/>",
  ),
```

3. modifierの追加パターンのサポート：
```js
modifier: ($) =>
  choice(
    $.standard_modifier,
    $.replace_modifier,
    $.regex_modifier,
    $.field_modifier,
    $.column_modifier,  // 追加
    $.tag_modifier      // 追加
  ),

// column:指定用のmodifier
column_modifier: ($) =>
  seq(
    "column:",
    field("column_name", $.identifier),
    "=",
    field("value", $.string),
  ),

// tag:指定用のmodifier
tag_modifier: ($) =>
  seq(
    "tag:",
    field("tag_name", $.identifier),
    "=",
    field("value", $.string),
  ),
```

4. エラーリカバリーの追加：
```js
_node: ($) =>
  choice(
    $.tag,
    $.dollar_self_close_tag,
    $.slash_self_close_tag,
    $.text,
    $.ERROR
  ),

ERROR: ($) => token(prec(-1, /.+/)),
```

5. 文字列内でのエスケープのサポート：
```js
string: ($) => choice(
  seq('"', repeat(choice(/[^"\\]+/, $.escape_sequence)), '"'),
  seq("'", repeat(choice(/[^'\\]+/, $.escape_sequence)), "'")
),

escape_sequence: ($) => token.immediate(seq(
  '\\',
  choice(
    /[\\'"]/,  // 基本的なエスケープ
    /[bfnrt]/,  // 制御文字
    /u[0-9a-fA-F]{4}/  // Unicode
  )
)),
```

6. コメントのサポート：
```js
_node: ($) =>
  choice(
    $.tag,
    $.dollar_self_close_tag,
    $.slash_self_close_tag,
    $.text,
    $.comment
  ),

comment: ($) => seq(
  '<mt:!--',
  /[^-]*(?:-[^-]+)*/,
  '-->'
),
```

7. regex_patternの改善（エスケープをサポート）：
```js
regex_pattern: ($) => seq(
  '"',
  '/',
  repeat(choice(
    /[^/\\]+/,
    seq('\\', /./),  // エスケープされた任意の文字
  )),
  '/',
  '"'
),
```

8. より厳密な空白文字の処理：
```js
_whitespace: ($) => /[\s\t\n\r]+/,

modifier: ($) =>
  seq(
    optional($._whitespace),
    choice(
      $.standard_modifier,
      $.replace_modifier,
      $.regex_modifier,
      $.field_modifier
    ),
    optional($._whitespace)
  ),
```

これらの改善を適用することで、より堅牢で柔軟なパーサーになります。必要に応じて取り入れていただければと思います。特に：

- エスケープシーケンスのサポート
- エラーリカバリー
- より柔軟な識別子
- 空白文字の明示的な処理

は有用かもしれません。

いくつかの改善を取り入れて以下のようになりました
```
rules: {
    // ドキュメントのルート
    source_file: ($) => repeat($._node),

    // ノードの種類
    _node: ($) =>
      choice($.function_tag, $.block_tag, $.text, $.comment_tag, $.ERROR),

    // ファンクションタグ
    function_tag: ($) =>
      choice(
        $._function_tag_dollar,
        $._function_tag_slash,
        $._function_tag_none,
      ),

    // <mtEntryTitle /> スタイル
    _function_tag_slash: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), "/>"),
    // <mtEntryTitle> スタイル
    _function_tag_none: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), ">"),
    // <$mtentrytitle$> スタイル
    _function_tag_dollar: ($) =>
      seq(/<\$[mM][tT]:?/, $.identifier, optional($.modifier), "$>"),

    // ブロックタグ
    block_tag: ($) =>
      seq(
        // 開始タグ
        seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), ">"),
        // 内容
        optional(repeat($._node)),
        // 終了タグ
        seq(/<\/[mM][tT]:?/, $.identifier, ">"),
      ),

    // コメントタグ
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
        $.standard_modifier,
        $.replace_modifier,
        $.regex_modifier,
        $.field_modifier,
      ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: ($) =>
      seq(field("key", $.identifier), "=", field("value", $.string)),

    // replace用のmodifier
    replace_modifier: ($) =>
      seq(
        field("key", "replace"),
        "=",
        field("pattern", $.string),
        ",",
        field("replacement", $.string),
      ),

    // regex_replace用のmodifier
    regex_modifier: ($) =>
      seq(
        field("key", "regex_replace"),
        "=",
        field("pattern", $.regex_pattern),
        ",",
        field("replacement", $.string),
      ),

    // フィールド指定用のmodifier
    field_modifier: ($) =>
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
```

しかし、generateすると次のエラーが出てしまいます

```
npx tree-sitter generate
Unresolved conflict for symbol sequence:

  '_function_tag_slash_token1'  identifier  '>'  •  '_function_tag_slash_token1'  …

Possible interpretations:

  1:  (_function_tag_none  '_function_tag_slash_token1'  identifier  '>')  •  '_function_tag_slash_token1'  …
  2:  (block_tag  '_function_tag_slash_token1'  identifier  '>'  •  source_file_repeat1  'block_tag_token1'  identifier  '>')

Possible resolutions:

  1:  Specify a higher precedence in `block_tag` than in the other rules.
  2:  Specify a higher precedence in `_function_tag_none` than in the other rules.
  3:  Specify a left or right associativity in `_function_tag_none`
  4:  Add a conflict for these rules: `_function_tag_none`, `block_tag`
```

このエラーは、`<mt:tag>`という形式が`_function_tag_none`と`block_tag`の両方にマッチする可能性があるために発生しています。パーサーがこれをファンクションタグとして解釈するべきか、空のブロックタグとして解釈するべきか判断できない状態です。

この問題を解決するために、precedence（優先度）を使用して明示的にどちらを優先するか指定しましょう：

```js
rules: {
    // ... 他のルールは同じ ...

    // ファンクションタグ（より高い優先度を設定）
    function_tag: ($) =>
      prec(2, choice(
        $._function_tag_dollar,
        $._function_tag_slash,
        $._function_tag_none,
      )),

    // <mtEntryTitle /> スタイル
    _function_tag_slash: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), "/>"),

    // <mtEntryTitle> スタイル
    _function_tag_none: ($) =>
      seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), ">"),

    // <$mtentrytitle$> スタイル
    _function_tag_dollar: ($) =>
      seq(/<\$[mM][tT]:?/, $.identifier, optional($.modifier), "$>"),

    // ブロックタグ（より低い優先度を設定）
    block_tag: ($) =>
      prec(1, seq(
        // 開始タグ
        seq(/<[mM][tT]:?/, $.identifier, optional($.modifier), ">"),
        // 内容
        optional(repeat($._node)),
        // 終了タグ
        seq(/<\/[mM][tT]:?/, $.identifier, ">"),
      )),

    // ... 他のルールは同じ ...
```

または、より明示的な区別を付けるために、ファンクションタグとブロックタグの判別ルールを追加する方法もあります：

```js
rules: {
    // ... 他のルールは同じ ...

    // ファンクションタグの名前リスト
    _function_tag_names: ($) => choice(
      'EntryTitle',
      'EntryBody',
      'EntryExcerpt',
      // ... 他のファンクションタグ名
    ),

    // ブロックタグの名前リスト
    _block_tag_names: ($) => choice(
      'Entries',
      'Pages',
      'Comments',
      // ... 他のブロックタグ名
    ),

    // <mtEntryTitle> スタイル
    _function_tag_none: ($) =>
      seq(/<[mM][tT]:?/, $._function_tag_names, optional($.modifier), ">"),

    // ブロックタグ
    block_tag: ($) =>
      seq(
        seq(/<[mM][tT]:?/, $._block_tag_names, optional($.modifier), ">"),
        optional(repeat($._node)),
        seq(/<\/[mM][tT]:?/, $._block_tag_names, ">"),
      ),

    // ... 他のルールは同じ ...
```

個人的には最初の方法（precedenceを使用）をお勧めします。理由は：

1. より柔軟性が高い
2. タグ名のリストをハードコードする必要がない
3. 将来の拡張性が高い

precedenceを使用する場合、基本的にはファンクションタグを優先的に解釈し、閉じタグが見つかった場合にのみブロックタグとして解釈するという動作になります。

ブロックタグの開始タグと閉じタグは同じidentifierである必要があります

ブロックタグの開始タグと閉じタグのidentifierが一致することを確認するために、field演算子を使って名前を保持し、それを比較できるようにしましょう：

```js
rules: {
    // ... 他のルールは同じ ...

    // ブロックタグ
    block_tag: ($) =>
      seq(
        // 開始タグ
        seq(
          /<[mM][tT]:?/,
          field("name", $.identifier),  // 開始タグの名前を保持
          optional($.modifier),
          ">"
        ),
        // 内容
        optional(repeat($._node)),
        // 終了タグ
        seq(
          /<\/[mM][tT]:?/,
          // 閉じタグの名前は開始タグと同じでなければならない
          field("closing_name", alias($.identifier, $.closing_identifier)),
          ">"
        ),
      ),

    // ... 他のルールは同じ ...
```

さらに、Tree-sitterの外部スキャナー機能を使用して、開始タグと閉じタグの名前が一致しているかを検証することができます。これには新しいファイル `src/scanner.c` を作成します：

```c
#include <tree_sitter/parser.h>
#include <string.h>

enum TokenType {
  CLOSING_IDENTIFIER,
};

void *tree_sitter_mt_template_external_scanner_create() {
  return NULL;
}

void tree_sitter_mt_template_external_scanner_destroy(void *payload) {
}

void tree_sitter_mt_template_external_scanner_reset(void *payload) {
}

unsigned tree_sitter_mt_template_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  return 0;
}

void tree_sitter_mt_template_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
}

bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  // 実装は複雑になるため、基本的な構文チェックはASTの検証時に行うことをお勧めします
  return false;
}
```

そして、grammar.jsでこのスキャナーを参照します：

```js
module.exports = grammar({
  name: 'mt_template',

  externals: $ => [
    $.CLOSING_IDENTIFIER
  ],

  rules: {
    // ... 他のルールは同じ ...

    // ブロックタグ
    block_tag: ($) =>
      prec(1, seq(
        // 開始タグ
        seq(
          /<[mM][tT]:?/,
          field("name", $.identifier),
          optional($.modifier),
          ">"
        ),
        // 内容
        optional(repeat($._node)),
        // 終了タグ
        seq(
          /<\/[mM][tT]:?/,
          field("closing_name", $.identifier),
          ">"
        )
      )),

    // ... 他のルールは同じ ...
  }
});
```

タグ名の一致チェックは、実際にはTree-sitterパーサーの後段で行う方が適切かもしれません：

1. まずTree-sitterで構文木を生成
2. その後、ASTを走査して開始タグと閉じタグの名前が一致しているかを確認

例えば、以下のようなJavaScriptコードで検証できます：

```javascript
function validateBlockTags(tree) {
  const cursor = tree.walk();
  let hasError = false;

  while (cursor.gotoNextSibling()) {
    if (cursor.nodeType === 'block_tag') {
      const node = cursor.currentNode();
      const openTag = node.child(0).fieldForName('name');
      const closeTag = node.child(2).fieldForName('closing_name');

      if (openTag.text !== closeTag.text) {
        hasError = true;
        console.error(
          `Mismatched tags: opening tag "${openTag.text}" doesn't match closing tag "${closeTag.text}"`
        );
      }
    }
  }

  return !hasError;
}
```

この方法の利点は：

1. 文法定義がシンプルになる
2. より柔軟なエラーハンドリングが可能
3. カスタムのエラーメッセージを表示できる
4. パフォーマンスへの影響が少ない

欠点は：

1. 構文エラーの検出が遅延する
2. 追加の検証ステップが必要

実際の使用ケースに応じて、適切なアプローチを選択してください。

詳しく解説してください

Tree-sitterでブロックタグの開始タグと閉じタグの一致を検証する方法について、詳しく解説します。

### 1. 基本的なアプローチ

タグの一致を検証するには、主に2つのアプローチがあります：

#### A. パース時の構文的な制約
```js
block_tag: ($) =>
  prec(1, seq(
    // 開始タグ
    seq(
      /<[mM][tT]:?/,
      field("name", $.identifier),     // 開始タグの名前を記録
      optional($.modifier),
      ">"
    ),
    optional(repeat($._node)),
    // 終了タグ
    seq(
      /<\/[mM][tT]:?/,
      field("closing_name", $.identifier),  // 閉じタグの名前を記録
      ">"
    )
  )),
```

このアプローチでは、開始タグと閉じタグの名前を`field`演算子を使って記録します。

#### B. 後処理での検証
生成されたASTを走査して検証を行います：

```javascript
class MTTemplateValidator {
  validate(tree) {
    const errors = [];
    this.validateNode(tree.rootNode, errors);
    return errors;
  }

  validateNode(node, errors) {
    if (node.type === 'block_tag') {
      // ブロックタグの検証
      const openTagName = node.childForFieldName('name');
      const closeTagName = node.childForFieldName('closing_name');

      if (openTagName.text !== closeTagName.text) {
        errors.push({
          type: 'tag_mismatch',
          message: `Opening tag "${openTagName.text}" doesn't match closing tag "${closeTagName.text}"`,
          location: {
            start: node.startPosition,
            end: node.endPosition
          }
        });
      }
    }

    // 子ノードの再帰的な検証
    for (const child of node.children) {
      this.validateNode(child, errors);
    }
  }
}
```

### 2. より詳細な実装

#### A. 文法の拡張
より厳密な文法定義を行う場合：

```js
module.exports = grammar({
  name: 'mt_template',

  rules: {
    source_file: ($) => repeat($._node),

    _node: ($) =>
      choice(
        $.function_tag,
        $.block_tag,
        $.text,
        $.comment_tag,
        $.ERROR
      ),

    // ブロックタグの詳細な定義
    block_tag: ($) =>
      prec(1, seq(
        field('opening_tag', $.tag_opening),
        optional(repeat($._node)),
        field('closing_tag', $.tag_closing)
      )),

    // 開始タグの定義
    tag_opening: ($) => seq(
      /<[mM][tT]:?/,
      field('name', $.identifier),
      optional(repeat($.modifier)),
      '>'
    ),

    // 閉じタグの定義
    tag_closing: ($) => seq(
      /<\/[mM][tT]:?/,
      field('name', $.identifier),
      '>'
    ),

    // ... 他のルール
  }
});
```

#### B. 高度な検証クラス

```javascript
class MTTemplateValidator {
  constructor() {
    this.errors = [];
    this.tagStack = [];
  }

  validate(tree) {
    this.errors = [];
    this.tagStack = [];
    this.validateNode(tree.rootNode);
    return this.errors;
  }

  validateNode(node) {
    switch (node.type) {
      case 'block_tag':
        this.validateBlockTag(node);
        break;
      case 'function_tag':
        this.validateFunctionTag(node);
        break;
      // 他のノードタイプの処理
    }

    // 子ノードの再帰的な検証
    for (const child of node.children) {
      this.validateNode(child);
    }
  }

  validateBlockTag(node) {
    const openingTag = node.childForFieldName('opening_tag');
    const closingTag = node.childForFieldName('closing_tag');

    if (!openingTag || !closingTag) {
      this.addError({
        type: 'invalid_tag_structure',
        message: 'Invalid block tag structure',
        node: node
      });
      return;
    }

    const openName = this.getTagName(openingTag);
    const closeName = this.getTagName(closingTag);

    if (openName !== closeName) {
      this.addError({
        type: 'tag_mismatch',
        message: `Opening tag "${openName}" doesn't match closing tag "${closeName}"`,
        node: node
      });
    }
  }

  getTagName(tagNode) {
    const nameNode = tagNode.childForFieldName('name');
    return nameNode ? nameNode.text : null;
  }

  addError({ type, message, node }) {
    this.errors.push({
      type,
      message,
      location: {
        start: node.startPosition,
        end: node.endPosition,
        startIndex: node.startIndex,
        endIndex: node.endIndex
      }
    });
  }
}
```

### 3. 使用例

```javascript
// パーサーとバリデーターの初期化
const Parser = require('tree-sitter');
const MTTemplate = require('tree-sitter-mt-template');
const validator = new MTTemplateValidator();

// テンプレートの検証
function validateTemplate(templateContent) {
  const parser = new Parser();
  parser.setLanguage(MTTemplate);

  const tree = parser.parse(templateContent);
  const errors = validator.validate(tree);

  return {
    isValid: errors.length === 0,
    errors: errors,
    ast: tree
  };
}

// 使用例
const result = validateTemplate(`
  <mt:Entries>
    <mt:EntryTitle />
    <mt:EntryBody />
  </mt:Entries2>  // エラー: タグ名不一致
`);

if (!result.isValid) {
  console.error('Template validation failed:');
  result.errors.forEach(error => {
    console.error(`- ${error.message} at line ${error.location.start.row + 1}`);
  });
}
```

### 4. 利点と注意点

#### 利点:
- 詳細なエラー報告が可能
- カスタムの検証ルールを追加可能
- 文法定義がクリーンに保てる
- パフォーマンスの最適化が容易

#### 注意点:
- 実装が複雑になる可能性がある
- パース後の追加処理が必要
- メモリ使用量が増加する可能性がある

このアプローチにより、堅牢なテンプレート検証システムを構築できます。必要に応じて、さらなる検証ルールや機能を追加することも可能です。

parser.cを用いた実装方法を詳しく説明してください

`parser.c`を用いた実装方法について、詳しく説明します。これは、Tree-sitterの外部スキャナーを使用してタグの一致を検証する方法です。

### 1. 基本構造

まず、`src/scanner.c`を作成します：

```c
#include <tree_sitter/parser.h>
#include <string.h>
#include <stdlib.h>

// スキャナーの状態を保持する構造体
typedef struct {
  // 現在処理中のタグ名を保持する配列
  char **tag_stack;
  // スタックのサイズ
  uint32_t stack_size;
  // スタックの容量
  uint32_t stack_capacity;
} Scanner;

// トークンタイプの列挙
enum TokenType {
  CLOSING_TAG_NAME,  // 閉じタグの名前
};

// スキャナーの作成
void *tree_sitter_mt_template_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->stack_capacity = 32;
  scanner->tag_stack = calloc(scanner->stack_capacity, sizeof(char *));
  return scanner;
}

// スキャナーの破棄
void tree_sitter_mt_template_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  free(scanner->tag_stack);
  free(scanner);
}
```

### 2. スキャナーの主要な機能

```c
// スタック操作のヘルパー関数
static void push_tag(Scanner *scanner, const char *tag_name) {
  if (scanner->stack_size >= scanner->stack_capacity) {
    scanner->stack_capacity *= 2;
    scanner->tag_stack = realloc(
      scanner->tag_stack,
      scanner->stack_capacity * sizeof(char *)
    );
  }

  size_t length = strlen(tag_name);
  char *tag_copy = malloc(length + 1);
  strcpy(tag_copy, tag_name);
  scanner->tag_stack[scanner->stack_size++] = tag_copy;
}

static char *pop_tag(Scanner *scanner) {
  if (scanner->stack_size == 0) return NULL;
  return scanner->tag_stack[--scanner->stack_size];
}

// スキャンの実装
bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // 空白文字をスキップ
  while (lexer->lookahead == ' ' ||
         lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' ||
         lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  // 閉じタグの検証
  if (valid_symbols[CLOSING_TAG_NAME]) {
    // タグ名の開始位置を保存
    uint32_t start_pos = lexer->get_position(lexer);

    // タグ名を読み取る
    char tag_name[256] = {0};
    int i = 0;
    while (isalnum(lexer->lookahead) || lexer->lookahead == '_') {
      if (i < 255) tag_name[i++] = lexer->lookahead;
      lexer->advance(lexer, false);
    }
    tag_name[i] = '\0';

    // スタックの最上位のタグと比較
    char *expected_tag = scanner->stack_size > 0 ?
      scanner->tag_stack[scanner->stack_size - 1] : NULL;

    if (expected_tag && strcmp(tag_name, expected_tag) == 0) {
      // タグが一致した場合
      pop_tag(scanner);
      lexer->result_symbol = CLOSING_TAG_NAME;
      return true;
    }

    // 不一致の場合は位置を戻す
    lexer->reset(lexer, start_pos);
  }

  return false;
}
```

### 3. シリアライズと状態の復元

```c
// スキャナーの状態のシリアライズ
unsigned tree_sitter_mt_template_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // スタックサイズを書き込む
  memcpy(&buffer[size], &scanner->stack_size, sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を書き込む
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    uint32_t name_length = strlen(scanner->tag_stack[i]);
    memcpy(&buffer[size], &name_length, sizeof(uint32_t));
    size += sizeof(uint32_t);
    memcpy(&buffer[size], scanner->tag_stack[i], name_length);
    size += name_length;
  }

  return size;
}

// シリアライズされた状態からの復元
void tree_sitter_mt_template_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // スタックをクリア
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;

  if (length == 0) return;

  // スタックサイズを読み込む
  memcpy(&scanner->stack_size, &buffer[size], sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を読み込む
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
```

### 4. grammar.jsの対応する部分

```js
module.exports = grammar({
  name: 'mt_template',

  externals: $ => [
    $.CLOSING_TAG_NAME
  ],

  rules: {
    // ... 他のルール ...

    block_tag: $ => seq(
      // 開始タグ
      seq(
        /<[mM][tT]:?/,
        field('name', $.identifier),
        optional($.modifier),
        '>'
      ),
      // コンテンツ
      optional(repeat($._node)),
      // 閉じタグ
      seq(
        /<\/[mM][tT]:?/,
        field('closing_name', $.CLOSING_TAG_NAME),
        '>'
      )
    ),

    // ... 他のルール ...
  }
});
```

### 5. エラーハンドリングの追加

```c
// エラー情報を保持する構造体を追加
typedef struct {
  char message[256];
  uint32_t position;
} Error;

typedef struct {
  char **tag_stack;
  uint32_t stack_size;
  uint32_t stack_capacity;
  Error *errors;
  uint32_t error_count;
  uint32_t error_capacity;
} Scanner;

// エラーを追加するヘルパー関数
static void add_error(Scanner *scanner, const char *message, uint32_t position) {
  if (scanner->error_count >= scanner->error_capacity) {
    scanner->error_capacity = scanner->error_capacity == 0 ? 8 : scanner->error_capacity * 2;
    scanner->errors = realloc(
      scanner->errors,
      scanner->error_capacity * sizeof(Error)
    );
  }

  Error *error = &scanner->errors[scanner->error_count++];
  strncpy(error->message, message, 255);
  error->message[255] = '\0';
  error->position = position;
}
```

### 6. 使用例

```c
// parser.c
const TSLanguage *tree_sitter_mt_template() {
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
    .external_scanner = {
      .create = tree_sitter_mt_template_external_scanner_create,
      .destroy = tree_sitter_mt_template_external_scanner_destroy,
      .scan = tree_sitter_mt_template_external_scanner_scan,
      .serialize = tree_sitter_mt_template_external_scanner_serialize,
      .deserialize = tree_sitter_mt_template_external_scanner_deserialize,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
```

この実装により：

1. タグの開始と終了の一致を厳密にチェック
2. エラー情報の詳細な記録
3. パース中の状態の保持と復元
4. メモリの適切な管理

が可能になります。実際の使用時には、これらの機能を必要に応じて調整してください。

完成したgrammer.jsとparser.cを書いてください

まず、完成したgrammer.jsから示します：

```javascript
// grammar.js
module.exports = grammar({
  name: 'mt_template',

  externals: $ => [
    $.CLOSING_TAG_NAME
  ],

  rules: {
    // ドキュメントのルート
    source_file: ($) => repeat($._node),

    // ノードの種類
    _node: ($) =>
      choice(
        $.function_tag,
        $.block_tag,
        $.text,
        $.comment_tag,
        $.ERROR
      ),

    // ファンクションタグ（セルフクローズタグ）
    function_tag: ($) =>
      choice(
        // <$mt:tag$> スタイル
        seq(
          '<$',
          choice('mt:', 'MT:', 'mt', 'MT'),
          field('name', $.identifier),
          optional(repeat($.modifier)),
          '$>'
        ),
        // <mt:tag/> スタイル
        seq(
          '<',
          choice('mt:', 'MT:', 'mt', 'MT'),
          field('name', $.identifier),
          optional(repeat($.modifier)),
          '/>'
        ),
        // <mt:tag> スタイル
        seq(
          '<',
          choice('mt:', 'MT:', 'mt', 'MT'),
          field('name', $.identifier),
          optional(repeat($.modifier)),
          '>'
        )
      ),

    // ブロックタグ
    block_tag: ($) =>
      seq(
        // 開始タグ
        seq(
          '<',
          choice('mt:', 'MT:', 'mt', 'MT'),
          field('name', $.identifier),
          optional(repeat($.modifier)),
          '>'
        ),
        // 内容
        optional(repeat($._node)),
        // 終了タグ
        seq(
          '</',
          choice('mt:', 'MT:', 'mt', 'MT'),
          field('closing_name', $.CLOSING_TAG_NAME),
          '>'
        )
      ),

    // コメントタグ
    comment_tag: ($) =>
      seq(
        '<',
        choice('mt:', 'MT:', 'mt', 'MT'),
        'ignore',
        '>',
        optional($.text),
        '</',
        choice('mt:', 'MT:', 'mt', 'MT'),
        'ignore',
        '>'
      ),

    // 修飾子定義
    modifier: ($) =>
      choice(
        $.standard_modifier,
        $.replace_modifier,
        $.regex_modifier,
        $.field_modifier
      ),

    // 標準的なmodifier（key="value"形式）
    standard_modifier: ($) =>
      seq(
        field('key', $.identifier),
        '=',
        field('value', $.string)
      ),

    // replace用のmodifier
    replace_modifier: ($) =>
      seq(
        field('key', 'replace'),
        '=',
        field('pattern', $.string),
        ',',
        field('replacement', $.string)
      ),

    // regex_replace用のmodifier
    regex_modifier: ($) =>
      seq(
        field('key', 'regex_replace'),
        '=',
        field('pattern', $.regex_pattern),
        ',',
        field('replacement', $.string)
      ),

    // フィールド指定用のmodifier
    field_modifier: ($) =>
      seq(
        'field:',
        field('field_name', $.identifier),
        '=',
        field('value', $.string)
      ),

    // 正規表現パターン
    regex_pattern: ($) =>
      seq('"', '/', /[^/]*/, '/', '"'),

    // 識別子（タグ名）
    identifier: ($) => /[A-Za-z][A-Za-z0-9_]*/,

    // 文字列値
    string: ($) =>
      choice(
        seq('"', repeat(choice(/[^"\\]+/, $.escape_sequence)), '"'),
        seq("'", repeat(choice(/[^'\\]+/, $.escape_sequence)), "'")
      ),

    // エスケープシーケンス
    escape_sequence: ($) =>
      token.immediate(seq(
        '\\',
        choice(
          /[\\'"]/,
          /[bfnrt]/,
          /u[0-9a-fA-F]{4}/
        )
      )),

    // テキストノード
    text: ($) => /[^<]+/,

    // エラーリカバリー
    ERROR: ($) => token(prec(-1, /.+/))
  }
});
```

次に、完成したparser.cを示します：

```c
// parser.c
#include <tree_sitter/parser.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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

// スキャナーの作成
void *tree_sitter_mt_template_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->stack_capacity = 32;
  scanner->tag_stack = calloc(scanner->stack_capacity, sizeof(char *));
  scanner->error_capacity = 8;
  scanner->errors = calloc(scanner->error_capacity, sizeof(Error));
  return scanner;
}

// スキャナーの破棄
void tree_sitter_mt_template_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  free(scanner->tag_stack);
  free(scanner->errors);
  free(scanner);
}

// スキャナーのリセット
void tree_sitter_mt_template_external_scanner_reset(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;
}

// スタックにタグを追加
static void push_tag(Scanner *scanner, const char *tag_name) {
  if (scanner->stack_size >= scanner->stack_capacity) {
    scanner->stack_capacity *= 2;
    scanner->tag_stack = realloc(
      scanner->tag_stack,
      scanner->stack_capacity * sizeof(char *)
    );
  }

  size_t length = strlen(tag_name);
  char *tag_copy = malloc(length + 1);
  strcpy(tag_copy, tag_name);
  scanner->tag_stack[scanner->stack_size++] = tag_copy;
}

// スタックからタグを取り出す
static char *pop_tag(Scanner *scanner) {
  if (scanner->stack_size == 0) return NULL;
  return scanner->tag_stack[--scanner->stack_size];
}

// エラーを追加
static void add_error(Scanner *scanner, const char *message, uint32_t position) {
  if (scanner->error_count >= scanner->error_capacity) {
    scanner->error_capacity *= 2;
    scanner->errors = realloc(
      scanner->errors,
      scanner->error_capacity * sizeof(Error)
    );
  }

  Error *error = &scanner->errors[scanner->error_count++];
  strncpy(error->message, message, 255);
  error->message[255] = '\0';
  error->position = position;
}

// メインのスキャン処理
bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // 空白文字をスキップ
  while (lexer->lookahead == ' ' ||
         lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' ||
         lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[CLOSING_TAG_NAME]) {
    uint32_t start_pos = lexer->get_position(lexer);

    // タグ名を読み取る
    char tag_name[256] = {0};
    int i = 0;
    while (isalnum(lexer->lookahead) || lexer->lookahead == '_') {
      if (i < 255) tag_name[i++] = lexer->lookahead;
      lexer->advance(lexer, false);
    }
    tag_name[i] = '\0';

    // スタックのトップと比較
    char *expected_tag = scanner->stack_size > 0 ?
      scanner->tag_stack[scanner->stack_size - 1] : NULL;

    if (expected_tag && strcmp(tag_name, expected_tag) == 0) {
      pop_tag(scanner);
      lexer->result_symbol = CLOSING_TAG_NAME;
      return true;
    }

    // エラー情報を記録
    char error_message[256];
    snprintf(error_message, 256,
      "Expected closing tag '%s' but found '%s'",
      expected_tag ? expected_tag : "(none)",
      tag_name
    );
    add_error(scanner, error_message, start_pos);

    lexer->reset(lexer, start_pos);
  }

  return false;
}

// スキャナーの状態のシリアライズ
unsigned tree_sitter_mt_template_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // スタックサイズを書き込む
  memcpy(&buffer[size], &scanner->stack_size, sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を書き込む
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    uint32_t name_length = strlen(scanner->tag_stack[i]);
    memcpy(&buffer[size], &name_length, sizeof(uint32_t));
    size += sizeof(uint32_t);
    memcpy(&buffer[size], scanner->tag_stack[i], name_length);
    size += name_length;
  }

  return size;
}

// シリアライズされた状態からの復元
void tree_sitter_mt_template_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // 現在のスタックをクリア
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;

  if (length == 0) return;

  // スタックサイズを読み込む
  memcpy(&scanner->stack_size, &buffer[size], sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を読み込む
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

// 言語定義の提供
const TSLanguage *tree_sitter_mt_template() {
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
    .external_scanner = {
      .create = tree_sitter_mt_template_external_scanner_create,
      .destroy = tree_sitter_mt_template_external_scanner_destroy,
      .scan = tree_sitter_mt_template_external_scanner_scan,
      .serialize = tree_sitter_mt_template_external_scanner_serialize,
      .deserialize = tree_sitter_mt_template_external_scanner_deserialize,
      .reset = tree_sitter_mt_template_external_scanner_reset,
    },
    .primary_state_ids = ts_primary_state_ids,
  };
  return &language;
}
```

この実装では：

1. MTテンプレート言語の全ての構文要素をサポート
2. タグの開始と終了の一致を厳密にチェック
3. 詳細なエラー情報の提供
4. メモリの適切な管理
5. スキャナーの状態の保持と復元

を実現しています。必要に応じて、さらなる機能の追加や調整が可能です。

最終的な`scanner.c`も出力してください

はい、以下が最終的な`scanner.c`の実装です：

```c
#include <tree_sitter/parser.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    scanner->tag_stack = realloc(
      scanner->tag_stack,
      scanner->stack_capacity * sizeof(char *)
    );
  }

  size_t length = strlen(tag_name);
  char *tag_copy = malloc(length + 1);
  strcpy(tag_copy, tag_name);
  scanner->tag_stack[scanner->stack_size++] = tag_copy;
}

// スタックからタグを取り出す
static char *pop_tag(Scanner *scanner) {
  if (scanner->stack_size == 0) return NULL;
  char *tag = scanner->tag_stack[--scanner->stack_size];
  free(tag);
  return tag;
}

// エラーを追加
static void add_error(Scanner *scanner, const char *message, uint32_t position) {
  if (scanner->error_count >= scanner->error_capacity) {
    scanner->error_capacity *= 2;
    scanner->errors = realloc(
      scanner->errors,
      scanner->error_capacity * sizeof(Error)
    );
  }

  Error *error = &scanner->errors[scanner->error_count++];
  strncpy(error->message, message, 255);
  error->message[255] = '\0';
  error->position = position;
}

// スキャナーの作成
void *tree_sitter_mt_template_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->stack_capacity = 32;
  scanner->tag_stack = calloc(scanner->stack_capacity, sizeof(char *));
  scanner->error_capacity = 8;
  scanner->errors = calloc(scanner->error_capacity, sizeof(Error));
  return scanner;
}

// スキャナーの破棄
void tree_sitter_mt_template_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  free(scanner->tag_stack);
  free(scanner->errors);
  free(scanner);
}

// スキャナーのリセット
void tree_sitter_mt_template_external_scanner_reset(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;
}

// スキャナーの状態のシリアライズ
unsigned tree_sitter_mt_template_external_scanner_serialize(
  void *payload,
  char *buffer
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // スタックサイズを書き込む
  memcpy(&buffer[size], &scanner->stack_size, sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を書き込む
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    uint32_t name_length = strlen(scanner->tag_stack[i]);
    memcpy(&buffer[size], &name_length, sizeof(uint32_t));
    size += sizeof(uint32_t);
    memcpy(&buffer[size], scanner->tag_stack[i], name_length);
    size += name_length;
  }

  return size;
}

// シリアライズされた状態からの復元
void tree_sitter_mt_template_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  // 現在のスタックをクリア
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;

  if (length == 0) return;

  // スタックサイズを読み込む
  memcpy(&scanner->stack_size, &buffer[size], sizeof(uint32_t));
  size += sizeof(uint32_t);

  // スタックの内容を読み込む
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

// タグ名を読み取る
static bool read_tag_name(TSLexer *lexer, char *buffer, size_t buffer_size) {
  size_t i = 0;
  while (i < buffer_size - 1 && (isalnum(lexer->lookahead) || lexer->lookahead == '_')) {
    buffer[i++] = lexer->lookahead;
    lexer->advance(lexer, false);
  }
  buffer[i] = '\0';
  return i > 0;
}

// メインのスキャン処理
bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // 空白文字をスキップ
  while (lexer->lookahead == ' ' ||
         lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' ||
         lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[CLOSING_TAG_NAME]) {
    uint32_t start_pos = lexer->get_position(lexer);

    // タグ名を読み取る
    char tag_name[256];
    if (!read_tag_name(lexer, tag_name, sizeof(tag_name))) {
      return false;
    }

    // スタックのトップと比較
    if (scanner->stack_size > 0) {
      const char *expected_tag = scanner->tag_stack[scanner->stack_size - 1];
      if (strcmp(tag_name, expected_tag) == 0) {
        pop_tag(scanner);
        lexer->result_symbol = CLOSING_TAG_NAME;
        return true;
      } else {
        // タグの不一致エラー
        char error_message[256];
        snprintf(
          error_message,
          sizeof(error_message),
          "Expected closing tag '%s' but found '%s'",
          expected_tag,
          tag_name
        );
        add_error(scanner, error_message, start_pos);
      }
    } else {
      // 対応する開始タグが見つからないエラー
      add_error(
        scanner,
        "Found closing tag without matching opening tag",
        start_pos
      );
    }

    lexer->reset(lexer, start_pos);
  }

  return false;
}

// エラー情報の取得
const Error *get_errors(void *payload, uint32_t *count) {
  Scanner *scanner = (Scanner *)payload;
  *count = scanner->error_count;
  return scanner->errors;
}

// スタック情報の取得（デバッグ用）
const char **get_tag_stack(void *payload, uint32_t *count) {
  Scanner *scanner = (Scanner *)payload;
  *count = scanner->stack_size;
  return (const char **)scanner->tag_stack;
}
```

この`scanner.c`の主な特徴は：

1. タグのスタック管理
   - タグ名のプッシュ/ポップ
   - メモリの動的割り当てと解放
   - スタックの自動拡張

2. エラー処理
   - 詳細なエラーメッセージの生成
   - エラー位置の記録
   - エラー情報の蓄積

3. 状態の管理
   - スキャナーの状態のシリアライズ/デシリアライズ
   - スキャナーのリセット機能
   - スキャナーの作成と破棄

4. ヘルパー機能
   - タグ名の読み取り
   - エラー情報の取得
   - スタック情報の取得（デバッグ用）

5. メモリ管理
   - 適切なメモリの割り当てと解放
   - バッファオーバーフローの防止
   - メモリリークの防止

この実装により、MTテンプレート言語の構文解析において、タグの一致チェックとエラー報告を確実に行うことができます。

また、デバッグやテストのために、エラー情報やスタック情報を取得する機能も提供しています。これにより、パーサーの動作を詳細に監視し、問題が発生した場合の原因特定が容易になります。

以下の警告が出ていいます。
なくしてください
```
Warning: Found non-static non-tree-sitter functions in the external scannner
  `_get_errors`
  `_get_tag_stack`
Consider making these functions static, they can cause conflicts when another tree-sitter project uses the same function name
```

はい、警告を解消するために、外部から呼び出す必要のない関数を`static`にします。修正した`scanner.c`の該当部分を示します：

```c
// エラー情報の取得（staticに変更）
static const Error *get_errors(void *payload, uint32_t *count) {
  Scanner *scanner = (Scanner *)payload;
  *count = scanner->error_count;
  return scanner->errors;
}

// スタック情報の取得（staticに変更）
static const char **get_tag_stack(void *payload, uint32_t *count) {
  Scanner *scanner = (Scanner *)payload;
  *count = scanner->stack_size;
  return (const char **)scanner->tag_stack;
}
```

または、これらの関数が実際に必要ない場合は、完全に削除することもできます。これらはデバッグ目的で追加されていた関数なので、実際の構文解析には影響しません。

必要に応じて、エラー情報やスタック情報を取得する別の方法を実装することも可能です。例えば、Tree-sitterのクエリ機能を使用して必要な情報を取得する方法などがあります。

警告を完全に解消するために、これらの関数を削除した場合の`scanner.c`の最後の部分は以下のようになります：

```c
bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  // 空白文字をスキップ
  while (lexer->lookahead == ' ' ||
         lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' ||
         lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[CLOSING_TAG_NAME]) {
    uint32_t start_pos = lexer->get_position(lexer);

    // タグ名を読み取る
    char tag_name[256];
    if (!read_tag_name(lexer, tag_name, sizeof(tag_name))) {
      return false;
    }

    // スタックのトップと比較
    if (scanner->stack_size > 0) {
      const char *expected_tag = scanner->tag_stack[scanner->stack_size - 1];
      if (strcmp(tag_name, expected_tag) == 0) {
        pop_tag(scanner);
        lexer->result_symbol = CLOSING_TAG_NAME;
        return true;
      } else {
        // タグの不一致エラー
        char error_message[256];
        snprintf(
          error_message,
          sizeof(error_message),
          "Expected closing tag '%s' but found '%s'",
          expected_tag,
          tag_name
        );
        add_error(scanner, error_message, start_pos);
      }
    } else {
      // 対応する開始タグが見つからないエラー
      add_error(
        scanner,
        "Found closing tag without matching opening tag",
        start_pos
      );
    }

    lexer->reset(lexer, start_pos);
  }

  return false;
}
```

これにより、警告が解消され、より適切なTree-sitter外部スキャナーの実装となります。

clang: No member named 'get_byte' in 'struct TSLexer'


はい、Tree-sitterの最新バージョンでは`get_byte`の代わりに`lookahead`を使用します。修正した`scanner.c`の該当部分を示します：

```c
#include <tree_sitter/parser.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

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
    scanner->tag_stack = realloc(
      scanner->tag_stack,
      scanner->stack_capacity * sizeof(char *)
    );
  }

  size_t length = strlen(tag_name);
  char *tag_copy = malloc(length + 1);
  strcpy(tag_copy, tag_name);
  scanner->tag_stack[scanner->stack_size++] = tag_copy;
}

// スタックからタグを取り出す
static char *pop_tag(Scanner *scanner) {
  if (scanner->stack_size == 0) return NULL;
  char *tag = scanner->tag_stack[--scanner->stack_size];
  free(tag);
  return tag;
}

// エラーを追加
static void add_error(Scanner *scanner, const char *message, uint32_t position) {
  if (scanner->error_count >= scanner->error_capacity) {
    scanner->error_capacity *= 2;
    scanner->errors = realloc(
      scanner->errors,
      scanner->error_capacity * sizeof(Error)
    );
  }

  Error *error = &scanner->errors[scanner->error_count++];
  strncpy(error->message, message, 255);
  error->message[255] = '\0';
  error->position = position;
}

void *tree_sitter_mt_template_external_scanner_create() {
  Scanner *scanner = calloc(1, sizeof(Scanner));
  scanner->stack_capacity = 32;
  scanner->tag_stack = calloc(scanner->stack_capacity, sizeof(char *));
  scanner->error_capacity = 8;
  scanner->errors = calloc(scanner->error_capacity, sizeof(Error));
  return scanner;
}

void tree_sitter_mt_template_external_scanner_destroy(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  free(scanner->tag_stack);
  free(scanner->errors);
  free(scanner);
}

void tree_sitter_mt_template_external_scanner_reset(void *payload) {
  Scanner *scanner = (Scanner *)payload;
  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;
}

unsigned tree_sitter_mt_template_external_scanner_serialize(
  void *payload,
  char *buffer
) {
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

void tree_sitter_mt_template_external_scanner_deserialize(
  void *payload,
  const char *buffer,
  unsigned length
) {
  Scanner *scanner = (Scanner *)payload;
  uint32_t size = 0;

  for (uint32_t i = 0; i < scanner->stack_size; i++) {
    free(scanner->tag_stack[i]);
  }
  scanner->stack_size = 0;
  scanner->error_count = 0;

  if (length == 0) return;

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
  while (i < buffer_size - 1 && (isalnum(lexer->lookahead) || lexer->lookahead == '_')) {
    buffer[i++] = lexer->lookahead;
    lexer->advance(lexer, false);
  }
  buffer[i] = '\0';
  return i > 0;
}

bool tree_sitter_mt_template_external_scanner_scan(
  void *payload,
  TSLexer *lexer,
  const bool *valid_symbols
) {
  Scanner *scanner = (Scanner *)payload;

  while (lexer->lookahead == ' ' ||
         lexer->lookahead == '\t' ||
         lexer->lookahead == '\n' ||
         lexer->lookahead == '\r') {
    lexer->advance(lexer, true);
  }

  if (valid_symbols[CLOSING_TAG_NAME]) {
    uint32_t start_pos = lexer->get_column(lexer); // get_position の代わりに get_column を使用

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
        snprintf(
          error_message,
          sizeof(error_message),
          "Expected closing tag '%s' but found '%s'",
          expected_tag,
          tag_name
        );
        add_error(scanner, error_message, start_pos);
      }
    } else {
      add_error(
        scanner,
        "Found closing tag without matching opening tag",
        start_pos
      );
    }

    // 位置のリセット
    while (isalnum(lexer->lookahead) || lexer->lookahead == '_') {
      lexer->advance(lexer, false);
    }
  }

  return false;
}
```

主な変更点：

1. `get_byte`の代わりに`lookahead`を使用
2. `get_position`の代わりに`get_column`を使用
3. `lexer->reset`の代わりに、手動で位置を進める方法を使用

これにより、最新のTree-sitterバージョンと互換性のある実装となります。
