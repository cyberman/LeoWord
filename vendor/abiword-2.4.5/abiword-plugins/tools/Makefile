#! gmake
# Build all the tools plugins supported on Windows

DIRS=

# These should be fairly xp, but may require extra library
# commented ones are not yet ready [may crash or fail to compile]
#DIRS+= 	abiCAPI

#DIRS+= 	abicommand
#DIRS+=	abidicdl
DIRS+= 	abigrammar
DIRS+= 	abimathview
DIRS+= 	abipaint
DIRS+= 	aiksaurus
DIRS+= 	babelfish
DIRS+= 	festvox
DIRS+=	freetranslation
#DIRS+=	gda
#DIRS+=	gdict
DIRS+=	google
#DIRS+=	gypsython
#DIRS+= 	link-grammar
#DIRS+=	ots
#DIRS+=	referee
DIRS+= 	urldict
DIRS+= 	wikipedia



################################################################################

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

all:: build

build::
	@echo Building tools plugins.
	-$(LOOP_OVER_DIRS)
	@echo Finished building tools plugins.
