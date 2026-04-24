# LeoWord wv / DOC Import Audit

## Purpose

This audit tracks whether `wv.framework` is part of LeoWord's essential V1 editor core or only required for legacy Microsoft Word `.doc` import.

## Initial Finding

The old AbiWord 2.4.5 Mac/PPC app target links and bundles `wv.framework`.

The source set contains `ie_imp_MsWord_97.cpp`, which indicates classic binary Microsoft Word document import support.

## LeoWord Interpretation

Classic `.doc` import is useful, but it is not part of the minimal native Leopard writing core.

LeoWord V1 should prioritize:

- native Cocoa startup
- ABW open/save
- TXT open/save
- RTF open/save
- native printing/PDF path

`.doc` support may be deferred to V1.1 or restored as an optional import module.

## V1 Decision

- Restoration phase: `wv.framework` may remain temporarily.
- Final V1: defer `.doc` import unless `wv.framework` proves trivial and dependency-light.
- If `.doc` is deferred, LeoWord V1 must not advertise `.doc` as a fully supported editable document type in Info.plist.

## Rule

`wv.framework` is not kept merely because AbiWord 2.4.5 used it.

It must justify itself by providing a retained V1 feature without dragging in avoidable non-native dependencies.
