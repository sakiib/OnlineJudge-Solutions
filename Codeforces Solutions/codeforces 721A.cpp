#include<bits/stdc++.h>
using namespace std;
vector<int>mv;
int main()
{
    //ios::sync_with_stdio(false);
    int n,j=0,count=0,oc=0;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        if(str[i]=='B'){
            while(str[i]=='B'){
                i++;count++;
            }
            oc++;i--;
            mv.push_back(count);
            count=0;
        }
    }
    cout<<oc<<endl;
    for(int i=0;i<mv.size();i++){
        cout<<mv[i]<<" ";
    }
    return 0;
}
