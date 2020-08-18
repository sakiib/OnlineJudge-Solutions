#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,n;
    cin>>m>>n;
    char str[1005][1005];
    string temp;
    for(int i=0;i<m;i++){
        cin>>str[i];
        temp=str[i];
        for(int j=0;j<temp.size()-1;j++){
            if(temp[j]!=temp[j+1]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    /*for(int i=0;i<n;i++){
        cout<<str[i]<<endl;
    }*/
    for(int i=0;i<m-1;i++){
        string a=str[i],b=str[i+1];
        if(a==b){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}
