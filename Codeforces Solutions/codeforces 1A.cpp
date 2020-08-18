#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll m,n,a,ans;
    cin>>m>>n>>a;
    ans=(ceil)((double)m/(double)a)*(ceil)((double)n/(double)a);
    cout<<ans;
}
