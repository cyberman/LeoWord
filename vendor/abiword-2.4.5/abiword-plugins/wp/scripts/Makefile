#! gmake
# Build all the script plugins


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
DIRS+= 	shell


all:: build

build::
	@echo Entering script to build plugins.
	-$(LOOP_OVER_DIRS)
	@echo Leaving script, finished building plugins.

