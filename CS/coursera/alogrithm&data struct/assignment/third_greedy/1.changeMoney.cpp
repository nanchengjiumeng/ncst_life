#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;
using std::vector;
using std::cin;
using std::cout;


int *changingMoney(int n){
	int Ds[]={10,5,1};
	int a=n,d=0,len=0;
	vector<int> arr;
	while(a>0){
			if(a>=Ds[d]){
				arr.push_back(Ds[d]);
				a=a-Ds[d];
				len++;
			}else{
				if(d<2){
				  d++;	
				}else{
					break;
				}
			}
		}
	int *res;
	res = new int[len+1];
	res[0]=len;
	for(int i = 0;i<len;i++){
		res[i+1]=arr[i];
	}
	return res;
}


int main(){
	int N;
	cin>> N ;
	int *a=changingMoney(N);
	cout<<a[0];
	
	return 0;
}