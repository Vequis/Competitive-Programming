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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int ini = 0;
        int fim = sz(s) - 1;

        int dif = 0;
        while(ini < fim) {
            if (s[ini] != s[fim]) dif++;
            ini++;
            fim--;
        }

        string resp = "";
        if (n%2) {
            for(int i = 0; i < dif; i++) resp = resp + '0';
            for(int i = dif; i < sz(s) - dif + 1; i++) resp = resp + '1';
            for(int i = 0; i < dif; i++) resp = resp + '0';
            cout << resp << endl;
        } else {
            int itr = 1;
            for(int i = 0; i < dif; i++) resp = resp + '0';
            for(int i = dif; i < sz(s) - dif + 1; i++) { 
                resp = resp + (char)('0' + itr);
                itr ^=1;
            }
            for(int i = 0; i < dif; i++) resp = resp + '0';
            cout << resp << endl;
        }
    }

    return 0;
}
