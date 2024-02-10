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

int mark[212345];
vi primos;

void crivo(int n) {
    primos.pb(2);
    for(int i = 3; i <=n; i+=2) {
        if (!mark[i]) {
            primos.pb(i);
            for(int j = i*i; j<=n; j+=i) mark[j] = 1; 
        }
    }
}

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

map<vii, int> f;

vi contadores;
int v[112345];

signed main(){_

    crivo(212300);

    int t;
    // cin >> t;
    t = 1;

    while(t--) {
        int n;
        cin >> n;

        int cont_1 = 0;
        for(int i = 0; i < n; i++) {
            cin >> v[i+1];
            if (v[i+1] == 1) cont_1++;
        }
        int resp = 1;

        for(int x : primos) {
            if (cont_1 == n) break;

            // cout << x << ' ' << cont_1 << endl;

            contadores.clear();
            int cont_0 = 0;
            for (int i = 1; i <=n; i++) {
                int cnt = 0;
                while(v[i] % x == 0) {
                    cnt++;
                    v[i]/=x;
                    if (v[i] == 1) cont_1++;
                }

                contadores.pb(cnt);
                if (cnt == 0) cont_0++;
                if (cont_0 > 1) break;
            }
            sort(all(contadores));
            resp *= power(x, contadores[1]);
        }

        cout << resp << endl;

    }

    return 0;
}
