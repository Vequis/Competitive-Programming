#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<int> V;

    for(int i=10; i>=1; i--) V.push_back(i);

    cout << V.size() << endl;

    V.erase(V.begin() + 5);

    cout << V.size() << endl;


    for(int i=1; i<=9; i++) cout << "V[" << i << "]: " << V[i] << endl;
    return 0;
}
