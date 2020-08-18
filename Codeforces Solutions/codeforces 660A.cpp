#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n,ara[100001],cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<n-1;i++){
        if(__gcd(ara[i+1],ara[i])>1){
            v.push_back(ara[i]);
            v.push_back(1);
            cnt++;
        }
        else v.push_back(ara[i]);
    }
    v.push_back(ara[n-1]);
    cout<<cnt<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<< " ";
    }
    return 0;
}
