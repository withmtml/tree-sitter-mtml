package tree_sitter_mtml_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_mtml "github.com/tree-sitter/tree-sitter-mtml/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_mtml.Language())
	if language == nil {
		t.Errorf("Error loading Mtml grammar")
	}
}
