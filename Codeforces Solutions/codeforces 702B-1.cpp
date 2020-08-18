#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
map<ll,ll>mymap;
int main()
{
    ll n,sum=0,num;
    cin>>n;
    while(n--){
      cin>>num;
      for(int i=1;i<=32;i++){
        sum+=mymap[pow(2,i)-num];
      }
      mymap[num]++;
    }
    cout<<sum<<endl;
    return 0;
}
