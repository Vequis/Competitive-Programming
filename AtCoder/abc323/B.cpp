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
#define int long long

using namespace std;

bool cmp(ii a, ii b) {
    if (a.fs != b.fs) return a.fs > b.fs;
    return a.sc < b.sc;
}

signed main(){_

    int n;
    cin >> n;

    vii resp;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cur = 0;
        for(char c : s) {
            if (c=='o') {
                cur++;
            }
        }

        resp.eb(cur, i);
    }

    sort(all(resp), cmp);

    for(ii p : resp) {
        cout << p.sc + 1 << ' ';
    }
    cout << endl;

    return 0;
}
