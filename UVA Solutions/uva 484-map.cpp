#include<bits/stdc++.h>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
vector<int> myvec;
map<int, int> mymap;
int main()
{
	int n;
	while (scanf("%d", &n)==1&&n!=0)
    {
		if (mymap.count(n) == 0)//kono kisu map e thakle 1 joto bari thakuk 1 dekhabe or 0 dekhabe//
		{
			mymap[n] = 1;//mymap 1 kore dilam mane eita agei chilo//
			myvec.push_back(n);//eitake vectore rakhlam//
		}
        else
            mymap[n]++;//jodi agei theke thake then oitar occurrence barbe//
	}
	for(int i=0;i<myvec.size();i++)
    {
		printf("%d %d\n",myvec[i], mymap[myvec[i]]);//vector er oi elements er occurrence er value//
    }
	return 0;
}
