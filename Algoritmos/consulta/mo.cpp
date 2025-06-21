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
#define INFLL 0x3f3f3f3f3f3f3f3
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

#define maxn 212345
// int s = ceil(sqrt(maxn));
const int block_len = 461;
// Each block goes from 0 to s-1
// Exactly s blocks.
// Block b[i] starts in s*i and goes to s*(i+1) - 1

// Element i belongs to block i/s

// EXAMPLE Problems: SUM, MAX,
// in SUM: Updates in O(1).
// finding the number of zero elements, finding the first non-zero element, 
// counting elements which satisfy a certain property etc.

// Useful for UPDATES ON INTERVALS
// Add for tails a[i] and for blocks b[i/s]
// Update in O(sqrtN) - Query in O(1)

// SET with K-TH greatest number
// Each update swaps ends and beginnings of each block

int a[maxn];
int b[block_len];

int op(int l, int r) {

    int resp = 0;
    while(l % block_len != 0 and l <= r) {
        resp += a[l];
        l++;
    }

    if (l > r) return resp;
    else if (l + block_len <= r) resp + b[l/block_len] + op(l + block_len, r);
    return resp;
}

void solve() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    
        b[i/block_len] += a[i];
    }

    while(q--) {
        int oper, p, c;
        cin >> oper >> p >> c;

        if (oper == 1) {
            b[p/block_len] += c - a[p];
            a[p] = c;
        } else {
            cout << op(p-1, c-1) << endl;
        }
    }

}

signed main(){_
    
    solve();

    return 0;
}