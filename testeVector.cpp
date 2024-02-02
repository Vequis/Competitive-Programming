#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int num;
    cin >> num;
    vector<int> V;

    for(int i=0; i<num; i++) {
        int a;
        cin >> a;
        V.push_back(a);
    }

    cout << endl;
    for (int i=0; i<(int)V.size(); i++) {
        cout << V[i] << endl;
    }
    cout << endl;

    while (true){
        int b,c;
        cout << "Faça a troca entre as posições: ";
        cin >> b >> c;
        if (b==0 or c==0) break;

        //Fzendo troca;
        int temp;
        temp = V[b-1];
        V[b-1] = V[c-1];
        V[c-1] = temp;

        cout << endl;
        for (int i=0; i<(int)V.size(); i++) {
            cout << V[i] << endl;
        }
        cout << endl;
    }

    cout << "Acabou, a config final é a seguinte";
    cout << endl;
    for (int i=0; i<(int)V.size(); i++) {
        cout << V[i] << endl;
    }
    cout << endl;
}
