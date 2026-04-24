# LeoWord Direct Cocoa GLib Symbol Audit

## Finding

Direct GLib/GObject/GModule/GThread usage in the Cocoa code path is very limited.

Observed direct Cocoa-path symbols:

- `xap_CocoaApp.mm`
  - `g_thread_supported()`
  - `g_thread_init(NULL)`

- `xap_CocoaDlg_History.mm`
  - `g_object_unref(model)`

- `xap_CocoaModule.mm`
  - `g_module_open()`
  - `g_module_error()`
  - `g_module_close()`
  - `g_module_symbol()`

## Interpretation

GLib is not broadly embedded in the Cocoa editor core.

The usage appears isolated into:

1. Thread initialization.
2. Plugin/module loading.
3. One History dialog cleanup call.

## V1 Decision

- `gthread` should be removable or replaceable.
- `gmodule` belongs to plugin loading and should be deferred from V1.
- `gobject` has only one visible Cocoa-path hit and should be investigated in `xap_CocoaDlg_History.mm`.
- GLib may remain temporarily for restoration, but the direct Cocoa usage does not justify a permanent LeoWord V1 dependency.
