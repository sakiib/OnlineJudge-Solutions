#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,limak,ans=0;
    cin>>n;
    cin>>limak;
    vector<int> V;
    for(int i=1;i<n;i++){
        int num;
        cin>>num;
        V.push_back(num);
    }
    while(true){
    sort(V.rbegin(),V.rend());
    bool boro=true;
    for(int i=0;i<V.size();i++){
        //cout<<V[i]<< " ";
        if(V[i]>=limak){
            V[i]--;
            ans++;
            limak++;
            boro=false;
            break;
        }
     }
    // cout<<endl;
     if(boro) break;
    }

    cout<<ans<<endl;

    return 0;
}
