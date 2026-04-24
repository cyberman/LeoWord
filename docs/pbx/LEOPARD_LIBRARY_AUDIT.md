# LeoWord Leopard Library Audit

LeoWord targets Mac OS X 10.5.8 PowerPC.

The old AbiWord 2.4.5 Mac/PPC build links and bundles several Fink-era libraries. LeoWord must not preserve those dependencies blindly. Every dependency must justify its existence.

## Source Evidence

The AbiWord 2.4.5 application target links or bundles:

- `Cocoa.framework`
- `/usr/lib/libz.1.dylib`
- `png.framework`
- `wv.framework`
- `enchant.framework`
- `fribidi.framework`
- `popt.framework`
- `libglib-2.0.dylib`
- `libgmodule-2.0.dylib`
- `libgthread-2.0.dylib`
- `libgobject-2.0.dylib`
- `libiconv.2.dylib`
- `libintl.1.dylib`
- `libxml2.2.dylib`
- `libgsf-1.1.dylib`

The original build scripts copy selected dylibs from `/sw/lib` and rewrite them to `@executable_path/../Frameworks`.

## Audit Table

| Library / Framework | Old Role | Leopard Native Candidate | V1 Status | Notes |
|---|---|---|---|---|
| `Cocoa.framework` | Native UI, app lifecycle | Yes | Keep system | Core requirement. Must remain native. |
| `/usr/lib/libz.1.dylib` | Compression | Yes | Keep system | Already linked from `/usr/lib` in old target. Do not bundle. |
| `libxml2.2.dylib` | XML parsing | Likely yes | Prefer system | Check ABI on Leopard. Bundle only if system version is insufficient. |
| `libiconv.2.dylib` | Character conversion | Likely yes | Prefer system | Check ABI on Leopard. Avoid bundled duplicate if compatible. |
| `libbz2.1.dylib` | bzip2 compression | Likely yes | Prefer system | Check availability on Leopard. Bundle only if absent or incompatible. |
| `png.framework` | PNG image handling | ImageIO/CoreGraphics candidate | Temporary | For restoration keep; later replace if Cocoa/ImageIO path is practical. |
| `wv.framework` | Legacy `.doc` import | No native equivalent | Defer / optional | Keep only if DOC import is V1-relevant. Otherwise plugin/deferred. |
| `enchant.framework` | Spellchecking | NSSpellChecker candidate | Replace candidate | Strong candidate for native Leopard replacement. |
| `fribidi.framework` | Bidirectional text | Partial native text stack candidate | Temporary | Keep only if required for retained bidi behavior. |
| `popt.framework` | Command-line option parsing | Trivial native replacement | Remove candidate | Likely replace with small local parser or Cocoa argument handling. |
| `libglib-2.0.dylib` | Utility/runtime dependency | No | Temporary / remove | Large dependency. Keep only if unavoidable during restoration. |
| `libgobject-2.0.dylib` | Object system dependency | No | Temporary / remove | Likely dragged in by libgsf/plugins. Avoid in final V1 if possible. |
| `libgmodule-2.0.dylib` | Dynamic module support | Native CFBundle/NSBundle candidate | Remove candidate | Strong candidate for native replacement or plugin deferral. |
| `libgthread-2.0.dylib` | Thread abstraction | pthread/NSThread candidate | Remove candidate | Avoid unless old code requires it directly. |
| `libintl.1.dylib` | gettext localization | NSBundle/.lproj candidate | Remove candidate | Prefer native `.lproj` localization. |
| `libgsf-1.1.dylib` | Structured file formats, ODF/SXW | No direct native equivalent | Defer | Likely needed for OpenDocument/StarWriter stack. Not V1-essential. |

## V1 Dependency Bias

LeoWord V1 should attempt to run with the smallest practical set:

### Keep

- `Cocoa.framework`
- `/usr/lib/libz.1.dylib`
- system `libxml2.2.dylib`, if ABI-compatible
- system `libiconv.2.dylib`, if ABI-compatible
- system bzip2, if available and compatible

### Temporarily Accept During Restoration

- `png.framework`
- `wv.framework`
- `enchant.framework`
- `fribidi.framework`
- `popt.framework`
- `glib` stack
- `libgsf`
- `libintl`

### Remove or Replace Before Final V1 If Practical

- `popt.framework`
- `libintl.1.dylib`
- `libgmodule-2.0.dylib`
- `libgthread-2.0.dylib`
- `enchant.framework`
- `png.framework`

### Defer Feature Stacks

- OpenDocument support
- StarWriter support
- WordPerfect support
- Wikipedia/Google plugins
- MathView
- LaTeX plugin

## Rule

A dependency may remain only if at least one of the following is true:

1. Leopard does not provide a suitable native equivalent.
2. Removing it would break a V1 feature.
3. It is temporarily required to reproduce the original build before refactoring.
4. It is isolated as an optional plugin dependency.

No dependency is kept merely because AbiWord 2.4.5 used it.

## Leopard 10.5.8 System Library Check - bzip2

Checked on the target iMac G5 / Mac OS X 10.5.8 PowerPC.

Confirmed system bzip2 libraries:

- `/usr/lib/libbz2.1.0.4.dylib`
- `/usr/lib/libbz2.1.0.5.dylib`
- `/usr/lib/libbz2.1.0.dylib -> libbz2.1.0.5.dylib`
- `/usr/lib/libbz2.dylib -> libbz2.1.0.5.dylib`

`otool -L /usr/lib/libbz2.1.0.dylib` reports:

- compatibility version: `1.0.0`
- current version: `1.0.5`

Initial conclusion:

- bzip2 should prefer the Leopard system library.
- Bundling `libbz2` from Fink/MacPorts is not justified by default.
- The old AbiWord build references `libbz2.1.dylib`; Leopard provides `libbz2.1.0.dylib` and `libbz2.dylib`, so the final build must verify linker and install-name behavior.

## Leopard Native Replacement Check - Spellchecking, PNG, Localization

Checked on the target iMac G5 / Mac OS X 10.5.8 PowerPC.

### NSSpellChecker

Confirmed:

- `/System/Library/Frameworks/AppKit.framework/Headers/NSSpellChecker.h`
- `@interface NSSpellChecker`
- `checkSpellingOfString:startingAt:`
- `checkSpellingOfString:startingAt:language:wrap:inSpellDocumentWithTag:wordCount:`

Initial conclusion:

- `enchant.framework` should be treated as a temporary restoration dependency.
- Final LeoWord should prefer AppKit `NSSpellChecker` for native spellchecking if practical.

### ImageIO / PNG

Confirmed:

- `ImageIO.framework` exists under `ApplicationServices.framework`
- ImageIO links internally against `libPng.dylib`

Initial conclusion:

- `png.framework` should be treated as a temporary restoration dependency.
- Final LeoWord should investigate replacing direct PNG handling with ImageIO/CoreGraphics where practical.

### libintl / gettext

Confirmed:

- no `/usr/lib/libintl*` on the target system
- `NSBundle.h` exists
- `localizedStringForKey:value:table:` exists

Initial conclusion:

- `libintl` should not be introduced merely for UI localization.
- Final LeoWord should prefer native `.lproj` and `NSBundle` localization.
