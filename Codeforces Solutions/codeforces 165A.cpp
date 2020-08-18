#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    pair<int,int> P[205];
    map<pair<int,int>,int> M;
    for(int i=1;i<=n;i++) {
        cin>>P[i].first>>P[i].second;
        M[make_pair(P[i].first,P[i].second)]=true;
    }
    int ans=0;
    bool right=false; bool left=false;
    bool up=false; bool down=false;
    for(int i=1;i<=n;i++) {
       right=false; left=false;
       up=false; down=false;
       int x=P[i].first;
       int y=P[i].second;
       for(int j=x+1;j<=1000;j++) {
         if(M[make_pair(j,y)]) {
            right=true; break;
         }
       }
       for(int j=x-1;j>=-1000;j--) {
         if(M[make_pair(j,y)]) {
            left=true; break;
         }
       }
       for(int j=y+1;j<=1000;j++) {
         if(M[make_pair(x,j)]) {
            up=true; break;
         }
       }
       for(int j=y-1;j>=-1000;j--) {
         if(M[make_pair(x,j)]) {
            down=true; break;
         }
       }
       if(up&&down&&left&&right) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
