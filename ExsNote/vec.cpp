#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    vector<int> V;

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        V.push_back(num);
    }

    cout << endl;
    for (int i=0; i<n; i++){
        cout << V[i] << endl;
    }
    cout << endl;

    int a;
    cout << "Qual posição queres levar ao final?" << endl;
    cin >> a;

    int temp;
    int tam = (int)V.size();
    temp = V[a-1];
    V[a-1] = V[tam-1];
    V[tam-1] = temp;


    cout << endl;
    for (int i=0; i<n; i++){
        cout << V[i] << endl;
    }
    cout << endl;



}
