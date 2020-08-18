#include<bits/stdc++.h>
using namespace std;
vector<string>myvec;
bool flag=false;
int main()
{
    int n;
    string str,str1;
    cin>>n;
    for(int i=0;i<n;i++){

        cin>>str;
        myvec.push_back(str);
    }
    for(int i=0;i<myvec.size();i++){

        str1=myvec[i];
        for(int j=0;j<str1.size();j++){

            if(str1[0]=='O'&&str1[1]=='O'){
                str1[0]='+';str1[1]='+';
                flag=true; myvec[i]=str1;break;
            }
            else if(str1[3]=='O'&&str1[4]=='O'){
                str1[3]='+';str1[4]='+';
                flag=true;myvec[i]=str1;break;
            }

        }
        if(flag==true) break;
    }
    if(flag==false) cout<<"NO"<<endl;
    else{
            cout<<"YES"<<endl;
        for(int i=0;i<myvec.size();i++){

            cout<<myvec[i]<<endl;
        }
    }
    return 0;
}
