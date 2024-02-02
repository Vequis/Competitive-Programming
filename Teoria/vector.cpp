#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int main(){
	vector<int> V;

	V.resize(10); //Muda o tamanho do vector V para 10.
	V.push_back(5);
	V.pop_back(); //Apaga o ultimo elemento do vector V.
	V.clear(); //Remove todos os elementos do vector V.


	V.push_back(10);
	V.push_back(2);
	V.push_back(4);

	sort(V.begin(), V.end()); //Ordena todo o vector V, deixando os elementos na seguinte ordem {2, 4, 5, 10}.


}
