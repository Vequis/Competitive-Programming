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

int mdc(int a, int b) {
    if(a < b) swap(a, b);
    if (b==0) return a;
    return mdc(b, a%b);
}

map<ii, int> f;
signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;


        int ck = 0, cd = 0;
        for(char x : s) {
            if (x == 'K') ck++;
            else cd++;

            int g = mdc(cd, ck);
            // if (cd == 0 or ck == 0) g = 1;
            ii p = make_pair(cd/g, ck/g);
            f[p]++;
            cout << f[p] << ' ';
        }
        cout << endl;

        f.clear();
    }

    return 0;
}
