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

vi primos;
int visitados[11234567];
int psaprimos[412345];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[j] = 1;
        }
    }
}

// Lembrar do caso
// N = 1
// 1
vi psa;

void solve() {
    int n;
    cin >> n;

    vi v(n);
    for (int i = 0; i <n; i++) {
        cin >> v[i];
    }   

    sort(all(v), greater<>());

    psa = vi(n);
    psa[0] = v[0];
    for(int i =1; i<n; i++) {
        psa[i] = psa[i-1] + v[i];
    }

    int maioresp = -1;

    for (int i = 0; i < n; i++) {
        if (psa[i] >= psaprimos[i]) maioresp = i;
    }

    cout << n - maioresp - 1 << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    crivo(11234560);
    // cout << sz(primos) << endl;
    psaprimos[0] = 2;
    for (int i = 1; i < 412340; i++) psaprimos[i] = psaprimos[i-1] + primos[i];

    while(t--) {
        solve();
    }

    return 0;
}