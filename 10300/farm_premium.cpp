#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    int n, f, s, c, p;
    int sum(0);
    scanf("%d", &n);
    while (n--) {
        sum = 0;
        scanf("%d", &f);
        while (f--) {
            scanf("%d %d %d", &s, &c, &p);
            sum += s * p;
        }
        printf("%d\n", sum);
    }
    return 0;
}

