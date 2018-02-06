#include <iostream>
#include <vector>
using namespace std;

using std::cin;
using std::cout;
using std::vector;

int main(){
	int A=0,B=0,C=0,D=2,i=0;
	vector<int> res;
	cin>>A>>B>>D;
	C=A+B;
	while(C){
		res.push_back(C%D);
		C/=D;
	}
	i=res.size();
	while(i){
		cout<<res[--i];
	}
	
	
	return 0;
}