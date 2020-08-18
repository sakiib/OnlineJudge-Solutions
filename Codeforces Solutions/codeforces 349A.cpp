#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
    }
    if(ara[1]>25) {
        cout<<"NO"<<endl;
        return 0;
    }
    map<int,int> M;
    for(int i=1;i<=n;i++) {
        if(ara[i]==25) {
            cerr<<"25";
            M[25]++;
        }
        if(ara[i]==50) {
            if(M[25]==0) {
                cerr<<"50";
                cout<<"NO"<<endl; return 0;
            }
            else M[25]--;
            M[50]++;
        }
        if(ara[i]==100) {
           cerr<<"100";
          if(M[50]>=1&&M[25]>=1) {
             M[50]--,M[25]--;
           }
           else if(M[25]>=3) {
             M[25]-=3;
           }
           else {
             cout<<"NO"<<endl; return 0;
           }
           M[100]++;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
