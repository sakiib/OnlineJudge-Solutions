#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--){

        map<char,int> M;
        string str;
        cin>>str;
        for(int i=0;i<str.size();i++){
           M[str[i]]++;
         }
        for(int i=0;i<str.size()-1;i++){
            if(str[i]=='m'&&str[i+1]=='s') {
                M['s']--;
                str[i]='X';
            }
            else if(str[i]=='s'&&str[i+1]=='m'){
                M['s']--;
                str[i+1]='X';
            }
        }
       // cout<<M['s']<< " " <<M['m']<<endl;
       if(M['s']==M['m']) puts("tie");
       else if(M['s']>M['m']) puts("snakes");
       else puts("mongooses");
    }
    return 0;
}
