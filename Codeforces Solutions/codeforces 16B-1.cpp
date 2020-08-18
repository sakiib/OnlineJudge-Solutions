#include<bits/stdc++.h>
??Wrong Answer??
typedef long long int ll;
using namespace std;
ll box[100001],pack[100001];
map<ll,ll>mymap;
int main()
{
    ll n,num,baki,ans=0;
    cin>>n>>num;
    baki=n;;
    for(int i=0;i<num;i++)
    {
        cin>>box[i];
        cin>>pack[i];
        mymap[pack[i]]+=box[i];
    }
    sort(pack,pack+num);
    reverse(pack,pack+num);
    for(int i=0;i<num;i++)
    {
      if(baki<=0)
        break;
      else if(baki==mymap[pack[i]])
      {
        ans+=(mymap[pack[i]]*pack[i]);
        baki=baki-mymap[pack[i]];
      }
      else if(baki<mymap[pack[i]])
      {
          ans+=(baki*pack[i]);
          baki=0;
      }
      else if(baki>mymap[pack[i]])
      {
          ans+=(mymap[pack[i]]*pack[i]);
          baki=baki-mymap[pack[i]];
      }
    }
    cout<<ans<<endl;
 return 0;
}
