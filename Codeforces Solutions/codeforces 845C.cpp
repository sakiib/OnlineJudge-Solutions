#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    //int ara[200100];
    //memset(ara,0,sizeof(ara));
    map<int,int> M;
    for(int i=0;i<n;i++) {
        int st,en;
        cin>>st>>en;
        M[st]++;
        M[en+1]--;
    }
    /*for(int i=0;i<=200010;i++) {
        ara[i]+=ara[i-1];
    }
    /*for(int i=0;i<=mx;i++) {
        cout<<ara[i]<< " ";
    }*/
    /*(for(int i=0;i<=200010;i++) {
        if(ara[i]>2) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;*/
    for(auto &x:M) {
        cout<<x.first<< " " <<x.second<<endl;
    }
    int tot=0;
    for(auto &x:M) {
        tot+=x.second;
        if(tot>2) {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
