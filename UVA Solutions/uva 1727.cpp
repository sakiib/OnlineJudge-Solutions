#include<bits/stdc++.h>
using namespace std;
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    string str[20]={"JAN","FEB","MAR","APR","MAY","JUN",
                    "JUL","AUG","SEP","OCT","NOV","DEC"};
    int days[20]={31, 28, 31, 30, 31, 30, 31, 31, 30,
                  31, 30 ,31};
    string time[30]{"SAT","SUN","MON","TUE","WED","THU",
                      "FRI","SAT","SUN","MON","TUE","WED",
                     "THU","FRI"};
    getchar();
    while(t--) {
       string m,d;
       cin>>m>>d;
       int tot=0;
       for(int i=0;i<11;i++) {
         if(str[i]==m) {
            tot=days[i];
            break;
         }
       }
       int ans=0;
       int i=0,j=0,ind=0;
       bool found=false;
       while(i<tot) {
         for(int j=ind;j<7+ind;j++) {
            if(!found) {
                if(time[j]==d) {
                    found=true;
                    ind=j;
                    i=1;
                    break;
                }
            }
            else {
                if(time[j]=="FRI"||time[j]=="SAT") ans++;
                cerr<<i<< " "<<ans<<endl;
                i++;
                if(i==tot+1) break;
            }
         }
       }
       cerr<<ind<<endl;
       cout<<ans<<endl;
    }
    return 0;
}
