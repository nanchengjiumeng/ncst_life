#include <iostream>
#include <vector>


using namespace std;

void print_star(int p_n,long long int n,char ch){
	for(int i = 0; i<p_n;i++){
		std::cout<< ' ';
	}
	for(int i = 0; i<n;i++){
		std::cout<<ch;	
	}
	std::cout<<std::endl;
}


int main(){
	long long int n,m=1;
	char ch = '*';
	std::cin>>n>>ch;
	vector<long long int> vec;
	bool flag = true;
	while(flag && n>0){
		if(m==1){
			vec.push_back(m);
			n--;
		}
		else if(n>=m*2){
			vec.push_back(m);
			n=n-(m*2);
		}else{
			flag = false;
		}
		
		m=m+2;
	}

	int p_n = 0;
	for(int i = vec.size()-1; i>=0; i--){
		print_star(p_n,vec[i],ch);
		if(i!=0){p_n++;}
	}
	for(int i = 1;i<vec.size();i++){
		p_n--;
		print_star(p_n,vec[i],ch);
	}
	std::cout<<n<<std::endl;
	
	
	
	
	return 0;
}
