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

TARGETS=			$(OBJS)
CPPSRCS= 			ie_impexp_WordPerfect.cpp \
				ie_imp_WordPerfect.cpp \
				ie_exp_WordPerfect.cpp

ifeq ($(ABI_FE), Win32)
ifeq ($(OS_NAME), MINGW32)
	INCLUDES+=	$(shell pkg-config --cflags libwpd-0.8 libwpd-stream-0.8)
else
	CFLAGS += -GX
	INCLUDES+=	-I$(ABI_ROOT)/../libs/glib-2.2/lib/glib-2.0/include
	INCLUDES+=	-I$(ABI_ROOT)/../libs/glib-2.2/include/glib-2.0
	INCLUDES+=	-I$(ABI_ROOT)/../libs/libgsf
	INCLUDES+=	-I$(ABI_ROOT)/../libs/libwpd2
endif
endif

include $(ABI_ROOT)/src/config/abi_rules.mk

build:: $(TARGETS)
