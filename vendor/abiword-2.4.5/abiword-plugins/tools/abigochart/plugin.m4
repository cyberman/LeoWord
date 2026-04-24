nl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_ABIGOCHART"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile unix/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Enables AbiWord to embed Gnome Office Charts."
dnl= 
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default
dnl= abi_plugin_enable="yes"
dnl= 
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_ABIGOCHART],[

# Checks for GOfficeCharts

LIBGOffice_REQUIRED_VERSION=0.1.0

PKG_CHECK_MODULES(GOFFICE, [libgoffice-1 >= $LIBGOffice_REQUIRED_VERSION],[
        ABI_PLUGIN_REPORT([abigochart: okay])
],[        ABI_PLUGIN_REPORT([abigochart: error libgoffice >= $LIBGOffice_REQUIRED_VERSION required])
        abi_plugin_disable=yes
])
AC_LANG(C++)

AC_CHECK_HEADER(hash_map,[GOFFICE_CFLAGS="-DHAVE_HASH_MAP $GOFFICE_CFLAGS"],[
AC_CHECK_HEADER(ext/hash_map,[GOFFICE_CFLAGS="-DHAVE_EXT_HASH_MAP $GOFFICE_CFLAGS"],
[        ABI_PLUGIN_REPORT([abigochart: error hash_map header not found])
abi_plugin_disable=yes])
])

AC_LANG(C)

echo $GOFFICE_CFLAGS
AC_SUBST(GOFFICE_CFLAGS)
AC_SUBST(GOFFICE_LIBS)
])
