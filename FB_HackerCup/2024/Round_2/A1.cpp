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

vi generate_all(int l) {
    vi v;
    for (int i = 1; i + l/2 <= 9 ; i++) {
        int x = 0;
        for (int j = 1+i-1; j<=i-1+l/2;j++) {
            x*=10;
            x+=j;
        }
        x*=10;
        x+=l/2 + 1 + i - 1;

        for (int j = l/2+i-1; j>=1+i-1;j--) {
            x*=10;
            x+=j;
        }
        v.pb(x);
    }
    return v;
}

void solve() {

}

int a[1123], b[1123], m[1123], resp[1123];

signed main(){_
    int t;
    cin >> t;
    // t=1;

    for (int i = 1; i <=t; i++) {
        cin >> a[i] >> b[i] >> m[i];
    }

    for (int l = 1; l<=9; l+=2) {
        vi v = generate_all(l);
        for (int x : v) {
            for (int i = 1; i<=t; i++) {
                if (a[i] <= x and x <= b[i] and x%m[i] == 0) resp[i]++;
            }
        }
    }

    for (int i = 1; i <=t; i++) {
        cout << "Case #" << i << ": " << resp[i] << endl;
    }


    return 0;
}