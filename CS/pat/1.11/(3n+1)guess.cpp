#include <iostream>
using namespace std;
int main()
{
	int n;
	int counter=0;
	cout << "Please enter an integer within 1000: \n";
	cin >> n;
	while(n>1000)
		cout << "Please enter an integer within 1000：\n";
		cin >> n;
	
    cout <<"the number is:" << n << "\n";
	while(n!=1){
		counter++;
		if(n%2==1)
			n=(3*n+1)/2;
		else
			n=n/2;
	}
	cout <<"Need " << counter << " steps to get this number is equal to 1.";
    return 0;
}