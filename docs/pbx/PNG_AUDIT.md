# LeoWord PNG Audit

## Purpose

This audit determines whether the old `png.framework` is essential for LeoWord V1 or can be replaced with Leopard-native ImageIO/CoreGraphics facilities.

## Initial Context

Mac OS X 10.5.8 provides ImageIO.framework.

On the target iMac G5 / Leopard system, ImageIO.framework links internally against:

- `libPng.dylib`

Therefore Leopard itself already provides PNG capability.

## Questions

The audit distinguishes between:

1. PNG use for application resources and toolbar icons.
2. PNG use for embedded document graphics.
3. PNG import filters.
4. PNG export filters.
5. CLI/windowless PNG conversion modes.
6. Thumbnail generation.

## LeoWord Interpretation

`png.framework` should not be kept merely because AbiWord 2.4.5 bundled it.

If PNG usage is limited to image import/export and toolbar/resource handling, LeoWord should investigate replacing it with:

- `NSImage`
- ImageIO
- CoreGraphics
- Quartz

## V1 Bias

- Restoration phase: `png.framework` may remain temporarily.
- Final V1: prefer ImageIO/CoreGraphics if practical.
- CLI `--to-png` and thumbnail modes may be deferred.
- Embedded document PNG support is more important than CLI PNG conversion.

## Rule

Do not keep a bundled PNG framework if Leopard-native image APIs can provide the retained V1 behavior.
