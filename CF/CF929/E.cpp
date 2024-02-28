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

int a[112345];
int resp[112345];
int psa[112345];
int psas[112345];
int nece[112345];
int sobra[112345];
int c;

int bb(int l, int r) {
    int ini = l+1, fim = r + 1, mid;
    while(ini < fim) {
        mid = ini + (fim - ini)/2;

        // cout << ini << ' ' << mid << ' ' << fim << ' ' << (resp[mid] - resp[l-1] + c*(psa[mid] - psa[l - 1])) << endl;
        if (((psa[mid] - psa[l] + nece[l])) > c) fim = mid;
        else ini = mid + 1;

    }

    return ini;
}

void solve() {
    int n;
    cin >> n;

    psa[0] = 0;
    psas[0] = 0;
    resp[0] = 0;
    sobra[0] = 0;

    for (int i = 1; i <=n; i++) {
        int x;
        cin >> x;
        // resp[i] = resp[i-1] + cur*x - x*(x-1)/2;
        int cur = 0;
        int nec = (x+1)/2;
        cur = nec - sobra[i-1];
        nece[i] = nec;
        psa[i] = psa[i-1] + cur;

        sobra[i] = nec - x;
        a[i] = x;

        // cout << resp[i] << endl;
    }

    int q;
    cin >> q;

    // for (int i = 1; i <=n;  i++) cout << psa[i] << ' ';
    // cout << endl;
    // for (int i = 1; i <=n;  i++) cout << nece[i] << ' ';
    // cout << endl;

    while(q--) {
        int l, u;
        cin >> l >> u;
        c = u;
        int x = bb(l, n);
        cout << x-1 << ' ';
    }

    cout << endl;
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
