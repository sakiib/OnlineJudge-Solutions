#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n;
    cin>>n;
    if(n%2==0){
        cout<<n/2;
        return 0;
    }
    ll bad=n/2;
    cout<<-(n-bad);
    return 0;

}
