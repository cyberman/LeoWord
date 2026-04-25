# LeoWord FriBidi Audit

## Finding

`fribidi.framework` is substantially different from other audited dependencies.

It is not merely tied to an optional importer or UI convenience feature. AbiWord's internal utility and layout code uses FriBidi through the `UT_bidi*` abstraction layer.

Observed core abstractions include:

- `UT_BidiCharType`
- `UT_BIDI_*` macros
- `UT_bidiGetCharType()`
- `UT_bidiReorderString()`
- `UT_bidiMapLog2Vis()`
- `UT_bidiGetMirrorChar()`

These are backed by FriBidi symbols such as:

- `fribidi_get_type()`
- `fribidi_log2vis()`
- `fribidi_get_mirror_char()`

## Cocoa Context

The Cocoa port reports:

- `theOSHasBidiSupport()`
- `BIDI_SUPPORT_FULL`

However, LeoWord does not simply delegate all text layout to `NSTextView`. AbiWord has its own document model and layout/rendering machinery.

Therefore, native OS bidi support does not automatically eliminate the need for AbiWord's internal bidi classification and reordering helpers.

## V1 Decision

`fribidi.framework` should be kept for restoration and likely for LeoWord V1.

It is a justified dependency until a safe compatibility replacement exists.

## Future Replacement Strategy

Any future replacement must happen behind the existing `UT_bidi*` boundary.

Possible approach:

1. Keep the `UT_bidi*` API stable.
2. Replace the implementation only after V1.
3. Investigate whether Leopard/CoreFoundation/AppKit can provide equivalent character classification, logical-to-visual mapping, and mirror character handling.
4. If not, keep FriBidi as a compact justified dependency.

## Rule

Do not remove FriBidi merely for dependency purity.

Unlike `popt`, `libintl`, `wv`, `libgsf`, or `gmodule`, FriBidi is tied to active text/layout semantics.
