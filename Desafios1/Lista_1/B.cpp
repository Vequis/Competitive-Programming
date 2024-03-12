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

int n, k;
int p;
int resp = 0;
vector<ii> v;

bool cmp(ii a, ii b) {
    return a.fs + p*a.sc < b.fs + p*b.sc;
}

bool verifica() {
    sort(all(v), cmp);

    int cont = 0;
    for (int i = 0; i < p; i++) {
        //cout << v[i].fs << ' ' << p*v[i].sc << endl;
        cont += v[i].fs + p*v[i].sc;
    }
    //cout << p << ' ' << cont << endl;
    resp = cont;
    return cont > k;
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a;
        v.eb(a, i+1);
    }

    int ini = 1, fim = n + 1;
    while(ini < fim) {
        p = ini + (fim - ini)/2;
        if (verifica()) fim = p;
        else ini = p + 1;
    }
    p = ini - 1;
    verifica();
    cout << ini - 1 << ' ' << resp << endl;

}

signed main(){_
    int t;
    //cin >> t;
    t=1;
    while(t--) {
        solve();
    }

    return 0;
}
