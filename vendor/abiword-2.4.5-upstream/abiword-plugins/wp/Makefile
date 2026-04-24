#! gmake
# Build all the word processor (wp) specific plugins


################################################################################
DIRS=

LOOP_OVER_DIRS		=						\
	@for d in $(DIRS); do						\
		if test -d $$d; then					\
			echo "entering $$d";	\
			$(MAKE) -C $$d $@;		\
			echo "leaving $$d";	\
		else							\
			echo "Skipping non-directory $$d...";		\
		fi;							\
	done

################################################################################

# These should be fairly xp, but may require extra library
# commented ones are not yet ready [may crash or fail to compile]
DIRS+= 	impexp
DIRS+=	scripts
DIRS+=	abicapi

all:: build

build::
	@echo Entering wp to build plugins.
	-$(LOOP_OVER_DIRS)
	@echo Leaving wp, finished building plugins.

