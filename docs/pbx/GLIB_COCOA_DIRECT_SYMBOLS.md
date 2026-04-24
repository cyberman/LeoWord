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

## History Dialog gobject Check

The only direct Cocoa-path `g_object_unref(model)` hit is located in:

- `abi/src/af/xap/cocoa/xap_CocoaDlg_History.mm`

The call is inside a disabled `#if 0` block containing old GTK TreeView code.

Conclusion:

- This is dead GTK-era code.
- It does not justify linking or bundling `libgobject` for LeoWord V1.
- `libgobject` should be treated as non-core and removable unless another active reference is found.
