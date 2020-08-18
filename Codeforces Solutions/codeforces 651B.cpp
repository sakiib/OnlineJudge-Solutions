#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int main()
{
    int n,num,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        v.push_back(num);
    }
    sort(v.begin(),v.end());
    vector<bool>used(100001,false);
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(used[j]) continue;
            if(v[j]>v[i]){
                cnt++; used[j]=true; break;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}
