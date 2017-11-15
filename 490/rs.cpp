#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    vector<string> s;
    string t;
    char c;
    int i,j,n;
    getline(cin,t);
    s.push_back(t);
    n=t.size();
    while(getline(cin,t)) {
        s.push_back(t);
        if(n<t.size())   n=t.size();
    }
    for(j=0;j<n;j++) {
        for(i=s.size()-1;i+1;i--){
            printf("%c",(j<s[i].size())?s[i][j]:' ');
        }
        cout << endl;
    }
    return 0;
}
