#include<bits/stdc++.h>
using namespace std;

bool lucky(int x){
    string str="";
    while(x!=0){
        str+=(x%10)+'0';
        x=x/10;
    }
   // reverse(str.begin(),str.end());
    //cout<<str<<endl;
    for(int i=0;i<str.size();i++){
        if(str[i]!='4'&&str[i]!='7') return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        if(lucky(i)){
            if(n%i==0){
               // cout<<i<<endl;
                puts("YES");
                return 0;
            }
        }
    }
    puts("NO");
    return 0;
}
