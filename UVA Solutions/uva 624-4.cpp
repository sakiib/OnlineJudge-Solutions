#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int ara[100005],t,n,mx=0;

vector<ll> V,A;

void solve(int s,int ind)
{
    if(s>mx){
        mx=s;
        A=V;
       // cout<<mx<<endl;
    }

    for(int i=ind;i<n;i++){
        if(s+ara[i]<=t){
            s+=ara[i];
            V.push_back(ara[i]);
            solve(s,i+1);
            s-ara[i];
            V.pop_back();
        }
    }

}
int main()
{
    while(scanf("%d%d",&t,&n)!=EOF){
        V.clear();
        for(int i=0;i<n;i++){
            scanf("%d",&ara[i]);
        }

        mx=0;

        solve(0,0);

       // cout<<mx<<endl;
       for(int i=0;i<A.size();i++){
         cout<<A[i]<< " ";
       }
    }
    return 0;
}
