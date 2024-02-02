#include <iostream>

using namespace std;

string title(string F){
	for (int i=F.size()-1;i>=0;i--){
        if (F[i]==' '){
            F[i+1] = F[i+1] - 'a' + 'A';
        } else if (F[i]>='A' and F[i]<='Z'){
            F[i] = F[i] + 'a' - 'A';
        }
	}
	F[0] = F[0] + 'A' - 'a';

	return F;
}

int main(){
	string F;

	getline(cin, F);

	cout << title(F) << "\n";

	return 0;
}
