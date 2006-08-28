# Configure script for GNU Mach Card Manager
# Copyright (C) 2006  Stefan Siegl <stesie@brokenpipe.de>, Germany
#
dnl Process this file with autoconf to produce a configure script.

#AC_INIT(configure.in)
AC_INIT(cardmgr-gnumach, 0.1, [stesie@brokenpipe.de])
AM_INIT_AUTOMAKE(cardmgr-gnumach, 0.1, [stesie@brokenpipe.de])
AM_MAINTAINER_MODE
AM_CONFIG_HEADER(config.h)

AC_ISC_POSIX
AC_PROG_CC
AM_PROG_CC_STDC
AC_PROG_YACC
AM_PROG_LEX

AC_GNU_SOURCE
AC_HEADER_STDC

pkgsysconfdir='${sysconfdir}/pcmcia'
AC_SUBST(pkgsysconfdir)

AC_CHECK_LIB([threads], [cthread_fork],,
	     AC_MSG_ERROR([cardmgr-gnumach requires libthreads]))

AC_OUTPUT([
Makefile
etc/Makefile
etc/cis/Makefile
src/Makefile
src/pcmcia/Makefile
])

