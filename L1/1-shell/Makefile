target=ush
OBJS=ush.o
CFILES=ush.c

all: $(target)

.c.o:
	$(CC) -c $< -o $@

$(target): $(OBJS)
	$(CC) -o $@ $^

run: $(target)
	./$^

clean:
	rm -f *.o $(target)
