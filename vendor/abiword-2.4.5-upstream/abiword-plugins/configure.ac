AC_INIT(abiword-plugins, 2.4.5, [http://bugzilla.abisource.com/])
AC_CONFIG_SRCDIR([ac-helpers/abi-plugin-init.m4])

dnl First of all AbiWord plugin macros:
dnl 
ABI_PLUGIN_INIT(2.4.5)
ABI_PLUGIN_CONFIG

# Checks for programs.
AC_PROG_CC
AC_PROG_CPP
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET

AM_INIT_AUTOMAKE(abiword, 2.4.5)

AC_DISABLE_STATIC
AC_PROG_LIBTOOL

AC_C_CONST
AC_C_INLINE

dnl Configure plugin sources
dnl 
dnl AC_CONFIG_SUBDIRS()

abi_plugin_extra=
abi_plugin_opt=yes
AC_ARG_ENABLE(all,[  --disable-all           disable all plugins by default],[
	if test "x$enableval" = "xno"; then
		abi_plugin_opt=no
	fi
])

abi_tools=
abi_plugin_add=yes
AC_ARG_ENABLE(abicommand,[  --disable-abicommand],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abicommand,[  --without-abicommand],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_ABICOMMAND
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abicommand"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(abidash,[  --disable-abidash],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abidash,[  --without-abidash],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abidash"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(abigimp,[  --disable-abigimp],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abigimp,[  --without-abigimp],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abigimp"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(abigochart,[  --disable-abigochart],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abigochart,[  --without-abigochart],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_ABIGOCHART
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abigochart"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(abigrammar,[  --disable-abigrammar],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abigrammar,[  --without-abigrammar],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_ABIGRAMMAR
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abigrammar"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(abimathview,[  --disable-abimathview],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abimathview,[  --without-abimathview],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_ABIMATHVIEW
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools abimathview"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(aiksaurus,[  --disable-aiksaurus],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(aiksaurus,[  --without-aiksaurus],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_AIKSAURUS
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools aiksaurus"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(babelfish,[  --disable-babelfish],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(babelfish,[  --without-babelfish],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools babelfish"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(freetranslation,[  --disable-freetranslation],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(freetranslation,[  --without-freetranslation],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools freetranslation"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(gda,[  --disable-gda],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(gda,[  --without-gda],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_GDA
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools gda"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(gdict,[  --disable-gdict],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(gdict,[  --without-gdict],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_GDICT
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools gdict"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(google,[  --disable-google],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(google,[  --without-google],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools google"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(ots,[  --disable-ots],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(ots,[  --without-ots],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_OTS
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools ots"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(urldict,[  --disable-urldict],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(urldict,[  --without-urldict],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools urldict"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(wikipedia,[  --disable-wikipedia],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(wikipedia,[  --without-wikipedia],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_tools="$abi_tools wikipedia"
	fi
fi
AC_SUBST(abi_tools)

abi_wp_impexp_graphics=
abi_plugin_add=yes
AC_ARG_ENABLE(bmp,[  --disable-bmp],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(bmp,[  --without-bmp],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_BMP
	if test $abi_plugin_disable = no; then
		abi_wp_impexp_graphics="$abi_wp_impexp_graphics bmp"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(jpeg,[  --disable-jpeg],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(jpeg,[  --without-jpeg],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_JPEG
	if test $abi_plugin_disable = no; then
		abi_wp_impexp_graphics="$abi_wp_impexp_graphics jpeg"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(librsvg,[  --disable-librsvg],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(librsvg,[  --without-librsvg],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_LIBRSVG
	if test $abi_plugin_disable = no; then
		abi_wp_impexp_graphics="$abi_wp_impexp_graphics librsvg"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(wmf,[  --disable-wmf],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(wmf,[  --without-wmf],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_WMF
	if test $abi_plugin_disable = no; then
		abi_wp_impexp_graphics="$abi_wp_impexp_graphics wmf"
	fi
fi
AC_SUBST(abi_wp_impexp_graphics)

abi_wp_impexp=
abi_plugin_add=yes
AC_ARG_ENABLE(applix,[  --disable-applix],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(applix,[  --without-applix],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp applix"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(bz2abw,[  --disable-bz2abw],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(bz2abw,[  --without-bz2abw],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_BZ2ABW
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp bz2abw"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(clarisworks,[  --disable-clarisworks],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(clarisworks,[  --without-clarisworks],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp clarisworks"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(docbook,[  --disable-docbook],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(docbook,[  --without-docbook],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_DOCBOOK
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp docbook"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(eml,[  --disable-eml],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(eml,[  --without-eml],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp eml"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(hancom,[  --disable-hancom],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(hancom,[  --without-hancom],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_HANCOM
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp hancom"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(hrtext,[  --disable-hrtext],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(hrtext,[  --without-hrtext],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp hrtext"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(iscii-text,[  --disable-iscii-text],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(iscii-text,[  --without-iscii-text],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp iscii-text"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(kword,[  --disable-kword],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(kword,[  --without-kword],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp kword"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(latex,[  --disable-latex],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(latex,[  --without-latex],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp latex"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(mif,[  --disable-mif],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(mif,[  --without-mif],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp mif"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(mswrite,[  --disable-mswrite],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(mswrite,[  --without-mswrite],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp mswrite"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(nroff,[  --disable-nroff],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(nroff,[  --without-nroff],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp nroff"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(OpenDocument,[  --disable-OpenDocument],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(OpenDocument,[  --without-OpenDocument],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_OPENDOCUMENT
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp OpenDocument"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(OpenWriter,[  --disable-OpenWriter],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(OpenWriter,[  --without-OpenWriter],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_OPENWRITER
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp OpenWriter"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(passepartout,[  --disable-passepartout],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(passepartout,[  --without-passepartout],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp passepartout"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(pdb,[  --disable-pdb],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(pdb,[  --without-pdb],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp pdb"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(pdf,[  --disable-pdf],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(pdf,[  --without-pdf],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_PDF
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp pdf"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(psion,[  --disable-psion],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(psion,[  --without-psion],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_PSION
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp psion"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(sdw,[  --disable-sdw],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(sdw,[  --without-sdw],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_SDW
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp sdw"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(t602,[  --disable-t602],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(t602,[  --without-t602],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp t602"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(wml,[  --disable-wml],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(wml,[  --without-wml],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp wml"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(wordperfect,[  --disable-wordperfect],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(wordperfect,[  --without-wordperfect],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_WORDPERFECT
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp wordperfect"
	fi
fi
abi_plugin_add=yes
AC_ARG_ENABLE(xhtml,[  --disable-xhtml],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(xhtml,[  --without-xhtml],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
ABIPGN_XHTML_INIT
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	ABIPGN_XHTML
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp xhtml"
	fi
fi
ABIPGN_XHTML_END
abi_plugin_add=yes
AC_ARG_ENABLE(xsl-fo,[  --disable-xsl-fo],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(xsl-fo,[  --without-xsl-fo],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_impexp="$abi_wp_impexp xsl-fo"
	fi
fi
AC_SUBST(abi_wp_impexp)

abi_wp_scripts=
abi_plugin_add=yes
AC_ARG_ENABLE(shell,[  --disable-shell],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(shell,[  --without-shell],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp_scripts="$abi_wp_scripts shell"
	fi
fi
AC_SUBST(abi_wp_scripts)

abi_wp=
abi_plugin_add=yes
AC_ARG_ENABLE(abicapi,[  --disable-abicapi],[
	if test "x$enableval" = "xno"; then
		abi_plugin_add=no
	fi
],[	abi_plugin_add=$abi_plugin_opt
])
AC_ARG_WITH(abicapi,[  --without-abicapi],[
	if test "x$withval" = "xno"; then
		abi_plugin_add=no
	else
		abi_plugin_add=yes
	fi
])
if test $abi_plugin_add = yes; then
	abi_plugin_disable=no
	if test $abi_plugin_disable = no; then
		abi_wp="$abi_wp abicapi"
	fi
fi
AC_SUBST(abi_wp)

AC_CONFIG_FILES([
GNUmakefile tools/GNUmakefile wp/GNUmakefile wp/impexp/GNUmakefile wp/impexp/graphics/GNUmakefile wp/scripts/GNUmakefile
])
AC_CONFIG_FILES([
tools/abicommand/GNUmakefile
tools/abicommand/xp/GNUmakefile
tools/abidash/GNUmakefile
tools/abidash/xp/GNUmakefile
tools/abigimp/GNUmakefile
tools/abigimp/xp/GNUmakefile
tools/abigochart/GNUmakefile
tools/abigochart/unix/GNUmakefile
tools/abigrammar/GNUmakefile
tools/abigrammar/linkgrammarwrap/GNUmakefile
tools/abigrammar/xp/GNUmakefile
tools/abimathview/GNUmakefile
tools/abimathview/itex2MML/GNUmakefile
tools/abimathview/xp/GNUmakefile
tools/aiksaurus/GNUmakefile
tools/aiksaurus/xp/GNUmakefile
tools/babelfish/GNUmakefile
tools/babelfish/xp/GNUmakefile
tools/freetranslation/GNUmakefile
tools/freetranslation/xp/GNUmakefile
tools/gda/GNUmakefile
tools/gda/unix/GNUmakefile
tools/gdict/GNUmakefile
tools/gdict/unix/GNUmakefile
tools/google/GNUmakefile
tools/google/xp/GNUmakefile
tools/ots/GNUmakefile
tools/ots/xp/GNUmakefile
tools/urldict/GNUmakefile
tools/urldict/xp/GNUmakefile
tools/wikipedia/GNUmakefile
tools/wikipedia/xp/GNUmakefile
])
AC_CONFIG_FILES([
wp/impexp/applix/GNUmakefile
wp/impexp/applix/xp/GNUmakefile
wp/impexp/bz2abw/GNUmakefile
wp/impexp/bz2abw/xp/GNUmakefile
wp/impexp/clarisworks/GNUmakefile
wp/impexp/clarisworks/xp/GNUmakefile
wp/impexp/docbook/GNUmakefile
wp/impexp/docbook/xp/GNUmakefile
wp/impexp/eml/GNUmakefile
wp/impexp/eml/xp/GNUmakefile
wp/impexp/hancom/GNUmakefile
wp/impexp/hancom/xp/GNUmakefile
wp/impexp/hrtext/GNUmakefile
wp/impexp/hrtext/xp/GNUmakefile
wp/impexp/iscii-text/GNUmakefile
wp/impexp/iscii-text/xp/GNUmakefile
wp/impexp/kword/GNUmakefile
wp/impexp/kword/xp/GNUmakefile
wp/impexp/latex/GNUmakefile
wp/impexp/latex/xp/GNUmakefile
wp/impexp/mif/GNUmakefile
wp/impexp/mif/xp/GNUmakefile
wp/impexp/mswrite/GNUmakefile
wp/impexp/mswrite/xp/GNUmakefile
wp/impexp/nroff/GNUmakefile
wp/impexp/nroff/xp/GNUmakefile
wp/impexp/OpenDocument/GNUmakefile
wp/impexp/OpenDocument/common/GNUmakefile
wp/impexp/OpenDocument/common/xp/GNUmakefile
wp/impexp/OpenDocument/exp/GNUmakefile
wp/impexp/OpenDocument/exp/xp/GNUmakefile
wp/impexp/OpenDocument/imp/GNUmakefile
wp/impexp/OpenDocument/imp/xp/GNUmakefile
wp/impexp/OpenWriter/GNUmakefile
wp/impexp/OpenWriter/xp/GNUmakefile
wp/impexp/passepartout/GNUmakefile
wp/impexp/passepartout/xp/GNUmakefile
wp/impexp/pdb/GNUmakefile
wp/impexp/pdb/xp/GNUmakefile
wp/impexp/pdf/GNUmakefile
wp/impexp/pdf/xp/GNUmakefile
wp/impexp/psion/GNUmakefile
wp/impexp/psion/xp/GNUmakefile
wp/impexp/sdw/GNUmakefile
wp/impexp/sdw/xp/GNUmakefile
wp/impexp/t602/GNUmakefile
wp/impexp/t602/xp/GNUmakefile
wp/impexp/wml/GNUmakefile
wp/impexp/wml/xp/GNUmakefile
wp/impexp/wordperfect/GNUmakefile
wp/impexp/wordperfect/xp/GNUmakefile
wp/impexp/xhtml/GNUmakefile
wp/impexp/xhtml/xp/GNUmakefile
wp/impexp/xsl-fo/GNUmakefile
wp/impexp/xsl-fo/xp/GNUmakefile
])
AC_CONFIG_FILES([
wp/impexp/graphics/bmp/GNUmakefile
wp/impexp/graphics/bmp/xp/GNUmakefile
wp/impexp/graphics/jpeg/GNUmakefile
wp/impexp/graphics/jpeg/xp/GNUmakefile
wp/impexp/graphics/librsvg/GNUmakefile
wp/impexp/graphics/librsvg/unix/GNUmakefile
wp/impexp/graphics/wmf/GNUmakefile
wp/impexp/graphics/wmf/xp/GNUmakefile
])
AC_CONFIG_FILES([
wp/abicapi/GNUmakefile
wp/abicapi/xp/GNUmakefile
wp/scripts/shell/GNUmakefile
wp/scripts/shell/xp/GNUmakefile
])
AC_OUTPUT

if test -f plugin.status; then
	echo ""
	echo "Plugin reports:"
	echo ""
	cat plugin.status
	echo ""
fi
