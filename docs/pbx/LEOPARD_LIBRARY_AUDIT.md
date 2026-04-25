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

## popt Check

`popt` is used by the AbiWord 2.4.5 argument parsing path, especially:

- `ap_Args.h`
- `ap_Args.cpp`
- `ap_App.cpp`
- `ap_CocoaApp.mm`

Initial conclusion:

- `popt.framework` may remain during restoration.
- It should not be part of the final dependency set if a small local compatibility shim is practical.
- For a native Cocoa application, a full external command-line parsing framework is not justified by default.

## popt Result

`popt` is used in AbiWord 2.4.5 for cross-platform command-line argument handling.

Observed files:

- `ap_Args.h`
- `ap_Args.cpp`
- `ap_App.cpp`
- `ap_CocoaApp.mm`

Initial conclusion:

- `popt.framework` may remain during restoration.
- It is not justified as a final LeoWord runtime dependency.
- A small local compatibility shim should be investigated.
- Native Cocoa/Finder document opening should eventually supersede command-line file handling for normal GUI use.

## popt Cocoa Startup Result

`AP_CocoaApp::main()` still calls `Args.parsePoptOpts()` and `Args.doWindowlessArgs(...)`.

However, `openCmdLineFiles(&Args)` is commented out and the Cocoa app unconditionally enters `[NSApp run]`.

Initial conclusion:

- `popt` is active for CLI/windowless option parsing.
- `popt` is not central to normal Cocoa GUI operation.
- For LeoWord V1, CLI conversion/plugin modes may be deferred.
- `popt.framework` should remain temporary and should be removed or replaced by a small compatibility shim before final V1 if practical.

## GLib / libgsf Result

The initial source and project scan indicates that `libgsf` is primarily tied to OpenDocument / structured document support and old plugin/import-export infrastructure.

Observed OpenDocument-related items include:

- `AbiOpenDocument`
- `AbiOpenDocument.so-abi`
- OpenDocument importer/exporter sources
- `.odt` / `.sxw` document type declarations in the old Info.plist

Initial conclusion:

- `libgsf` is not V1-core.
- OpenDocument / StarWriter support should be deferred from LeoWord V1.
- `glib`, `gobject`, `gmodule`, and `gthread` should be treated as restoration-only unless proven necessary.
- V1 Info.plist should not advertise `.odt` / `.sxw` support unless that stack is retained and tested.

## Refined GLib Result

The broad GLib scan was noisy, but real Cocoa-path GLib usage exists.

Important Cocoa files:

- `xap_CocoaApp.mm`
- `xap_CocoaEncodingManager.mm`
- `xap_CocoaModule.mm`

Observed direct GLib/GModule usage includes:

- `<glib.h>`
- `<gmodule.h>`
- `GList`
- `g_hash_table_lookup`
- `g_i18n_get_language_list`
- `g_module_open`
- `g_module_close`
- `g_module_symbol`
- `g_module_error`

Initial conclusion:

- GLib is not purely OpenDocument/libgsf baggage.
- The usage is localized and appears replaceable.
- GLib may remain during restoration.
- `gmodule` should be removed or replaced if plugin loading is deferred.
- `gobject`, `gthread`, and `libgsf` remain non-core unless proven otherwise.

## GLib Replacement Plan

The relevant Cocoa-path GLib usage is localized:

- `xap_CocoaApp.mm`: thread initialization
- `xap_CocoaModule.mm`: plugin/module loading
- `xap_CocoaEncodingManager.mm`: locale and encoding helper logic

Initial conclusion:

- GLib is not deeply embedded in the editor core.
- GLib may remain during restoration.
- Final LeoWord V1 should replace these localized usage points with Leopard-native facilities where practical.
- Plugin loading should be deferred from V1, allowing `gmodule` to be removed.

## Direct Cocoa GLib Symbol Result

Direct GLib/GObject/GModule/GThread usage in the Cocoa path is very limited.

Observed direct symbols:

- `g_thread_supported()`
- `g_thread_init(NULL)`
- `g_object_unref(model)`
- `g_module_open()`
- `g_module_error()`
- `g_module_close()`
- `g_module_symbol()`

Initial conclusion:

- GLib is localized, not core-wide.
- `gmodule` is plugin-related and should be deferred from V1.
- `gthread` should be removed or replaced if possible.
- `gobject` needs one targeted check in `xap_CocoaDlg_History.mm`.

## gobject Result

The only observed direct Cocoa-path `g_object_unref(model)` occurrence is inside a disabled `#if 0` block in `xap_CocoaDlg_History.mm`.

Initial conclusion:

- `libgobject` is not required by active Cocoa V1 code.
- It appears to be dead GTK-era residue in the Cocoa tree.
- `libgobject` should be removed from the final V1 dependency set unless another active reference is found.

## wv / DOC Import Check

`wv.framework` is linked and bundled by the old AbiWord 2.4.5 app target.

Initial conclusion:

- `wv.framework` appears tied to classic Microsoft Word `.doc` import.
- `.doc` import is useful but not mandatory for LeoWord V1.
- RTF should be prioritized before binary `.doc`.
- If `.doc` import is deferred, LeoWord V1 must not advertise `.doc` as a fully supported editable document type.

## wv / DOC Import Result

`wv.framework` is primarily tied to classic Microsoft Word `.doc` import via `ie_imp_MsWord_97`.

The old source also uses `wv.h` in RTF import/export for language/codepage helper functions.

Initial conclusion:

- DOC import should be deferred from LeoWord V1.
- RTF remains V1-relevant.
- The large `wv` parser stack should not be a final V1 dependency unless required.
- If RTF only needs small LID/codepage helpers, those should be shimmed or extracted rather than keeping the whole Word parser.

## wv / DOC Import Result

`wv.framework` is primarily tied to classic Microsoft Word `.doc` import via `ie_imp_MsWord_97`.

The old source also uses `wv.h` in RTF import/export for language/codepage helper functions.

Initial conclusion:

- DOC import should be deferred from LeoWord V1.
- RTF remains V1-relevant.
- The large `wv` parser stack should not be a final V1 dependency unless required.
- If RTF only needs small LID/codepage helpers, those should be shimmed or extracted rather than keeping the whole Word parser.

## wv / DOC Import Result

`wv.framework` is primarily tied to classic Microsoft Word `.doc` import via `ie_imp_MsWord_97`.

The old source also uses `wv.h` in RTF import/export for language/codepage helper functions.

Initial conclusion:

- DOC import should be deferred from LeoWord V1.
- RTF remains V1-relevant.
- The large `wv` parser stack should not be a final V1 dependency unless required.
- If RTF only needs small LID/codepage helpers, those should be shimmed or extracted rather than keeping the whole Word parser.

## RTF / wv Symbol Result

RTF import/export uses only three `wv` helper functions:

- `wvLIDToLangConverter()`
- `wvLIDToCodePageConverter()`
- `wvLangToLIDConverter()`

Initial conclusion:

- `wv.framework` is not justified for final V1 solely to support RTF.
- The large DOC parser stack should be deferred.
- A small local RTF language/codepage compatibility layer should replace the required `wv` helper functions.

## FriBidi Check

`fribidi.framework` is linked and bundled by the old AbiWord 2.4.5 app target.

Initial conclusion:

- Bidirectional text support is a real layout feature.
- It may be deferred from LeoWord V1 if necessary.
- The Cocoa port reports `BIDI_SUPPORT_FULL`, so the relationship between AbiWord's internal bidi logic and Leopard-native text behavior must be verified.

## FriBidi Result

`fribidi.framework` is an active text/layout dependency.

The Cocoa port reports `BIDI_SUPPORT_FULL`, but AbiWord's own utility layer still defines and implements bidi helpers through FriBidi-backed abstractions:

- `UT_BidiCharType`
- `UT_BIDI_*`
- `UT_bidiGetCharType()`
- `UT_bidiReorderString()`
- `UT_bidiMapLog2Vis()`
- `UT_bidiGetMirrorChar()`

Initial conclusion:

- FriBidi should remain during restoration.
- FriBidi should likely remain in LeoWord V1.
- Any replacement must preserve the `UT_bidi*` API boundary.
- Removal should be deferred until after a working native V1 exists.

## PNG Check

Leopard provides ImageIO.framework, and ImageIO links internally against `libPng.dylib`.

Initial conclusion:

- `png.framework` is suspicious as a final LeoWord V1 dependency.
- It may remain during restoration.
- Final V1 should prefer `NSImage`, ImageIO, CoreGraphics, or Quartz for PNG handling if practical.
- CLI PNG conversion and thumbnail generation may be deferred.

## PNG Result

`png.framework` is not an editor text-core dependency, but it is involved in image import/export and embedded graphics support.

Relevant active areas include:

- `ut_png.cpp`
- `ut_png.h`
- `ie_impGraphic_PNG.cpp`
- `ie_impGraphic_PNG.h`
- PNG graphic importer registration
- RTF/HTML/embedded graphics paths

Initial conclusion:

- `png.framework` may remain during restoration and early V1.
- It should be treated as a replacement candidate, not a permanent dependency.
- Final LeoWord should prefer ImageIO/CoreGraphics/NSImage if practical.
- Image insertion and RTF image behavior must be tested before removing it.

## PNG Cocoa Importer Result

The Cocoa image importer already uses native AppKit image APIs:

- `NSImage`
- `NSImageRep`
- `NSBitmapImageRep`
- `NSPNGFileType`

It converts Cocoa-readable image formats into PNG byte buffers and then feeds them into `FG_GraphicRaster::setRaster_PNG()`.

Initial conclusion:

- Cocoa already provides the preferred image import front-end.
- AbiWord still uses PNG as an internal raster interchange format.
- `png.framework` remains acceptable during restoration.
- Final LeoWord should investigate replacing direct libpng usage in `ut_png.cpp` and `ie_impGraphic_PNG.*` with ImageIO/CoreGraphics.
