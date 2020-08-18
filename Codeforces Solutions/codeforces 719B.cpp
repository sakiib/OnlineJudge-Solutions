#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    int n,r_odd=0,r_even=0,b_odd=0,b_even=0;
    string str;
    cin>>n;
    cin>>str;
    for(int i=0;i<n;i++){
       if(i%2==0){
        if(str[i]=='r') r_even++;
        else b_even++;
       }
       else{
        if(str[i]=='r') r_odd++;
        else b_odd++;
       }
    }
    //cout<<r_odd<<" "<<r_even<<" "<<b_odd<<" "<<b_even<<endl;;
    //cout<<max(r_even,b_even)<<endl;
    int a=max(r_even,b_odd);//checking who are not in appropriate pos
    //cout<<max(r_odd,b_odd)<<endl;
    int b=max(r_odd,b_even);//for both cases//e:g-rbrbr & brbrb (given-rbbrr)
    cout<<min(a,b)<<endl;
    return 0;
}
