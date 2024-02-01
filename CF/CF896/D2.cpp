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

int find(int x) {
    int resp = 1;

    while(resp <= x) {
        resp = (resp << 1);
    }

    return resp;
}

bool verifica(int y) {
    int ainda0 = 1;

    while(y > 0) {
        if ((y&1)) ainda0 = 0;
        else {
            if (ainda0 == 0) return false;
        }

        y = (y>>1);
    }

    return 1;
}

signed main(){_

    // cout << verifica(8) << endl;
    // cout << verifica(7) << endl;
    // cout << verifica(6) << endl;
    // cout << verifica(4) << endl;
    // cout << 5 << ' ' << verifica(5) << endl;

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vi v(n+1);

        int media = 0;
        for(int i = 1; i <=n; i++) {
            cin >> v[i];
            media+=v[i];
        }

        if (media%n) {
            cout << "No" << endl;
            continue;
        }

        media/=n;

        multiset<int> in;
        multiset<int> out;

        int cont0 = 0;

        bool deuruim = 0;

        vi pots;

        for(int i = 1; i <=n; i++) {
            int sobra = media - v[i];

            int x = find(abs(sobra));
            int y = x - abs(sobra);
            // cout << x << ' ' << y << endl;
            if (!verifica(sobra)) {
                deuruim = 1;
            }

            if(__builtin_popcountll((abs(sobra))) == 1) pots.pb(sobra);

            if (sobra < 0) {
                if (out.find(x - abs(sobra)) != out.end()) {
                    out.erase(out.find(x-abs(sobra)));
                } else {
                    in.insert(x - abs(sobra));
                }

                if (in.find(x) != in.end()) {
                    in.erase(in.find(x));
                } else {
                    out.insert(x);
                }
            } else if (sobra > 0) {
                if (in.find(x - abs(sobra)) != in.end()) {
                    in.erase(in.find(x-abs(sobra)));
                } else {
                    out.insert(x - abs(sobra));
                }

                if (out.find(x) != out.end()) {
                    out.erase(out.find(x));
                } else {
                    in.insert(x);
                }

            } else {
                cont0++;
            }
        }

        if(deuruim) {
            cout << "No" << endl;
            continue;
        }

        int flag = 1;
        int used[212345];

        for(int i = 0; i <=n; i++) used[i] = 0;

        if (sz(in) == 0 and sz(out) == 0) flag = 1;
        else {
            int mudou = 1;

            while(mudou) {
                mudou = 0;
                int i = -1;
                for(int sob : pots) {
                    // cout << "sobra: " << sob << endl;
                    i++;
                    if (sz(in) == 0 and sz(out) == 0) continue;
                    // if(used[i]) cout << '*' << sob << ' ' << i << endl;
                    if(used[i]) continue;

                    if (sob < 0) {
                        if (out.find(2*abs(sob)) != out.end() and in.find(abs(sob)) != in.end()){ 
                            out.erase(out.find(2*abs(sob)));
                            in.erase(in.find(abs(sob)));

                            int x = abs(sob);
                            if (in.find(x) != in.end()) {
                                in.erase(in.find(x));
                            } else {
                                out.insert(x);
                            }
                            mudou = 1;
                            used[i] = 1;
                        }
                    } else {
                        if (in.find(2*abs(sob)) != in.end() and out.find(abs(sob)) != out.end()){ 
                            used[i] = 1;
                            mudou = 1;
                            // cout << sob << endl;
                            in.erase(in.find(2*abs(sob)));
                            out.erase(out.find(abs(sob)));

                            int x = abs(sob);
                            if (out.find(x) != out.end()) {
                                out.erase(out.find(x));
                            } else {
                                in.insert(x);
                            }
                        }
                    }

                }
            }

                // for (int x : in) cout << x << ' ';
                // cout << endl;
                // for (int x : out) cout << x << ' ';
                // cout << endl;
        }



        if (sz(in) == 0 and sz(out) == 0) flag = 1;
        else flag = 0;

        if(flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

        in.clear();
        out.clear();
        pots.clear();
    }

    return 0;
}
