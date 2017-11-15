/*
    coder: ACboy
    date: 2010-2-16
    result: AC
    description: UVa 10115 Automatic Editing
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<string> findve;
vector<string> replaceve;

int main()
{
    int n;
    int i;

    while (cin >> n)
    {
        string k;
        if (n == 0) break;
        else
        {
            getline(cin, k);
            for (i = 0; i < n; i++)
            {
                string temp;
                getline(cin, temp);
                findve.push_back(temp);
                getline(cin, temp);
                replaceve.push_back(temp);
            }
            string str;
            getline(cin, str);

            for (i = 0; i < n; i++)
            {
                int position = str.find(findve[i]);
                while (position != -1)
                {
                    str.replace(position, findve[i].size(), replaceve[i]);
                    position = str.find(findve[i]);
                }
            }
            cout << str << endl;
            findve.clear();
            replaceve.clear();
        }
    }
    return 0;
}
