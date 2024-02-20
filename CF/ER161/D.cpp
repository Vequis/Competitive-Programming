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
#define maxn 312345

using namespace std;

int a[maxn];
int b[maxn];
int l[maxn];
int r[maxn];
int nl[maxn];
int nr[maxn];
int dam[maxn];
set<int> mort;
set<int> atualizados;

void solve() {

    int n;
    cin >> n;

    mort.clear();

    dam[0] = dam[n+1] = 0;
    b[0] = b[n+1] = 2*MODN;
    a[0] = a[n+1] = 0;
    queue<int> mortos;

    for(int i = 1; i <=n; i++) cin >> a[i];
    for(int i = 1; i <=n; i++) cin >> b[i];
    for(int i = 1; i <=n; i++) l[i] = i-1;
    for(int i = 1; i <=n; i++) r[i] = i+1;
    for(int i = 1; i <=n; i++) {
        dam[i] = a[i-1] + a[i+1];
        if (dam[i] > b[i]) mortos.push(i);
        if (dam[i] > b[i]) mort.insert(i);
        // cout << dam[i] << endl;
    }

    while(n--) {
        int s = sz(mortos);
        cout << s << ' ';

        atualizados.clear();

        for (int i = 0; i < s; i++) {
            int t = mortos.front();
            // cout << t << endl;
            mortos.pop();

            l[r[t]] = l[t];
            r[l[t]] = r[t];
            atualizados.insert(l[t]);
            atualizados.insert(r[t]);
        }

        for (int x : atualizados) {
            dam[x] = a[l[x]] + a[r[x]];
            if (dam[x] > b[x] and mort.find(x) == mort.end()) {
                mortos.push(x);
                mort.insert(x);
            }
        }
    }

    while(!mortos.empty()) mortos.pop();
    cout << endl;

}

signed main(){_
    int t;
    cin >> t;

    while(t--) {
        solve();
    }

    return 0;
}
