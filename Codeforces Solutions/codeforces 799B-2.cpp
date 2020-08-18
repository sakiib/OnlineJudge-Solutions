#include<bits/stdc++.h>
using namespace std;

int price[200010],fro[200010],bac[200010];
set<pair<int,int> > S[100000];

int  main()
{
    int n,customer,choice;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>fro[i];
    }
    for(int i=0;i<n;i++){
        cin>>bac[i];
    }
    for(int i=0;i<n;i++){
       S[fro[i]].insert(make_pair(price[i],i));
       S[bac[i]].insert(make_pair(price[i],i));
    }
    cin>>customer;
    while(customer--){
        cin>>choice;
        if(S[choice].empty()){
            cout<<-1<< " ";
        }
        else{
            pair<int,int> P=*S[choice].begin();
           // cout<<P.first<< " "<<P.second<<endl;
           // cout<<fro[P.second]<< " " <<bac[P.second]<<endl;
            S[fro[P.second]].erase(P);
            S[bac[P.second]].erase(P);
            cout<<P.first<< " ";
        }
    }
    return 0;
}
