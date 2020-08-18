#include<bits/stdc++.h>
using namespace std;

bool check[100];
bool feck[100];

int main(int argc,char const *argv[]) {
    int n,a,x,y;
    cin>>n;
    a=n*n;
    for(int i=1;i<=a;i++){
        cin>>x>>y;
        if(!check[x]&&!feck[y]){
          cout<<i<< " ";
          check[x]=true; feck[y]=true;
        }
    }
    return 0;
}
