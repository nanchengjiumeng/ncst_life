#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
using std::vector;
using std::cin;
using std::cout;


int *sort(double w[], double v[],int n){
	int *arr;
	arr = new int[n];
	for(int i = 0; i< n;i++){
		arr[i]=i;
	}
	for(int i = 0; i< n;i++){
		for(int j = i+1; j < n; j++){
		if(v[arr[i]]/w[arr[i]] < v[arr[j]]/w[arr[j]]){
				int a = arr[i];
				arr[i]=arr[j];
				arr[j]=a;
			}
		}
	}	
	return arr;
} 

double MTVOAL(int n,double W,  double w[],  double v[]){
	int *index = sort(w,v,n);
	 double a=W;
	int d=0,len=0;
	 double val=0;
	while(a>0){
			if(a>=w[index[d]]){
				val=val+v[index[d]];
				a=a-w[index[d]];		
			}else{
				 double m = a/w[index[d]];
				val=val+v[index[d]]*m;
				a=a-a;
			}
			d++;
			if(d>=n){
				break;
			}
		}
	return val;
}

int main(){
	int n,W;
	cin>>n>>W;
	double w[n],v[n];
	for(int i = 0; i<n; i++){
		cin >>v[i]>>w[i];
	}
	double a =MTVOAL(n,W,w,v);
	printf("%.4f", a);
	return 0;
}
