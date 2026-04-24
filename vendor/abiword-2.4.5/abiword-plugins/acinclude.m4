dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_ABICOMMAND"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Enables AbiWord to be used as a commanded daemon."
dnl= 
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default
dnl= abi_plugin_enable="yes"
dnl= 
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_ABICOMMAND],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_COMMAND_CPPFLAGS=""
ABI_COMMAND_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

PKG_CHECK_MODULES(_abi_glib,glib-2.0 >= 2.0,,[	ABI_PLUGIN_REPORT([AbiCommand: error - glib-2.0 >= 2.0 required])
	abi_plugin_disable=yes
])

if test $abi_plugin_disable = no; then
	ABI_COMMAND_CPPFLAGS="$_abi_glib_CFLAGS"
	ABI_COMMAND_LDFLAGS="$_abi_glib_LIBS"
fi

have_readline=unknown
AC_CHECK_HEADER(readline/readline.h,[
	AC_CHECK_HEADER(readline/history.h,[
		AC_CHECK_LIB(readline,readline,[
			have_readline=yes
			LDFLAGS="-ltermcap $LDFLAGS"
			ABI_COMMAND_LDFLAGS="-ltermcap $ABI_COMMAND_LDFLAGS"
		],[	AC_CHECK_LIB(readline,rl_initialize,[
				have_readline=yes
				LDFLAGS="-lcurses $LDFLAGS"
				ABI_COMMAND_LDFLAGS="-lcurses $ABI_COMMAND_LDFLAGS"
			],have_readline=no,-lcurses)
		],-ltermcap)
	],have_readline=no)
],have_readline=no)

if [ test $have_readline != yes ]; then
	ABI_PLUGIN_REPORT([AbiCommand: error - readline library and/or headers not found])
	abi_plugin_disable=yes

else
	ABI_PLUGIN_REPORT([AbiCommand: okay])
	ABI_COMMAND_LDFLAGS="-lreadline -lhistory $ABI_COMMAND_LDFLAGS"
fi

AC_SUBST(ABI_COMMAND_CPPFLAGS)
AC_SUBST(ABI_COMMAND_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
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

dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_AIKSAURUS"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to connect with AikSaurus."
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_AIKSAURUS],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_AIKSAURUS_CPPFLAGS=""
ABI_AIKSAURUS_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

AC_ARG_WITH(Aiksaurus,[  --with-Aiksaurus=DIR    Aiksaurus library in DIR],[
	if [ test "x$withval" = "xno" ]; then
		AC_MSG_ERROR([* * * Aiksaurus library required to build this plugin * * *])
	elif [ test "x$withval" != "xyes" ]; then
		ABI_AIKSAURUS_CPPFLAGS="-I$withval/include"
		ABI_AIKSAURUS_LDFLAGS="-L$withval/lib"
	fi
])

CPPFLAGS="$CPPFLAGS $ABI_AIKSAURUS_CPPFLAGS"
LDFLAGS="$LDFLAGS $ABI_AIKSAURUS_LDFLAGS"

AC_LANG_CPLUSPLUS
PKG_CHECK_MODULES(PKGAIKSAURUS, aiksaurus-1.0,[
	ABI_AIKSAURUS_CPPFLAGS="`pkg-config --cflags aiksaurus-1.0` $ABI_AIKSAURUS_CPPFLAGS"
	ABI_AIKSAURUS_LDFLAGS="`pkg-config --libs aiksaurus-1.0` -lAiksaurus $ABI_AIKSAURUS_LDFLAGS"
],[	ABI_PLUGIN_REPORT([aiksaurus: error - Aiksaurus.h not found])
	abi_plugin_disable=yes
])
AC_LANG_C

if test $abi_plugin_disable = no; then
	dnl other front ends will be possible eventually, but for the moment it's only GTK-1.2

	ABI_GTK2
	ABI_AIKSAURUS_CPPFLAGS="$ABI_AIKSAURUS_CPPFLAGS `pkg-config --cflags gtk+-2.0`"
	ABI_AIKSAURUS_LDFLAGS="$ABI_AIKSAURUS_LDFLAGS `pkg-config --libs gtk+-2.0`"

	AC_LANG_CPLUSPLUS
	PKG_CHECK_MODULES(PKGGAIKSAURUS, gaiksaurus-1.0,[
		ABI_AIKSAURUS_CPPFLAGS="`pkg-config --cflags gaiksaurus-1.0` $ABI_AIKSAURUS_CPPFLAGS"
		ABI_AIKSAURUS_LDFLAGS="`pkg-config --libs gaiksaurus-1.0` -lAiksaurusGTK $ABI_AIKSAURUS_LDFLAGS"
	],[	ABI_PLUGIN_REPORT([aiksaurus: error - AiksaurusGTK.h not found])
		abi_plugin_disable=yes
	])
dnl	AC_CHECK_HEADER(AiksaurusGTK.h,[
dnl		ABI_AIKSAURUS_LDFLAGS="-lAiksaurusGTK $ABI_AIKSAURUS_LDFLAGS"
dnl	],[	ABI_PLUGIN_REPORT([aiksaurus: error - AiksaurusGTK.h not found])
dnl		abi_plugin_disable=yes
dnl	])
	AC_LANG_C
fi

if test $abi_plugin_disable = no; then
	ABI_PLUGIN_REPORT([aiksaurus: okay])
fi

AC_SUBST(ABI_AIKSAURUS_CPPFLAGS)
AC_SUBST(ABI_AIKSAURUS_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_GDA"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile unix/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to use gda"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="no"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_GDA],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_GDA_CPPFLAGS=""
ABI_GDA_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

dnl only unix builds should need this stuff, so why...?
PKG_CHECK_MODULES(_abi_gda,[libgda >= 1.2.0 libgnomedb >= 1.2.0],[
	ABI_PLUGIN_REPORT([gda: okay])
],[	ABI_PLUGIN_REPORT([gda: error - libgda and libgnomedb >= 1.2.0 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	ABI_GDA_CPPFLAGS="$_abi_gda_CFLAGS"
	ABI_GDA_LDFLAGS="$_abi_gda_LIBS"
fi

AC_SUBST(ABI_GDA_CPPFLAGS)
AC_SUBST(ABI_GDA_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_GDICT"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile unix/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to use gdict"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="no"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_GDICT],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_GDICT_CPPFLAGS=""
ABI_GDICT_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

# ABI_GNOME_OPT(1.2.13,yes)
# if [ test $abi_gnome_opt = no ]; then

dnl only unix builds should need this stuff, so why...?
PKG_CHECK_MODULES(_abi_gtk,gtk+-2.0 >= 2.0,[
	ABI_PLUGIN_REPORT([gdict: okay (no GNOME; using fork-and-exec method)])
],[	ABI_PLUGIN_REPORT([gdict: error - gtk+-2.0 >= 2.0 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	ABI_GDICT_CPPFLAGS="$_abi_gtk_CFLAGS -DUSE_FORK_AND_EXEC_METHOD=1"
	ABI_GDICT_LDFLAGS="$_abi_gtk_LIBS"
fi

# else
# 	ABI_GDICT_CPPFLAGS="`$abi_gnome_config --cflags gnomeui gtk glib`"
# 	ABI_GDICT_LDFLAGS="`$abi_gnome_config --libs gnomeui gtk glib`"
# 
# 	CPPFLAGS="$CPPFLAGS $ABI_GDICT_CPPFLAGS"
# 	LDFLAGS="$LDFLAGS $ABI_GDICT_LDFLAGS"
# 
# 	have_libgdict=yes
# 	AC_CHECK_HEADER(libgdict/gdict-defbox.h,[
# 		AC_CHECK_LIB(gdict,gdict_defbox_lookup,have_libgdict=yes,[
# 			have_libgdict=no
# 			AC_MSG_WARN([* * * can't link against libgdict * * *])
# 		],$ABI_GDICT_LDFLAGS)
# 	],[	AC_MSG_WARN([* * * libgdict doesn't appear to be installed * * *])
# 		have_libgdict=no
# 	])
# 
# 	if [ test $have_libgdict = no ]; then
# 		ABI_GTK12(0)
# 		ABI_GDICT_CPPFLAGS="`$abi_gtk_config --cflags` -DUSE_FORK_AND_EXEC_METHOD=1"
# 		ABI_GDICT_LDFLAGS="`$abi_gtk_config --libs`"
# 		ABI_PLUGIN_REPORT([gdict: okay (falling back to fork-and-exec method)])
# 	else
# 		ABI_GDICT_LDFLAGS="-lgdict $ABI_GDICT_LDFLAGS"
# 		ABI_PLUGIN_REPORT([gdict: okay (using libgdict)])
# 	fi
# fi

AC_HEADER_SYS_WAIT
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_PID_T

# Checks for library functions.

AC_SUBST(ABI_GDICT_CPPFLAGS)
AC_SUBST(ABI_GDICT_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
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
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_BMP"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc=""
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_BMP],[

ABI_BMP_CPPFLAGS="$LIBPNG_CFLAGS"
ABI_BMP_LDFLAGS="$LIBPNG_LIBS"

AC_SUBST(ABI_BMP_CPPFLAGS)
AC_SUBST(ABI_BMP_LDFLAGS)
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_JPEG"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc=""
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_JPEG],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_JPEG_CPPFLAGS=""
ABI_JPEG_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

AC_CHECK_HEADER(jpeglib.h,[
	AC_CHECK_LIB(jpeg,jpeg_read_header,[
		ABI_PLUGIN_REPORT([jpeg: okay])
	],[	ABI_PLUGIN_REPORT([jpeg: error - libjpeg not found])
		abi_plugin_disable=yes
	])
],[	ABI_PLUGIN_REPORT([jpeg: error - jpeg header not found])
	abi_plugin_disable=yes
])

if test $abi_plugin_disable = no; then
	ABI_JPEG_CPPFLAGS="$LIBPNG_CFLAGS"
	ABI_JPEG_LDFLAGS="-ljpeg $LIBPNG_LIBS"
fi

AC_SUBST(ABI_JPEG_CPPFLAGS)
AC_SUBST(ABI_JPEG_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_LIBRSVG"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile unix/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to import several image types with gdk-pixbuf"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_LIBRSVG],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

LIBRSVG_CPPFLAGS=""
LIBRSVG_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

PKG_CHECK_MODULES(_abi_librsvg,librsvg-2.0 >= 2.0,[
	ABI_PLUGIN_REPORT([LibRSVG: okay])
],[	ABI_PLUGIN_REPORT([LibRSVG: error - librsvg-2.0 >= 2.0 required])
	abi_plugin_disable=yes
])
if test $abi_plugin_disable = no; then
	LIBRSVG_CPPFLAGS="$_abi_librsvg_CFLAGS"
	LIBRSVG_LDFLAGS="$_abi_librsvg_LIBS"
fi

AC_SUBST(LIBRSVG_CPPFLAGS)
AC_SUBST(LIBRSVG_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_WMF"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc=""
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_WMF],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_WMF_CPPFLAGS=""
ABI_WMF_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

ABI_LIBWMF_OPT(0.2.8,yes)
if [ test "$abi_libwmf_opt" = "no" ]; then
	ABI_PLUGIN_REPORT([wmf: error - libwmf >= 0.2.8 not found])
	abi_plugin_disable=yes
else
	ABI_PLUGIN_REPORT([wmf: okay])
fi

if test $abi_plugin_disable = no; then
	ABI_WMF_CPPFLAGS="`$abi_libwmf_config --cflags`"
	ABI_WMF_LDFLAGS="`$abi_libwmf_config --libs`"
fi

AC_SUBST(ABI_WMF_CPPFLAGS)
AC_SUBST(ABI_WMF_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])

AC_DEFUN([ABI_LIBWMF_OPT],[
	abi_libwmf_config=""
	abi_libwmf_version=""
	if [ test "x$2" = "xyes" ]; then
		abi_libwmf_opt=check
	else
		abi_libwmf_opt=required
	fi
	AC_ARG_WITH(libwmf,[  --with-libwmf[=DIR]     Use libwmf [in DIR] ],[
		if [ test "x$withval" = "xno" ]; then
			if [ test $abi_libwmf_opt = required ]; then
				AC_MSG_ERROR([* * * libwmf is not optional! * * *])
			fi
			abi_libwmf_opt=no
		elif [ test "x$withval" = "xyes" ]; then
			abi_libwmf_opt=required
			abi_libwmf_dir=""
		else
			abi_libwmf_opt=required
			abi_libwmf_dir="$withval"
		fi
	],[	abi_libwmf_dir=""
	])
	if [ test $abi_libwmf_opt != no ]; then
		if [ test "x$abi_libwmf_dir" = "x" ]; then
			AC_PATH_PROG(abi_libwmf_config,libwmf-config, ,[$PATH])
		else
			AC_PATH_PROG(abi_libwmf_config,libwmf-config, ,[$abi_libwmf_dir/bin:$PATH])
		fi
		if [ test "x$abi_libwmf_config" = "x" ]; then
			if [ test $abi_libwmf_opt = required ]; then
				AC_MSG_ERROR([* * * unable to find libwmf-config in path! * * *])
			fi
			abi_libwmf_opt=no
		fi
	fi
	if [ test $abi_libwmf_opt != no ]; then
	        if [ $abi_libwmf_config --version > /dev/null 2>&1 ]; then
			_abi_libwmf_version="$1"
			_abi_libwmf_major=`echo $_abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
			_abi_libwmf_minor=`echo $_abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
			_abi_libwmf_micro=`echo $_abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

			AC_MSG_CHECKING(for libwmf >= $_abi_libwmf_major.$_abi_libwmf_minor.$_abi_libwmf_micro)

			abi_libwmf_version=`$abi_libwmf_config --version`
			abi_libwmf_major=`echo $abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
			abi_libwmf_minor=`echo $abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
			abi_libwmf_micro=`echo $abi_libwmf_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`

			abi_libwmf_version=""
			if [ test $abi_libwmf_major -gt $_abi_libwmf_major ]; then
				abi_libwmf_version="$abi_libwmf_major.$abi_libwmf_minor.$abi_libwmf_micro"
			elif [ test $abi_libwmf_major -eq $_abi_libwmf_major ]; then
				if [ test $abi_libwmf_minor -gt $_abi_libwmf_minor ]; then
					abi_libwmf_version="$abi_libwmf_major.$abi_libwmf_minor.$abi_libwmf_micro"
				elif [ test $abi_libwmf_minor -eq $_abi_libwmf_minor ]; then
					if [ test $abi_libwmf_micro -ge $_abi_libwmf_micro ]; then
						abi_libwmf_version="$abi_libwmf_major.$abi_libwmf_minor.$abi_libwmf_micro"
					fi
				fi
			fi
			if [ test "x$abi_libwmf_version" = "x" ]; then
				if [ test $abi_libwmf_opt = required ]; then
					AC_MSG_ERROR([* * * libwmf version is incompatible! require at least "1.2.$1" * * *])
				fi
				abi_libwmf_opt=no
				AC_MSG_RESULT(no - $abi_libwmf_major.$abi_libwmf_minor.$abi_libwmf_micro)
			else
				AC_MSG_RESULT(yes - $abi_libwmf_version)
			fi
		else
			AC_MSG_WARN([* * * problem obtaining libwmf version... * * *])
			if [ test $abi_libwmf_opt = required ]; then
				AC_MSG_ERROR([* * * unable to determine libwmf version! * * *])
			fi
			abi_libwmf_opt=no
		fi
	fi
	if [ test $abi_libwmf_opt != no ]; then
		if [ test "x$abi_libwmf_dir" = "x" ]; then
			abi_libwmf_opt=yes
		else
			abi_libwmf_opt="$abi_libwmf_dir"
		fi
	fi
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_BZ2ABW"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword documents compressed with bzip2"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_BZ2ABW],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

BZ2ABW_CPPFLAGS=""
BZ2ABW_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

ABI_BZIP2_OPT(yes)
if [ test "$abi_bzip2_opt" = "no" ]; then
        ABI_PLUGIN_REPORT([bz2abw: error - libbz2 not found])
	abi_plugin_disable=yes
else
	ABI_PLUGIN_REPORT([bz2abw: okay])
fi

if test $abi_plugin_disable = no; then
	BZ2ABW_CPPFLAGS="$abi_bzip2_cppflags"
	BZ2ABW_LDFLAGS="$abi_bzip2_ldflags $abi_bzip2_libs"
fi

AC_SUBST(BZ2ABW_CPPFLAGS)
AC_SUBST(BZ2ABW_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
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

dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_HANCOM"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to read/write Hancom and StarWriter documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_HANCOM],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_HANCOM_CPPFLAGS=""
ABI_HANCOM_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

if pkg-config --exists libgsf-1; then
	ABI_HANCOM_CPPFLAGS=`pkg-config --cflags libgsf-1`
	ABI_HANCOM_LDFLAGS=`pkg-config --libs libgsf-1`
	ABI_PLUGIN_REPORT([Hancom: okay])
else
        ABI_PLUGIN_REPORT([Hancom: error - can't find libgsf])
	abi_plugin_disable=yes
fi

if test $abi_plugin_disable = no; then
	ABI_HANCOM_LDFLAGS="$ABI_HANCOM_LDFLAGS"
fi

AC_SUBST(ABI_HANCOM_CPPFLAGS)
AC_SUBST(ABI_HANCOM_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_OPENDOCUMENT"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile common/GNUmakefile common/xp/GNUmakefile exp/GNUmakefile exp/xp/GNUmakefile imp/GNUmakefile imp/xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to allow abiword to read/write OASIS OpenDocument .odt files"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_OPENDOCUMENT],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_OPENDOCUMENT_CPPFLAGS=""
ABI_OPENDOCUMENT_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

LIBGSF_REQUIRED_VERSION=1.11.1

PKG_CHECK_MODULES(ABI_OPENDOCUMENT, [libgsf-1 >= $LIBGSF_REQUIRED_VERSION],[
        ABI_PLUGIN_REPORT([OpenDocument: okay])
],[        ABI_PLUGIN_REPORT([OpenDocument: error libgsf >= $LIBGSF_REQUIRED_VERSION required])
        abi_plugin_disable=yes
])

ABI_OPENDOCUMENT_DEFS=""

if test $abi_plugin_disable = no; then
	ABI_OPENDOCUMENT_CPPFLAGS="$ABI_OPENDOCUMENT_CFLAGS $ABI_OPENDOCUMENT_DEFS"
	ABI_OPENDOCUMENT_LDFLAGS="$ABI_OPENDOCUMENT_LIBS"
fi

AC_SUBST(ABI_OPENDOCUMENT_CPPFLAGS)
AC_SUBST(ABI_OPENDOCUMENT_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
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
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_PSION"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="psion word import"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################


AC_DEFUN([ABIPGN_PSION],[

# The required psiconv version, as reported by psiconv-config
psiconv_major_req=0
psiconv_minor_req=9
psiconv_patch_req=4

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_PSION_CPPFLAGS=""
ABI_PSION_LDFLAGS=""
psiconvconfigdir=""

AC_ARG_WITH(psiconv-config,[  --with-psiconv-config=DIR      use psiconv-config in DIR],[
	psiconvconfigdir="$withval"
])


if test "x$abi_plugin_disable" != "xyes"; then
	if test "x$psiconvconfigdir" = "x"; then
		AC_PATH_PROG(psiconvconfig,psiconv-config)
	else
		AC_PATH_PROG(psiconvconfig,psiconv-config,,"$psiconvconfigdir")
	fi
		
	if test "x$psiconvconfig" = "x"; then
		abi_plugin_disable=yes
	fi
fi

if test "x$abi_plugin_disable" != "xyes"; then
	AC_MSG_CHECKING([for psiconv >= ${psiconv_major_req}.${psiconv_minor_req}.${psiconv_patch_req}])
	IFS_old="$IFS"
	IFS='.'
	set -- `psiconv-config --version`
	psiconv_major_found="${1}"
	psiconv_minor_found="${2}"
	psiconv_patch_found="${3}"
	IFS="$IFS_old"
	if test "$psiconv_major_found" -lt "$psiconv_major_req"; then
		abi_plugin_disable=yes
	elif test "$psiconv_major_found" -eq "$psiconv_major_req"; then
		if test "$psiconv_minor_found" -lt "$psiconv_minor_req"; then
			abi_plugin_disable=yes
		elif test "$psiconv_minor_found" -eq "$psiconv_minor_req"; then
			if test "$psiconv_patch_found" -lt "$psiconv_patch_req"; then
				abi_plugin_disable=yes
			fi
		fi
	fi
	if test "x$abi_plugin_disable" = "xyes"; then
		AC_MSG_RESULT([version ${psiconv_major_found}.${psiconv_minor_found}.${psiconv_patch_found} (Too old!)])
	else
		AC_MSG_RESULT([version ${psiconv_major_found}.${psiconv_minor_found}.${psiconv_patch_found} (OK)])
	fi
fi

if test "x$abi_plugin_disable" != "xyes"; then
	ABI_PSION_CPPFLAGS=`psiconv-config --cflags`
	ABI_PSION_LDFLAGS=`psiconv-config --libs`
fi

ABI_PSION_CPPFLAGS="$ABI_PSION_CPPFLAGS $LIBPNG_CFLAGS"
ABI_PSION_LDFLAGS="$ABI_PSION_LDFLAGS $LIBPNG_LDFLAGS"
	
AC_SUBST(ABI_PSION_CPPFLAGS)
AC_SUBST(ABI_PSION_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"

if test "x$abi_plugin_disable" != "xyes"; then
	ABI_PLUGIN_REPORT([psion: OK])
else
	ABI_PLUGIN_REPORT([psion: psiconv (>= 0.9.1) not found])
fi
])
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_SDW"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Importer for StarWriter <= 5.x files (.sdw)"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_SDW],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

ABI_SDW_CPPFLAGS=""
ABI_SDW_LDFLAGS=""

# Checks for libraries.
# Checks for header files.

if test $abi_plugin_disable = no; then
	PKG_CHECK_MODULES(ABI_SDW, libgsf-1 >= 1.4.0,[
		ABI_SDW_CPPFLAGS="$ABI_SDW_CFLAGS"
		ABI_SDW_LDFLAGS="$ABI_SDW_LIBS"
		ABI_PLUGIN_REPORT([sdw: okay])
	],[	abi_plugin_disable=yes
		ABI_SDW_CPPFLAGS="$ABI_SDW_CFLAGS"
		ABI_SDW_LDFLAGS="$ABI_SDW_LIBS"
		ABI_PLUGIN_REPORT([sdw: error - libgsf-1 >= 1.4.0 required])
	])
fi

AC_SUBST(ABI_SDW_CPPFLAGS)
AC_SUBST(ABI_SDW_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"
])
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
dnl= ##########################################################################
dnl= # abiword-plugins: autogen.sh header
dnl= # this file is executed as a shell script
dnl= 
dnl= # 1. abi_plugin_macro is the name of the main macro defined here:
dnl= abi_plugin_macro="ABIPGN_XHTML"
dnl= abi_plugin_macro_init="ABIPGN_XHTML_INIT"
dnl= abi_plugin_macro_end="ABIPGN_XHTML_END"
dnl= 
dnl= # 2. abi_plugin_files is the list of files that configure must generate:
dnl= abi_plugin_files="GNUmakefile xp/GNUmakefile"
dnl= 
dnl= # 3. abi_plugin_desc is a short description of the plugin
dnl= abi_plugin_desc="Plugin to enable import of Multipart HTML documents"
dnl=
dnl= # 4. abi_plugin_enable - whether plugin should be enabled by default 
dnl= abi_plugin_enable="yes"
dnl=
dnl= return
dnl= ##########################################################################

AC_DEFUN([ABIPGN_XHTML_INIT],[

inter7eps_disable=no
htmltidy_disable=yes
htmlxml2_disable=no

])

AC_DEFUN([ABIPGN_XHTML],[

_abi_cppflags_save="$CPPFLAGS"
_abi_ldflags_save="$LDFLAGS"

# Checks for libraries.
# Checks for header files.

ABI_XHTML_I7EPS_CPPFLAGS=""
ABI_XHTML_I7EPS_LDFLAGS=""

AC_ARG_WITH(inter7eps,[  --with-inter7eps=DIR     inter7 EPS library in DIR],[
	if test "x$withval" = "xno"; then
		ABI_PLUGIN_REPORT([xhtml(mht):  inter7 EPS support disabled])
		inter7eps_disable=yes
	elif test "x$withval" != "xyes"; then
		ABI_XHTML_I7EPS_CPPFLAGS="-I$withval/include/eps"
		ABI_XHTML_I7EPS_LDFLAGS="-L$withval/lib"
		CPPFLAGS="$CPPFLAGS -I$withval/include/eps"
		LDFLAGS="$LDFLAGS -L$withval/lib"
	else
		ABI_XHTML_I7EPS_CPPFLAGS="-I/usr/include/eps"
		CPPFLAGS="$CPPFLAGS -I/usr/include/eps"
	fi
],[	ABI_XHTML_I7EPS_CPPFLAGS="-I/usr/include/eps"
	CPPFLAGS="$CPPFLAGS -I/usr/include/eps"
])

if test $inter7eps_disable != yes; then
	AC_CHECK_HEADER(mime.h,[
		ABI_PLUGIN_REPORT([xhtml(mht):  okay])
		ABI_XHTML_I7EPS_CPPFLAGS="$ABI_XHTML_I7EPS_CPPFLAGS -DXHTML_MULTIPART_SUPPORTED"
		ABI_XHTML_I7EPS_LDFLAGS="$ABI_XHTML_I7EPS_LDFLAGS -leps"
	],[	ABI_PLUGIN_REPORT([xhtml(mht):  error - inter7 EPS headers not found])
		ABI_PLUGIN_REPORT([xhtml(mht):          http://www.inter7.com/eps/])
		inter7eps_disable=yes
	])
fi
if test $inter7eps_disable = yes; then
	ABI_XHTML_I7EPS_CPPFLAGS=""
	ABI_XHTML_I7EPS_LDFLAGS=""
fi

ABI_XHTML_TIDY_CPPFLAGS=""
ABI_XHTML_TIDY_LDFLAGS=""

AC_ARG_WITH(libtidy,[  --with-libtidy=DIR       tidy library in DIR],[
	if test "x$withval" = "xno"; then
		ABI_PLUGIN_REPORT([xhtml(html): libtidy support disabled])
		htmltidy_disable=yes
	elif test "x$withval" != "xyes"; then
		ABI_XHTML_TIDY_CPPFLAGS="-I$withval/include"
		ABI_XHTML_TIDY_LDFLAGS="-L$withval/lib"
		CPPFLAGS="$CPPFLAGS -I$withval/include"
		LDFLAGS="$LDFLAGS -L$withval/lib"
		ABI_PLUGIN_REPORT([xhtml(html): libtidy support enabled])
		htmltidy_disable=no
	else
		ABI_PLUGIN_REPORT([xhtml(html): libtidy support enabled])
		htmltidy_disable=no
	fi
])

if test $htmltidy_disable != yes; then
	AC_CHECK_HEADER(tidy.h,[
		ABI_PLUGIN_REPORT([xhtml(html): okay])
		ABI_XHTML_TIDY_CPPFLAGS="$ABI_XHTML_TIDY_CPPFLAGS -DXHTML_HTML_TIDY_SUPPORTED"
		ABI_XHTML_TIDY_LDFLAGS="$ABI_XHTML_TIDY_LDFLAGS -ltidy"
	],[	ABI_PLUGIN_REPORT([xhtml(html): error - libtidy headers not found])
		ABI_PLUGIN_REPORT([xhtml(html):         http://tidy.sourceforge.net/])
		htmltidy_disable=yes
	])
fi
if test $htmltidy_disable = yes; then
	ABI_XHTML_TIDY_CPPFLAGS=""
	ABI_XHTML_TIDY_LDFLAGS=""
fi

ABI_XHTML_XML2_CPPFLAGS=""
ABI_XHTML_XML2_LDFLAGS=""

if test $htmlxml2_disable != yes; then
	PKG_CHECK_MODULES(LIBXML2,[libxml-2.0 >= 2.4.20],[
		ABI_PLUGIN_REPORT([xhtml(html): libxml2 support enabled])
	],[	ABI_PLUGIN_REPORT([xhtml(html): libxml2 support disabled])
		htmlxml2_disable=yes
	])
fi
if test $htmlxml2_disable != yes; then
	ABI_XHTML_XML2_CPPFLAGS="$LIBXML2_CFLAGS -DXHTML_HTML_XML2_SUPPORTED"
	ABI_XHTML_XML2_LDFLAGS="$LIBXML2_LIBS"
fi

ABI_XHTML_CPPFLAGS="$ABI_XHTML_I7EPS_CPPFLAGS $ABI_XHTML_TIDY_CPPFLAGS $ABI_XHTML_XML2_CPPFLAGS"
ABI_XHTML_LDFLAGS="$ABI_XHTML_I7EPS_LDFLAGS $ABI_XHTML_TIDY_LDFLAGS $ABI_XHTML_XML2_LDFLAGS"

AC_SUBST(ABI_XHTML_CPPFLAGS)
AC_SUBST(ABI_XHTML_LDFLAGS)

CPPFLAGS="$_abi_cppflags_save"
LDFLAGS="$_abi_ldflags_save"

if test "$inter7eps_disable" = yes; then
	if test "$htmltidy_disable" = yes -a "$htmlxml2_disable" = yes; then
		abi_plugin_disable=yes
		ABI_PLUGIN_REPORT([xhtml: no options enabled/satisfied - disabling])
	else
		ABI_PLUGIN_REPORT([xhtml: building without Multipart support])
	fi
else
	if test "$htmltidy_disable" = yes -a "$htmlxml2_disable" = yes; then
		ABI_PLUGIN_REPORT([xhtml: building without HTML support])
	else
		ABI_PLUGIN_REPORT([xhtml: okay])
	fi
fi

])

AC_DEFUN([ABIPGN_XHTML_END],[

AM_CONDITIONAL(ABI_XHTML_MHT,[test $inter7eps_disable != yes])
AM_CONDITIONAL(ABI_XHTML_TIDY,[test $htmltidy_disable != yes])
AM_CONDITIONAL(ABI_XHTML_XML2,[test $htmlxml2_disable != yes])

])
