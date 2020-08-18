#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<math.h>
#include<cstdlib>
#include<string>
#define pi acos(-1)
#define mod 1000000007
#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

using namespace std;
int main()
{
   char str[10000];
   int i,l,count=0,co=0;
    cin >> str;
     l=strlen(str);
      for(i=0;i<l;i++) {
            if(str[i]=='@')
                count++;
           }
            if(count==0) {
            cout <<"No solution";
               return 0;
           }
       for(i=0;i<l;i++) {
         if((str[i]=='@'&&str[i+1]=='@')||(str[i]=='@'&&str[i+2]=='@'))
            cout << "No solution";
              return 0;
       }
         if(str[0]=='@'||str[l-1]=='@') {
            cout <<"No solution";
              return 0;
        }
              for(i=0;i<l;i++) {
            cout << str[i];
              if(str[i-1]=='@'&&i!=(l-1)&&co!=(count-1)) {
                 co++;
                cout <<",";
               }
            }
	return 0;
}


