#include <iostream>
#include <string>
using namespace std;

void reverse_arr(int a[],int b[],int n){
	int m;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(a[j]>a[i]){
				m=a[j];
				a[j]=a[i];
				a[i]=m;
			}
		}
	}
	for(int i=0;i<n;i++){
		b[n-1-i]=a[i];
	}
}
bool check_arr(int a[],int n){
	bool f=true;
	for(int i=1;i<n;i++){
		if(a[i]!=a[0])f=false;
	}
	return f;

}
void get_arr(int a[],int b){
	for(int i=0;i<4;i++){
		a[i]=0;
	}
	for(int i=3;i>=0;i--){
		a[i]=b%10;
		b/=10;
	}
	
	
}
int get_digit(int a[]){
	//std::cout<<a[0]<<a[1]<<a[2]<<a[3];
	int A=a[0]*1000+a[1]*100+a[2]*10+a[3];
	//std::cout<<A<<'\n';
	return A;
}
void printfFormat(int N[],int M[],int num){
	
	std::cout<<N[0]<<N[1]<<N[2]<<N[3]<<" - "<<M[0]<<M[1]<<M[2]<<M[3]\
				<< " = ";

	if(num>999){
		std::cout<<num<<std::endl;
	}else if(num>99){
		std::cout<<"0"<<num<<std::endl;
	}else if(num>9){
		std::cout<<"00"<<num<<std::endl;
	}else{
		std::cout<<"000"<<num<<std::endl;
	}
	
}

int main(){
	int n=0,m=0,size=4;
	int N[4]={0,0,0,0},M[4]={0,0,0,0};
	std::string str;
	std::cin>>str;
	int Si=str.size();
	//std::cout<<Si<<'\n';
	int Ni=3;
	while(Si){
		N[Ni]=str[Si-1]-'0';
		Ni--;
		Si--;
	}
	reverse_arr(N,M,size);
	n=get_digit(N);
	m=get_digit(M);
	int res=0;
	if(check_arr(N,size)){
		printfFormat(N,M,res);
	}else {
		for(;;){
		//	std::cout<<n<<' ' <<m<<"*************\n";
			res=n-m;
			printfFormat(N,M,res);
			get_arr(N,res);
			reverse_arr(N,M,size);
			if(res==6174)break;
			n=get_digit(N);
			m=get_digit(M);
		}
	}
	
	
	return 0;
}