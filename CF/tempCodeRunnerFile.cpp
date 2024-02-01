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

    while(t--) {
        string s;
        cin >> s;

        int waiting = -1;
        for(int i = 0; i < sz(s) ; i++) {
            if (s[i] - '0' < 3) {
                waiting = -1;
            } else if (s[i] == '4') {
                if (waiting == -1) waiting = i;
            } else {
                if(waiting != -1) {
                    for(int j = waiting; j < sz(s); j++) s[j] = '0';
                    if (waiting > 0) s[waiting - 1] = (char)((int)s[waiting-1] + 1);
                    else s = '1' + s;
                    break;
                } else {
                    for(int j = i; j < sz(s); j++) s[j] = '0';
                    if (i > 0) s[i - 1] = (char)((int)s[i-1] + 1);
                    else s = '1' + s;
                    break;
                }
            }
        }

        cout << s << endl;
    }

    return 0;
}
