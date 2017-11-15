rareorder: rareorder.c
	gcc -g -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE -o rareorder rareorder.c

test: test.c
	gcc -o test test.c

ref: ref.cpp
	g++ -lm -lcrypt -O2 -pipe -DONLINE_JUDGE -o ref ref.cpp

clean:
	rm rareorder test