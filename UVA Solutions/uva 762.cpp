#include<bits/stdc++.h>
using namespace std;
string a,b;
vector<pair<string,string> > V[100001];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        cin>>a>>b;
        V[i].push_back(make_pair(a,b));
    }


}
