CC  = gcc
LD  = gcc
OBJ = immdec
LFLAG = -g -lm -lcrypt -Wall -pipe -DONLINE_JUDGE

$(OBJ): $(OBJ).c
	$(CC) $(LFLAG) -o $(OBJ) $(OBJ).c

clean:
	rm $(OBJ)
