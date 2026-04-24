# LeoWord RTF / wv Symbol Audit

## Finding

RTF import/export includes `wv.h`, but only uses a very small subset of `wv` functionality.

Observed symbols:

- `wvLIDToLangConverter()`
- `wvLIDToCodePageConverter()`
- `wvLangToLIDConverter()`

## Import Path

`ie_imp_RTF.cpp` uses:

- `wvLIDToLangConverter()`

This maps RTF language IDs to language strings.

## Export Path

`ie_exp_RTF.cpp` uses:

- `wvLIDToCodePageConverter()`
- `wvLangToLIDConverter()`

This maps language strings and language IDs for RTF output.

## Interpretation

RTF support does not require the full `wv` parser stack.

The large `wv.framework` is mainly needed for classic Microsoft Word `.doc` import.

## LeoWord V1 Decision

- Keep RTF as V1-relevant.
- Defer `.doc` import from final V1.
- Replace or shim the three small `wv` language/codepage helpers.
- Do not keep the full `wv.framework` solely for these helper functions.

## Potential Replacement

Create a small LeoWord-local compatibility unit, for example:

- `leoword/compat/wv_lid/`

It should provide only:

- `wvLIDToLangConverter()`
- `wvLIDToCodePageConverter()`
- `wvLangToLIDConverter()`

The implementation can be table-based and limited to the mappings needed by AbiWord's RTF import/export path.

## Rule

Do not keep a full binary Word parser dependency to support three RTF language/codepage helper functions.
