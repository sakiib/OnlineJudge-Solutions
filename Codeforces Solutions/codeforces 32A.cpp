#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {

    long long int n,d,i,ara[100000],count=0;
     cin >> n >> d  ;
      for(i=0;i<n;i++) {
        cin >>ara[i];
      }
      sort(ara,ara+n);
        for(i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                int x=abs(ara[i]-ara[j]);
                 if(x<=d) {
                    count++;
                 }
                 else break;
            }
        }
    cout << count*2 <<endl;
    return 0;

}


