#include <iostream>
#include <string>
using namespace std;
const string today = "2014/09/06";
const string limit_day = "1814/09/05";

bool str_AGB(string a, string b){
	bool f = true;
	for(int i=0; i<10; i++){
		if(a[i]-b[i]<0){
			//cout<<"***"<<a[i]<<'?'<<b[i]<<"***"<<endl;
			f = false;
			break;
		}
		else if(a[i]-b[i]>0){
			break;
		}
	}
	return f;
}
bool judge_birthday(string birth){
	bool f = true;
	if(str_AGB(limit_day,birth)){
		f = false;
	}
	if(str_AGB(birth,today)){
		f = false;
	}
	return f;
}
struct People{
	string name;
	string birthday;
};
struct P_census{
	long long int number=0;
	struct People elder ;
	struct People young ;
};

int main(){
	long long int n;
	struct P_census p_census;
	p_census.elder.birthday = today;
	p_census.young.birthday = limit_day;
	struct People p;
	std::cin>>n;
	while(n--){
		std::cin>>p.name>>p.birthday;

		if(judge_birthday(p.birthday)){
			p_census.number++;
			
			
			if(str_AGB(p_census.elder.birthday, p.birthday)){
				
				p_census.elder.birthday = p.birthday;
				p_census.elder.name = p.name;
			}
			if(str_AGB(p.birthday,p_census.young.birthday)){
				p_census.young.birthday = p.birthday;
				p_census.young.name = p.name;
			}
		}
	}

	std::cout<<p_census.number<<' '<<p_census.elder.name
	<<' '<< p_census.young.name;
	
	
	return 0;
}