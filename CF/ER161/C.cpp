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

int a[1123456];

int prox[112345];
int asc[112345]; //tempo para o 1 chegar até i;
int desc[112345]; //tempo de n chegar até i

void solve() {

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    prox[1] = 2;
    prox[n] = n-1;

    for(int i = 2; i < n; i++) {
        if (a[i+1] - a[i] < a[i] - a[i-1]) prox[i] = i+1;
        else prox[i] = i-1;
    }

    asc[1] = 0;
    for(int i = 2; i<=n; i++) {
        asc[i] = asc[i-1];
        if (prox[i-1] == i) asc[i]++;
        else asc[i] += a[i] - a[i-1];
    }

    desc[n] = 0;
    for(int i = n-1; i>=1; i--) {
        desc[i] = desc[i+1];
        if (prox[i+1] == i) desc[i]++;
        else desc[i] += a[i+1] - a[i];
    }

    int m;
    cin >> m;

    while(m--) {
        int x, y;
        cin >> x >> y;

        if (x < y) {
            cout << asc[y] - asc[x] << endl;
        } else {
            cout << desc[y] - desc[x] << endl;            
        }
    }
}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
