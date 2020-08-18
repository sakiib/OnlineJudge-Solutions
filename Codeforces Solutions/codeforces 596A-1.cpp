#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > V;
set<int> S1,S2;
int main()
{
    int n,a[1000],b[1000],len=0,wid=0,ans;
    scanf("%d",&n);
    if(n==1){
        puts("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i],&b[i]);
        V.push_back(make_pair(a[i],b[i]));
        S1.insert(a[i]);
        S2.insert(b[i]);
    }
   // printf("%d %d",S1.size(),S2.size());
    if(S1.size()!=2||S2.size()!=2){
        puts("-1");
        return 0;
    }
  /*  for(int i=0;i<V.size()-1;i++){
        if(abs(V[i].first-V[i+1].first!=0)&&(V[i].second()==V[i].second){
            len=abs([V[i].first-V[i+1].first);
            break;
        }
    }
    for(int i=0;i<V.size()-1;i++){
         if((abs(V[i].second-V[i+1].second)!=0)&&(V[i].first==V[i].first)){
            wid=abs([V[i].second-V[i+1].second);
            break;
        }
    }
    printf("%d\n",len*wid);*/
    for(int i=0;i<n-1;i++){
        if(abs(a[i]-a[i+1])!=0&&(b[i]==b[i+1])){
            len=abs(a[i]-a[i+1]);
            break;
        }
    }
     for(int i=0;i<n-1;i++){
        if(abs(b[i]-b[i+1])!=0&&(a[i]==a[i+1])){
            wid=abs(b[i]-b[i+1]);
            break;
        }
    }
    ans=len*wid;
    for(int i=0;i<n-1;i++){
        if(a[i]!=a[i+1]&&b[i]!=b[i+1]){
            ans=abs(a[i]-a[i+1])*abs(b[i]-b[i+1]);
            break;
        }
    }
    printf("%d\n",ans);
    return 0;

}
