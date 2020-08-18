#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int count_trail_zero(int n)
{
    int cnt=0;
    for(int i=5;n/i>=1;i*=5){
        cnt+=(n/i);
    }
    return cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,ans,tot=0;
    cin>>n;
    for(int i=5;i<=10000000;i++){
        ans=count_trail_zero(i);
          if(ans>n) break;
          if(ans==n){
            tot++;
            v.push_back(i);
        }
    }
    cout<<tot<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<< " ";
    }
    return 0;
}
