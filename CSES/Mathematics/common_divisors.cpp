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

// Hn <= logn
// sum i = 1->10^6 (10^6/i) <= 10^6 * log(10^6)
// executar quase um crivo

int f[1123456];

signed main(){_

    int n;
    cin >> n;
    int limite = -1;
    for(int i = 1; i <=n; i++) {
        int a;
        cin >> a;
        limite = max(a, limite);
        f[a]++;
    }

    int resp = 1;
    for(int i = 2; i<=limite; i++) {
        int cont = 0;
        for(int j = i; j<=limite; j+=i) {
            cont += f[j];
            if (cont >= 2) break;
        }

        // cout << i << ' ' << cont << endl;
        if (cont>=2) resp = i;
    }

    cout << resp << endl;

    return 0;
}
