#include <cstdio>
using namespace std;

const int MAX_WORD = 1024;

char word[MAX_WORD] = {0};
char guess[MAX_WORD] = {0};
char table[26] = {0};        // 0: not in word, 1: in word, 2: hit, 3: fail

inline size_t char_index(char c)
{
    return c - 'a';
}

int main()
{
    const int max_strokes = 7;
    int round = 0;
    int char_types_count = 0;
    int hit_count = 0;
    int fail_count = 0;
    int i = 0;                  // guess count
    bool got_result = false;

    while (scanf("%d\n", &round) != EOF) {
        if (round == -1) {
            break;
        }

        (void)scanf("%s\n", word);
        (void)scanf("%s\n", guess);

        printf("Round %d\n", round);

        // Fill the char table according to the input word.
        i = 0;
        while (word[i]) {
            if (table[char_index(word[i])] == 0) {
                table[char_index(word[i])] = 1;
                ++char_types_count;
            }
            ++i;
        }

        // Fill the char table according to the guess word, and do some count.
        i = 0;
        while (guess[i]) {
            if (table[char_index(guess[i])] == 1) {
                ++hit_count;
                table[char_index(guess[i])] = 2; // mark as solved
            } else if (table[char_index(guess[i])] == 0){
                ++fail_count;
                table[char_index(guess[i])] = 3; // mark as fail
            }
            ++i;
            if (fail_count >= max_strokes) {
                printf("You lose.\n");
                got_result = true;
                break;
            } else if (hit_count == char_types_count) {
                printf ("You win.\n");
                got_result = true;
                break;
            }
        }

        // Judge the game result.
        if (!got_result && hit_count < char_types_count) {
            printf("You chickened out.\n");
            got_result = true;
        }

        // Prepare the next round.
        fail_count = 0;
        hit_count = 0;
        char_types_count = 0;
        got_result = false;
        for (i = 0; i < 26; ++i)
            table[i] = 0;
    }

    return 0;
}
