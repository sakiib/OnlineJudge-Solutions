#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &V)
{
    reverse(V.begin(),V.end());
    vector<int> A;
    int mx=0;
    A.push_back(0);
    for(int i=1;i<V.size();i++){
        for(int j=i-1;j<i;j++){
            mx=max(mx,V[j]);
        }
        if(mx>=V[i]) A.push_back(mx-V[i]+1);
        else A.push_back(0);
       // cout<<mx<< " ";
    }
    reverse(A.begin(),A.end());
    for(int i=0;i<A.size();i++){
        cout<<A[i]<< " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,h;
    vector<int> V;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>h;
        V.push_back(h);
    }
    solve(V);
    return 0;
}
