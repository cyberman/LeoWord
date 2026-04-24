# start: abiword-plugins/ac-helpers/abi-plugin-platform.m4
#
# Copyright (C) 2003 Francis James Franklin <fjf@alinameridon.com>
# Copyright (C) 2003 AbiSource, Inc.
#
# This file is free software; you may copy and/or distribute it with
# or without modifications, as long as this notice is preserved.
# This software is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even
# the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
# PURPOSE.
#
# The above license applies to THIS FILE ONLY, the abiword code
# itself may be copied and distributed under the terms of the GNU
# GPL, see COPYING for more details
#
# This file detects which of the AbiWord platforms we are currently
# building on.  The detection logic in question is mostly by Jeff
# Hostetler, and is taken from the original AbiWord build system.  
#
# Usage: ABI_PLUGIN_PLATFORM
# 
# sets:
#     abi_platform=[qnx|unix|gnome|cocoa]
#     abi_platf_be=[qnx|unix]
# 
# substitutions:
#     PLATFORM_CPPFLAGS
#     PLATFORM_LDFLAGS
# 
# conditionals:
#     BUILD_PLATFORM_COCOA
#     BUILD_PLATFORM_GNOME
#     BUILD_PLATFORM_QNX

AC_DEFUN([ABI_PLUGIN_PLATFORM],[

abi_platform=unix
abi_platf_be=unix

PLATFORM_CPPFLAGS=""
PLATFORM_LDFLAGS=""

xuname="x`uname`"

# convenience option for building with fink installed on Darwin...
# 
AC_ARG_WITH(fink,[  --with-fink       add /sw/... to CPP/LDFLAGS (Mac OSX)],[
	if test "x$withval" = "xyes"; then
		CPPFLAGS="$CPPFLAGS -I/sw/include"
		LDFLAGS="$LDFLAGS -L/sw/lib"
	fi
])

if test "$xuname" = "xQNX"; then
	ABI_PLATFORM_QNX
elif test "$xuname" = "xDarwin"; then
	ABI_PLATFORM_COCOA
fi

if test $abi_platform = unix; then
	ABI_PLATFORM_UNIX
fi

AC_SUBST(PLATFORM_CPPFLAGS)
AC_SUBST(PLATFORM_LDFLAGS)

AM_CONDITIONAL(BUILD_PLATFORM_COCOA,[test "$abi_platform" = "cocoa"])
AM_CONDITIONAL(BUILD_PLATFORM_GNOME,[test "$abi_platform" = "gnome"])
AM_CONDITIONAL(BUILD_PLATFORM_QNX,  [test "$abi_platform" = "qnx"  ])

])

AC_DEFUN([ABI_PLATFORM_QNX],[

abi_platform=qnx
abi_platf_be=qnx

if test "x$CC" = "x"; then
	CC="qcc"
	export CC
fi
if test "x$CXX" = "x"; then
	if test "$OS_RELEASE" = "6.1.0"; then
		CXX="QCC -Vgcc_ntox86"
	else
		CXX="QCC -Vgcc_ntox86_gpp"
	fi
	export CXX
fi

])

AC_DEFUN([ABI_PLATFORM_COCOA],[

abi_platform=cocoa
abi_platf_be=unix

AC_ARG_ENABLE(Cocoa,[  --disable-Cocoa   Disable Cocoa build if on Darwin],[
	if test "x$enableval" = "xno"; then
		abi_platform=unix
	fi
])

if test "$abi_platform" = "cocoa"; then
	PKG_CHECK_MODULES(GLIB,[
		fribidi >= 0.10.4
		glib-2.0 >= 2.0
	])

	PLATFORM_CPPFLAGS="$GLIB_CFLAGS"
	PLATFORM_LDFLAGS="$GLIB_LIBS"
fi

])

AC_DEFUN([ABI_PLATFORM_UNIX],[

abi_platform=unix
abi_platf_be=unix

AC_ARG_ENABLE(gnome,[  --enable-gnome    Turn on gnome],[
	if test "x$enableval" = "xyes"; then
		abi_platform=gnome
	fi
])

if test "$abi_platform" = "gnome"; then
	NAUTILUS_CFLAGS=""
	NAUTILUS_LIBS=""

	PKG_CHECK_MODULES(GNOME,[
		xft >= 2.0
		fontconfig >= 1.0
		fribidi >= 0.10.4
		gmodule-2.0 >= 2.0
		gtk+-2.0 >= 2.0
		libglade-2.0 >= 2.0.0
		libbonobo-2.0 >= 2.0
		libgnomeui-2.0 >= 2.0
		libgnomeprint-2.2 >= 2.2.1
		libgnomeprintui-2.2 >= 2.2.1
	])
	PKG_CHECK_MODULES(NAUTILUS,[
		libnautilus >= 2.0
	],[	_abi_gnome_nautilus=yes
	],[	_abi_gnome_nautilus=no
	])
	if test "x$_abi_gnome_nautilus" = "xyes"; then
		NAUTILUS_CFLAGS="$NAUTILUS_CFLAGS -DHAVE_NAUTILUS=1"
	fi

	PLATFORM_CPPFLAGS="$NAUTILUS_CFLAGS $GNOME_CFLAGS -DHAVE_GNOME=1"
	PLATFORM_LDFLAGS="$NAUTILUS_LIBS $GNOME_LIBS"
else
	PKG_CHECK_MODULES(GTK,[
		xft >= 2.0
		fontconfig >= 1.0
		fribidi >= 0.10.4
		gmodule-2.0 >= 2.0
		gtk+-2.0 >= 2.0
		libglade-2.0 >= 2.0.0
	])

	PLATFORM_CPPFLAGS="$GTK_CFLAGS"
	PLATFORM_LDFLAGS="$GTK_LIBS"
fi

])

#
# end: abiword-plugins/ac-helpers/abi-plugin-platform.m4
