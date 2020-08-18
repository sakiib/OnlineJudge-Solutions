#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    int n,k,i,a,led=0,del;
    vector<int>v;
    cin >> n >> k;
    for(i=1;i<=n;i++){
        v.push_back(i);
    }
    while(k--)
    {
        cin >> a;
        del=(led+a)%n;
        cout << v[del] << " ";
        v.erase(v.begin()+del);
        n--;
        led=del%n;
    }
    return 0;
}
