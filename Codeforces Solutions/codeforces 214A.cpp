#include <iostream>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){

		long N,flag=0,a[700][700],max,sum=0,temp=9999999999;
		cin>>N;

		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
				cin>>a[i][j];


		for(int i=N-1;i>=0;i--){
			max=0;
			for(int j=0;j<N;j++){
				if(a[i][j]>max && a[i][j]<temp)
					max=a[i][j];
			}
			if(max==0){
				cout<<"-1"<<endl;
				flag=1;
				break;
			}
			else{
                cout << "Max " << max << endl;
				sum=sum+max;
				temp=max;
			}
		}

		if(flag!=1)
			cout<<sum<<endl;
	}
	return 0;
}
