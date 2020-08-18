#include<bits/stdc++.h>
using namespace std;

int n,m;
string str[100];

int main(int argc,char const *argv[]) {
    int t;
    scanf("%d",&t);
    for(int tc=1;tc<=t;tc++) {
       scanf("%d%d",&n,&m);
       cin.ignore();
       for(int i=0;i<m;i++) {
        getline(cin,str[i]);
       }

    }
    return 0;
}
