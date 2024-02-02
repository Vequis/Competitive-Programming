#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    vector<int> V;
    vector<int> U;

    cin >> n;

    for (int i=0; i<n; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    cin >> m;

    for (int i=0; i<m; i++){
        int num;
        cin >> num;
        U.push_back(num);
    }

    bool breaked;

    for (int i=0; i<n; i++){
        breaked = false;
        for(int j=0; j<m; j++){
            if (U[j]==V[i]){
                breaked = true;
                break;
            }
        }
        if (!breaked) cout << V[i] << " ";
    }
    cout << endl;
    return 0;

}
