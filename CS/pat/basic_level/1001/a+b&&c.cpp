#include <iostream>

using namespace std;

string cmp(long int &a, long int &b, long int &c){
	long int d = a+b;
	bool r = false;
	if(d>c) r = true;
	
	return r?"true\n":"false\n";	
}

int main(){
    int t;
	long int a,b,c;
	a=-2147483648;
	b=-2147483648;
	cout << a+b << endl;
    cin >> t;
    long int arr[t][3];
    for(int i = 0; i<t; i++)
	{
	//	cout << "the "<< i+1 << "th group:\n";
        cin >> a;
        cin >> b;
        cin >> c;
        arr[i][0]=a;
        arr[i][1]=b;
        arr[i][2]=c;
	//	cout << "\n";
	}
     
    for(int i = 0; i<t; i++)
	{
		a = arr[i][0];
        b = arr[i][1];
        c = arr[i][2];
		string r = cmp(a,b,c);
        cout << "Case #" << i+1 << ": " << r <<  endl;
	}
    return 0;
}