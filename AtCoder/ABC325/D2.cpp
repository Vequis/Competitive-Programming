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

int t[212345];
int d[212345];
vii times;

ii times2[212345];
ii times3[212345];
int vis[212345];

bool cmp(ii a, ii b) {
    if (a.sc != b.sc) return a.sc < b.sc;
    return a.fs < b.fs;
}

bool cmp2(ii a, ii b) {
    if (a.fs != b.fs) return a.fs < b.fs;
    return a.sc < b.sc;
}

int prox[212345];

signed main(){_

    int n;
    cin >> n;

    // int a = 1e18;
    // int b = 1e18;
    // cout << 1e18 << ' ' << a + b << endl;

    for(int i = 1; i <=n; i++) {
        int a, b;
        cin >> a >> b;
        // times.eb(a, b);
        times2[i-1] = {a, a+b};
        times3[i-1] = {a, b};
    }

    // sort(all(times), cmp);
    sort(times2, times2+n, cmp);
    sort(times3, times3+n, cmp2);

    int minimo = INF;
    int indmin = -1;
    for(int i = n-1; i >=0; i--) {
        prox[i] = indmin;

        if (times2[i].fs < minimo) {
            minimo = times2[i].fs;
            indmin = i;
        }
    }

    int itr = 1;

    int resp = 0;

    for(int i = 0; i < n; i++) {
        // cout << times2[i].fs << ' ' << times2[i].sc << ' ' << itr<< endl;
        if (times2[i].sc >= itr) {
            // cout << "entrou" << endl;

            if (times2[i].fs > itr+1) {
                if (times2[prox[i]].fs <= itr+1) {
                    vis[prox[i]];
                }
            }
            resp++;
            itr = max(times2[i].fs, itr+1);
        }
    }

    // for (ii p : times) {
    //     if (p.fs + p.sc >= itr) {
    //         resp++;
    //         itr = max(p.fs, itr+1);
    //     }
    // }

    cout << resp << endl;


    return 0;
}
