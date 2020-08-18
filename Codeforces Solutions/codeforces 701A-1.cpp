#include<bits/stdc++.h>
using namespace std;
int ara[10001]={0};
vector< pair<int,int> >vp;
int main()
{
    int n,sum=0,ans,lagbe;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
        sum+=ara[i];
    }
    ans=sum/(n/2);
    //cout<<ans<<endl;
    for(int i=1;i<=n;i++){
        if(ara[i]!=-1){
        lagbe=ans-ara[i];
        //cout<<"Lagbe:"<< " " <<lagbe<<endl;
        ara[i]=-1;
        for(int j=1;j<=n;j++){
           if(ara[j]==lagbe){
             //cout<<ara[j]<<endl;
             ara[j]=-1;
             vp.push_back({i,j});
             break;
           }
        }
     }
     else continue;
    }
    for(int i=0;i<vp.size();i++){
        cout<<vp[i].first<< " " <<vp[i].second<<endl;
    }
    return 0;
}
