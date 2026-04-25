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

## Cocoa Importer Finding

The Cocoa image importer already uses native Cocoa image APIs.

Relevant file:

- `abi/src/wp/impexp/cocoa/ie_impGraphic_Cocoa.mm`

Observed native APIs:

- `NSImage`
- `NSImageRep`
- `NSBitmapImageRep`
- `NSPNGFileType`

The Cocoa importer accepts Cocoa-readable image data, converts it to PNG via `NSBitmapImageRep`, and then passes the resulting PNG byte buffer into AbiWord's raster graphic layer via `FG_GraphicRaster::setRaster_PNG()`.

## Interpretation

This is an important finding.

LeoWord does not need libpng to make Cocoa read common image formats. The old Cocoa importer already delegates image decoding and conversion to AppKit.

However, AbiWord's internal raster path still expects PNG data as a normalized intermediate format.

Therefore the goal is not to remove PNG as an internal format immediately.

The goal is to remove the bundled `png.framework` dependency where Leopard-native APIs can produce or inspect PNG data.

## Updated Decision

- Keep the existing Cocoa image importer.
- Prefer it for general image import on Leopard.
- Keep `png.framework` during restoration.
- Replace `ut_png.cpp` with ImageIO/CoreGraphics later if practical.
- Investigate whether `ie_impGraphic_PNG.*` can be superseded by the Cocoa importer or rewritten on top of ImageIO.
- Do not remove PNG support before testing embedded images, RTF image import/export, and image dimensions.

## Raster Path Result

`setRaster_PNG()` is called from a very small set of importer paths:

- Cocoa image importer
- Unix/GdkPixbuf image importer
- explicit PNG graphic importer

The broader scan shows that AbiWord uses `image/png` as an internal raster/embedded-graphic representation across several document import/export paths.

Important uses include:

- ABW embedded image import
- RTF image import/export
- XHTML/HTML image handling
- clipboard image MIME handling
- embedded object/image dimensions
- `UT_PNG_getDimensions()`

## Updated Interpretation

LeoWord should not remove PNG as an internal document/image representation.

The real target is the bundled `png.framework`, not PNG itself.

The preferred final architecture is:

- keep `image/png` as the internal raster interchange format
- keep `setRaster_PNG()` unless a larger graphic-layer refactor is justified
- replace direct libpng usage in `UT_PNG_getDimensions()` with ImageIO/CoreGraphics if practical
- use the existing Cocoa image importer as the native front-end for common image import

## Rule

PNG remains a retained V1 behavior.

The bundled `png.framework` remains only a temporary implementation dependency.

## FG_GraphicRaster Result

`FG_GraphicRaster` explicitly documents that its internal raster file format is PNG.

Relevant files:

- `abi/src/text/fmt/xp/fg_GraphicRaster.h`
- `abi/src/text/fmt/xp/fg_GraphicRaster.cpp`

`setRaster_PNG()` stores the PNG byte buffer, marks ownership, and then calls:

- `UT_PNG_getDimensions()`

This confirms that the main libpng dependency is not the document model itself, but the implementation used to inspect PNG data.

## Updated Architecture Decision

LeoWord should keep:

- `image/png` as the internal raster MIME type
- `FG_GraphicRaster`
- `setRaster_PNG()`
- existing document image semantics

LeoWord should replace:

- direct libpng usage inside `UT_PNG_getDimensions()`
- later, possibly the explicit PNG importer implementation

## Native Replacement Target

The cleanest first replacement target is:

- `UT_PNG_getDimensions()`

Potential Leopard-native implementation:

- `NSData`
- `CGImageSource`
- ImageIO
- CoreGraphics

## Rule

Do not refactor the document model to remove PNG.

Only replace the non-native PNG implementation layer.
