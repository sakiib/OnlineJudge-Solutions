#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,from,to;
    string str;
    cin>>n>>from>>to;
    cin>>str;
    if(str[from-1]==str[to-1]) cout<<0<<endl;
    else cout<<1<<endl;
    return 0;
}
