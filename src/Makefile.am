# Copyright (C) 2007 Satya Kiran Popuri <spopur2@uic.edu>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

DEFS += -DPKGDATADIR=\"$(pkgdatadir)\"
AM_YFLAGS = "-dv"
INCLUDES = -I/usr/include/crypto++ -lcrypto++ -lpthread
LDADD = -lcrypto++ -lctemplate_nothreads -lpthread
CC = g++

EXTRA_DIST = cdl2cpp.tpl
dist_pkgdata_DATA = cdl2cpp.tpl

bin_PROGRAMS = cdlcc cdlpp

cdlcc_SOURCES = parse-cdl.h parse-cdl.y \
		CDLType.cpp CDLType.h \
	 	Codegen.cpp Codegen.h \
		Constraints.h \
		SymbolTable.cpp SymbolTable.h \
		scan-cdl.c

cdlpp_SOURCES = preproc-cdl.l

EXTRA_cdlcc_SOURCES = scan-cdl.l

BUILT_SOURCES = scan-cdl.c preproc-cdl.c parse-cdl.c parse-cdl.h
