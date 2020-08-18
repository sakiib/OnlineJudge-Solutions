#include<bits/stdc++.h>
using namespace std;
vector<int>myvec;
int main()
{
    int n,k,len,ans,target,best,worst,target1;
    cin>>n>>k;
    string str,str1;
    for(int i=0;i<n;i++){
        cin>>str;
        myvec.push_back(str.size());
    }
    cin>>str1;
    len=str1.size();
    sort(myvec.begin(),myvec.end());
    for(int i=0;i<myvec.size();i++){
        //cout<<myvec[i]<< " ";
        ans=myvec[i];
        if(len==ans){
          target=i+1; break;
        }
    }
    //cout<<endl;
    //cout<<target<<endl;
    if(target==1){
        best=1;
    }
    else if(target<k){
        best=target;
    }
    else{
        best=target+((target-1)/k)*5;
    }
    for(int i=0;i<myvec.size();i++){
        if(myvec[i]==len){
            while(myvec[i]==len){
                i++;
            }
            target1=i; break;
        }
    }
    if(target1==1){
        worst=1;
    }
    else if(target1<k){
        worst=target1;
    }
    else{
        worst=target1+((target1-1)/k)*5;
    }
   // cout<<target1<<endl;
    cout<<best<<" "<<worst<<endl;

    return 0;
}
