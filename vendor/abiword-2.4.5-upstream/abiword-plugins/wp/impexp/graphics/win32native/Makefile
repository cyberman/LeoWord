#! gmake

## AbiWord
## Copyright (C) 1998 AbiSource, Inc.
##
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU General Public License
## as published by the Free Software Foundation; either version 2
## of the License, or (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  
## 02111-1307, USA.

ABI_ROOT:=$(shell pwd)/../../../../../abi
include $(ABI_ROOT)/src/config/abi_defs.mk

DIRS=				win

LIBRARY_NAME=		Abi_IEG_Win32Native
LIBRARY_VERSION=	$(ABI_VERSION)
TARGETS=			$(PLUGIN)

OBJS=				$(OBJDIR)/ie_impGraphic_Win32Native.$(OBJ_SUFFIX)	\
				$(OBJDIR)/ie_impGraphic_Win32GDIPlus.$(OBJ_SUFFIX)

ifeq ($(ABI_FE), Win32)
# common to all Win32 compilers

# compiler (MinGW, MSVC, etc) specific
ifeq ($(OS_NAME),MINGW32)
	EXTRA_LIBS+=	-lAbiWord.dll
	EXTRA_LIBS+=	-lAbi_libpng
#	EXTRA_LIBS+=	-lAbi_zlib	
	OS_LIBS+= -lkernel32 -luser32 -lgdi32 -lcomdlg32 -ladvapi32 -lshell32 -luuid -lcomctl32 -lole32 -loleaut32
else
	EXTRA_LIBS=	 $(BINDIR)/AbiWord.$(LIB_SUFFIX) $(ABI_ZLIB_LIB) $(OBJDIR)/Abi_libpng.$(LIB_SUFFIX)
	OS_LIBS+= kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib shell32.lib uuid.lib comctl32.lib ole32.lib oleaut32.lib 
endif
endif

include $(ABI_ROOT)/src/config/abi_rules.mk

build:: $(TARGETS)
