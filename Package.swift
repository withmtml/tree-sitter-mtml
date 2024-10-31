// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "TreeSitterMtml",
    products: [
        .library(name: "TreeSitterMtml", targets: ["TreeSitterMtml"]),
    ],
    dependencies: [
        .package(url: "https://github.com/ChimeHQ/SwiftTreeSitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterMtml",
            dependencies: [],
            path: ".",
            sources: [
                "src/parser.c",
                // NOTE: if your language has an external scanner, add it here.
            ],
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterMtmlTests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterMtml",
            ],
            path: "bindings/swift/TreeSitterMtmlTests"
        )
    ],
    cLanguageStandard: .c11
)
