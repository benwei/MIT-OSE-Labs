all: leal

leal: test_leal.c
	cc -o $@ test_leal.c --save-temps

run: leal 
	./$^

clean:
	rm -f *.o leal
