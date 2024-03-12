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
int n, k;

bool verifica(int d) {
    int soma = 0;
    for (int i = 0; i < n; i++) soma += (d/v[i]);
    return (soma>=k);
}

void solve() {
    cin >> n >> k;
    v.clear();
    v = vi(n);
    int s = 0;
    for(int i =0 ; i < n; i++) {
        cin >> v[i];
        s+=v[i];
    }

    //Era um erro com o upper+bound que eu estava usando
    int ini = 1, fim = 1112233445566778899/n, mid;
    while(ini < fim) {
        mid = ini + (fim - ini)/2;
        if (verifica(mid)) fim = mid;
        else ini = mid + 1;
        //cout << mid << ' ' << verifica(mid) << endl;
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
