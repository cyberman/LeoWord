# LeoWord GLib Replacement Plan

## Finding

GLib is used in the old AbiWord 2.4.5 Cocoa path, but the usage appears localized.

Relevant files:

- `abi/src/af/xap/cocoa/xap_CocoaApp.mm`
- `abi/src/af/xap/cocoa/xap_CocoaModule.mm`
- `abi/src/af/xap/cocoa/xap_CocoaEncodingManager.mm`

## Usage Classes

### 1. Thread Initialization

File:

- `xap_CocoaApp.mm`

Observed usage:

- `g_thread_supported()`
- `g_thread_init(NULL)`

LeoWord interpretation:

This is not enough to justify a permanent GLib runtime dependency.

Potential replacement:

- remove if unnecessary on Leopard
- use native pthread/NSThread assumptions if needed

### 2. Plugin / Module Loading

File:

- `xap_CocoaModule.mm`

Observed usage:

- `g_module_open()`
- `g_module_close()`
- `g_module_symbol()`
- `g_module_error()`

LeoWord interpretation:

This belongs to the old AbiWord plugin system.

Potential replacement:

- defer plugin loading for V1
- later replace with `NSBundle`, `CFBundle`, or `dlopen` / `dlsym`

### 3. Locale / Encoding Helper Logic

File:

- `xap_CocoaEncodingManager.mm`

Observed usage:

- `GList`
- `GHashTable`
- `g_hash_table_lookup()`
- `g_hash_table_insert()`
- `g_malloc()`
- `g_free()`
- `g_strdup()`
- `g_strstrip()`
- `g_strconcat()`
- `g_getenv()`
- `g_warning()`
- `g_i18n_get_language_list()`

LeoWord interpretation:

This is GNOME/gettext-style locale discovery logic embedded in the Cocoa port.

Potential replacement:

- `NSLocale`
- `NSBundle` localization APIs
- CoreFoundation locale/string encoding APIs
- small LeoWord-local fallback table if needed

## V1 Decision

GLib may remain during restoration if required for a first successful build.

Final LeoWord V1 should not depend on GLib unless one of these localized usage sites cannot be replaced safely.

## Replacement Order

1. Defer plugin loading and remove `gmodule`.
2. Remove or replace `g_thread_supported()` / `g_thread_init()`.
3. Replace `xap_CocoaEncodingManager.mm` GLib logic with Leopard-native locale/encoding logic.
4. Remove `gobject` and `gthread` if no direct references remain.
5. Remove GLib from the final app bundle.
