#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;

    vector<pair<int,int> > L,R;

    while(n--){
        int a,b;
        cin>>a>>b;
        if(a>0) R.push_back(make_pair(a,b));
        else L.push_back(make_pair(a,b));
    }
    sort(L.rbegin(),L.rend());
    sort(R.begin(),R.end());

   /* for(int i=0;i<L.size();i++){
        cout<<L[i].first<< " " <<L[i].second<<endl;
    }
    cout<<endl;
    for(int i=0;i<R.size();i++){
        cout<<R[i].first<< " " <<R[i].second<<endl;
    }*/

    int i=0;
    int ans=0;

    while(i!=R.size()&&i!=L.size()){
        ans+=L[i].second;
        ans+=R[i].second;
        i++;
    }
    if(i!=L.size()) ans+=L[i].second;

   // cout<<ans<<endl;
    i=0;
    int sum=0;

    while(i!=R.size()&&i!=L.size()){
        sum+=L[i].second;
        sum+=R[i].second;
        i++;
    }
    if(i!=R.size()) sum+=R[i].second;


   // cout<<sum<<endl;
    cout<<max(ans,sum)<<endl;
    return 0;
}
