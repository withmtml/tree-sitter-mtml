/**
 * @file 
 * @license ISC
 */

/// <reference types="tree-sitter-cli/dsl" />
// @ts-check

module.exports = grammar({
  name: "mtml",

  rules: {
    // TODO: add the actual grammar rules
    source_file: $ => "hello"
  }
});
