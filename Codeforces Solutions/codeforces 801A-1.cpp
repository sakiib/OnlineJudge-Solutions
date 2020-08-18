#include<bits/stdc++.h>

using namespace std;

int main()
{
    int count=0;
    string str;
    cin>>str;

    for(int i=0;i<str.size()-1;i++){

        if(str[i]=='V'&&str[i+1]=='K'){
            str[i]=true;str[i+1]=true;count++;
        }
    }

    for(int i=0;i<str.size()-1;i++){

        if(str[i]==false) continue;
        if(str[i+1]==false) continue;
        if(str[i]=='V'&&str[i+1]=='V'){
            count++;break;
        }
        if(str[i]=='K'&&str[i+1]=='K'){
            count++;break;
        }
    }

    cout<<count<<endl;
    return 0;
}
