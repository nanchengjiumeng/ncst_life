#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int Fibonacci(int n){
	if(n<=1){
		return n;
	}
	return Fibonacci(n-1)+Fibonacci(n-2);
}

long int FibonacciArr(int n){
	if(n==0){return 0;}
	vector<long int>a(n+1,0);
	a[1]=1;
	for(int i=2;i<=n;i++){
		a[i] = a[i-2]+a[i-1];
	}
	return a[n];
}

int main(){
	int n;
	cin >> n;
	cout << FibonacciArr(n);
	return 0;
}