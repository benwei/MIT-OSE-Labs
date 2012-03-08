
projects=$(wildcard *)

all:

run:
	sh scripts/runqemu.sh

clean: mk-clean

include Makefile.rules
