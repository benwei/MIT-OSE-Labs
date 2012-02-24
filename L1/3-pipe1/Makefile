target=pipe1
OBJS=pipe1.o
CFILES=pipe1.c

all: $(target)

.c.o:
	$(CC) -c $< -o $@

$(target): $(OBJS)
	$(CC) -o $@ $^

run: $(target)
	./$^

clean:
	rm -f *.o $(target)
