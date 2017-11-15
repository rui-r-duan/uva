CC  = gcc
LD  = gcc
OBJ = mirrorpalindrome
LFLAG = -g -lm -lcrypt -O2 -pipe -ansi -DONLINE_JUDGE

$(OBJ): $(OBJ).c
	$(CC) $(LFLAG) -o $(OBJ) $(OBJ).c

clean:
	rm $(OBJ)