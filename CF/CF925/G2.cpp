#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 998244353
#define int long long // -> solução divina

using namespace std;

int sum(int a, int b) { return (a+b)%MODN; }
int mult(int a, int b) { return (a*b)%MODN; }
int power(int a, int b) {
    int resp = 1;
    int pot = a;
    while(b > 0) {
        if (b & 1) resp = mult(resp, pot);
        pot = mult(pot, pot);
        b/=2;
    }
    return resp;
}
//So funciona se MODN for primo
int modinv(int x) {
    return power(x, MODN-2);
}


vi fatorial(2123451);
void solve() {
    int c1, c2, c3, c4;
    cin >> c1 >> c2  >> c3 >> c4;

    if (c1 == 0 and c2 == 0 and c3 == 0 and c4 == 0) {
        cout << 1 << endl;
        return;
    } else if (c1 == 0 and c2 == 0) {
        if (c3 != 0 and c4 != 0) {
            cout << 0 << endl;
            return;
        } else {
            cout << 1 << endl;
            return;
        }
    } else if (abs(c1 - c2) > 1) {
        cout << 0 << endl;
    } else if (c1 == 0 or c2 == 0) {
        cout << 1 << endl;
        return;
    }


    if (c1 == c2) {
        int resp = mult(mult(fatorial[c3 + c1], mult(modinv(fatorial[c3]), modinv(fatorial[c1]))), mult(fatorial[c4 + c1 - 1], mult(modinv(fatorial[c4]), modinv(fatorial[c1-1]))));
        resp = sum(resp, mult(mult(fatorial[c3 + c1 - 1], mult(modinv(fatorial[c3]), modinv(fatorial[c1-1]))), mult(fatorial[c4 + c1], mult(modinv(fatorial[c4]), modinv(fatorial[c1])))));
        // cout << fatorial[c3 + c1] << ' ' << fatinv[c3] << endl;
        cout << resp << endl;

    } else if (abs(c1 - c2) == 1) {
        int m = min(c1, c2);

        int resp = mult(mult(fatorial[c3 + m], mult(modinv(fatorial[c3]), modinv(fatorial[m]))), mult(fatorial[c4 + m], mult(modinv(fatorial[c4]), modinv(fatorial[m]))));
        cout << resp << endl;
    }
}

signed main(){_

    int t;
    cin >> t;

    fatorial[0] = 1;
    for(int i = 1; i <=2123450; i++) {
        fatorial[i] = mult(fatorial[i-1], i);
    }

    while(t--) {
        solve();
    }

    return 0;
}
