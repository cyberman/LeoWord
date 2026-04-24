#! gmake
# Build all the importer/exporter plugins supported on Windows


################################################################################

DIRS=

LOOP_OVER_DIRS		=						\
	@for d in $(DIRS); do						\
		if test -d $$d; then					\
			echo "Attempting to make $$d plugin ...";	\
			$(MAKE) -C $$d $@;		\
			echo "Build attempt for $$d plugin complete.";	\
		else							\
			echo "Skipping non-directory $$d...";		\
		fi;							\
	done

################################################################################

# These should be fairly xp, but may require extra library
# commented ones are not yet ready [may crash or fail to compile]
DIRS= 	bmp
#DIRS+=	jpeg #Deprecated, 6 June 2006
#DIRS+= 	svg
DIRS+=	wmf
DIRS+=	win32native

# The following are Gdk/Unix specific
#DIRS+= librsvg


all:: build

build::
	@echo "Building image (graphics) importer/exporter plugins."
	-$(LOOP_OVER_DIRS)
	@echo Finished building importer/exporter plugins.

