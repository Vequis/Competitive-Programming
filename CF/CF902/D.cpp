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

int a[112345];
int maximokth[112345];

int soma (int a, int b) {
    return (a+b)%MODN;
}

int mult(int a, int b) {
    return (a*b)%MODN;
}

int binexpo(int n, int exp) {   
    int resp = 1;
    int pot = n;

    while(exp > 1) {
        if (exp%2) resp= mult(resp, pot);
        pot = mult(pot, pot);
        exp/=2;
    }

    return resp;
}

bool cmp(int a, int b) {
    return a > b;
}

signed main(){_

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vi v;

    for(int i = 1; i <= n; i++) {
        maximokth[i] = -1;
        for(int j = i; j<=n; j+=i) {
            maximokth[i] = max(maximokth[i], a[j]);
            
        }

        v.pb(maximokth[i]);
    }

    sort(all(v), cmp);

    // int pot = binexpo(2, n-1);


    int resp = 0;
    int pot = 1;
    for(int i = n-1; i >= 0; i--) {
        resp = soma(resp, pot*v[i]);
        pot = mult(pot, 2);
    }

    cout << resp << endl;

    return 0;
}
