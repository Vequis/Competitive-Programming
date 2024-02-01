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

    string s;
    cin >> s;

    int resp = 0;

    for(int i = 0; i < sz(s); i++) {
        int ini = i - 1;
        int fim = i + 1;

        int cur = 1;

        while(ini >= 0 and fim < sz(s) and s[ini] == s[fim]) {
            cur+=2;
            ini--;
            fim++;
        }

        resp = max(resp, cur);
    }

    for(int i = 1; i < sz(s); i++) {
        int ini = i - 1;
        int fim = i;

        int cur = 0;

        while(ini >= 0 and fim < sz(s) and s[ini] == s[fim]) {
            cur+=2;
            ini--;
            fim++;
        }

        resp = max(resp, cur);
    }

    cout << resp << endl;

    return 0;
}
