#include<bits/stdc++.h>
using namespace std;
bool flag=false;
int st_int(string &s)
{
    int time=(s[0]-'0')*10+(s[1]-'0');
    return time;
}
int main()
{
    string str,hour="",mint="";
    int h,m,change;
    cin>>str>>change;
    for(int i=0;i<str.size();i++){
        if(str[i]==':'){
            flag=true;
            continue;
        }
        if(!flag){
            hour+=str[i];
        }
        if(flag){
            mint+=str[i];
        }
    }
   // cout<<hour<< " "<<mint<<endl;
    h=st_int(hour);
    m=st_int(mint);
   // cout<<h<<" "<<m<<endl;
    while(change--){
       if(m>=60){
         m=m-60;
         h++;
       }
       if(h>=24){
        h=h-24;
       }
       m++;
    }
    if(m>=60){
        m=m-60;
        h++;
    }
    if(h>=24){
        h=h-24;
    }
   // cout<<h<< " "<<m<<endl;
   if(h<10&&m<10){
     cout<<0<<h<<":"<<0<<m<<endl;
   }
   else if(h<10&&m>=10){
    cout<<0<<h<<":"<<m<<endl;
   }
   else if(h>=10&&m<10){
    cout<<h<<":"<<0<<m<<endl;
   }
   else{
    cout<<h<<":"<<m<<endl;
   }
    return 0;
}
