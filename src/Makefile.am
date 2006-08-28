## Process this file with automake to produce Makefile.in

SUBDIRS = pcmcia
AM_CPPFLAGS = -DPACKAGE_SYSCONFDIR=\"${pkgsysconfdir}\"

sbin_PROGRAMS = cardctl cardmgr

cardmgr_SOURCES = \
	cardmgr.c \
	cardmgr.h \
	mach-ioctl.h \
	yacc_config.c \
	yacc_config.h \
	lex_config.c

cardctl_SOURCES = \
	cardctl.c \
	mach-ioctl.h

EXTRA_DIST = \
	mach-ioctl.c


