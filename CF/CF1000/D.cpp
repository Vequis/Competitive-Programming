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

int find_kmax(int a, int b) {
    if (a < b) swap(a, b); // a e o maior
    if (a >= 2 and b >= 1) return 1 + find_kmax(a-2, b-1);
    return 0;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int x;

    vi p(a), q(b);
    for (int i = 0; i < a; i++) {
        cin >> p[i];
    }
    for (int i = 0; i < b; i++) cin >> q[i];

    sort(all(p));
    sort(all(q));

    int kmax = find_kmax(a, b);

    stack<int> pilhaa;
    stack<int> pilhab;

    int pta0 = 0;
    int ptafim = a-1;
    int ptb0 = 0;
    int ptbfim = b-1;
    int resp = 0;

    int dispa = ptafim - pta0 + 1;
    int dispb = ptbfim - ptb0 + 1;
    cout << kmax<< endl;
    if (kmax == 0) return;

    for (int k = 1; k <= kmax; k++) {

        int maxa = -1;
        if (dispa >= 2) {
            maxa = p[ptafim] - p[pta0];
        }

        int maxb = -1;
        if (dispb >= 2) {
            maxb = q[ptbfim] - q[ptb0];
        }
        //cout << '*' << ' ' << maxa << ' ' << maxb << ' ' << '&' << ' ';

        if (maxa > maxb) {
            pta0++;
            ptafim--;
            pilhaa.push(maxa);
            //resp += maxa;
            dispa -= 2;

            if (dispb== 0) {
                int topo = pilhab.top();
                pilhab.pop();

                int novoa = p[ptafim] - p[pta0];
                ptafim--;
                pta0++;
                dispa-=1;
                pilhaa.push(novoa);

                resp += novoa+maxa - topo;
            } else {
                dispb--;
                resp += maxa;
            }
        } else {
            ptb0++;
            ptbfim--;
            pilhab.push(maxb);
            //resp += maxa;
            dispb -= 2;

            if (dispa== 0) {
                int topo = pilhaa.top();
                pilhaa.pop();

                int novob = q[ptbfim] - q[ptb0];
                ptbfim--;
                ptb0++;
                dispb-=1;
                pilhab.push(novob);

                resp += novob+maxb - topo;
            } else {
                dispa--;
                resp += maxb;
            }
        }

        if (k<=kmax) {
            cout << resp << ' ';
        }
    }
    cout << endl;

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