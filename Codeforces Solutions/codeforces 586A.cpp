#include<bits/stdc++.h>
using namespace std;
vector<int> V;
void solve()
{
    int cnt=0,start;
    for(int i=0;i<V.size();i++){
        if(V[i]!=0){
            start=i;
            break;
        }
    }
    for(int i=start;i<V.size();i++){
       if(V[i]) cnt++;
    }
    for(int i=start+1;i<V.size()-1;i++){
        if(V[i-1]==1&&V[i+1]==1&&V[i]==0) cnt++;
    }
    cout<<cnt;

}
int main()
{
    int n,num,ans;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        V.push_back(num);
    }
    solve();
    return 0;
}
