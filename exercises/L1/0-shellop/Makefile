all: 1 2 3

1:
	sort < in
2:
	sort < in | uniq
3:
	# sort < in > out
	# uniq out > out2
	# wc out2
	# rm out out2
	## equal to following line
	sort < in | uniq | wc

clean:
