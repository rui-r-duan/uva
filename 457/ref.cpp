#include<iostream>
using namespace std;
#define REP(i,b,n) for(int i=b;i<n;i++)
#define rep(i,n)   REP(i,0,n)

void solve(int *dna,int *array,char *op){
  int val = 50;
  while(val--){
    rep(i,40)cout << op[array[i]];
    cout << endl;
    int tmp[40];
    tmp[0]=array[0]+array[1];
    tmp[39]=array[39]+array[38];
    REP(i,1,39)tmp[i]=array[i-1]+array[i]+array[i+1];
    rep(i,40)array[i]=dna[tmp[i]];
  }
  return;
}


main(){
  char op[4]={' ','.','x','W'};
  int tc;
  cin>>tc;
  while(tc--){
    int array[40]={0},dna[10];
    rep(i,10)cin>>dna[i];

    array[19]=1;

    solve(dna,array,op);
    if (tc)puts("");
  }
}
