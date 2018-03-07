#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

int main(){
	vector<int>  a={10,123,334,234,5543,656,456,45645,546,123};
	vector<int> a_vec(a);
	vector<int>::iterator a_0 = a.begin(),a_end =a.end();
	a_0+=a_end;
	cout<<int(*a_0);
	
	return 0;
}
