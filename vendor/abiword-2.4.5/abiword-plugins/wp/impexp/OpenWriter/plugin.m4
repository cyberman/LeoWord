dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_OPENWRITER"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to read/write OpenWriter and StarWriter documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_OPENWRITER],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_OPENWRITER_CPPFLAGS=""
ABI_OPENWRITER_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

LIBGSF_REQUIRED_VERSION=1.11.1

PKG_CHECK_MODULES(ABI_OPENWRITER, [libgsf-1 >= $LIBGSF_REQUIRED_VERSION],[
        ABI_PLUGIN_REPORT([OpenWriter: okay])
],[        ABI_PLUGIN_REPORT([OpenWriter: error libgsf >= $LIBGSF_REQUIRED_VERSION required])
        abi_plugin_disable=yes
])

if test $abi_plugin_disable = no; then
	ABI_OPENWRITER_CPPFLAGS="$ABI_OPENWRITER_CFLAGS"
	ABI_OPENWRITER_LDFLAGS="$ABI_OPENWRITER_LIBS"
fi

AC_SUBST(ABI_OPENWRITER_CPPFLAGS)
AC_SUBST(ABI_OPENWRITER_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
