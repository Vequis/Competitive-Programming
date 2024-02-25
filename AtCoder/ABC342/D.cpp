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
int visitadoscrivo[212345];
void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitadoscrivo[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitadoscrivo[j] = 1;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    map<vi, int> f;

    int resp = 0;
    int contzero = 0;

    for (int i = 0; i < n; i++) {
        vi cur;
        int a;
        cin >> a;
        for (int j = 0; j < sz(primos) and a > 1; j++) {
            int cont = 0;
            while (a%primos[j] == 0) {
                cont++;
                a/=primos[j];
            }
            if (cont % 2 == 1) cur.pb(primos[j]);
            // cout << a << ' ' << primos[j] << ' ' << cont << endl;
        }
        // for(int x : cur) cout << x << ' ';
        // cout << endl;
        if (a!=0) {
            resp += f[cur];
            f[cur]++;
            resp += contzero;
        } else {
            contzero++;
            resp += i;
        }
    }

    cout << resp << endl;
}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    crivo(212340);

    while(t--) {
        solve();
    }

    return 0;
}
