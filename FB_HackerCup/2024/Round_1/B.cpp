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

map<int, int> resp;
vi primos;
int vis[10234567];

void solve() {

    int acum = 1;

    primos.pb(2);
    primos.pb(3);
    primos.pb(5);

    acum = 1;
    for (int i = 2; i<10234567; i++){
        if (vis[i] == 0) {
            if (primos[sz(primos) - 1] == i - 2) acum++;
            primos.pb(i);
            for (int j = i*i; j < 10234567; j+=i) vis[j] = 1;

        }

        if (resp[i] == -1) resp[i] = acum;
    }

    resp[1] = 0;
    resp[2] = 0;
    resp[3] = 0;
    resp[4] = 0;
    resp[5] = 2;

}

int casos[111];

signed main(){_
    int t;
    cin >> t;
    // t=1;

    int cont = 1;

    while(cont <= t) {
        int n;
        cin >> n;
        resp[n] = -1;
        casos[cont] = n;
        cont++;
    }
    solve();

    cont = 1;
    while(cont <= t) {
        cout << "Case #" << cont << ": ";
        cout << resp[casos[cont]] << endl;
        cont++;
    }

    return 0;
}