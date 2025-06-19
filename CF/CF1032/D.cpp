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

int a[42];
int b[42];

vii ops;

void bubble_sort(int* v, int n, int op) {
    for (int i = 1; i <= n; i++) {
        int ptr = i;
        while(ptr > 1 and v[ptr] < v[ptr-1]) {
            swap(v[ptr], v[ptr-1]);
            ops.eb(op, ptr-1);

            ptr--;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
    }
    
    for (int i = 1; i <=n; i++) {
        cin >> b[i];
    }

    ops.clear();
    bubble_sort(a, n, 1);
    bubble_sort(b, n, 2);

    for (int i = 1; i <=n; i++) {
        if (a[i] > b[i]) {
            ops.eb(3, i);
        }
    }

    cout << sz(ops) << endl;

    for (ii p : ops) {
        cout << p.fs << ' ' << p.sc << endl;
    }

    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << b[i] << ' ';
    // cout << endl;
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