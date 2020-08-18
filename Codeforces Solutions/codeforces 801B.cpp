#include<bits/stdc++.h>

using namespace std;

vector<char>mc;
bool flag=true;
int main()
{
    string a,b;
    cin>>a>>b;

    for(int i=0;i<a.size();i++){

        if(a[i]<b[i]){
            flag=false; break;
        }

        else if(a[i]==b[i]){
           mc.push_back(b[i]);
        }

        else if(a[i]>b[i]){
            mc.push_back(b[i]);
        }
    }
    if(flag==false) cout<<-1<<endl;

    else{
        for(int i=0;i<mc.size();i++){

            cout<<mc[i];
        }

        cout<<endl;
    }
    return 0;
}
