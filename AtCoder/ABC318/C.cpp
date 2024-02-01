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

signed main(){_

    int n, d, p;

    cin >> n >> d >> p;

    multiset<int> s;

    int somaatual = 0;

    int resp = 0;

    for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            s.insert(a);

            resp += a;

            if (s.size() > d) {
                if (s.find(a) != s.begin()) somaatual += a;
                somaatual -= *(s.begin());
                s.erase(s.begin());

            } else {
                somaatual += a;
            }

            // cout << somaatual << ' ' << s.size() << endl;
            if (somaatual >= p) {
                while(!s.empty()) s.erase(s.begin());
                resp -= somaatual;
                somaatual = 0;
                resp += p;
            }

    }

    cout << resp << endl;


    return 0;
}
