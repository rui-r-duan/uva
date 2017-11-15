CC  = gcc
LD  = gcc
OBJ = autoedit
LFLAG = -g -lm -lcrypt -Wall -pipe -DONLINE_JUDGE

$(OBJ): $(OBJ).c
	$(CC) $(LFLAG) -o $@ $<

clean:
	rm $(OBJ)
