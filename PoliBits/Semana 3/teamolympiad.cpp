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

vi prog;
vi math;
vi pe;

signed main(){_

    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (a == 1) {
            prog.pb(i + 1);
        } else if (a==2) {
            math.pb(i + 1);

        } else {
            pe.pb(i + 1);
        }
    }

    int k = min(sz(prog), min(sz(math), sz(pe)));
    cout << k << endl;

    for(int i = 0; i < k; i++) {
        cout << prog[i] << ' ' << math[i] << ' ' << pe[i] << endl;
    }

    return 0;
}
