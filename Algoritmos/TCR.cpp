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
#define maxn 11234

using namespace std;

int y[maxn];
int r[maxn];
//x congr rn (mod yn)

int mdc(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    return (a/mdc(a,b))*b;
}

int binexpo(int a, int pot, int mod) {
    int resp = 1;
    int pote = a%mod;

    while(pot >= 1) {
        if (pot & 1) resp= (resp*pote)%mod;
        pot = pot>>1;
        // cout << '*' <<  pot << ' ' << resp << ' ' <<pote << endl;
        pote = (pote*pote)%mod;
    }

    return resp%mod;
}

int invmod(int n, int mod) {
    return binexpo(n, mod - 2, mod);
} 

int tcr(int n) {
    int x0 = r[1]%y[1];
    int m = y[1];

    for(int i = 2; i <=n; i++) {
        int rx = x0 % y[i];
        rx = (y[i] + r[i] - rx)%y[i];

        // int k = (rx * invmod(m, y[i])) % y[i]; //O(sum(log(yi)))



        int k = 0;
        //CUIDADO COM O LOOP INFINITO!!!!!!1
        while((x0 + k*m)%y[i]!=r[i]) k++; //O(sum( yi ))

        // cout << rx << ' ' << invmod(m, y[i]) << ' ' << k << endl;

        x0 = (x0 + k*m);
        m = mmc(m, y[i]);
        // cout << x0 << ' ' << m << endl;
    }

    return x0;
}

signed main(){_

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        int re, ye;
        cin >> re >> ye;
        r[i] = re%ye;
        y[i] = ye;
    }

    cout << tcr(n) << endl;

    return 0;
}
