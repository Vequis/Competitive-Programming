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

void limpa (string* s, int k) {
    int cont = 0;
    for (int i = sz(*s) - 1; i >=0; i--) {
        if (cont == k) return;
        (*s)[i] = '0';
    }
    return;
}

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int carry = 0;
        for (int i = sz(s) - 1; i >=0; i--) {
            char c = s[i];
            int a = c + '0';

            limpa(&s, sz(s) - 1 - i);
        }
    }

    return 0;
}
