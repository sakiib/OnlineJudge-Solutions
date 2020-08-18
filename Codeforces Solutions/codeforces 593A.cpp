#include<bits/stdc++.h>

using namespace std;

set<char> S;
vector<string> V;

int main()
{
    int n;
    scanf("%d",&n);
    string str;
    for(int i=0;i<n;i++){
        cin>>str;
        for(int i=0;i<str.size();i++){
            S.insert(str[i]);
        }
       // cout<<S.size()<<endl;
        if(S.size()>2){
            S.clear();
        }
        else {
            V.push_back(str);
            S.clear();
        }
       // cout<<S.size()<<endl;
    }
    for(int i=0;i<V.size();i++){
        cout<<V[i]<<endl;
    }

}
