#include<bits/stdc++.h>
using namespace std;
set<char>s;
int main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;
    if(str.size()>26){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<str.size();i++){
         s.insert(str[i]);
    }
    cout<<n-s.size();
    return 0;
}
