AC_DEFUN([ABI_PLUGIN_INIT],[
	dnl Initialize variables:
	dnl 
	abi_plugin_major=""
	abi_plugin_minor=""
	abi_plugin_micro=""
	abi_plugin_source=""
	abi_plugin_target=""
	abi_plugin_version=""

	abi_plugin_topdir=`pwd`
	rm -f $abi_plugin_topdir/plugin.status

	dnl Set plugins version:
	dnl 
	if [ test "x$1" = "x" ]; then
		AC_MSG_ERROR([No AbiWord plugins version number!])
	fi
	abi_plugin_version="$1"
	abi_plugin_major=`echo $abi_plugin_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\1/'`
	abi_plugin_minor=`echo $abi_plugin_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\2/'`
	abi_plugin_micro=`echo $abi_plugin_version | sed 's/\([[0-9]]*\).\([[0-9]]*\).\([[0-9]]*\)/\3/'`
	abi_plugin_version="$abi_plugin_major.$abi_plugin_minor.$abi_plugin_micro"
	echo ""
	echo "Configuring AbiWord plugins for Version $abi_plugin_version"
	echo ""

	dnl Find the AbiWord sources:
	dnl 
	AC_MSG_CHECKING(for AbiWord source)
	AC_ARG_WITH(abiword,[  --with-abiword=DIR      AbiWord source is in DIR],[
		if [ test "x$withval" = "xno" ]; then
			AC_MSG_ERROR([* * * AbiWord sources are required for building plugins! * * *])
		elif [ test "x$withval" = "xyes" ]; then
			AC_MSG_WARN([* * * assuming peer directory for sources * * *])
		else
			if [ test -d "$withval" ]; then
				abi_plugin_source="$withval"
			else
				AC_MSG_ERROR("$withval is not a directory")
			fi
		fi
	],[	if test -d ../abi; then
			abi_plugin_source="../abi"
		else
			AC_MSG_ERROR([can't find AbiWord source in peer; use --with-abiword=DIR])
		fi
	])
	if [ test "x$abi_plugin_source" = "x" ]; then
		AC_MSG_ERROR([* * * unable to find AbiWord sources - which are required! * * *])
	else
		AC_MSG_RESULT($abi_plugin_source)
	fi
	case $abi_plugin_source in
	/* | ?:/*)
	  # absolute path
	  ;;
	*)
	  # relative path to the SOURCE dir
	  abi_plugin_source="\$(top_srcdir)/$abi_plugin_source"
	  ;;
	esac

	dnl Find AbiWord
	dnl
	if test "x$libdir" != 'x${exec_prefix}/lib'; then
		abi_plugin_target="$libdir"
	elif test "x$prefix" != "xNONE"; then
		abi_plugin_target="$prefix/lib"
	else
		abi_plugin_target="/usr/local/lib"
	fi
	echo ""
	echo "Installing plugins in $abi_plugin_target/AbiWord-2.4/plugins"
	echo ""

	export abi_plugin_major
	export abi_plugin_minor
	export abi_plugin_micro
	export abi_plugin_source
	export abi_plugin_target
	export abi_plugin_version
	export abi_plugin_topdir

	dnl platform detection
	dnl 
	ABI_PLUGIN_PLATFORM
])
