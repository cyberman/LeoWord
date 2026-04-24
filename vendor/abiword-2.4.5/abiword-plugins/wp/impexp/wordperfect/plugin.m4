dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_WORDPERFECT"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow AbiWord to read WordPerfect documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_WORDPERFECT],[
_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

WORDPERFECT_CPPFLAGS=""
WORDPERFECT_LDFLAGS=""

# Checks for libraries.
# Checks for header fils.

PKG_CHECK_MODULES(_abi_wordperfect, libwpd-0.8 >= 0.8.0 libwpd-stream-0.8 >= 0.8.0 ,[
	ABI_PLUGIN_REPORT([WordPerfect: okay])
],[	ABI_PLUGIN_REPORT([WordPerfect: error - libwpd-0.8 >= 0.8.0 required libwpd-stream >= 0.8.0 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	WORDPERFECT_CPPFLAGS="$_abi_wordperfect_CFLAGS"
	WORDPERFECT_LDFLAGS="$_abi_wordperfect_LIBS"
fi

AC_SUBST(WORDPERFECT_CPPFLAGS)
AC_SUBST(WORDPERFECT_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
