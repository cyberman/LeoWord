#!/bin/sh


# 1.2.1 does not build. There is no 1.2.2 atm
cvs co -rHEAD enchant
cvs co -renchant-1-2-1 enchantpbx

curl http://www.abisource.com/downloads/link-grammar/4.2.2/link-grammar-4.2.2.tar.gz -O
tar zxvf link-grammar-4.2.2.tar.gz
ln -sf link-grammar-4.2.2 link-grammar
(cd link-grammar ; \
	if test ! -e link-grammar/link-features.h then ; ./configure; fi ;\
cvs -d `cat ../CVS/Root` co -d link-grammar.xcode  link-grammar/link-grammar.xcode)

tar jxvf ~/fribidi-0.10.4.tar.bz2
ln -sf fribidi-0.10.4 fribidi
(cd fribidi; if test ! -e config.h then ; ./configure; fi)

