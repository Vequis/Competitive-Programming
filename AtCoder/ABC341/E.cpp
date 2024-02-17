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

set<int> ini;
set<int> fim;

void solve() {

    int n;
    cin >> n;

    int q;
    cin >> q;

    string s;
    cin >> s;

    int ultimoini = 1;
    char last = s[0];
    for(int i = 1; i < n; i++) {
        if (s[i] == last) {
            ini.insert(ultimoini);
            fim.insert(i);
            ultimoini = i + 1; //atual
        }

        last = s[i];
    }
    ini.insert(ultimoini);
    fim.insert(n);

    while(q--) {
        int op, l, r;
        cin >> op >> l >> r;

        // for (int x : ini) cout << x << ' ';
        // cout << endl;
        // for (int x : fim) cout << x << ' ';
        // cout << endl;
        if (op == 1) {
            auto it1 = ini.lower_bound(l);
            if (*it1 != l) {
                it1--;
                int l1 = *it1;
                fim.insert(l-1);
                ini.insert(l);
            } else {
                int l1 = *it1;
                if (l1 != 1) {
                    ini.erase(ini.find(l));
                    fim.erase(fim.find(l-1));
                }
            }

            auto it2 = fim.lower_bound(r);
            if (*it2 != r) {
                int r1 = *it2;
                fim.insert(r);
                ini.insert(r+1);
            } else {
                int r1 = *it2;
                if (r1 != n) {
                    ini.erase(ini.find(r+1));
                    fim.erase(fim.find(r));
                }
            }
        } else {
            auto itf = fim.lower_bound(r);
            if (itf == fim.begin()) {
                cout << "Yes" << endl;
            } else {
                itf--;
                if(*itf >= l) {
                    cout << "No" << endl;
                } else {
                    cout << "Yes" << endl;
                }
            }

        }
    }


}

signed main(){_
    solve();

    return 0;
}
