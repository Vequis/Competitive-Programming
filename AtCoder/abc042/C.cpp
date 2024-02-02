#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {

    int n, k;
    cin >> n >> k;

    int l = log(n)+1;

    vector<int> V;

    for (int i=0; i<k; i++) {
        int num;
        cin >> num;
        V.push_back(num);
    }

    bool var = true;

    while (true) {
        var = true;
        for (int i=0; i<k; i++){

            int nV = n;
            while (nV!=0){
                int dig;
                dig = nV%10;
                nV/=10;
                if (V[i]==dig){
                    var = false;
                    break;
                }
            }
        }

        if (var){
            cout << n << endl;
            break;
        } else {n++;}
    }
    return 0;
}
