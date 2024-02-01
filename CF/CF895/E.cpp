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


int n, a[112345], tree[4*112345];

void build(int node, int left, int right){
    if (left>right) return;
    if (left==right){
        tree[node] = a[left];
        return;
    }   

    int mid = left + (right-left)/2;
    build(2*node, left, mid);
    build(2*node + 1, mid+1, right);
    tree[node] = tree[2*node] ^ tree[2*node+1];
    return;
}

int sum(int node, int left, int right, int l, int r){
    if (l > r) return 0;
    if (l==left and r == right) return tree[node];
    int mid = left + (right-left)/2;
    return sum(2*node, left, mid, l, min(r, mid)) ^ sum(2*node+1, mid+1, right, max(l, mid+1), r);
}


signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];

        string s;
        cin >> s;

        int init0 = 0;
        int init1 = 0;
        for(int i = 0; i < sz(s); i++) {
            if(s[i]=='0') init0 ^= a[i];
            else init1 ^= a[i];
        }

        int q;
        cin >> q;
        int var = 0;

        build(1, 0, n-1);
        while(q--) {
            int op;
            cin >> op;

            if (op == 1) {
                int l, r;
                cin >> l >> r;

                var^= sum(1, 0, n-1, l-1, r-1);

                // cout << var << endl;
            } else {
                int g;
                cin >> g;

                int resp = var;
                if (g==0) resp^=init0;
                else resp^=init1;

                cout << resp << ' ';
            }
        }

        cout << endl;
    }

    return 0;
}
