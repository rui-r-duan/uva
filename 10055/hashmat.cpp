#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    long a, b;
    while (cin >> a >> b) {
        cout << abs(b - a) << endl;
    }
    return 0;
}
