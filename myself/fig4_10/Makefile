ROOT=../../apue.3e
LDFLAGS=
LDDIR=-L$(ROOT)/lib
LDLIBS=$(LDDIR) -lapue
CFLAGS=-I$(ROOT)/include -Wall -DLINUX
LIBAPUE=$(ROOT)/lib/libapue.a

all: st_dev
%: %.c $(LIBAPUE)
	gcc $(CFLAGS) $< -o $@ $(LDFLAGS) $(LDLIBS)
.PHONY: clean
clean:
	rm -rf *.o myls
include $(ROOT)/Make.libapue.inc
