dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_ABIGRAMMAR"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile linkgrammarwrap/GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Interface with grammar checkers"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_ABIGRAMMAR],[
_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_GRAMMAR_CPPFLAGS=""
ABI_GRAMMAR_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

PKG_CHECK_MODULES(_abi_grammar,[
	link-grammar >= 4.2.1
],[	ABI_PLUGIN_REPORT([Link Grammar: okay])
],[	ABI_PLUGIN_REPORT([Link Grammar: error - link-grammar >= 4.2.1 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	ABI_GRAMMAR_CPPFLAGS="$_abi_grammar_CFLAGS"
	ABI_GRAMMAR_LDFLAGS="$_abi_grammar_LIBS"
fi

AC_SUBST(ABI_GRAMMAR_CPPFLAGS)
AC_SUBST(ABI_GRAMMAR_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
