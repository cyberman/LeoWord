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
DIRS+= 	applix
#DIRS+=	awml
DIRS+= 	bz2abw
DIRS+= 	clarisworks
DIRS+= 	docbook
DIRS+= 	eml
DIRS+= 	graphics
#DIRS+= 	hancom
DIRS+= 	hrtext
DIRS+= 	iscii-text
#DIRS+= 	kword
DIRS+= 	latex
DIRS+= 	mif
DIRS+= 	mswrite
DIRS+= 	nroff
DIRS+= 	OpenDocument
DIRS+= 	OpenWriter
DIRS+= 	pdb
# DIRS+= 	pdf  #This doesn't work.  Bye bye!  6 June 2006
DIRS+= 	psion
DIRS+= 	pw
DIRS+= 	sdw
DIRS+= 	t602
DIRS+= 	wml
DIRS+= 	wordperfect
#DIRS+= 	xhtml
DIRS+= 	xsl-fo
DIRS+=		passepartout

all:: build

build::
	@echo Building importer/exporter plugins.
	-$(LOOP_OVER_DIRS)
	@echo Finished building importer/exporter plugins.

