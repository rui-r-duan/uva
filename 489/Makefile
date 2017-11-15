CC  = g++
LD  = g++
OBJ = hangman
LFLAG = -g -lm -lcrypt -O2 -pipe -DONLINE_JUDGE

$(OBJ): $(OBJ).cpp
	$(CC) $(LFLAG) -o $(OBJ) $(OBJ).cpp

clean:
	rm $(OBJ)