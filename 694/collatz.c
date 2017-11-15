#include <stdio.h>

int count_collatz_seq(int A, int L)
{
    int count = 1;
    do {
        if (A % 2 == 0) {
            A = A / 2;
            ++count;
        } else {
            A = A * 3 + 1;
            if (A < 0 || A > L) {
                break;
            } else {
                ++count;
            }
        }
    } while (A != 1);

    return count;
}

int main()
{
    int A;
    int L;

    int case_count = 0;
    while (!feof(stdin)) {
        if (scanf("%d", &A) == EOF) {
            return 0;
        }
        if (scanf("%d", &L) == EOF) {
            return 0;
        }
        if (A <= 0 && L <= 0) {
            return 0;
        }

        ++case_count;

        printf("Case %d: A = %d, limit = %d, number of terms = %d\n",
               case_count, A, L, count_collatz_seq(A, L));
    }

    return 0;
}
