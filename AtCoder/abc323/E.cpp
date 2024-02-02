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
#define int long long

using namespace std;

ii memo[11234];

pair<int, int> p(int t) { //{soma, pd}
    if (t < 0) return {0, 0};
    if (t == 0) return {1, 0};

    return memo[t];
}

int sum(int a, int b) {
    return (a+b)%MODN;
}

int mult(int a, int b) {
    return (a*b)%MODN;
}

int expo(int a, int exp) {
    int resp = 1;
    int pot = a;

    int aux = exp;
    while(aux > 0) {
        if (aux%2) resp=mult(pot, resp);

        pot = mult(pot, pot);
        aux/=2;
    }

    return resp;
}

int t[11234];



signed main(){_

    int n, x;

    cin >> n >> x;
    for(int i = 0; i < n; i++) {
        cin >> t[i+1];
    }

    // cout << expo(2, 1123) << endl;

    for(int i = 1; i <= x; i++) {
        int maxpd = -1;

        for(int j = 1; j <=n; j++) maxpd = max(maxpd, p(i-t[j]).sc);

        int soma = 0;
        for(int j = 1; j <=n; j++) soma = sum(soma, mult(p(i-t[j]).fs, expo(n,maxpd - p(i-t[j]).sc)));

        memo[i] = {soma, maxpd+1};

        // cout << i << endl;
        // cout << soma << ' ' << expo(n, maxpd+1) << endl;
    }

    int maxpd = -1;

    for(int j = 0; j <= t[1] - 1; j++) maxpd = max(maxpd, p(x - j).sc);

    int soma = 0;
    for(int j = 0; j <= t[1] - 1; j++) soma = sum(soma, mult(p(x - j).fs, expo(n,maxpd - p(x - j).sc)));

    // cout << 'f' << endl;

    int y = soma;
    int xis = expo(n, maxpd + 1);
    // cout << y << ' ' << xis << endl;

    // cout << 'r' << endl;
    // cout << expo(xis, MODN-2) << endl;
    cout << mult(y, expo(xis, MODN-2));

    return 0;
}
