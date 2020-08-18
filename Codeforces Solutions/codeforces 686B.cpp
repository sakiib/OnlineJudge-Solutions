#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;
ll ara[10001];
int main()
{
    ll n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            if (ara[j]>ara[j+1]){
                swap(ara[j],ara[j+1]);
                cout<<j<<" "<<j+1<<endl;
            }
        }
    }
    /*for(int i=1;i<=n;i++){
        cout<<ara[i]<< " ";
    }*/
  return 0;
}
