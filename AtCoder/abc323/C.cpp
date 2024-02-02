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
#define int long long

using namespace std;

int a[1123];

bool cmp(ii a, ii b) {
    return a.fs > b.fs;
}

signed main(){_

    int n, m;
    cin >> n >> m;

    vii scores;
    for(int i = 1; i <= m; i++) {
        cin >> a[i];
        scores.eb(a[i], i);
    }

    sort(all(scores), cmp);

    vector<string> gab;

    int maior = -1;
    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        gab.eb(s);

        int cur = i;

        for (int i = 0; i < m; i++) {
            if (s[i] == 'o') cur += a[i+1];
        }

        maior = max(maior, cur);
    }

    for(int i = 1; i <=n; i++) {
        string s = gab[i-1];

        int cur = i;

        for (int i = 0; i < m; i++) {
            if (s[i] == 'o') cur += a[i+1];
        }

        int cont = 0;
        int itr = -1;
        while(cur < maior) {
            itr++;
            if (s[scores[itr].sc - 1] == 'x'){
                cont++;
                cur += scores[itr].fs;
            }

        }

        cout << cont << endl;
    }

    return 0;
}
