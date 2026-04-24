# Leopard Native First Policy

LeoWord targets Mac OS X 10.5.8 PowerPC.

The system has absolute primacy.

## Principle

Every additional byte must justify its existence.

If Mac OS X 10.5.8 provides a suitable native facility, LeoWord must prefer it over bundled third-party code.

## Restoration vs. Final Architecture

AbiWord 2.4.5 Mac/PPC is the restoration baseline.

However, the original AbiWord build environment bundled several Fink-era libraries into the application bundle. This was useful for distribution in its historical context, but it is not automatically acceptable for LeoWord.

LeoWord may temporarily reproduce the old dependency set for restoration purposes, but the final architecture should be reduced toward native Leopard facilities wherever practical.

## Preferred Native Facilities

Prefer Leopard-native components for:

- application lifecycle: Cocoa/AppKit
- windows, menus, panels, sheets: Cocoa/AppKit
- document handling: NSDocument-style behavior where practical
- printing and PDF output: Cocoa/Quartz printing pipeline
- images: Cocoa, Quartz, ImageIO where practical
- fonts and text UI: AppKit/Core Text/ATS facilities where practical
- compression: system zlib and bzip2 where ABI-compatible
- XML: system libxml2 where ABI-compatible
- character conversion: system iconv where ABI-compatible

## Dependency Classes

### System

Use from the operating system if available and ABI-compatible.

Examples:

- Cocoa.framework
- /usr/lib/libz.1.dylib
- /usr/lib/libxml2.2.dylib
- /usr/lib/libiconv.2.dylib
- system bzip2 library if suitable

### Temporary Build Depot

May be used during restoration, but must not become a hard runtime dependency.

Examples:

- MacPorts
- Fink-style library depots
- local dependency staging directories

### Bundled Only If Justified

May be copied into the app bundle only if there is no suitable Leopard-native alternative or if the dependency is essential for a retained feature.

Examples:

- wv for legacy DOC import
- enchant for spellchecking
- fribidi for bidirectional text
- popt if command-line parsing cannot be trivially replaced
- libgsf if OpenDocument/SXW support is retained
- glib/gobject/gmodule/gthread only if unavoidable

### Deferred / Removable

Features that drag in large dependency trees may be deferred from V1.

Examples:

- OpenDocument plugin stack
- WordPerfect plugin
- Google/Wikipedia plugins
- MathView
- LaTeX plugin
- exotic import/export filters

## V1 Bias

LeoWord V1 should aim for:

- native Cocoa app startup
- native menu/window/frame path
- basic editing
- ABW support
- TXT support
- RTF support if dependency-light
- printing through Leopard facilities

V1 should not aim for full AbiWord feature parity.

## Rule

Do not preserve a dependency merely because AbiWord 2.4.5 used it.

Preserve behavior first, dependencies last.
