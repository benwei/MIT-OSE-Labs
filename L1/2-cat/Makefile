target=ucat
OBJS=ucat.o
CFILES=ucat.c

all: $(target)

.c.o:
	$(CC) -c $< -o $@

$(target): $(OBJS)
	$(CC) -o $@ $^

run: $(target)
	./$^ ucat.c

clean:
	rm -f *.o $(target)
