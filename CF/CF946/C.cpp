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

void solve() {
    int n;
    cin >> n;

    map<ii, map<int, int> > mpa;
    map<ii, map<int, int> > mpb;
    map<ii, map<int, int> > mpc;

    int a, b;
    cin >> a >> b;

    for (int i = 2; i < n; i++) {
        int c;
        cin >> c;

        mpa[{a, b}][c]++;
        mpb[{b, c}][a]++;
        mpc[{a, c}][b]++;
        a = b;
        b = c;
    }   

    int resp = 0;
    int cont;
    cont = 0;
    for (auto p : mpa) {
        cont += p.sc.size();
    }
    cont = 0;
    for (auto p : mpa) {
        resp += (cont - p.sc.size()) * p.sc.size();
    }

    cont = 0;
    for (auto p : mpb) {
        cont += p.sc.size();
    }
    cont = 0;
    for (auto p : mpb) {
        resp += (cont - p.sc.size()) * p.sc.size();
    }

        cont = 0;
    for (auto p : mpc) {
        cont += p.sc.size();
    }
    cont = 0;
    for (auto p : mpc) {
        resp += (cont - p.sc.size()) * p.sc.size();
    }


    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}