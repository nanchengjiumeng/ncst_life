#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int FibonacciArr(unsigned long long int n){
	if(n==0){
		return 0;
		}
	int index = -1;
	vector<long int>a(2,0);
	a[1]=1;
	for(int i=2;i<=n;i++){
		a.push_back((a[i-2]+a[i-1])%10);
		if(a[i]==1 && a[i-1]==0){
			index = i-1;
			break;		
			}
	}
	int res =0;
	if(index>=0){
	for(int i =0;i<index;i++){
			res+=a[i];
		}
		res=res%10;
		int m = n%index;
		unsigned long long int b = (n-m)/index;
		res=res*b;
		 for(int i=0;i<=m;i++){
			 res=res+a[i];
		 }

		 res=res%10;
		
	}else{
		for(int i =0;i<=n;i++){
			res+=a[i];
		}
		res=res%10;
	}
	return res ;
}
// 2816213588 30524

int main(){
	unsigned long long int n;
	cin >> n;
	cout << FibonacciArr(n);
	return 0;
}