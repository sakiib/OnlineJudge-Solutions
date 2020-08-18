#include<bits/stdc++.h>
using namespace std;

int a[100010],b[100010];

vector<pair<int,int> > V;

int main(int argc,char const *argv[]) {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) {
        scanf("%d%d",&a[i],&b[i]);
        V.push_back({a[i],b[i]});
    }
    sort(V.begin(),V.end());
    int ans=0,cur=0;
    for(int i=0;i<V.size();i++) {
        if(V[i].second<cur) {
            ans++;
        }
        else {
            cur=V[i].second;
        }
    }
    printf("%d\n",ans);
    return 0;
}
