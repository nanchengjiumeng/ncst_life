#include <iostream>
class Student
{
	public:
		int p;
		int m;
		int e;
}
int main(){
	int p,m,n;
	Student s;
	cout << "Input P,M,N:\n"
	cin >> p >> m >> n;
	cout << "Input:";
	cin >> s.p >> s.m >> s.e;
	
	cout >> "grade is :" >> s.p >> s.m >> s.e >>endl;
	
	return 0;
}