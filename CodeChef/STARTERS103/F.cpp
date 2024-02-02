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
#define int long long

using namespace std;

int vetor[1001001];
vector<int> primos;

void crivo(int n) {
    for (int i=2; i<=n; i++){
        if (vetor[i] == 0){
            primos.push_back(i);
            int limite = floor(n/i);
            for (int j=i*i; j<=limite*i; j+=i) vetor[j] = 1;
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

        map<int, int> f;

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;

            for(int j = 0; j < sz(primos); j++) {
                while(a >= primos[j]*primos[j] and a % (primos[j]*primos[j]) == 0) {
                    // cout << a << ' ' << primos[j]*primos[j] << ' ' << a % primos[j]*primos[j] << endl;
                    a /= primos[j]*primos[j];
                    // cout << primos[j] << endl;
                }
                if (a==1) break;
            }
            // cout << a << endl;
            if (a != 1) f[a]++;
        }

        int resp = 0;
        for(ii p : f) {
            resp = max(resp, p.sc);
        }

        cout << resp << endl;
    }

    return 0;
}
