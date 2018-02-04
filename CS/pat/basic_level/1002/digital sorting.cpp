#include <iostream>

using namespace std;

int compute(int &a){
	int res=0;
	if(a%5==0 && a%2==0) {	
		res=1;
	}else if(a%5!=0){
		res = a%5+1;
	}
//	cout << '\n' <<res ;
	return res;
}

int result(int (&A)[7], int &a,int &res){
	///cout << res << ' ' << a;
	if(res==1){
		A[res]=A[res]+a;
	}
	if(res==2){
		if(A[0]==0){
			A[0]=1;
			A[res]=A[res]+a;
		}else{
			A[0]=0;
			A[res]=A[res]-a;
		}
	}
	if(res==3){
		A[res]=A[res]+1;
	}
	if(res==4){
		A[res]=A[res]+a;
		A[6]=A[6]+1;
	}
	if(res==5){
		A[res]=a>A[res]?a:A[res];
	}
	return 0;
}



int main(){
	int N,A[7]={0},a,b;
	cin >>N;
	for(int i=0;i<N;i++){
	   cin >> a;
	   b=compute(a);
	//  cout << '\n' << a << ' ' << b;
	   result(A,a,b);
	}
	for(int i=1;i<=5;i++){
		if(i==4){
			if(A[6]==0){
				printf("N ");
			}else{
				printf("%.1f ",A[4]*1.0/A[6]);
			}
		}else if(i==5){
			if(A[i]==0){
				cout <<"N";
			}else{
				cout << A[i];	
			}
		}else{
			if(A[i]==0){
				cout <<"N ";
			}else{
				cout << A[i] << ' ';	
			}
		}
	
	}
	return 0;
}

