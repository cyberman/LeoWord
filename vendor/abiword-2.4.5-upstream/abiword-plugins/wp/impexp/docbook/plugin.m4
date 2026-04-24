dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_DOCBOOK"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow AbiWord to read and write DocBook documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_DOCBOOK],[

AC_HEADER_TIME

ABI_DOCBOOK_CPPFLAGS=""
ABI_DOCBOOK_LDFLAGS=""

AC_SUBST(ABI_DOCBOOK_CPPFLAGS)
AC_SUBST(ABI_DOCBOOK_LDFLAGS)

])

