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

ABI_ROOT:=$(shell pwd)/../../../abi
include $(ABI_ROOT)/src/config/abi_defs.mk

DIRS=				$(ABI_NATIVE) xp

LIBRARY_NAME=		AbiPaint
LIBRARY_VERSION=		$(ABI_VERSION)
TARGETS=			$(PLUGIN)

OBJS=				$(OBJDIR)/AbiPaint.$(OBJ_SUFFIX)	\
				$(OBJDIR)/AbiGeneric.$(OBJ_SUFFIX)	\
				$(OBJDIR)/ut_$(ABI_FE)Process.$(OBJ_SUFFIX)

ifeq ($(ABI_FE), Win32)
# common to all Win32 compilers
	OBJS+=		$(OBJDIR)/pngdib.$(OBJ_SUFFIX)
	OBJS+=		$(OBJDIR)/png2bmp.$(OBJ_SUFFIX)
	OBJS+=		$(OBJDIR)/bmp2png.$(OBJ_SUFFIX)

	EXTRA_LIBS+=	$(OBJDIR)/ut_sleep.$(OBJ_SUFFIX)

# compiler (MinGW, MSVC, etc) specific
ifeq ($(OS_NAME),MINGW32)
	EXTRA_LIBS+=	-lAbiWord.dll
	EXTRA_LIBS+=	-lAbi_libpng

# no longer included by abi_defs.mk
	OS_LIBS+=	-ladvapi32 -lgdi32
else
	EXTRA_LIBS+=	$(BINDIR)/AbiWord.$(LIB_SUFFIX)
	EXTRA_LIBS+=	$(OBJDIR)/libAbi_libpng_s.$(LIB_SUFFIX)
	EXTRA_LIBS+=	$(OBJDIR)/libAbi_zlib_s.$(LIB_SUFFIX) 

# no longer included by abi_defs.mk
	OS_LIBS+=	advapi32.$(LIB_SUFFIX) gdi32.$(LIB_SUFFIX)
endif
endif

include $(ABI_ROOT)/src/config/abi_rules.mk

build:: $(TARGETS)
