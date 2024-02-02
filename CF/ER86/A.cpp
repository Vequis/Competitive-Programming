#include <iostream>
#include <cmath>

using namespace std;

int main() {

    int n;
    cin >> n;

    int v[n];

    for (int i=0; i<n; i++) {
        long long int ans=0;

        int x,y;
        cin >> x >> y;

        int a,b;
        cin >> a >> b;

        if (x>0 and y>0){
            int m = min(x,y);

            ans += m*b;

            x -= m;
            y -= m;

            ans += (x+y)*a;
        } else {
            ans += a*(abs(x)+abs(y));
        }

        v[i] = ans;
    }

    for (int i=0; i<n; i++) {
        cout << v[i] << endl;
    }
    return 0;

}
