#include<bits/stdc++.h>
using namespace std;

int power(int a,int b){
    int ret=1;
    for(int i=1;i<=b;i++){
        ret*=a;
    }
    return ret;
}
int st_in(string &str){
    reverse(str.begin(),str.end());
    int n=0;
    for(int i=0,j=0;i<str.size();i++,j++){
        n+=(str[i]-'0')*power(10,j);
    }
   // cout<<n<<endl;
    return n;
}
int main(){
    int n,cnt=0;
    cin>>n;
    char drink[11][1000]={"ABSINTH","BEER","BRANDY","CHAMPAGNE","GIN","RUM",
                      "SAKE","TEQUILA","VODKA","WHISKEY","WINE"};
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str[0]-'0'>=0&&str[0]-'0'<=9){
            int age=st_in(str);
            if(age<18) cnt++;
        }
        else{
           for(int i=0;i<11;i++){
             if(str==drink[i]){
                cnt++; break;
             }
           }
        }
    }
    cout<<cnt<<endl;
    return 0;
}

