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

int mark[112345];
vi primos;

void crivo(int n) {
    primos.pb(2);
    for(int i = 3; i<=n; i+=2) {
        if (!mark[i]) {
            primos.pb(i);
            for(int j = i*i; j<=n; j+=i) mark[i] = 1;
        }
    }
}

int numdiv(int n) {
    int resp = 1;
    cout << n << ' ';
    for(int primo : primos) {
        if (n == 1) break;
        int cur = 0;
        while(n%primo == 0) {
            cur++;
            n/=primo;
        }

        resp *= (cur + 1);
    }

    if (n > 1) resp *= 2;

    cout << resp << endl;
    return resp;
}

int mdc(int a, int b) {
    if (a < b ) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

set<int> resp;
void solve() {
    int n, x;
    cin >> n >> x;

    resp.clear();
    if ((n + x)%2 == 1) {
        cout << 0 << endl;
        return;
    }

    for(int i = 1; i*i <= (n - x); i++) {
        //divs : i e n/i
        if (((n - x))%i == 0) {
            if (i %2 == 0) {
                int k = i/2 + 1;
                if (k >= x and k<=n) resp.insert(k);
            }
            if ((n-x)/i%2 == 0) {
                int k = ((n-x)/i)/2 + 1;
                if (k >= x and k<=n) resp.insert(k);
            } 
        }
    }
    // cout << sz(resp) << endl;

    for(int i = 1; i*i <= (n + x - 2); i++) {
        //divs : i e n/i
        if (((n + x - 2))%i == 0) {
            if (i %2 == 0) {
                int k = i/2 + 1;
                if (k >= x and k<=n) resp.insert(k);
            }
            if ((n + x - 2)/i%2 == 0) {
                int k = ((n + x - 2)/i)/2 + 1;
                if (k >= x and k<=n) resp.insert(k);
            } 
        }

        // if ((n + x - 2)%i == 0) cout << i << ' ' << (n-x)/i << endl;
        // if (((n + x - 2))%i == 0 and (i + 1)%2 == 0) resp.insert(i + 1);
        // if (((n + x - 2))%i == 0 and (i + 1)%2 == 0) resp.insert(n/i + 1);
        
    }

    cout << sz(resp) << endl;

    // int resp = numdiv((n - x) / 2) + numdiv((n + x - 2)/2);
    // resp -= numdiv(mdc((n - x) / 2, (n + x - 2)/2));
    // cout << resp << endl;
    return;
}

signed main(){_

    int t;
    cin >> t;

    crivo(112340);

    while(t--) {
        solve();
    }

    return 0;
}
