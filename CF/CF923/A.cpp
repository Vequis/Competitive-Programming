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
        int n;
        cin >> n;

        string s;
        cin >> s;

        int resp = 0;

        int comecou =  0;
        int first = -1;
        int last = -1;
        for(int i = 0; i < sz(s); i++) {
            if (first == -1 and s[i] == 'B') first = i;
            if (s[i] == 'B') last = i; 
        }


        if (last != -1) {
            cout  << last - first + 1 << endl;

        } 
    }

    return 0;
}
