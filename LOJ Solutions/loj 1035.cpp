#include<bits/stdc++.h>
using namespace std;

map<int,int> M;

void solve(int n) {
    for(int i=2;i<=n;i++) {
        int k=i;
        if(k%2==0) {
            M[2]++;
            k/=2;
            while(k%2==0) {
                M[2]++;
                k/=2;
            }
        }
        for(int j=3;j<=k;j+=2) {
            while(k%j==0) {
                k/=j;
                M[j]++;
            }
        }
        if(k>1) M[k]++;
    }
}
int main(int argc,char const *argv[]) {
    int t,tc;
    scanf("%d",&t);
    for(tc=1;tc<=t;tc++) {
        int n;
        scanf("%d",&n);
        M.clear();
        solve(n);
        //cout<<"---"<<M[2]<<endl;
        printf("Case %d: %d = ",tc,n);
        vector<pair<int,int> > V;
        V.clear();
        for(int i=2;i<=100;i++) {
            if(M.count(i)>0) {
               V.push_back({i,M[i]});
            }
        }
        for(int i=0;i<V.size();i++) {
            if(!i) printf("%d (%d)",V[i].first,V[i].second);
            else printf(" * %d (%d)",V[i].first,V[i].second);
        }
        printf("\n");
    }
    return 0;
}
