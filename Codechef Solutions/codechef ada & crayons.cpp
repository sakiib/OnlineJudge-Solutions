#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    while(n--){

        vector<string> U,D;
        string str;
        cin>>str;

        string fu="",fd="";

        for(int i=0;i<str.size();i++){
            if(str[i]=='U'){
               fu+=str[i];
               if(fd!="") D.push_back(fd);
               fd="";
            }
            else if(str[i]=='D'){
                fd+=str[i];
                if(fu!="") U.push_back(fu);
                fu="";
            }
        }
        if(fu.size()>0) U.push_back(fu);
        if(fd.size()>0) D.push_back(fd);

        /*for(int i=0;i<U.size();i++){
            cout<<U[i]<<endl;
        }
        for(int i=0;i<D.size();i++){
            cout<<D[i]<<endl;
        }*/
        //cout<<U.size()<< " " <<D.size()<<endl;
       /* if(U.size()==0||D.size()==0) cout<<0<<endl;
        else if(D.size()<U.size()) cout<<D.size()<<endl;
        else if(D.size()>U.size()) cout<<U.size()<<endl;
        else cout<<U.size()<<endl;*/
        cout<<min(U.size(),D.size())<<endl;
    }
    return 0;
}
