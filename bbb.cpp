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
#define int long long

using namespace std;

int pai[112345];

int find(int node) {
    if (pai[node] == -1) return node;
    return pai[node] = find(pai[node]);
}

signed main(){_

    int n, k;
    cin >> n >> k;

    for(int i = 1; i <= n; i++) {
        pai[i] = -1;
    }

    while(k--) {
        char op;
        int a, b;

        cin >> op >> a >> b;

        if (op == 'C') {
            if (find(a) == find(b)) {
                cout << 'S' << endl;
            } else {
                cout << 'N' << endl;
            }
        } else {
            a = find(a);
            b = find(b);

            pai[a] = b;
        }
    }

    return 0;
}
