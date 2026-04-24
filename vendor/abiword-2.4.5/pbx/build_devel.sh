#!/bin/sh
#/* AbiWord build scripts
# * Copyright (c) 2004 Hubert Figuiere
# * Copyright (c) 2004-2005 Francis James Franklin
# * 
# * This program is free software; you can redistribute it and/or
# * modify it under the terms of the GNU General Public License
# * as published by the Free Software Foundation; either version 2
# * of the License, or (at your option) any later version.
# * 
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
# * 
# * You should have received a copy of the GNU General Public License
# * along with this program; if not, write to the Free Software
# * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
# * 02111-1307, USA.
# */

abi_config_file=.config

abi_buildstyle="Deployment"

abi_create_disc_image=yes
abi_build_dependencies=yes

abi_arg_symroot=""
abi_arg_objroot=""

for i in $@; do
    if test "x$i" = "x--help"; then
	echo "./build_all.sh [options] [plug-in list, or \"all\"]"
	echo ""
	echo "  e.g., ./build_all.sh --no-disc-image --no-dependencies all"
	echo ""
	echo "Options:"
	echo "  --help             Display this help and exit."
	echo "  --devel            Do a development build."
	echo "  --disc-image       Create a disc image at the end (default for non-development builds)."
	echo "  --no-disc-image    Don't create a disc image at the end."
	echo "  --no-dependencies  Don't build popt, fribidi, png, wv & enchant."
	echo "  --symroot=<path>   Location of build products (overrides default location)."
	echo "  --objroot=<path>   Location of intermediate build products (overrides default location)."
	echo ""
	echo "Plug-in List:"
	echo "  urldict, wikipedia, google, latex, xhtml, bz2abw, OpenWriter, sdw, wordperfect"
	echo "  abigrammar, OpenDocument (HEAD only)"
	echo "  abimathview or abimathview-shared (HEAD only; must be explicit)"
	echo ""
	exit 0
    fi
    if test "x$i" = "x--devel"; then
	abi_buildstyle="Development"
	abi_create_disc_image=no
    fi
done

for i in $@; do
    if test "x$i" = "x--disc-image"; then
	abi_create_disc_image=yes
    fi
    if test "x$i" = "x--no-disc-image"; then
	abi_create_disc_image=no
    fi
    if test "x$i" = "x--no-dependencies"; then
	abi_build_dependencies=no
    fi

    j=`echo "x$i" | cut -c 1-11`
    if test "$j" = "x--symroot="; then
	abi_arg_symroot=`echo "x$i" | sed 's/x--symroot=//'`
    fi
    if test "$j" = "x--objroot="; then
	abi_arg_objroot=`echo "x$i" | sed 's/x--objroot=//'`
    fi
done

if [ -z "$abi_arg_symroot" ]; then
    if [ ! -f $abi_config_file ]; then
	echo "Build directory [`pwd`/BUILD]:"
	read pbxbuilddir
	if [ -z "$pbxbuilddir" ]; then
	    echo "Using default."
	    pbxbuilddir="`pwd`/BUILD"
	fi
	echo "SYMROOT=\"$pbxbuilddir\"" > $abi_config_file
	echo "export SYMROOT" >> $abi_config_file
    fi
    . $abi_config_file
else
    SYMROOT="$abi_arg_symroot"
    export SYMROOT
fi

if [ -z "$abi_arg_objroot" ]; then
    SYM_OBJ="SYMROOT=\"$SYMROOT\""
else
    OBJROOT="$abi_arg_objroot"
    export OBJROOT

    SYM_OBJ="SYMROOT=\"$SYMROOT\" OBJROOT=\"$OBJROOT\""
fi

if [ ! -f wv/bmptopng.c ]; then
    echo "*** Currently the stable branch of wv is required in order to build CocoaAbi."
    echo "    You can get this from cvs by doing the following:"
    echo "        cvs -z3 co -r wv-1-0-0-STABLE wv"
    exit 2
fi

BUILD_CMD=/usr/bin/xcodebuild

if [ ! -x $BUILD_CMD ]; then
    echo "*************************"
    echo "* No devtools found !!! *"
    echo "*************************"
    exit 2
fi

if test "$abi_build_dependencies" = "yes"; then

    (cd poptpbx; eval $BUILD_CMD $SYM_OBJ -project poptpbx2.pbproj -target "poptpbx" -buildstyle '"Deployment - Embedded"' build)
    if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
    fi

    (cd fribidipbx; eval $BUILD_CMD $SYM_OBJ -project fribidipbx2.pbproj -target "fribidipbx" -buildstyle "Deployment" build)
    if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
    fi

    (cd pngpbx; eval $BUILD_CMD $SYM_OBJ -project pngpbx2.pbproj -target "pngpbx" -buildstyle "Deployment" build)
    if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
    fi

    (cd wvpbx; eval $BUILD_CMD $SYM_OBJ -project wvpbx2.pbproj -target "wv" -buildstyle '"Deployment - Embedded"' build)
    if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
    fi

    (cd enchantpbx \
     && eval $BUILD_CMD $SYM_OBJ -project enchantpbx.xcode -target  "AppleSpell"         build \
     && eval $BUILD_CMD $SYM_OBJ -project enchantpbx.xcode -target  "ISpell"             build \
     && eval $BUILD_CMD $SYM_OBJ -project enchantpbx.xcode -target '"enchant framework"' build)
    if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
    fi

fi

(cd abipbx; eval $BUILD_CMD $SYM_OBJ -project abipbx2.pbproj -target Complete -buildstyle $abi_buildstyle build)
if [ $? -ne 0 ] ; then
	echo "********************"
	echo "*** BUILD FAILED ***"
	echo "********************"
	exit 3
fi

for i in $@; do
    if test "$i" = "all" -o "$i" = "urldict"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiURLDict -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiURLDict -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "wikipedia"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiWikipedia -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiWikipedia -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "google"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiGoogle -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiGoogle -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "latex"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiLaTeX -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiLaTeX -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "xhtml"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiXHTML -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiXHTML -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "bz2abw"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiBZ2 -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiBZ2 -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "OpenWriter"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiOpenWriter -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiOpenWriter -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "sdw"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiSDW -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiSDW -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "wordperfect"; then
	(cd abipbx \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiWordPerfect -buildstyle $abi_buildstyle build \
	 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiWordPerfect -buildstyle $abi_buildstyle install)
	if [ $? -ne 0 ] ; then
	    echo "********************"
	    echo "*** BUILD FAILED ***"
	    echo "********************"
	    exit 3
	fi
    fi
    if test "$i" = "all" -o "$i" = "abigrammar"; then
	if test "$abi_build_dependencies" = "yes"; then
	    if test -d link-grammar; then
		(cd link-grammar \
		 && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project link-grammar.xcode -buildstyle $abi_buildstyle build)
		if [ $? -ne 0 ] ; then
		    echo "********************"
		    echo "*** BUILD FAILED ***"
		    echo "********************"
		    exit 3
		fi
	    else
		echo "*** WARNING: Unable to build link-grammar dependency, but continuing anyway. ***"
	    fi
	fi
	if test -f abiword-plugins/tools/abigrammar/plugin.m4; then
	    (cd abipbx \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiLinkGrammar -buildstyle $abi_buildstyle build \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiLinkGrammar -buildstyle $abi_buildstyle install)
	    if [ $? -ne 0 ] ; then
		echo "********************"
		echo "*** BUILD FAILED ***"
		echo "********************"
		exit 3
	    fi
	else
	    echo "*** WARNING: Unable to build abigrammar plug-in (is this 2.2.x, maybe?), but continuing anyway. ***"
	fi
    fi
    if test "$i" = "all" -o "$i" = "OpenDocument"; then
	if test -f abiword-plugins/wp/impexp/OpenDocument/plugin.m4; then
	    (cd abipbx \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiOpenDocument -buildstyle $abi_buildstyle build \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiOpenDocument -buildstyle $abi_buildstyle install)
	    if [ $? -ne 0 ] ; then
		echo "********************"
		echo "*** BUILD FAILED ***"
		echo "********************"
		exit 3
	    fi
	else
	    echo "*** WARNING: Unable to build OpenDocument plug-in (is this 2.2.x, maybe?), but continuing anyway. ***"
	fi
    fi
    if test "$i" = "abimathview"; then
	if test -f abiword-plugins/tools/abimathview/plugin.m4; then
	    (cd abipbx \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiMathView -buildstyle $abi_buildstyle build \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiMathView -buildstyle $abi_buildstyle install)
	    if [ $? -ne 0 ] ; then
		echo "********************"
		echo "*** BUILD FAILED ***"
		echo "********************"
		exit 3
	    fi
	else
	    echo "*** WARNING: Unable to build abimathview plug-in (is this 2.2.x, maybe?), but continuing anyway. ***"
	fi
    fi
    if test "$i" = "abimathview-shared"; then
	if test -f abiword-plugins/tools/abimathview/plugin.m4; then
	    (cd abipbx \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiMathView-Shared -buildstyle $abi_buildstyle build \
	     && eval $BUILD_CMD $SYM_OBJ DSTROOT="$SYMROOT" -project abipbx2.pbproj -target AbiMathView-Shared -buildstyle $abi_buildstyle install)
	    if [ $? -ne 0 ] ; then
		echo "********************"
		echo "*** BUILD FAILED ***"
		echo "********************"
		exit 3
	    fi
	else
	    echo "*** WARNING: Unable to build abimathview plug-in (is this 2.2.x, maybe?), but continuing anyway. ***"
	fi
    fi
done

echo "Copying AbiWord system files to bundle resources directory:"
(cd abi/user/wp; tar cf $SYMROOT/tmp-appfiles.tar strings system.profile*; cd $SYMROOT/AbiWord.app/Contents/Resources; /bin/rm -rf AbiWord; mkdir AbiWord; cd AbiWord; tar xf $SYMROOT/tmp-appfiles.tar; rm $SYMROOT/tmp-appfiles.tar)

echo "Copying AbiWord barbarism files to bundle resources directory:"
(/bin/rm -rf $SYMROOT/AbiWord.app/Contents/Resources/dictionary; mkdir $SYMROOT/AbiWord.app/Contents/Resources/dictionary; cd abidistfiles/dictionary; cp *barbarism.xml $SYMROOT/AbiWord.app/Contents/Resources/dictionary)

echo "Copying AbiWord template files to bundle resources directory:"
(cd abidistfiles/templates; tar cf $SYMROOT/tmp-templates.tar *awt*; cd $SYMROOT/AbiWord.app/Contents/Resources; /bin/rm -rf templates; mkdir templates; cd templates; tar xf $SYMROOT/tmp-templates.tar; rm $SYMROOT/tmp-templates.tar)

rm -f $SYMROOT/AbiWord.dmg

if test "$abi_create_disc_image" = "no"; then
    exit
fi

hdiutil create -megabytes 40 -fs HFS+ -volname AbiWord $SYMROOT/AbiWord.dmg
device_name=`hdiutil attach $SYMROOT/AbiWord.dmg | grep "/Volumes/" | cut -f 1 -d " "`
if test -z $device_name; then
	echo "error: unable to mount $SYMROOT/AbiWord.dmg"
else
	echo "$SYMROOT/AbiWord.dmg mounted as $device_name"
	cp -RP $SYMROOT/AbiWord.app /Volumes/AbiWord/
	cp COPYING /Volumes/AbiWord/COPYING.txt
#	cp README-MacOSX.pdf /Volumes/AbiWord/
	mkdir /Volumes/AbiWord/InvisibleAnt
	mkdir /Volumes/AbiWord/InvisibleAnt/images
	/Developer/Tools/SetFile -a V /Volumes/AbiWord/InvisibleAnt
	cp abipbx/AbiWord-DMG-ReadMe/README.html /Volumes/AbiWord/
	cp abipbx/AbiWord-DMG-ReadMe/InvisibleAnt/*.* /Volumes/AbiWord/InvisibleAnt/
	cp abipbx/AbiWord-DMG-ReadMe/InvisibleAnt/images/*.* /Volumes/AbiWord/InvisibleAnt/images/
	cp abipbx/AbiWord-DMG-Background.png /Volumes/AbiWord/InvisibleAnt/
	cp abipbx/AbiWord-DMG-DS_Store /Volumes/AbiWord/.DS_Store
	hdiutil detach $device_name

	echo ""
	echo "(1) Use the Finder's View Options to set the image background."
	echo "(2) Then: hdiutil convert AbiWord.dmg -format UDZO -o AbiWord-2.4.x.dmg -imagekey zlib-level=9"
	echo ""
fi
