#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ordem(int a, int b){
    return a>b;
}

int main(){

    int n;
    cin >> n;

    vector<int> V;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    sort(V.begin(), V.end(), ordem);

    while (true){
        if (V[0] < V[1] + V[2]) {
            cout << V[0] << " " << V[1] << " " << V[2] << endl;
            break;
        }else{
            V.erase(V.begin());
        }
    }

}
