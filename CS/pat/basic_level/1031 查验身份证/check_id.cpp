#include <iostream>
#include <vector>
#include <string>

#define MAXSTRING 100
#define ID_DIGIT 18

using namespace std;

const int w[ID_DIGIT-1]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
const char M[11]={'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
const int Z[11]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

bool weight(string str){
	char ch_z = str[ID_DIGIT-1], ch_w=' ';
	int id_weight = 0;
	for(int i = 0; i<ID_DIGIT-1; i++){
		id_weight+= (str[i] - '0')*w[i];
	}
	id_weight = id_weight % 11;
	ch_w = M[Z[id_weight]];
	return ch_z == ch_w;
}

using namespace std;

int main(){
	string ids[MAXSTRING]={""};
	int n,i=0;
	bool all_passed = true;
	std::cin>>n;
	while(i<n){	
		cin >>ids[i];
		i++;
	}
	
	for(i=0; i< n; i++){
		if(!weight(ids[i])){
			std::cout<<ids[i]<<std::endl;
			if(all_passed){all_passed=false;}
		}
	}
	if(all_passed){
		std::cout<<"All passed"<<std::endl;
	}
	
	
	
	return 0;
}