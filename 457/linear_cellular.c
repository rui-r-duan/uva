#include <stdio.h>
#include <string.h>

#define DISH_NUM 40

void grow_one_day(const int *dna, const int *curr, int *next)
{
    int i;
    int k = curr[0] + curr[1];
    next[0] = dna[k];
    for (i = 1; i <= DISH_NUM - 2; ++i) {
        k = curr[i - 1] + curr[i] + curr[i + 1];
        next[i] = dna[k];
    }
    k = curr[DISH_NUM - 2] + curr[DISH_NUM - 1];
    next[DISH_NUM - 1] = dna[k];
}

void print_line(int *densities)
{
    int i;
    for (i = 0; i < DISH_NUM; ++i) {
        switch (densities[i]) {
        case 0:
            putchar(' ');
            break;
        case 1:
            putchar('.');
            break;
        case 2:
            putchar('x');
            break;
        case 3:
            putchar('W');
            break;
        default:
            break;
        }
    }
    putchar('\n');
}

void exchange(int **a, int **b)
{
    int *t = *a;
    *a = *b;
    *b = t;
}

int main()
{
    int case_count = 0;
    int dna[10] = { 0 };
    int a[DISH_NUM] = { 0 }; /* population densities in the line of dishes */
    int b[DISH_NUM] = { 0 };
    int i, j, day;
    int *curr = a;
    int *next = b;
    
    scanf("%d", &case_count);
    for (i = 0; i < case_count; ++i) {
        for (j = 0; j < 10; ++j) {
            scanf("%d", &dna[j]);
        }

        curr = a;
        next = b;
        memset(curr, 0, sizeof(int) * DISH_NUM);
        curr[19] = 1;

        day = 0;
        while (day < 50) {
            print_line(curr);
            grow_one_day(dna, curr, next);
            ++day;
            exchange(&curr, &next);
        }
        if (i < case_count - 1)
            putchar('\n');
    }
    return 0;
}
