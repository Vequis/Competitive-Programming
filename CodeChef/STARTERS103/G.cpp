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

int w[312345];
int ngr[312345];
int ngl[312345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> w[i+1];
        }

        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            w[i+1] = max(0LL, a - w[i+1]);
        }

        stack<ii> s;
        s.push({w[1], 1});

        for(int i = 2; i <= n; i++) {
            if (s.empty()) {
                s.push({w[i], i});
                continue;
            }

            while(!s.empty() and s.top().fs < w[i]) {
                ngr[s.top().sc] = i;
                s.pop();
            }

            s.push({w[i], i});
        }

        while(!s.empty()) {
            ngr[s.top().sc] = -1;
            s.pop();
        }


        s.push({w[n], n});

        for(int i = n-1; i >= 1; i--) {
            if (s.empty()) {
                s.push({w[i], i});
                continue;
            }

            while(!s.empty() and s.top().fs < w[i]) {
                ngl[s.top().sc] = i;
                s.pop();
            }

            s.push({w[i], i});
        }

        while(!s.empty()) {
            ngl[s.top().sc] = -1;
            s.pop();
        }

        cout << max(ngr[2], w[2]) << ' ';

        for(int i = 2; i <= n-1; i++) {
            cout << (max(ngr[i+1], w[i+1])) + (max(ngl[i-1], w[i-1])) << ' ';
        }
        if (n > 1) cout << max(ngl[n-1], w[n-1]) << endl;

    }

    return 0;
}
