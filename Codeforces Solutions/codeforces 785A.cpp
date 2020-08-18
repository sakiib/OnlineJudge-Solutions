#include<bits/stdc++.h>
#include<stdio.h>
typedef long long int ll;
typedef unsigned long long int llu;
using namespace std;
stack<int>mysti;
stack<char>mystc;
vector<ll>myvec;
map<string,int>mymapsi;
map<string,string>mymapss;
map<int,int>mymapii;
map<ll,ll>mymapll;
int main()
{
    int n,ans=0;
    string str;
    mymapsi["Tetrahedron"]=4;
    mymapsi["Cube"]=6;
    mymapsi["Octahedron"]=8;
    mymapsi["Dodecahedron"]=12;
    mymapsi["Icosahedron"]=20;
    cin>>n;
    while(n--)
    {
        cin>>str;
        ans+=mymapsi[str];
    }
    cout<<ans<<endl;
    return 0;
}



