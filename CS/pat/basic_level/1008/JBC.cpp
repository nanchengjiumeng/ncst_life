#include <iostream>
#include <vector>
using namespace std;

struct People{
	short J[3]={0,0,0};
	short B[3]={0,0,0};
	short C[3]={0,0,0};
	short All[3]={0,0,0};
	void printfData(){
		for(int i=0;i<3;i++){
			All[i]=B[i]+C[i]+J[i];
		}
		std::cout<<All[0]<<' '<<All[1]<<' '<<All[2]<<std::endl;
	}
	char JOrBOrC(){
		short a[3];
		a[0]=J[0];
		a[1]=C[0];
		a[2]=B[0];
		
		short index=0;
		for(int i=1;i<3;i++){
			if(a[i]>=a[index]) index=i;
		}
		if(index==0){
			return 'J';
		}
		if(index==1){
			return 'C';
		}
		if(index==2){
			return 'B';
		}
		return '0';
	}
};

int main(){
	short N = 0;
	People X;
	People Y;
	std::cin >> N;
	char a,b;
	while(N){
		std::cin>>a>>b;
		if(a=='B'&&b=='B'){
			X.B[1]++;
			Y.B[1]++;
		}
		if(a=='B'&&b=='C'){
			X.B[0]++;
			Y.C[2]++;
		}
		
		if(a=='B'&&b=='J'){
			X.B[2]++;
			Y.J[0]++;
		}
		if(a=='C'&&b=='B'){
			X.C[2]++;
			Y.B[0]++;
		}
		if(a=='C'&&b=='C'){
			X.C[1]++;
			Y.C[1]++;
		}
		
		if(a=='C'&&b=='J'){
			X.C[0]++;
			Y.J[2]++;
		}
		if(a=='J'&&b=='B'){
			X.J[0]++;
			Y.B[2]++;
		}
		if(a=='J'&&b=='C'){
			X.J[2]++;
			Y.C[0]++;
		}
		
		if(a=='J'&&b=='J'){
			X.J[1]++;
			Y.J[1]++;
		}
		
		N--;
	}
	X.printfData();
	Y.printfData();
	a=X.JOrBOrC();
	b=Y.JOrBOrC();
	std::cout<<a<<' '<<b<<std::endl;
	return 0;
}