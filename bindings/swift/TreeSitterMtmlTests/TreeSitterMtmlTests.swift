import XCTest
import SwiftTreeSitter
import TreeSitterMtml

final class TreeSitterMtmlTests: XCTestCase {
    func testCanLoadGrammar() throws {
        let parser = Parser()
        let language = Language(language: tree_sitter_mtml())
        XCTAssertNoThrow(try parser.setLanguage(language),
                         "Error loading Mtml grammar")
    }
}
