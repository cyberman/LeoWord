# LeoWord FriBidi Audit

## Purpose

This audit determines whether `fribidi.framework` is essential for LeoWord V1 or whether bidirectional text support can be deferred or delegated to Leopard-native text facilities.

## Initial Context

The old AbiWord 2.4.5 Mac/PPC app target links and bundles `fribidi.framework`.

The Cocoa app layer reports OS bidi support via:

- `theOSHasBidiSupport()`
- `BIDI_SUPPORT_FULL`

## LeoWord Interpretation

Bidirectional text support is a real text-layout feature, not mere historical baggage.

However, LeoWord V1 should prioritize a small, stable, native Leopard writing core. Full bidi support may be deferred if it requires retaining a non-native dependency stack.

## V1 Decision Bias

- Restoration phase: `fribidi.framework` may remain temporarily.
- Final V1: remove or defer `fribidi.framework` if bidi support is not part of V1 scope.
- If retained, it must be justified as essential to active retained layout behavior.

## Native Candidate

Leopard text systems may provide bidi behavior through native Cocoa/Core Text/AppKit text handling, but AbiWord's own layout engine may not automatically benefit from that unless integrated.

Therefore this requires code-level verification.

## Rule

Do not keep `fribidi.framework` merely because AbiWord 2.4.5 linked it.

Keep it only if active V1 text layout requires it and no native replacement is practical.
