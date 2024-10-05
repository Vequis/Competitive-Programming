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

int mult(int a, int b) {
    return (a*b)%MODN;
}

int soma(int a, int b) {
    return (a+b)%MODN;
}

int subt(int a, int b) {
    return (a - b + MODN) % MODN;
}

int code[112345];

void solve() {
    string e;
    int k;
    cin >> e >> k;
    k--;

    for (int i = 1; i <=sz(e); i++) {
        if (e[i-1] == '?') code[i] = -1;
        else code[i] = (int)(e[i-1] - '0');
    }

    int resp = 1;
    int ant = 1;

    if (code[sz(e)] == -1) {
        if (k%15 < 6) code[sz(e)] = 6 - k%15;
        else code[sz(e)] = 15 - k%15;
        
        if (k%15 < 6) {
            k = k/15;
            k = k<<1;
        } else {
            k = k/15;
            k = (k<<1) + 1;
        }
    }

    code[sz(e) + 1] = 1;

    for (int i = sz(e) - 1; i>=1; i--) {
        int temp = resp;

        if (code[i] == -1 or code[i] == 1) {
            if (code[i+1] and code[i+2]) resp = soma(resp, ant);
        } else if (code[i] == 2) {
            if (code[i+1] and code[i+1]<=6 and code[i+2]) {
                resp = soma(resp, ant);
            }
        } else {
            resp = resp;
        }

        if (code[i] == -1) {
            if (code[i+1] <= 6) {
                if (k%2 == 0) code[i] = 2;
                else code[i] = 1;
                k = k>>1;   
            } else {
                code[i] = 1;
            }
        }

        ant = temp;
    } 


    for (int i = 1; i<=sz(e); i++) cout << code[i];
    cout << ' ';

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    int cont = 1;
    while(cont <= t) {
        cout << "Case #" << cont << ": ";
        solve();
        cont++;
    }

    return 0;
}