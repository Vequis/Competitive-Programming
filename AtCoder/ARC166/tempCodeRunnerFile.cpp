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
#define INF 1000000000000000009
#define INFF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int v[212345];
int ra[212345];
int rb[212345];
int rc[212345];

int mdc(int a, int b) {
    if (a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    int resp = a/mdc(a, b);
    resp *= b;
    return resp;
}

int mina, minb, minc, minab, minbc, minac, minabc;
signed main(){_

    // cout << INFF << endl;
    int n;
    cin >> n;

    int a, b, c;
    cin >> a >> b >> c;

    for(int i = 1; i <=n; i++) {
        cin >> v[i];
        ra[i] = (a - v[i]%a);
        rb[i] = (b - v[i]%b);
        rc[i] = (c - v[i]%c);
    }

    mina = INF;
    minb = INF;
    minc = INF;
    minab = INF;
    minbc = INF;
    minac = INF;
    minabc = INF;

    int ab = mmc(a, b);
    int ac = mmc(a, c);
    int bc = mmc(b, c);
    int abc = mmc(ab, c);

    vii va, vb, vc;
    vii vab, vac, vbc;
    vii vabc;

    for(int i = 1; i <= n; i++) {
        va.eb(ra[i], i);
        vb.eb(rb[i], i);
        vc.eb(rc[i], i);
        vab.eb((ab - v[i]%ab), i);
        vac.eb((ac - v[i]%ac), i);
        vbc.eb((bc - v[i]%bc), i);
        vabc.eb((abc - v[i]%abc), i);
    }

    sort(all(va));
    sort(all(vb));
    sort(all(vc));
    sort(all(vab));
    sort(all(vac));
    sort(all(vbc));
    sort(all(vabc));

    // resp

    int resp = INF;
    resp = min(resp, mina + minb + minc);
    int casosa[] = {0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 2, 2, 1};
    int casosb[] = {0, 1, 0, 0, 1, 1, 0, 1, 2, 2, 1, 0, 0};
    int casosc[] = {0, 0, 0, 1, 1, 0, 1, 2, 1, 0, 0, 1, 2};

    for(int i = 0; i < 13; i++) {
        if (va[casosa[i]].sc == vb[casosb[i]].sc or va[casosa[i]].sc == vc[casosc[i]].sc or vc[casosc[i]].sc == vb[casosb[i]].sc) continue;
        if (casosa[i] >= n or casosb[i] >= n or casosc[i] >= n) continue;
        resp = min(resp, va[casosa[i]].fs + vb[casosb[i]].fs + vb[casosb[i]].fs);
    }

    if (va[0].sc == vbc[0].sc) {
        if (n > 1) {
            resp = min(resp, va[0].fs + vbc[1].fs);
            resp = min(resp, va[1].fs + vbc[0].fs);
        }
    } else {
        resp = min(resp, va[0].fs + vbc[0].fs);
    }

    if (vc[0].sc == vbc[0].sc) {
        if (n > 1) {
            resp = min(resp, vc[0].fs + vab[1].fs);
            resp = min(resp, vc[1].fs + vab[0].fs);
        }
    } else {
        resp = min(resp, vc[0].fs + vbc[0].fs);
    }

    if (vb[0].sc == vac[0].sc) {
        if (n > 1) {
            resp = min(resp, vb[0].fs + vac[1].fs);
            resp = min(resp, vb[1].fs + vac[0].fs);
        }
    } else {
        resp = min(resp, vb[0].fs + vac[0].fs);
    }

    resp = min(resp, vabc[0].fs);

    // resp = vabc[0].fs;
    cout << resp << endl;

    return 0;
}
