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
// #define int long long // -> solução divina

using namespace std;

signed main(){_

    int n, k;
    cin >> n >> k;

    multiset<int> ms;
    multiset<int>::iterator it;

    int dif = 0;

    vector<int> v[100005];

    for (int i = 1; i <=n; i++) {
        cin >> v[i];
    }

    int ini = 0;
    int fim = 0;

    int resp = 0;

    while(ini < n) {
        if(dif <= k and fim < n) {
            fim++;
            it = ms.find(v[fim]);
            if (it == ms.end()) {
                dif++;
            }
            if(dif == k) resp++;
            ms.insert(v[fim]);
        } else {
            ini++;
            it = ms.find(v[ini]);
            ms.erase(it);
            it = ms.find(v[ini]);
            if (it == ms.end()) dif--;
            if(dif == k) resp++;
        }
        cout << ini << ' ' << fim << ' ' << resp << endl;
    }

    cout << resp << endl;

    return 0;
}
