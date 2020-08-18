    #include <iostream>
    #include <algorithm>
    #include <cstring>
    using namespace std;
    typedef long long ll;

    ll gcd(ll a,ll b){
        if(a<b) swap(a,b);
        return b==0?a:gcd(b,a%b);
   }

   ll lcm(ll a,ll b){
       return a/gcd(a,b)*b;
   }

   int run()
   {
       ll a,b,cas=1,L,T;
       cin>>T;
       while(T--)
       {
           cin>>a>>b>>L;
           ll m=lcm(a,b);
           if(m>L||L%m!=0)
           {
              cout<<"Case "<<cas++<<": "<<"impossible"<<endl;
               continue;
           }
           ll c=L/m,g;
           if(c!=1)
            while((g=gcd(m,c))!=1){
            c*=g,m/=g;
        }
        cout<<"Case "<<cas++<<": "<<c<<endl;
       }
       return 0;
   }

   int main()
   {
       ios::sync_with_stdio(0);
       return run();
   }
