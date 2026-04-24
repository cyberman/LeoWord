# LeoWord popt Audit

## Finding

AbiWord 2.4.5 uses `popt` in its cross-platform application argument handling.

Relevant files include:

- `abi/src/wp/ap/xp/ap_Args.h`
- `abi/src/wp/ap/xp/ap_Args.cpp`
- `abi/src/wp/ap/xp/ap_App.cpp`
- `abi/src/wp/ap/cocoa/ap_CocoaApp.mm`

The old Cocoa app target links and bundles `popt.framework`.

## Used API Surface

The observed API surface appears to include:

- `struct poptOption`
- `poptContext`
- `poptGetContext`
- `poptGetNextOpt`
- `poptGetArg`
- `poptBadOption`
- `poptStrerror`
- `poptPrintHelp`
- `poptFreeContext`

## LeoWord Interpretation

`popt` is not a native Leopard facility and should not be preserved merely because AbiWord 2.4.5 used it.

However, it is wired into AbiWord's existing argument parsing path, so removing it immediately would be invasive.

## V1 Decision

- Restoration phase: keep `popt.framework` temporarily.
- Final LeoWord V1: replace with a small local compatibility layer if practical.

## Replacement Strategy

Create a minimal LeoWord-local parser or compatibility shim that implements only the subset of `popt` used by AbiWord 2.4.5.

Possible implementation locations:

- `leoword/compat/popt/`
- `tools/compat/popt/`
- later: direct simplification of `ap_Args`

The replacement should prefer:

- plain `argc` / `argv`
- `NSProcessInfo` where useful
- no external runtime dependency

## Rule

`popt.framework` is allowed only as a temporary restoration dependency.
