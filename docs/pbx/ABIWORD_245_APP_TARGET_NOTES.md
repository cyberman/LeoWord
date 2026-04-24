# AbiWord 2.4.5 Application Target Notes

## Target

The AbiWord 2.4.5 PBX project contains one native application target:

- Target name: `AbiWord`
- Product type: `com.apple.product-type.application`
- Product name: `AbiWord`
- Wrapper extension: `app`
- Deployment target: `10.2`

## Platform Defines

The application target is explicitly configured for the old Mac/Cocoa port:

- `XP_TARGET_COCOA`
- `XP_MAC_TARGET_MACOSX`
- `XP_MAC_TARGET_QUARTZ`
- `WORDS_BIGENDIAN=1`
- `ABIWORD_APP_NAME="AbiWord"`
- `ABI_BUILD_VERSION="2.4.5"`

This confirms that the 2.4.5 source tree contains a real native Cocoa/Mac OS X application target, not only generic cross-platform code.

## Legacy Dependency Assumptions

The application target expects old framework and Fink-style include paths:

- `$(BUILD_DIR)/png.framework/Headers`
- `$(BUILD_DIR)/enchant.framework/Headers`
- `$(BUILD_DIR)/wv.framework/Headers`
- `$(BUILD_DIR)/fribidi.framework/Headers`
- `$(BUILD_DIR)/popt.framework/Headers`
- `/sw/include`
- `/sw/include/gtkmathview`
- `/sw/include/libgsf-1`
- `/sw/include/libxml2`
- `/sw/include/glib-2.0`
- `/sw/lib/glib-2.0/include`

## LeoWord Interpretation

The first LeoWord restoration task is not to invent a Cocoa frontend.

The first task is to make the existing native Cocoa application target buildable on Mac OS X 10.5.8 PowerPC with controlled, minimal dependencies.

## V1 Bias

V1 should prioritize:

- application startup
- native Cocoa menu/window/frame path
- `.abw` document support
- basic text editing
- basic save/open path

V1 should defer optional plugin targets unless required for startup.
