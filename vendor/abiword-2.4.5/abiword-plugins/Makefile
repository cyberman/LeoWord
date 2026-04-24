#! gmake
# Build all the plugins

ABI_ROOT:=$(shell pwd)/../abi
include $(ABI_ROOT)/src/config/abi_defs.mk


################################################################################
DIRS=

LOOP_OVER_DIRS		=						\
	@for d in $(DIRS); do						\
		if test -d $$d; then					\
			set -e;						\
			echo "$(MAKE) -C $$d $@";	\
			$(MAKE) -C $$d $@;		\
			set +e;						\
		else							\
			echo "Skipping non-directory $$d...";		\
		fi;							\
	done

################################################################################

# These should be fairly xp, but may require extra library
# commented ones are not yet ready [may crash or fail to compile]
DIRS+= 	tools
DIRS+=	wp


all:: build

build::
	@echo About to build all plugins.
	+$(LOOP_OVER_DIRS)
	@echo Finished building all plugins.


ifeq ($(ABI_FE), Win32)
distribution: all
ifeq ($(ABI_OPT_DEBUG),1)
	@echo ABI_OPT_DEBUG is set.  Building a setup program in
	@echo debug mode is not allowed.
#	exit 1
else
	@echo Creating plugin installers
	$(ABICOPY) $(ABI_ROOT)/src/pkg/win/setup/pluginTools.nsi $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/src/pkg/win/setup/pluginImportersExporters.nsi $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/../libs/glib-2.2/bin/libglib-2.0-0.dll $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/../libs/glib-2.2/bin/libgobject-2.0-0.dll $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/../libs/glib-2.2/bin/iconv.dll $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/../libs/glib-2.2/bin/intl.dll $(PLUGINDIR)
	$(ABICOPY) $(ABI_ROOT)/src/pkg/win/setup/pluginGLibImportersExporters.nsi $(PLUGINDIR)
	cd $(PLUGINDIR); \
	$(BINDIR)/makensis$(EXE_SUFFIX) ./pluginTools.nsi; \
	$(BINDIR)/makensis$(EXE_SUFFIX) ./pluginImportersExporters.nsi; \
	$(BINDIR)/makensis$(EXE_SUFFIX) ./pluginGLibImportersExporters.nsi
	@echo Plugin installers built.
endif
endif
