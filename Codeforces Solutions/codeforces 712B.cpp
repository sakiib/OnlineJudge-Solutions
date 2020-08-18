#include<bits/stdc++.h>
using namespace std;
int main()
{
    int left=0,right=0,up=0,down=0,a,b;
    string str;
    cin>>str;
    if(str.size()%2!=0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<str.size();i++){
        if(str[i]=='D') down++;
        else if(str[i]=='U') up++;
        else if(str[i]=='R') right++;
        else if(str[i]=='L') left++;
    }
    a=abs(left-right);
    b=abs(up-down);
    //cout<<a<< " " <<b<<endl;
    cout<<(a+b)/2<<endl;
    return 0;
}
