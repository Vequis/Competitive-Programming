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

    void brute (int n) {
        for (int i = 1; i <= n; i++) {
            for (int j = i+1; j <=n; j++) {
                for (int k = j+1; k <= n; k++) {
                    if (j%3 == 0 or i%3 == 0 or k%3 == 0 or i == j or i == k or j == k) continue;

                    if (i + j + k == n) {
                        cout << "YES" << endl;
                        cout <<  i << ' ' << j << ' ' << k << endl;
                        return;
                    }
                }
            }
        }

        cout << "NO" << endl;
    }

    void solve() {
        int n;
        cin >> n;
        if (n < 12) {
            brute(n);
        } else {
            int a = 1, b = 4, c = 7;
            c += (n - 12 - n%3);
            a += (n%3 > 0);
            b += (n%3 == 2);
            cout << "YES" << endl;
            cout << a << ' ' << b << ' ' << c << endl;
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