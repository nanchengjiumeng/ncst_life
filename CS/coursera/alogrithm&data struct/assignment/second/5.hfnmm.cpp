#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long int FibonacciArr(unsigned long long int n,long int m){
	if(n==0){
		return 0;
		}
	int index = -1;
	vector<long int>a(2,0);
	a[1]=1;
	for(int i=2;i<=n;i++){
		a.push_back((a[i-2]+a[i-1])%m);
		if(a[i]==1 && a[i-1]==0){
			index = i-1;
			break;		
			}
	}
	
	if(index>=0){
		return a[n%index];
	}
	//for(int i=0;i<=n;i++){
	//	cout << a[i] << '\n';
	//}
	return a[n];
}
// 2816213588 30524

int main(){
	unsigned long long int n;
	long int m;
	cin >> n >> m;
	cout << FibonacciArr(n,m);
	return 0;
}