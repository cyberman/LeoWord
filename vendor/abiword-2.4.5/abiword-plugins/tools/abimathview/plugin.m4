dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_ABIMATHVIEW"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile itex2MML/GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Enables AbiWord to embed some maths."
dnl= 
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default
dnl= abi_plugin_enable="yes"
dnl= 
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_ABIMATHVIEW],[

# Checks for GtkMathView.

MATH_VIEW_REQUIRED_VERSION=0.7.5

PKG_CHECK_MODULES(MATHVIEW, [mathview-frontend-libxml2 >= $MATH_VIEW_REQUIRED_VERSION],[
        ABI_PLUGIN_REPORT([abimathview: okay])
],[
	ABI_PLUGIN_REPORT([abimathview: error gtkmathview >= $MATH_VIEW_REQUIRED_VERSION required])
        abi_plugin_disable=yes
])
AC_LANG(C++)

AC_CHECK_HEADER(hash_map,[MATHVIEW_CFLAGS="-DHAVE_HASH_MAP $MATHVIEW_CFLAGS"],[
AC_CHECK_HEADER(ext/hash_map,[MATHVIEW_CFLAGS="-DHAVE_EXT_HASH_MAP $MATHVIEW_CFLAGS"],
[        ABI_PLUGIN_REPORT([abimathview: error hash_map header not found])
abi_plugin_disable=yes])
])

AC_LANG(C)

echo $MATHVIEW_CFLAGS
AC_SUBST(MATHVIEW_CFLAGS)
AC_SUBST(MATHVIEW_LIBS)
])

