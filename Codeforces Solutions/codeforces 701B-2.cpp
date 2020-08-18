#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll row[100001]={0};
ll col[100001]={0};
int main()
{
    ll m,n,a,b,x,y;
    cin>>n>>m;
    a=n;b=n;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        if(row[x]==0){
            row[x]=1;
            a--;
        }
        if(col[y]==0){
            col[y]=1;
            b--;
        }
        cout<<a*b<<" ";
    }
    cout<<endl;
    return 0;
}
