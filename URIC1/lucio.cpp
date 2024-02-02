#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {

	int n;
	cin>>n;

  int v[n];

	for (int i=0; i<n; i++) {
		cin >> v[i];
	}

	sort(v, v+n);

	int Amaior;

	int pos;

	for (int i=0; i<n-2; i++) {
		double p = (v[i]+v[i+1]+v[i+2])/2;
		double mult = p*(p-v[i]) * (p-v[i+1]) * (p-v[i+2]);
		if (mult>=0){
    	int A = sqrt(mult);
			if (A>=Amaior){
				Amaior=A;
				pos = i;
			}
		}
	}

	cout << v[pos] << " " << v[pos+1] << " " << v[pos+2];
}
