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
    #define MODN 998244353
    #define int long long // -> solução divina

    using namespace std;

    int a[212345];

    void solve() {
        int n;
        cin >> n;

        for (int i = 1; i <=n; i++) {
            cin >> a[i];
            // a[i] = a[i]%MODN;
        }   

        int resp = 0;
        int soma = 0;
        for (int i = n; i >=1; i--) {
            resp = (resp + (i-1)*a[i] + soma*a[i])%MODN;

            int pot = 1;
            int it = a[i];
            while(it > 0) {
                pot*=10;
                it/=10;
            }
            soma = (soma+pot)%MODN;
        }

        cout << resp << endl;
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