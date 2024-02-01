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
        int k;
        cin >> k;

        string s;
        cin >> s;

        map<char, int> f;

        int contimpar = 0;

        for(char c : s) {
            f[c]++;

            if(f[c]%2)contimpar++;
            else contimpar--;
        }

        if ((n - k)%2 == 0 and k >= contimpar) {
            cout << "YES" << endl;
        } else if ((n-k)%2 == 1 and k+1 >= contimpar) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
