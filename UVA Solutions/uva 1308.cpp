#include<bits/stdc++.h>
using namespace std;
map<string,int>mymap;
int main()
{
    int t,available,recepie,budget,cost;
    string binder,item,cake;
    cin>>t;
    getchar();
    getline(cin,binder);
    cin>>available>>recepie>>budget;
    while(available--)
    {
        cin>>item>>cost;
        mymap.insert(pair<string,int>(item,cost));
    }
    getline(cin,cake);
    cin>>koyta;
    while(koyta--)
    {

    }
}
