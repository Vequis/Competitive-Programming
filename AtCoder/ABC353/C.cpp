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

int psa[312345];

void solve() {
    int n;
    cin >> n;

    int resp = 0;
    vi v;
    int somaant = 0;

    int soma = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        v.eb(x);
        soma += x;
    }

    v.eb(-1);
    sort(all(v));

    for (int i = 1; i <= n; i++) {
        int ini = 1;
        int fim = n+1;
        int mid;

        while(ini < fim) {
            mid = ini + (fim - ini) / 2;

            if(v[mid] + v[i] >= 100000000) fim = mid;
            else ini = mid + 1;
        }

        if (v[i] >= 50000000) ini++;
        resp += (soma - v[i]) + (n-1)*v[i] - 100000000*(n-ini + 1);
    }   

    cout << resp/2 << endl;
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