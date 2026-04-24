# LeoWord wv / DOC Import Audit

## Finding

AbiWord 2.4.5 uses `wv` primarily for classic Microsoft Word `.doc` import.

Relevant files:

- `abi/src/wp/impexp/xp/ie_imp_MsWord_97.cpp`
- `abi/src/wp/impexp/xp/ie_imp_MsWord_97.h`
- `pbx/wvpbx/`
- `pbx/wvpbx/wv.exports`

The importer includes:

- `#include "wv.h"`
- `wvParseStruct`
- `wvInitParser()`
- `wvText()`
- many `wvGet*` and `wvStream*` functions

The impexp README identifies `IE_Imp_MsWord_97` as importing MS Word 97 documents using `libwv`.

## Interpretation

`wv.framework` is not part of the essential editor core.

It is mainly legacy binary Microsoft Word `.doc` import infrastructure.

## RTF Caveat

RTF code also includes `wv.h` for helper conversion functions such as:

- `wvLIDToLangConverter`
- `wvLIDToCodePageConverter`

Therefore LeoWord should not blindly delete all `wv` references before checking the RTF path.

## V1 Decision

- `.doc` import is useful but not V1-critical.
- LeoWord V1 should prioritize ABW, TXT, and RTF.
- The large `wv` parser stack should be deferred from final V1 if possible.
- Small `wv` language/codepage helper logic may be replaced, shimmed, or locally extracted if required by RTF support.

## Info.plist Rule

If `.doc` import is deferred, LeoWord V1 must not advertise `.doc` / `.dot` as fully supported editable document types.

## Rule

`wv.framework` is allowed during restoration.

Final LeoWord V1 should keep only the minimum required functionality needed for retained V1 formats.
