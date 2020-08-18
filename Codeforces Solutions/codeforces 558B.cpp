#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int n,ara[100005],num,mx,f,s,ans=20000000000,x,y;
    map<int,int> M;for(int i=1;i<=n;i++){
        if(ara[i]==num){
            f=i; break;
        }
    }
    for(int i=n;i>=1;i--){
        if(ara[i]==num){
            s=i; break;
        }
    }
    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>ara[i];
        M[ara[i]]++;
    }

    vector<pair<int,int> > choice;
    map<int,int> :: iterator it;

    for(it=M.begin();it!=M.end();it++){
       // cout<<it->first<< " " <<it->second<<endl;
        choice.push_back(make_pair(it->second,it->first));
    }
   // cout<<num<< " "<<mx<<endl;

    sort(choice.rbegin(),choice.rend());

   /* for(int i=0;i<choice.size();i++){
       // cout<<choice[i].first<< " " <<choice[i].second<<endl;
    }*/
    mx=choice[0].first;
    num=choice[0].second;

    for(int i=1;i<=n;i++){
        if(ara[i]==num){
            f=i; break;
        }
    }
    for(int i=n;i>=1;i--){
        if(ara[i]==num){
            s=i; break;
        }
    }
   // vector<a> A;
    ans=(s-f+1);

    stack<pair<int,int> > S;
    S.push(make_pair(f,s));
   // A.push_back({ans,f,s});
    if(mx==1){
        cout<<f<< " "<<s<<endl;
        return 0;
    }
    for(int j=1;j<choice.size();j++){
        num=choice[j].second;
        if(mx==choice[j].first){
        for(int i=1;i<=n;i++){
        if(ara[i]==num){
            x=i; break;
        }
    }
    for(int i=n;i>=1;i--){
        if(ara[i]==num){
            y=i; break;
        }
      }
       if((y-x+1)<ans) {
            ans=(y-x+1);
            S.push(make_pair(x,y));
       }

    }
    else break;
   }

   while(!S.empty()){
     pair<int,int>p=S.top();
     cout<<p.first<< " " <<p.second<<endl;
     S.pop();
     break;
   }
   return 0;
}
