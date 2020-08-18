#ifdef JUDGE
#include <fstream>
std::ifstream cin("a.in");
std::ofstream cout("a.out");
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define ll long long int
#define loo(i,a,b) for(i=a;i<b;i++)
#define vi vector<int>
#define ii pair<int,int>
#define is pair<int,string>
#define vii vector<ii>
#define vis vector<is>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define mod 1000000007
#define nu 100001

ll modular_pow(ll base, ll exponent, int modulus)
{
    ll result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;
        exponent = exponent >> 1;
        base = (base * base) % modulus;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);

    ll a,b,n,x;
    cin>>a>>b>>n>>x;
    if(a==1){
        a=n%mod;
        a=(a*b)%mod;
        a=(a+x)%mod;
        cout<<a;
    }
    else{
    ll z=modular_pow(a,n,mod);
    ll y=modular_pow(a-1,mod-2,mod);
    cout << z << " " << y << endl;
    ll ans=(z+mod-1)%mod;
    ans=(ans*b)%mod;
    //ans=(ans*x)%mod;
    ans=(ans*y)%mod;
    ans+=(x*z)%mod;
    ans=ans%mod;
    cout<<ans;
    }
}
