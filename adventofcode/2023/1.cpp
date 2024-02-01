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

int findsubstring(string s, string ss) {
    
}

signed main(){_

    string s;
    int soma1 = 0;
    int soma2 = 0;
    while(cin >> s) {
        int first = -1;
        int last = 0;
        for(int i = 0; i < sz(s); i++) {
            if (s[i] >= '0' and s[i] <= '9') {
                if (first == -1) first = s[i] - '0';

                last = s[i] - '0';
            }
        }
        soma1+=first;
        soma2+=last;
    }

    cout << 10*soma1 + soma2 << endl;

    return 0;
}

