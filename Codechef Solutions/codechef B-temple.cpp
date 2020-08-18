#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> &V)
{
    vector<int> A;
    int cnt=0,a,b;
    for(int i=0;i<V.size();i++){
       if(V[i]==1){
         cnt++;
       }
    }

    if(cnt==0) return(V.size());

    for(int i=0;i<V.size()-1;i++){
        if(V[i]+1==V[i+1]){
            a=i;
        }
        if(V[i]-1==V[i+1]){
            b=i;
        }
    }
    cout<<a<< " " <<b<<endl;;
}
int main()
{
    int t,n,h;
    cin>>t;

    while(t--){
        cin>>n;
        vector<int> V;

        for(int i=0;i<n;i++){
            cin>>h;
            V.push_back(h);
        }
        if(V.size()<3){
            puts("0");
            continue;
        }
        solve(V);
       // cout<<solve(V)<<endl;
    }
    return 0;
}
