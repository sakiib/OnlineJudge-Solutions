#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    for(int j=0; ; j++) {
        cin >> str;
        if(str[0]=='-') break;
        int len = str.size();
        int sz = len/2, cnt1 = 0, cnt2 = 0, cntAns=0;

        for(int i=0; i<len; i++) {
            if(str[i]=='{') {
                cnt1++;
                if(cnt1>sz) {
                    str[i] = '}';
                    cnt1--;
                    cnt2++;
                    cntAns++;
                }
            }
            else if(str[i]=='}') {
                cnt2++;
                if(cnt2>cnt1) {
                    str[i] = '{';
                    cnt2--;
                    cnt1++;
                    cntAns++;
                }
            }
        }
        cout<<str<<" "<<cnt2<<" "<<cnt1<<endl;
        printf("%d. %d\n", j+1, cntAns);
    }
    return 0;
}
