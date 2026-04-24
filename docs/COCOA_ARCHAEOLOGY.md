# LeoWord Cocoa Archaeology

## Finding

AbiWord 2.4.5 contains a substantial native Cocoa/Mac OS X port.

This is not a GTK-only application tree. The 2.4.5 source contains Cocoa-specific code for:

- application startup
- main menu
- bundle Info.plist
- app/frame/window integration
- keyboard and mouse events
- menus and toolbars
- graphics and image handling
- clipboard integration
- native dialogs
- import/export registration
- PBX/Project Builder era project files

## Key 2.4.5 Locations

- `vendor/abiword-2.4.5/abi/docs/MacPort_Documentation.abw`
- `vendor/abiword-2.4.5/abi/src/af/ev/cocoa`
- `vendor/abiword-2.4.5/abi/src/af/gr/cocoa`
- `vendor/abiword-2.4.5/abi/src/af/xap/cocoa`
- `vendor/abiword-2.4.5/abi/src/wp/ap/cocoa`
- `vendor/abiword-2.4.5/abi/src/wp/impexp/cocoa`
- `vendor/abiword-2.4.5/abi/src/wp/main/cocoa`
- `vendor/abiword-2.4.5/abi/src/wp/main/cocoa/CocoaMain.mm`
- `vendor/abiword-2.4.5/abi/src/wp/main/cocoa/MainMenu.nib`
- `vendor/abiword-2.4.5/abi/src/wp/main/cocoa/bundle/Info.plist`
- `vendor/abiword-2.4.5/abipbx/abipbx2.pbproj`
- `vendor/abiword-2.4.5/pbx`

## Interpretation

LeoWord should be treated as a restoration of the existing AbiWord Cocoa/Mac port, not as a new Cocoa frontend written from scratch.

AbiWord 2.4.5 remains the baseline.

AbiWord 2.8.6 and current AbiWord are useful as controlled diff sources only.
