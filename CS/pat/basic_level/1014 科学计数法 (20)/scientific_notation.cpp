#include <iostream>
#include <regex>
#include <string>
#include <algorithm>

using namespace std;
void generate_s_n( std::smatch sm ){
	int _e = 0; //需要移动的位数
	stringstream = ss;
	ss<<sm[5].str();
	ss>>_e;
	// int _e_basic = 1;
	// string _e_str = sm[5].str();
	// for(int i = _e_str.size()-1; i >= 0; i--){
		// _e = _e + (_e_str[i]-'0')*_e_basic;
		// _e_basic *= 10;
	// }
	if(sm[1]=='-') cout<<'-';
	if(_e == 1){
		cout << sm[2] <<'.'<<sm[3];
	}else{
		if(sm[4]=='-'){
			cout<<"0.";
			for(int i = 1;i<_e; i++) cout<<'0';
			cout<<sm[2]<<sm[3];
		}
		if(sm[4]=='+'){
			cout<<sm[2];
			string str = sm[3].str();
			int len = str.size();
			int out_sum = max(len,_e);
			int index = 0;
			while(out_sum){
				if(index!=_e){
					if(index < len) 
						cout<<str[index];
					else
						cout<<'0';
					index++;
					out_sum--;
				}else{
					if(_e<len) 
						cout<<'.';
						_e = -1;
				}
			}
		}
	}
	
	
}

int main(){
	string str("([+-])([1-9]).([0-9]+)E([+-])([0-9]+)");
	string s_in;
	cin>>s_in;
	std::smatch sm;
	if(std::regex_match(s_in,sm,std::regex(str)))
			generate_s_n(sm);
		
	
	return 0;
}