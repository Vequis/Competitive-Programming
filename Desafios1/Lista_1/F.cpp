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

vi v;
int n, m;
int k;

// N[x] : quantos numeros na tabela sao menores ou iguais a x?
// Quero o primeiro x em que N[x] >= k
// verifica: true <=> N[x] >= k

bool verifica(int d) {
    int cont = 0;
    for (int i = 1; i <=n; i++) cont += min(d/i, m);

    return cont >= k;
}

void solve() {
    cin >> n >> m;
    cin >> k;

    int ini = 1, fim = n*m, mid;
    while(ini < fim) {
        mid = ini + (fim - ini)/2;
        if (verifica(mid)) fim = mid;
        else ini = mid + 1;
    } 

    cout << ini << endl;
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
