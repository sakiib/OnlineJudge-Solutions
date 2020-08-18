#include<bits/stdc++.h>
using namespace std;

int m,n,ara[100005],a,b,c;

bool solve()
{
    int cnt=0,cn=0;
    int tar=(c-a);
    int f=ara[c];
    //cout<<tar<< " " <<f<<endl;
    for(int i=a;i<=b;i++){
        if(ara[i]<f) cnt++;
       // cout<<ara[i]<< " ";
    }
    //cout<<endl;
   // cout<<cnt<<endl;
    if(cnt==tar) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>m>>n;
    for(int i=0;i<m;i++){
        cin>>ara[i];
    }
    while(n--){
        cin>>a>>b>>c;
        a--,b--,c--;
        if(solve()) puts("Yes");
        else puts("No");
    }
    return 0;
}

