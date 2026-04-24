# DYLD_BUNDLE_LOADER(EXECUTABLE-PATH)
# -----------------------------------
AC_DEFUN([DYLD_BUNDLE_LOADER],[

PLATFORM_LDFLAGS="$PLATFORM_LDFLAGS -Xlinker -bundle_loader -Xlinker $1"

])
