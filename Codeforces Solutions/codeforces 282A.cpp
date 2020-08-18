#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    char keep[4][100]={"++X","X++","--X","X--"};
    int val[4]={1,1,-1,-1};
    cin>>n;
    int ans=0;
    while(n--){
        string str;
        cin>>str;
        for(int i=0;i<4;i++){
            if(keep[i]==str){
                ans+=val[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
