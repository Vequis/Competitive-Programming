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

int mult(int a, int b) {
    return (a*b)%MODN;
}

int soma(int a, int b) {
    return (a+b)%MODN;
}

int subt(int a, int b) {
    return (a - b + MODN) % MODN;
}


void solve() {
    int W, G, L;
    cin >> W >> G >> L;

    int resp = mult(subt(W, G), soma(mult(2, L), 1));

    cout << resp << endl;
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    int cont = 1;
    while(cont <= t) {
        cout << "Case #" << cont << ": ";
        solve();
        cont++;
    }

    return 0;
}