#include <cstdio>
using namespace std;

int main()
{
    int n;
    int amplitude, frequency;
    int i, j, k, w;

    (void)scanf("%d", &n);

    for (i = 0; i < n; ++i) {
        scanf("%d", &amplitude);
        scanf("%d", &frequency);
        for (j = 0; j < frequency; ++j) {
            for (k = 1; k <= amplitude; ++k) {
                for (w = 1; w <= k; ++w) {
                    printf("%d", k);
                }
                printf("\n");
            }
            for (k = amplitude - 1; k >= 1; --k) {
                for (w = 1; w <= k; ++w) {
                    printf("%d", k);
                }
                printf("\n");
            }
            if (j < frequency - 1)
                printf("\n");
        }
        if (i < n - 1)
            printf("\n");
    }

    return 0;
}
