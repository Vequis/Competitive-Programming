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
int n;
void solve() {
    int resp = 0;

    int a[11234];
    int soma = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        soma += a[i];
    }

    if (soma % n) {
        cout << -1 << endl;
        return;
    }

    int nec = soma/n;


    for (int i = 1; i <=n; i++) {
        resp += abs(a[i] - nec);
    }

    resp = resp/2;
    resp++;
    cout << resp << endl;


}

signed main(){
    int t;
    // cin >> t;
    // t=1;

    while(cin >> n) {
        solve();
    }

    return 0;
}