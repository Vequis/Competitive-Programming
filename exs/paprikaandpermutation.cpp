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

int a[112345];
int ocupado[112345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int cont = 0;
        int n;
        cin >> n;

        vi aux;

        for(int i = 1; i <= n; i++) ocupado[i] = 0;

        for (int i = 1; i <=n; i++) {
            cin >> a[i];
            if (a[i] <= n) {
                if (ocupado[a[i]]) {
                    aux.pb(a[i]);
                }

                ocupado[a[i]] = 1;
            } else {
                aux.pb(a[i]);
            }
        }

        sort(all(aux));

        int ptr = 1;
        while(ocupado[ptr])ptr++;

        for (int i = 0; i < sz(aux); i++) {
            if (((aux[i] - 1) / 2) >= ptr) {
                ocupado[ptr] = 1;

                while(ocupado[ptr]) ptr++;

                cont++;
            } else {
                cont = -1;
                break;
            }
        }

        aux.clear();
        cout << cont << endl;
    }

    return 0;
}
