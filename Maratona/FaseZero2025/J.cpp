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
    int n, k;
    cin >> n >> k;

    vi v(n);
    vi resp(n);

    stack<ii> pilha;
    for (int i = 0; i < n; i++) cin >> v[i];


    int ptr = 0;
    pilha.push({v[0], 0});


    while(ptr < n or !pilha.empty()) {
        ptr++;

        if (!pilha.empty()) {
            ii topo = pilha.top();
            while (v[ptr%n] - k * ptr < topo.fs) {
                pilha.pop();
                resp[topo.sc] = ptr%n + 1;
                if (pilha.empty()) break;
                topo = pilha.top();
            }
        }

        if (ptr < n) pilha.push({v[ptr] - k*ptr, ptr});
    }

    for (int i = 0; i < n; i++) {
        cout << resp[i] << ' ';
    }
    cout << endl;

}

signed main(){
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}