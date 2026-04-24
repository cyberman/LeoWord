#!/bin/sh
#/* AbiWord build scripts
# * Copyright (c) 2004 Hubert Figuiere
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

FINK_LIB_DIR=/sw/lib
EMBED_LIB_DIR=@executable_path/../Frameworks
BUNDLE_LIB_DIR=$SYMROOT/AbiWord.app/Contents/Frameworks

if [ x"$*" == "x" ]; then
    # no arguments - default behaviour

    for i in `ls $BUNDLE_LIB_DIR/*.dylib` ; do
	echo "Relocating $i..."
	linked_libs=`otool -L $i 2>/dev/null | grep $FINK_LIB_DIR | cut -d\  -f 1`
	for j in $linked_libs ; do
	    install_name_tool -change $j `echo $j | sed -e "s,$FINK_LIB_DIR,$EMBED_LIB_DIR,"` $i
	done
    done
    (cd $BUNDLE_LIB_DIR && rm -f libglib-2.0.0.dylib && ln -s libglib-2.0.dylib libglib-2.0.0.dylib)
    (cd $BUNDLE_LIB_DIR && rm -f libgobject-2.0.0.dylib && ln -s libgobject-2.0.dylib libgobject-2.0.0.dylib)

else
    for lib in $@; do
	i=$BUNDLE_LIB_DIR/$lib
	echo "Relocating $i..."
	linked_libs=`otool -L $i 2>/dev/null | grep $FINK_LIB_DIR | cut -d\  -f 1`
	for j in $linked_libs ; do
	    install_name_tool -change $j `echo $j | sed -e "s,$FINK_LIB_DIR,$EMBED_LIB_DIR,"` $i
	done
    done
fi
