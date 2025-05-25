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

int a[212345];
int b[212345];

void solve() {
    int n, k;
    cin >> n >> k;

    int menor =  INF;
    int maior = -1;  

    int s = -1;

    for (int i = 0; i <n; i++) {
        cin >> a[i];
        menor = min(menor, a[i]);
        maior = max(maior, a[i]);
    }

    bool flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if (b[i] != -1) {
            if (s == -1) {
                s = b[i] + a[i]; 
            } else if (s != b[i] + a[i]) {
                if (!flag) {
                    cout << 0 << endl;
                    flag = 1;
                }
            }
        }
    }
    if (flag) return;

    if (s != -1) {
        
        for (int i = 0; i < n; i++) {
            b[i] = s - a[i];
            if (b[i] < 0 or b[i] > k) {
                cout << 0 << endl;
                return;
            }
        }
        cout << 1 << endl;
    } else {
        sort(a, a+n);
        int delta = a[n-1] - a[0];
        cout << k - delta + 1 << endl;
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}