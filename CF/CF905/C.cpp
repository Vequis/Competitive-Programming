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

int a[212345];
string par[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 1; i <=n; i++) {
            cin >> a[i];
        }

        map<string, int> f;
        int resp = 0;

        for(int i = 1; i <=n; i++) par[i] = "";

        for(int l = 1; l <=n; l++) {
            resp += n - l + 1;
            for(int j = 1; j<=n + 1 - l; j++) {
                par[j] = par[j] + (char)('0' + a[j + l - 1]);

                f[par[j]]++;

                cout << par[j] << endl;

                if (f[par[j]] > 1) resp--;
                if (f[par[j]] == 2) resp--;
            }

            cout << resp << endl;
        }

        cout << resp << endl;
    }

    return 0;
}
