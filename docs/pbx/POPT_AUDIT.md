# LeoWord popt Audit

## Finding

AbiWord 2.4.5 uses `popt` for cross-platform command-line argument handling.

Relevant files:

- `abi/src/wp/ap/xp/ap_Args.h`
- `abi/src/wp/ap/xp/ap_Args.cpp`
- `abi/src/wp/ap/xp/ap_App.cpp`
- `abi/src/wp/ap/cocoa/ap_CocoaApp.mm`

The old Cocoa app target links and bundles `popt.framework`.

## Used API Surface

Observed API surface:

- `poptContext`
- `struct poptOption`
- `poptGetContext`
- `poptGetNextOpt`
- `poptGetArg`
- `poptBadOption`
- `poptStrerror`
- `poptPrintHelp`
- `poptFreeContext`

## Cocoa Observation

The Cocoa startup path contains this notable logic:

`if (true) // really don't want to be opening files atm anyway`

followed by `[NSApp run]`.

This suggests that classic command-line file opening was already not central to the Cocoa port.

## LeoWord Interpretation

`popt` is not a native Leopard facility.

For a native Cocoa application, a full external command-line parsing framework is not justified by default.

## V1 Decision

- Restoration phase: `popt.framework` may remain temporarily.
- LeoWord V1: replace with a small compatibility shim if practical.
- Final goal: remove external `popt.framework`.

## Replacement Strategy

A minimal LeoWord-local compatibility layer should implement only the subset of `popt` used by AbiWord 2.4.5.

Possible location:

- `leoword/compat/popt/`

The implementation should use:

- plain `argc` / `argv`
- possibly `NSProcessInfo`
- no external runtime dependency

## V1-Relevant Arguments

Likely V1-relevant:

- `--version`
- `--help`
- positional filenames, if Finder/NSDocument integration does not cover them yet

Likely deferrable:

- conversion modes
- PNG export mode
- plugin execution mode
- mail merge options
- print-to-file CLI mode
- debug-only options

## Rule

`popt.framework` is allowed only as a temporary restoration dependency.

## Cocoa Startup Path Check

`AP_CocoaApp::main()` still constructs `AP_Args` and calls:

- `Args.parsePoptOpts()`
- `Args.doWindowlessArgs(...)`

However, normal command-line file opening is disabled in the Cocoa startup path:

- `pMyCocoaApp->openCmdLineFiles(&Args)` is commented out
- the application unconditionally enters `[NSApp run]`

This means `popt` remains active for option parsing and windowless/CLI modes, but it is not central to normal Cocoa GUI document opening.

## Updated Decision

`popt.framework` is not part of the native Cocoa application core.

For LeoWord V1, `popt` should be treated as:

- acceptable during restoration
- replaceable before final V1
- removable if windowless conversion/plugin modes are deferred

A small compatibility shim is likely sufficient if the old `AP_Args` structure must be preserved temporarily.
