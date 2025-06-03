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
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int minimo[1123456];
int prox[1213456][26];

void solve() {
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;
    s = s+'$';

    map<char, int> acumulado;

    for (int j = 0; j < k; j++) {
        prox[n][j] = n;
        char c = ('a' + j);
        acumulado[c] = 0;
        minimo[n] = 0;
    }


    for (int i = n-1; i>=0; i--) {
        
        for (int j = 0; j < k; j++) {
            prox[i][j] = prox[i+1][j];
        }
        acumulado[s[i]]++;
        minimo[i] = INF;
        if (i!=n-1) prox[i][(int)(s[i+1] - 'a')] = i+1;
        // cout << i << endl;
        for (int j = 0; j < k; j++) {
            minimo[i] = min(minimo[i], 1 + minimo[prox[i][j]]);
            // cout << j << ' ' << prox[i][j] << ' ' << minimo[prox[i][j]] << endl;
        }

        // cout << i << ' ' << minimo[i] << endl;
    }

    int q;
    cin >> q;

    while(q--) {
        string qr;
        cin >> qr;

        int ptr = -1;

        for (char c : qr) {
            if (ptr == -1) {
                if (c == s[0]) ptr = 0;
                else ptr = prox[0][(int)(c - 'a')];
            } else {
                ptr = prox[ptr][(int)(c - 'a')];
            }
        }

        // cout << ptr << '*' << endl;

        if (ptr == n) {
            cout << 0 << endl;
        } else {
            cout << minimo[ptr] << endl;
        }
    }
    
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}