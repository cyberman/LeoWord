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
