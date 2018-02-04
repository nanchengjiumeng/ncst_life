#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int &a){
	bool res = true;
	for(int i = 2; i<=sqrt(a); i++){
		   if(a%i==0)
		   {
			   res = false;
		   }
	}
	return res;
}


int main(){
	int n,m;
	int arr[30000];
	cin >> n >> m;
	int i=2;
	int index=0;
	while(true){
		bool res = isPrime(i);
		if(res){
			arr[index]=i;
			index++;
		}
		if(index==m) 
		{
			break;
		}
		i++;
	}
	
	int counter=1;
	for(int i = n-1;i<m;i++){
		cout << arr[i];
		if(i<m-1){
			
			if(counter==10){
				cout << '\n';
				counter=1;
			}else{
				cout<< ' ';
				counter++;
			}
		}
	}
	return 0;
}