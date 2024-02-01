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
int visitados[1123456];

void crivo(int n){
    primos.pb(2);
    for(int i=3; i<=n; i+=2){
        if(!visitados[i]){
            primos.pb(i);
            for(int j=i*i; j<=n; j+=i) visitados[i] = 1;
        }
    }
}


signed main(){_

    int t;
    cin >> t;

    crivo(1123);

    while(t--) {
        int n;
        cin >> n;

        int mult = 1;

        map<int, int> f;
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;

            for(int i = 0; i < sz(primos); i++) {
                while(a%primos[i] == 0) {
                    f[primos[i]]++;
                    a/=primos[i];
                }

                if (a==1) break;
            }

            if (a > 1) f[a]++;
        }

        int resp = 1;

        for (ii p : f) {
            // cout << p.fs << ' ' << p.sc << endl;
            if (p.sc % n) resp = 0;
        }

        if (!resp) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }

    return 0;
}
