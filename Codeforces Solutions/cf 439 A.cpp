#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL a[100010];
LL b[100010];
map<LL,bool> M;

int main(int argc,char const *argv[]) {
    LL n;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
        M[a[i]]=true;
    }
    for(int i=1;i<=n;i++) {
        cin>>b[i];
        M[b[i]]=true;
    }
    LL k=0, r=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            LL x=(a[i]^a[j]);
            if(M[x]) k++;
        }
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            LL x=(b[i]^b[j]);
            if(M[x]) r++;
        }
    }
    if(r%2==0) cout<<"Karen"<<endl;
    else cout<<"Koyomi"<<endl;
    return 0;
}


