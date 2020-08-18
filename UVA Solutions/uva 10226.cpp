#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]){
    int t;
    scanf("%d",&t);
    scanf("\n");
    bool done=false;
    while(t--) {
        map<string,int> M;
       // cin.ignore();
        int tot=0;
        while(true) {
            string str;
            getline(cin,str);
            if(!str.size()) break;
            M[str]++;
            tot++;
        }
        for(auto x:M) {
            double res=x.second*100.0/tot;
            cout<<x.first<<" ";
            printf("%0.4lf\n",res);
        }
        M.clear();
        if(t!=0) cout<<endl;
    }
    return 0;
}
