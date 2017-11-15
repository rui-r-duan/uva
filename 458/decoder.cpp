#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
    string line;
    const char d = '*' - '1';
    while (getline(cin, line)) {
        for (int i = 0; i < line.size(); ++i) {
            line[i] += d;
        }
        cout << line << endl;
    }
    return 0;
}
