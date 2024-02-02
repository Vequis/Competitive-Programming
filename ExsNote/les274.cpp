#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void ApagarEl(int num, vector<int> V){
    for(int i=0; i<(int)V.size(); i++) {
        if (V[i]==num){
            cout << V[i]<< endl;
            int temp;
            temp = V[V.size()-1];
            cout << temp;
            V[V.size()-1] = V[i];
            V[i] = temp;
            V.pop_back();

        }
    }
}

int main() {
    int n, m;
    cin >> n;

    vector<int> V;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    cin >> m;

    for (int i=0; i<m; i++) {
        int num;
        cin >> num;
        ApagarEl(num, V);
    }

    sort(V.begin(), V.end());

    for (int i=0; i<n-m; i++) {
        cout << V[i] << " ";
    }

    cout << endl; return 0;
}
