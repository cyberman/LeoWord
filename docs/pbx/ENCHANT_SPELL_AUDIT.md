# LeoWord Enchant / Spellcheck Audit

## Purpose

This audit determines whether `enchant.framework` is required for LeoWord V1 or whether spellchecking can be moved to native Leopard/AppKit facilities.

## Leopard Native Context

Mac OS X 10.5.8 provides AppKit `NSSpellChecker`.

Previously confirmed on the target iMac G5 / Leopard system:

- `NSSpellChecker.h`
- `@interface NSSpellChecker`
- `checkSpellingOfString:startingAt:`
- `checkSpellingOfString:startingAt:language:wrap:inSpellDocumentWithTag:wordCount:`

## Finding

Direct Enchant usage is localized in:

- `abi/src/other/spell/xp/enchant_checker.cpp`

Observed Enchant API usage includes:

- `enchant_broker_init()`
- `enchant_broker_free()`
- `enchant_broker_request_dict()`
- `enchant_broker_free_dict()`
- `enchant_dict_check()`
- `enchant_dict_suggest()`
- `enchant_dict_free_suggestions()`
- `enchant_dict_add_to_personal()`
- `enchant_dict_is_in_session()`
- `enchant_dict_add_to_session()`
- `enchant_dict_store_replacement()`

## Cocoa Spellcheck Finding

No direct Cocoa `NSSpellChecker` integration was found in the old AbiWord 2.4.5 Cocoa path.

The Cocoa spell dialog exists, but it uses the cross-platform AbiWord spell dialog/backend path:

- `ap_CocoaDialog_Spell.h`
- `ap_CocoaDialog_Spell.mm`
- `ap_Dialog_Spell.cpp`
- `SpellChecker`
- `spell_manager`

## Interpretation

`enchant.framework` is not spread throughout the editor core.

It is localized behind AbiWord's spellchecking backend abstraction.

Spellchecking is a useful feature, but Enchant is not a native Leopard facility.

For LeoWord, this makes Enchant a good replacement candidate, not a permanent architectural dependency.

## V1 Decision

- Restoration phase: keep `enchant.framework` if required.
- Early LeoWord V1: spellchecking may remain Enchant-backed if that is the least invasive way to restore the app.
- Final LeoWord V1: prefer an `NSSpellChecker` backend if practical.
- If native spell integration is not ready, spellchecking may be deferred rather than making Enchant permanent.

## Replacement Boundary

The likely replacement boundary is the existing AbiWord spell abstraction:

- `SpellChecker`
- `spell_manager`
- `enchant_checker.cpp`

A LeoWord-native backend could provide the same expected spellcheck operations while internally using AppKit `NSSpellChecker`.

## Native Replacement Candidate

Potential native backend:

- `leoword/compat/spell/cocoa_spell_checker.mm`

It should adapt AbiWord's expected spellchecking behavior to:

- `NSSpellChecker`
- native dictionaries
- native suggestions
- native language handling where possible

## Rule

Do not keep `enchant.framework` permanently unless `NSSpellChecker` cannot support the retained LeoWord spellchecking behavior.

Enchant is allowed as a restoration dependency, not as a default final dependency.
