# AbiWord 2.4.5 Library Relocation

## Finding

The original AbiWord 2.4.5 Mac/PPC build uses Fink as a build-time library depot.

The application build phase runs:

- `preparelibs.sh`
- `finishlibs.sh`

## preparelibs.sh

The script expects libraries in:

- `/sw/lib`

It copies selected dylibs into the build product directory and rewrites their install names to:

- `@executable_path/../Frameworks/<library>`

This indicates that the final app bundle was meant to carry its own runtime libraries.

## finishlibs.sh

The script scans the copied dylibs with `otool -L`, finds references to `/sw/lib`, and rewrites them with `install_name_tool -change` to:

- `@executable_path/../Frameworks`

It also creates compatibility symlinks for:

- `libglib-2.0.0.dylib`
- `libgobject-2.0.0.dylib`

## Important Constraint

The original script supports `FINK_DEPOT_DIR` as a copy source, but still checks file existence against the hardcoded `FINK_LIB_DIR=/sw/lib`.

Therefore, setting `FINK_DEPOT_DIR` alone is not enough if `/sw/lib` does not exist.

## LeoWord Interpretation

Fink should be treated as an old build depot assumption, not as a LeoWord runtime requirement.

LeoWord should eventually replace the hardcoded `/sw/lib` assumption with a configurable dependency depot, while preserving the original relocation strategy:

- copy required libraries into the app bundle
- set library IDs to `@executable_path/../Frameworks`
- rewrite internal dylib dependencies away from external absolute paths

## Rule

Do not modify the vendored AbiWord 2.4.5 scripts directly.

Any LeoWord-specific replacement should live under `tools/` or `leoword/`.
