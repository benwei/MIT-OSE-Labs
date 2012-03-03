SYSINFO:=$(shell uname -s)
CYGWIN:=$(findstring CYGWIN,$(SYSINFO))

target = inlineasm
CFLAGS = --save-temps

ifeq ($(CYGWIN),)
CFLAGS += -fasm-blocks
endif
all: $(target) run

$(target): %:%.c
	cc -o $@ $^ $(CFLAGS)

test:
	echo $(SYSINFO),$(a)

run: $(target)
	./$^

clean:
	rm -f *.o $(target) 
