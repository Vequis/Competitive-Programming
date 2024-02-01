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

map<int, int> f;
map<int, int> f1;
map<int, int> f2;
int a[212345];
int fat[212345];
int resp[212345];

int soma (int a, int b) {
    return (a+b)%MODN;
}

int mult(int a, int b) {
    return (a*b)%MODN;
}

int binexpo(int n, int exp) {
    int resp = 1;
    int pot = n;

    int aux = exp;
    while(aux >= 1) {
        if (aux%2) resp= mult(resp, pot);
        pot = mult(pot, pot);
        aux/=2;
    }

    return resp;
}

int invmod(int x) {
    return binexpo(x, MODN-2);
}

int c(int n, int p) {
    if (p < 0) return 0;
    if (p==0) return 1;
    int resp = 1;
    // cout << 'c' << ' ' << n << ' ' << p << endl;
    resp = mult(fat[n], resp);
    // cout << fat[n] << endl;
    resp = mult(invmod(fat[n-p]), resp);
    // cout << invmod(fat[n-p]) << endl;
    resp = mult(invmod(fat[p]), resp);
    // cout << invmod(fat[p]) << endl;

    // cout <<"resp" << resp << endl;

    return resp;
}

signed main(){_

    int n;
    cin >> n;

    fat[1] = 1;
    fat[0] = 1;
    for(int i = 2; i <= 212343; i++) fat[i] = mult(fat[i-1], i);

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        f[a[i]]++;
    }

    int valini = 1;
    for(ii p : f) {
        int x = p.sc;
        int ant = c(x, x/2);
        if (x % 2 == 1) ant = soma(ant, c(x, x/2 + 1));

        cout << p.fs << ' ' << p.sc <<  ' ' << valini << ' ' << ant << endl;

        valini = mult(valini, ant);
    }

    int cur = valini;
    cout << valini << endl;
    for(int i = 1; i <= n;  i++) { // posição do primeiro blue
        resp[i] = 0;
        if (i != 1) f2[a[i-1]]++;
        if (a[i] > a[1]) continue;
        
        resp[i] = soma(resp[i], cur);
        f1[a[i]]++;

        int ant = c(f[a[i]]-f1[a[i]], f[a[i]]/2 - f2[a[i]]);
        if (f[a[i]] % 2 == 1) ant += soma(ant, c(f[a[i]]-f1[a[i]], f[a[i]]/2 + 1 - f2[a[i]]));

        f2[a[i]]++;
        if (f1[a[i]] >= ((f[a[i]] + 1) / 2) + 1) break;
        int att = c(f[a[i]]-f1[a[i]], f[a[i]]/2 - f2[a[i]]);
        if (f[a[i]] % 2 == 1) att = soma(att, c(f[a[i]]-f1[a[i]], f[a[i]]/2 + 1 - f2[a[i]]));

        cur = mult(invmod(ant), cur);
        cur = mult(att, cur);

        cout << i << ' ' << cur << endl;

        // int curi = cur;
        // for(int j = i+1; j<=n; j++) {
        //     resp[i] = soma(resp[i], curi);

        //     int ant = c(f[a[j]-f1[a[j]], f[a[j]]/2 - f2[a[j]]);
        //     if (f[a[j]] % 2 == 1) ant += soma(ant, c(f[a[j]-f1[a[j]], f[a[j]]/2 + 1 - f2[a[j]]));

        //     f1[a[j]]++;
        //     if (f1[a[j]] >= ((f[a[j]] + 1) / 2) + 1) break;
        //     int att = c(f[a[j]-f1[a[j]], f[a[j]]/2 - f2[a[j]]);
        //     if (f[a[j]] % 2 == 1) att = soma(att, c(f[a[j]-f1[a[j]], f[a[j]]/2 + 1 - f2[a[j]]));

        //     curi = mult(invmod(ant), curi);
        //     curi = mult(att, curi);
        // }

    }


    //itera pra ver se tem outro f_blue

    return 0;
}
