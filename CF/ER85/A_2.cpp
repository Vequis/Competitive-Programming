#include <iostream>
#include <vector>

using namespace std;

int a[101];
int b[101];
vector<string> V;

int main() {
    int t;
    cin >> t;

    for (int i=0; i<t; i++) {

        bool ok = true;

        int n;
        cin >> n;

        for (int j=0; j<n; j++) {
            cin >> a[j] >> b[j];
        }

        if (b[0] > a[0] ) {
            ok = false;
        }

        for (int j=1; j<n; j++) {
            if (a[j] < a[j-1] or b[j] < b[j-1] or b[j] > a[j]) {
                ok = false;
                break;
            }

            if ((b[j]-b[j-1] > a[j] - a[j-1])){
                ok = false;
                break;
            }
        }

        if (ok) {
            V.push_back("YES");
        } else {
            V.push_back("NO");
        }

    }

    for (int i=0; i<t; i++) {
        cout << V[i] << endl;
    }
    return 0;
}
