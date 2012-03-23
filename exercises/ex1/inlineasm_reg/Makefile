SYSINFO:=$(shell uname -s)
CYGWIN:=$(findstring CYGWIN,$(SYSINFO))

target = inlineasm
CFLAGS = -O0 --save-temps

ifeq ($(CYGWIN),)

ifeq ($(SYSINFO),Linux)

else # not Linux
CFLAGS += #-fasm-blocks
endif # Linux

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
