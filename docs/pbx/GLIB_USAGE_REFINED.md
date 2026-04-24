# LeoWord Refined GLib Usage Audit

## Finding

The broad `glib-usage.txt` scan is noisy because the search pattern `g_*` matches many unrelated identifiers.

After filtering for actual GLib/GModule/GObject-related usage, the relevant Cocoa-path findings are limited but real.

## Cocoa-path GLib usage

Relevant Cocoa files:

- `abi/src/af/xap/cocoa/xap_CocoaApp.mm`
  - includes `<glib.h>`

- `abi/src/af/xap/cocoa/xap_CocoaEncodingManager.mm`
  - includes `<glib.h>`
  - uses `GList`
  - uses `g_hash_table_lookup`
  - uses `g_i18n_get_language_list`

- `abi/src/af/xap/cocoa/xap_CocoaModule.mm`
  - includes `<glib.h>`
  - includes `<gmodule.h>`
  - uses `g_module_open`
  - uses `g_module_close`
  - uses `g_module_symbol`
  - uses `g_module_error`

## Interpretation

GLib is not only an OpenDocument/libgsf transitive dependency. The old Cocoa port uses GLib directly in a few localized Cocoa support components.

However, the usage appears limited and replaceable.

## Replacement Candidates

### xap_CocoaModule.mm

Likely plugin/module loading.

Possible native replacements:

- `CFBundle`
- `NSBundle`
- `dlopen` / `dlsym` / `dlclose`

LeoWord V1 may defer plugin loading entirely.

### xap_CocoaEncodingManager.mm

Likely encoding/language list support.

Possible native replacements:

- `NSArray`
- `NSDictionary`
- `NSLocale`
- CoreFoundation string/encoding APIs
- static encoding tables if sufficient

### xap_CocoaApp.mm

Needs detailed inspection to determine whether `<glib.h>` is actually required or historically included.

## V1 Decision

- Restoration phase: keep GLib temporarily if required for buildability.
- LeoWord V1 final: remove `gmodule`, `gobject`, `gthread`, and `libgsf` if their feature stacks are deferred.
- Keep plain `glib` only until the few Cocoa usage points are replaced.

## Rule

GLib is not accepted as a permanent dependency merely because the old Cocoa port used it.

Each GLib usage site must be either:

1. replaced with Leopard-native APIs,
2. isolated behind a LeoWord compatibility layer, or
3. explicitly justified for a retained V1 feature.
