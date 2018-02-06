#include <iostream>
#include <string>
using namespace std;
int main(){
	//std::cout<<"a\nb\nc"<<std::endl;
	long counter[10]={0};
	std::string str;
	std::cin>>str;
	int len=str.length();
	for(int i=0; i<len; i++){
		counter[str[i]-'0']++;
	}
	for(int i = 0; i<10; i++){
		if(counter[i]>0)
			std::cout<<i<<':'<<counter[i]<<std::endl;
	}
	
	
	
	return 0;
}