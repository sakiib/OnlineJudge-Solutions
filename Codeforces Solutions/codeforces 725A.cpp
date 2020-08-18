#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int cnt=0,n;
    cin>>n;
    string str;
    cin>>str;
    if(str=="<"||str==">"){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<str.size();i++){
        if(str[0]=='<'){
            while(str[i]=='<'){
                cnt++;i++;
            }
            break;
        }
    }
    for(int i=str.size()-1;i>=0;i--){
        if(str[str.size()-1]=='>'){
            while(str[i]=='>'){
                cnt++;i--;
            }
            break;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
