#                                               -*- Autoconf -*-
# Copyright (C) 2007 Satya Kiran Popuri <spopur2@uic.edu>
#  
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without 
# modifications, as long as this notice is preserved.
# 
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
#
# Process this file with autoconf to produce a configure script.

AC_PREREQ(2.60)
AC_INIT([CDL compiler], 
        [1.0], 
	[say_anything@rites.uic.edu],
	[cdl-compiler])

AC_CONFIG_SRCDIR([src/SymbolTable.cpp])
AC_CONFIG_AUX_DIR([config])
AM_INIT_AUTOMAKE([dist-bzip2])

# Checks for programs.
AC_PROG_YACC
AC_PROG_CXX
AC_PROG_CC
AC_PROG_LEX

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lctemplate_nothreads':
#AC_CHECK_LIB([ctemplate_nothreads], [main])


# Checks for header files.
AC_FUNC_ALLOCA
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h inttypes.h libintl.h malloc.h stddef.h stdlib.h string.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_CONST
AC_TYPE_INT16_T
AC_TYPE_INT32_T
AC_TYPE_INT8_T
AC_TYPE_SIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([memset strdup])

AC_PROG_MAKE_SET

AC_CONFIG_FILES([
   Makefile
   doc/Makefile
   src/Makefile
])

AC_OUTPUT
