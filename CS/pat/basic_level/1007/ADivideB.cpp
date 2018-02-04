#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	std::string str;
	short B=0;
	std::cin>>str>>B;
	int size = str.size();
	std::vector<short> C;
	int r=0;
	bool flag=false;
	for(int i = 0; i<size;i++){
		//A[i]=(str[i]-'0')
		if((r*10+(str[i]-'0'))/B)flag=true;
		if(flag){
			C.push_back((r*10+(str[i]-'0'))/B);
		}
		r=(r*10+(str[i]-'0'))%B;
	}
	for(int i =0; i< C.size();i++){
		std::cout<<C[i];
	} 
	std::cout<<' '<<r<<std::endl;
	
	return 0;
}