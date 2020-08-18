#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,k;
    int ara[100000];
    cin>>n>>m>>k;
    vector<int> V;
    for(int i=0;i<n*m;i++){
        cin>>ara[i];
        V.push_back(ara[i]);
    }
    int t=ara[0]%k;
    for(int i=1;i<n*m;i++){
        if(ara[i]%k!=t){
            cout<<-1<<endl;
            return 0;
        }
    }
    sort(V.begin(),V.end());
    /*for(int i=0;i<V.size();i++){
        cout<<V[i]<< " ";
    }*/
    int ans=0;
    int median=V[V.size()/2];
   // cout<<median<<endl;
    for(int i=0;i<V.size();i++){
        if(V[i]!=median){
            int temp=abs(median-V[i]);
            ans+=(temp/k);
            //cout<<ans<<endl;
        }
    }
    cout<<ans<<endl;
    return 0;
}
