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

map<int, int> f1;
map<int, int> f2;
int v[1123];

signed main(){_

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) cin >> v[i];

    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            for(int c = 0; c < n; c++) {
                f1[v[a]*v[b] + v[c]]++;
            }
        }
    }

    
    for(int a = 0; a < n; a++) {
        for(int b = 0; b < n; b++) {
            for(int c = 0; c < n; c++) {
                if (v[a] == 0) continue;
                f2[v[a]*v[b] + v[a]*v[c]]++;
            }
        }
    }

    int resp = 0;
    for(ii p : f1) {
        // cout << p.fs << ' ' << p.sc << ' ' << f2[p.fs] << endl;
        resp += p.sc*f2[p.fs];
    }

    cout << resp << endl;

    return 0;
}
