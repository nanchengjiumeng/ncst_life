#include <iostream>
#include <vector>
#include <string>
#include <math.h>


using namespace std;



long long int indexOf(char a, string str_a){
	long long int len =str_a.length();
	for(long long int i =0; i<len; i++){
		if(str_a[i] == a){
			return i;
			};
	}
	return -1;
}

bool check_a_vec(string a,vector<long long int> a_vec, long long int index){
	for(long long int i =0; i<a_vec.size(); i++){
		//cout <<a[a_vec[i]]<<'*'<<a[index]<<endl ;
		if(a[index] == a[a_vec[i]] ||  abs(a[index]-a[a_vec[i]])==32 ){
			return false;
			}
	}
	return true;
}

void comp_str_then_printf(string a, string b){
	long long int a_i;
	vector<long long int> a_vec;
	for(a_i = 0; a_i<a.length(); a_i++){
		if( indexOf(a[a_i],b) == -1 ){
			if(check_a_vec(a,a_vec,a_i)){
				a_vec.push_back(a_i);
				};
		}
	}

	for(a_i = 0; a_i<a_vec.size(); a_i++){
		char m;
		m = (char)(toupper(a[a_vec[a_i]]));
		cout<<(char)(m);
	}
	cout<<endl;
	return;
}




int main (){
	string str_a,str_b;
	std::cin>>str_a>>str_b;


	comp_str_then_printf(str_a,str_b);
	return 0;
}