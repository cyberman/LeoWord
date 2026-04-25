# LeoWord Expat / XML Audit

## Purpose

This audit determines whether the bundled `expat.framework` is required for LeoWord V1 or whether XML parsing can use a Leopard-provided system library.

## Initial Interpretation

XML support is core for LeoWord because AbiWord's native ABW format is XML-based.

Therefore the question is not whether XML support can be removed.

The question is whether LeoWord needs the old bundled `expat.framework`.

## V1 Decision Bias

- XML parsing is V1-core.
- ABW support is V1-core.
- The bundled `expat.framework` should be treated as suspicious if Mac OS X 10.5.8 already provides a compatible system Expat.
- If system Expat is available and ABI-compatible enough, prefer the system library.
- If not, retain Expat as a justified minimal dependency.

## Rule

Do not remove XML support.

Only remove or replace the bundled Expat framework if LeoWord can still parse and write ABW reliably.
