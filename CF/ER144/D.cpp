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

int v[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, k, x;
        cin >> n;
        cin >> k >> x;
    
        int resp = 0;

        if (x < 0) {
            x = -x;
            k = (n - k);
        }

        for(int i = 1; i <= n; i++) {
            cin >> v[i];
        }

        for(int window = 1; window <=min(n, k); window++) {
            int acresc = window*x;

            int soma = 0;
            for(int i = 1; i <= window; i++) {
                soma += v[i];
            }

            resp = max(resp, soma + acresc);

            for(int i = window + 1; i <=n; i++) {
                soma -= v[i - window];
                soma += v[i];
                resp = max(resp, soma + acresc);
            }
        }

        for (int window = k + 1; window <= n; window++) {
            int acresc = x*k - x*(window - k);

            int soma = 0;
            for(int i = 1; i <= window; i++) {
                soma += v[i];
            }

            resp = max(resp, soma + acresc);

            for(int i = window + 1; i <=n; i++) {
                soma -= v[i - window];
                soma += v[i];
                resp = max(resp, soma + acresc);
            }
        }   

        cout << resp << endl;
    }



    return 0;
}
