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

    int t;
    cin >> t;

    multiset<int> left;
    multiset<int> right;
    while(t--) {
        char c;
        cin >> c;
        int a, b;
        cin >> a >> b;
        

        if (c == '+') {
            left.insert(a);
            right.insert(b);
        } else {
            left.erase(left.find(a));
            right.erase(right.find(b));
        }

        if (!right.empty()) {
            int r = *right.begin();
            int l = *left.rbegin();

            if (r < l) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
