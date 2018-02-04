#include <iostream>

using namespace std;

int main(){
	long A=0,B=0,Pa=0,Pb=0;
	short Da=0,Db=0,Ma=0,Mb=0;
	std::cin>>A>>Da>>B>>Db;
	while(A){
		Ma = A%10;
		A = A/10;
		if(Ma==Da){
			Pa=Pa*10+Ma;
			Ma=0;
		}	
	}
	while(B){
		Mb = B%10;
		B = B/10;
		if(Mb==Db){
			Pb=Pb*10+Mb;
			Mb=0;
		}
	}
	std::cout<<Pa+Pb<<std::endl;
	return 0;
}