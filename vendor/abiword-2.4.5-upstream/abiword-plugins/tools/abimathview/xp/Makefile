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

ABI_ROOT:=$(shell pwd)/../../../../abi
include $(ABI_ROOT)/src/config/abi_defs.mk

TARGETS=			$(OBJS)
CPPSRCS=			AbiMathView.cpp \
				gr_Abi_CharArea.cpp \
				gr_Abi_ColorArea.cpp \
				gr_Abi_ComputerModernShaper.cpp \
				gr_Abi_DefaultShaper.cpp \
				gr_Abi_InkArea.cpp \
				gr_Abi_MathGraphicDevice.cpp \
				gr_Abi_RenderingContext.cpp \
				gr_Abi_StandardSymbolsShaper.cpp \
				ie_imp_MathML.cpp

ifeq ($(ABI_FE), Win32)
ifeq ($(OS_NAME), MINGW32)
	INCLUDES+=	$(shell pkg-config --cflags glib-2.0 mathview-core mathview-frontend-libxml2)
	INCLUDES+=  -I../itex2MML
	INCLUDES+=  -DHAVE_EXT_HASH_MAP
	# TODO: get the version from some sane place NOTE: this might conflict with gtkmathview/Init.hh around line 52
	INCLUDES+=  -DVERSION=\"2.3.4\"
	# Fscked up, but needed for snprintf.. silly mingw headers
	INCLUDES+=  -D_GLIBCXX_USE_C991 -D_GLIBCXX_USE_C99_CHECK -D_GLIBCXX_USE_C99_DYNAMIC
else
	CFLAGS += -GX
#	TODO
endif
endif

include $(ABI_ROOT)/src/config/abi_rules.mk

build:: $(TARGETS)
