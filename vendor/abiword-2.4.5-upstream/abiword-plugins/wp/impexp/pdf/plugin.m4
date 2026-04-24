dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_PDF"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow AbiWord to read PDF documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_PDF],[
_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

PDF_CPPFLAGS=""
PDF_LDFLAGS=""

# Checks for libraries.
# Checks for header fils.

POPPLER_REQUIRED_VERSION=0.4.0

PKG_CHECK_MODULES(_abi_pdf, poppler >= $POPPLER_REQUIRED_VERSION,
,[	ABI_PLUGIN_REPORT([PDF: error - poppler >= $POPPLER_REQUIRED_VERSION required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
# Check if xpdf headers are there (poppler does not install them by default)
	CPPFLAGS=$_abi_pdf_CFLAGS
	LDFLAGS=$_abi_pdf_LIBS
	AC_LANG(C++)
	AC_HEADER_CHECK(GlobalParams.h, [have_xpdf_headers=yes], [have_xpdf_headers=no])
	AC_LANG(C)
	if test $have_xpdf_headers = yes; then
		PDF_CPPFLAGS="$_abi_pdf_CFLAGS"
		PDF_LDFLAGS="$_abi_pdf_LIBS"
		ABI_PLUGIN_REPORT([PDF: okay])
	else
		ABI_PLUGIN_REPORT([PDF: error - poppler was installed without the xpdf headers])		
		abi_plugin_disable=yes
	fi
fi

AC_SUBST(PDF_CPPFLAGS)
AC_SUBST(PDF_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
