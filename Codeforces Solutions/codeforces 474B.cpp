#include<bits/stdc++.h>
using namespace std;

map<int,int> M;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    int temp=0,sum=0;
    int st=1,j;
    ara[0]=0;
    M[0]=0;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        ara[i]+=ara[i-1];
        for(int j=ara[i-1]+1;j<=ara[i];j++) {
            M[j]=i;
        }
    }
    int query,val;
    cin>>query;
    while(query--) {
        cin>>val;
        cout<<M[val]<<endl;
    }
    return 0;
}
