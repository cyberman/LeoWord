# LeoWord GLib / libgsf Audit

## Finding

The old AbiWord 2.4.5 Mac/PPC build links and bundles:

- `libglib-2.0.dylib`
- `libgmodule-2.0.dylib`
- `libgthread-2.0.dylib`
- `libgobject-2.0.dylib`
- `libgsf-1.1.dylib`

However, the initial source scan does not show `libgsf` as part of the normal Cocoa application core.

The observed `libgsf` references are mainly:

- PBX header search paths
- PBX linked/copied library entries
- `preparelibs.sh`
- OpenDocument-related target/build context

## OpenDocument Context

AbiWord 2.4.5 contains a separate OpenDocument plugin/target:

- `AbiOpenDocument`
- `AbiOpenDocument.so-abi`
- OpenDocument importer/exporter source files
- `.odt` and `.sxw` document type entries in the old Info.plist

## LeoWord Interpretation

`libgsf` appears to belong primarily to the OpenDocument / structured document plugin stack, not to the essential Cocoa editor core.

The GLib stack appears to be dragged in by old GNOME/Fink-era support libraries and plugin/import/export infrastructure.

## V1 Decision

LeoWord V1 should defer OpenDocument / StarWriter support.

Therefore the following dependencies should be treated as non-core for V1:

- `libgsf-1.1.dylib`
- `libglib-2.0.dylib`
- `libgobject-2.0.dylib`
- `libgmodule-2.0.dylib`
- `libgthread-2.0.dylib`

They may remain during restoration if required to reproduce the original build, but they should not be part of the final V1 runtime dependency set unless proven necessary.

## Info.plist Rule

LeoWord V1 must not register document types that it does not reliably support.

If OpenDocument support is deferred, V1 should not advertise `.odt` / `.sxw` as editable document types in its Info.plist.

## Rule

OpenDocument support is valuable, but not at the price of making V1 depend on the full GLib/libgsf stack.

Preserve a small, native Leopard application first.
Restore optional document stacks later.
