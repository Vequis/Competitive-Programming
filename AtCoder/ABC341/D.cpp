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

int mdc(int a, int b){
    if (a < b) swap(a, b);
    if (b== 0) return a;
    return mdc(b, a%b);
}

int mmc(int a, int b) {
    return (a*b)/mdc(a, b);
}

int n, m, xi;
int k;

int bb(int x){
    int ini = 0, fim = 1123456789112345679, mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        // cout << mid << endl;
        int p = ((mid%m == 0) xor (mid%n == 0));
        if(mid/n + mid/m - 2*(mid/xi) == x and p) return mid;
        else if (mid/n + mid/m - 2*(mid/xi) >= x) fim = mid - 1;
        else ini = mid + 1;
    }

    return ini;
}

void solve() {
    cin >> n >> m >> k;
    int ki = k;

    int x = mmc(n, m);
    xi = x;
    
    cout << bb(k) << endl;
}

signed main(){_
    int t;  

    // cout << 500000002499999925/100000000 + 500000002499999925/99999999 - 2*(500000002499999925/mmc(100000000, 99999999)) << endl;
    // cout << 500000002499999925/100000000  << endl;
    // cout << 500000002499999925/99999999 << endl;
    // cout << 2*(500000002499999925/mmc(100000000, 99999999)) << endl;

    t=1;
    while(t--) {
        solve();
    }

    return 0;
}
