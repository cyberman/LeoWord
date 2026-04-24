dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_OTS"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to summarize documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_OTS],[
_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_OTS_CPPFLAGS=""
ABI_OTS_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

PKG_CHECK_MODULES(_abi_ots,[
	gtk+-2.0
	libglade-2.0
	libots-1 >= 0.4.1
],[	ABI_PLUGIN_REPORT([Ots: okay])
],[	ABI_PLUGIN_REPORT([Ots: error - libots-1 >= 0.4.1 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	ABI_OTS_CPPFLAGS="$_abi_ots_CFLAGS"
	ABI_OTS_LDFLAGS="$_abi_ots_LIBS"
fi

AC_SUBST(ABI_OTS_CPPFLAGS)
AC_SUBST(ABI_OTS_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
