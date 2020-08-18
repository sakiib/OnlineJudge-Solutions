#include<bits/stdc++.h>
using namespace std;
bool flag=true;
int main()
{
    int n,m;
    string str;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>str;
            if(str=="C"||str=="M"||str=="Y"){
                flag=false; break;
            }
            if(flag==false) break;
        }
    }

    if(flag==false) cout<<"#Color"<<endl;
    else cout<<"#Black&White"<<endl;
    return 0;
}
