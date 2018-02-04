#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	long long int A[n]={0};
	int i=0;
	while(i<n){
		cin >> A[i];\
		i++;
	}
	int a=0,b=0;
	for(int i=1;i<n;i++){ 
		if(A[i]>A[a]){
			a=i;	
			}
	}
	if(a==0){b=1;}		
	for(int i =1;i<n;i++){
		if(i!=a && A[i]>A[b]){
			b=i;
		}
	}
	long long int r =A[a]*A[b] ;
	cout << r;
	return 0;
}