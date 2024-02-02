#include <iostream>

using namespace std;

int fact(int n){
	if (n<2){
		return 1;
	} else {
		return fact(n-1)*n;
	}
}

int main() {
	int n;
	cin >> n;
	
	cout << fact(n) << endl;
	return 0;
	
}
