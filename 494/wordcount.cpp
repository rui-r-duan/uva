#include <iostream>
#include <sstream>
using namespace std;

int main(int argc, char* argv[])
{
    string line;
    while (getline(cin, line)) {
        int cnt(0);
        bool bInWord(false);
        for (string::size_type i = 0; i < line.size(); ++i) {
            if (isalpha(line[i])) {
                bInWord = true;
            } else {
                if (bInWord) {
                    ++cnt;
                    bInWord = false;
                }
            } 
        }
        cout << cnt << endl;
    }
    return 0;
}
