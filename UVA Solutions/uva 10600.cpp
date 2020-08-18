#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin >> t;
    while(t--){
      stack<char>c;
      string s;
      cin >> s;
      int f=0;
      for(int i=0;i<s.size();i++){
          if(!c.empty()&&s[i]==')'&&c.top()=='(')
                 c.pop();
          else if(!c.empty()&&s[i]==']'&&c.top()=='[')
                c.pop();
          else
                c.push(s[i]);

                }
        if(c.empty())
            cout << "Yes"<<endl;
        else
             cout <<"No"<<endl;

            }
    return 0;
}
