#include<bits/stdc++.h>
using namespace std;

inline int st_int(string &str) {
    int num;
    stringstream st(str);
    st>>num;
    return num;
}
int process(int n) {
    string str="";
    bool found=false;
    while(n>0) {
       int a=n%2;
       str+=(a+'0');
       n/=2;
       found=true;
    }
    if(!found) str+='0';
    reverse(str.begin(),str.end());
    int k=st_int(str);
    return k;
}
int main(int argc,char const *argv[]) {
    int t,tc;
    cin>>t;
    for(tc=1;tc<=t;tc++) {
       int a,b,c,d,A,B,C,D;
       scanf("%d.%d.%d.%d",&a,&b,&c,&d);
       scanf("%d.%d.%d.%d",&A,&B,&C,&D);
       int a1,b1,c1,d1;
       a1=process(a);
       b1=process(b);
       c1=process(c);
       d1=process(d);
       //printf("%d %d %d %d\n",a1,b1,c1,d1);
       //printf("%d %d %d %d\n",A,B,C,D);
       if(a1==A&&b1==B&&c1==C&&d1==D)
        printf("Case %d: Yes\n",tc);
       else printf("Case %d: No\n",tc);
    }
    return 0;
}
