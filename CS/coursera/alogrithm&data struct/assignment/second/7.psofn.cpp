#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int FibonacciArr(unsigned long long int l,unsigned long long int n){
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
	unsigned long long int res =0;
	if(index>=0){
	for(int i =0;i<index;i++){
			res+=a[i];
		}
		unsigned long long  m0 = l/index;
		unsigned long long  m1 = n/index;
		int i0 = l%index;
		int i1 = n%index;
		if(i1>=i0){
			res = res*(m1-m0);
		}else{
			res = res*(m1-m0);
		}
		res = res %10;
		if(i1>=i0){
			for(int i = i0;i<=i1;i++){
				res = res+a[i];
			}
		}else{
			for(int i = i0-i1;i<=i0;i++){
				res = res - a[i];
			}
		}
		res=res%10;
	
	}else{
		for(int i =0;i<=n;i++){
			if(i>=l){res+=a[i];}
			
		}
		res=res%10;
	}
	return res ;
}
// 2816213588 30524

int main(){
	unsigned long long int m,n;
	cin >> m >> n;
	cout << FibonacciArr(m,n);
	return 0;
}