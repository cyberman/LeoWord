# LeoWord PNG Audit

## Finding

PNG support in AbiWord 2.4.5 is broader than a simple application-resource issue, but it is not part of the core text/layout engine in the same way as FriBidi.

Observed PNG-related areas:

- application and documentation PNG resources
- Cocoa bundle PNG resources, including cursors and small UI assets
- `ut_png.cpp`
- `ut_png.h`
- `ie_impGraphic_PNG.cpp`
- `ie_impGraphic_PNG.h`
- PNG graphic importer registration via `IE_ImpGraphicPNG_Sniffer`
- RTF/HTML/embedded graphics paths that include or rely on `ut_png`

## Interpretation

`png.framework` is not a text engine dependency.

It is primarily an image import/export and resource-handling dependency.

Mac OS X 10.5.8 already provides native PNG capability through ImageIO/CoreGraphics/NSImage, so a bundled `png.framework` should not be accepted permanently without justification.

## V1 Decision

- Restoration phase: keep `png.framework`.
- Early LeoWord V1: keep temporarily if required for stable embedded image handling.
- Final LeoWord V1: replace with native Leopard image APIs if practical.

## Replacement Boundary

The preferred replacement boundary is:

- `ut_png`
- `ie_impGraphic_PNG`
- Cocoa-specific graphic importer code

Possible native replacements:

- `NSImage`
- ImageIO
- CoreGraphics / Quartz

## Important Distinction

Many PNG files in the source tree are screenshots, documentation images, clipart, cursors, or bundle resources. These files do not by themselves justify a bundled libpng framework.

The dependency is justified only by active image import/export code.

## Rule

Do not remove PNG support before image insertion, embedded images, and RTF image paths are tested.

Do not keep `png.framework` permanently if Leopard-native ImageIO/CoreGraphics can provide the retained behavior.
