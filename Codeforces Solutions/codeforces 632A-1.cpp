#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
stack<string>st;
int main()
{
    ll n,price,a=1,total,free,half=1;
    string str;
    cin>>n>>price;
    for(int i=1;i<=n;i++){
        cin>>str;
        st.push(str);
    }
    st.top();
    st.pop();
    while(!st.empty()){
      // cout<<st.top()<<endl;
       if(st.top()=="half"){
          a=a*2;
       }
       else{
        a=a*2+1;
        half++;
       }
        st.pop();
    }
   // cout<<a<<endl;
   total=a*price;
   free=(half*price/2);
   cout<<total-free<<endl;
   return 0;
}
