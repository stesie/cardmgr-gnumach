#
# cardmgr/Makefile 1.93 2003/11/22 08:54:13 (David Hinds)
#

# Include site dependent options

prefix = /
DESTDIR = 

SRCS  = cardmgr.c cardctl.c yacc_config.c lex_config.c
TOOLS = cardmgr cardctl

CFLAGS=-Wall -W -ggdb -O0
CPPFLAGS=-I. -D_GNU_SOURCE

all:	$(SRCS) $(TOOLS)

clean:
	rm -f core core.* *.o *.s *.a *~ .depend .depfiles/*.d
	rm -f $(TOOLS) $(EXTRA)

cardmgr: cardmgr.o yacc_config.o lex_config.o
	$(CC) -o $@ $^ $(CFLAGS) -lthreads

yacc_config.o lex_config.o: %.o: %.c
	$(CC) -c -MD -O -pipe $(CPPFLAGS) $<
	@mkdir -p .depfiles ; mv $*.d .depfiles

parser: lex_config.o yacc_config.c
	$(CC) -O $(CPPFLAGS) -DYYDEBUG=1 -o $@ yacc_config.c lex_config.o

cardmgr.o: mach-ioctl.c mach-ioctls.h
cardctl.o: mach-ioctl.c mach-ioctls.h

install: cardmgr cardctl
	install -d $(DESTDIR)/$(prefix)/sbin
	install -m 0755 cardmgr $(DESTDIR)/$(prefix)/sbin
	install -m 4755 cardctl $(DESTDIR)/$(prefix)/sbin

uninstall:
	rm -f $(DESTDIR)/$(prefix)/sbin/cardmgr
	rm -f $(DESTDIR)/$(prefix)/sbin/cardctl

