#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(int a,int b){return a<b;}


int main(){
	int digits_counter[10]={0};
	int index=0,end=10;
	while(index!=end){
		std::cin>>digits_counter[index];
		index++;
	}
	index=0;
	
	int L = 1;
	while(index!=end){
		if(digits_counter[L]>0){
			break;
		}
		L++;
		index++;
	}
	index=0;
	
	std::cout<<L;
	digits_counter[L]--;
	while(index!=end){
		if(digits_counter[index]!=0){
			for(int i =0; i< digits_counter[index];i++){
				std::cout<<index;
			}	
		}
		index++;
	}
	return 0;
}
