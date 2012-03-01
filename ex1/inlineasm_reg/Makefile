target = inlineasm
CFLAGS = -fasm-blocks --save-temps
all: $(target) run

$(target): %:%.c
	cc -o $@ $^ $(CFLAGS)

run: $(target)
	./$^

clean:
	rm -f *.o $(target) 
