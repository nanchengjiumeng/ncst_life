#include <iostream>
#include <cstdlib>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


int GCD(int a,int b){
	if(b==0){
		return a;
	}else{
		return GCD(b,a%b);
	}
}


int main(){
	unsigned long long int a,b;
	cin >> a >>b;
	unsigned long long int g= GCD(a,b);
	unsigned long long int res=a*b/g;
	cout <<res ;
	return 0;
}