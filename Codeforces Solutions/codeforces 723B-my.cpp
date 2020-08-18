#include<bits/stdc++.h>
using namespace std;
bool bracket=false;
int longest_out(string & str)
{
    int maxs=0,current=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='('){
            bracket=true;
            maxs=max(maxs,current);
            current=0;
           }
        else if(str[i]==')'){
            bracket=false;
        }
        else if(str[i]=='_'){
            if(bracket==true) continue;
            else{
                maxs=max(maxs,current);
            }
            current=0;
        }
        else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
            if(bracket==true) continue;
            else current++;
        }
    }

    return maxs;

}
int word_in(string & str)
{
  int total=0,cnt=0;
  for(int i=0;i<str.size();i++){
     if(str[i]=='('){
        bracket=true;

     }
     else if(str[i]==')'){
        bracket=false;
        if(cnt>0){
            total++;
        }
        cnt=0;
     }
     else if(str[i]=='_'){
        if(bracket==true){
            if(cnt>0){
                total++;
            }
            cnt=0;
        }
     }
     else if(str[i]>='a'&&str[i]<='z'||str[i]>='A'&&str[i]<='Z'){
         if(bracket==true){
            cnt++;
         }
     }
  }

  return total;

}
int main()
{
    ios::sync_with_stdio(false);
    int n,ans1,ans2;
    cin>>n;
    string str;
    cin>>str;
    str+='_';
    ans1=longest_out(str);
    ans2=word_in(str);
    cout<<ans1<<" "<<ans2<<endl;
    return 0;
}
