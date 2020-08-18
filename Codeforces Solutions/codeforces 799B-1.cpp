#include<bits/stdc++.h>
using namespace std;
int p[200010],a[200010],b[200010];
set<pair<int,int> > S[10];
int main()
{
    int n,custom,choice;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    for(int i=0;i<n;i++){
        S[a[i]].insert(make_pair(p[i],i));
        S[b[i]].insert(make_pair(p[i],i));
    }

    scanf("%d",&custom);
    while(custom--){
       scanf("%d",&choice);
       if(S[choice].empty()){
         puts("-1");
       }
       else{
         pair<int,int> x=*S[choice].begin();
         S[a[x.second]].erase(x);
         S[b[x.second]].erase(x);
         printf("%d ",x.first);
       }
    }
    return 0;
}
