
projects=$(wildcard *)

all:

run:
	sh scripts/runqemu.sh

clean: mk-clean
	rm -f lab/jos.in lab/jos.in

include Makefile.rules
