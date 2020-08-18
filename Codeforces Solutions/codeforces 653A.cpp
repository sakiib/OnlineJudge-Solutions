#include<bits/stdc++.h>
using namespace std;
set<int>s;
vector<int>v;
int main()
{
    int n,ara[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
        s.insert(ara[i]);
    }
    if(s.size()<3){
        cout<<"NO"<<endl;
        return 0;
    }
    set<int>::iterator it;
    for(it=s.begin();it!=s.end();it++){
        v.push_back(*it);
    }
    for(int i=0;i<v.size()-2;i++){
       // cout<<v[i]<< " ";
       if(v[i+2]-v[i+1]<=2&&v[i+1]-v[i]<=2&&v[i+2]-v[i]<=2){
         cout<<"YES"<<endl;
         return 0;
       }
    }
    cout<<"NO"<<endl;
    return 0;

}
