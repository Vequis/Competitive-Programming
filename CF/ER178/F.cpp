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

string generate_s(int n) {
    string s;
    s = "";
    int it = n;
    while(it>0){
        s = s+(char)('0' + it%10);
        it/=10;
    }
    it = n + 1;
    while(it>0){
        s = s+(char)('0' + (it%10));
        it/=10;
    }
    sort(all(s));
    return s;
}

vi all_possibilities;
int max_n;

set<string> cj;
vi minimal_possibilities;

int intfromstring(string s, bool flag) {

    if (flag == 0) {
        int resp = 0;
        for (int i = 0; i < sz(s) - 1; i++) {
            char c = s[i];
            resp*=10;
            resp += (c - '0');
        }

        for (int i = 0; i < sz(s); i++) {
            if (s[i] != '0') {
                int exp = 1;
                while(i--) exp*=10;
                resp*= exp;
                break;
            }
        }

        resp*=10;
        resp += (s[sz(s) - 1]);
    
        return resp;
    } else {
        int resp = 0;
        for (int i = 0; i < sz(s); i++) {
            char c = s[i];
            resp*=10;
            resp += (c - '0');
        }

        for (int i = 0; i < sz(s); i++) {
            if (s[i] != '0') {
                int exp = 1;
                while(i--) exp*=10;
                resp*= exp;
                break;
            }
        }

        return resp;
    }
}

void generate_all_possibilities(string prefix, bool flag) {
    int it = intfromstring(prefix, flag);
    if (it < 40 and flag == 0) {
    cout << prefix << ' ' << it << endl;
    }
    while(it < 1123456789) {
        all_possibilities.pb(it);
        it = 10*it + 9;
    }

    if (flag==0 or sz(prefix) >= 9) return;
    
    int last_digit = (prefix[sz(prefix) - 1] - '0');
    for (int i = 0; i<=9; i++) {
        char c = (char)('0' + i);
        string s = prefix + c;
        if (i < last_digit) generate_all_possibilities(s, 0);
        else generate_all_possibilities(s, 1); 
    }
}

void solve() {
    int n;
    cin >> n;

    for (int i = 0; i <=n; i++) {
        string s = generate_s(i);
        if (cj.find(s) == cj.end()) {
            cout << "Erro: " << i << endl;

        }
    }

    for (int i = 0; i<sz(minimal_possibilities); i++) {
        if (n<minimal_possibilities[i]) {
            cout << i + 1 << endl;
            return;
        }
    }
}

signed main(){_
    int t;
    cin >> t;
    // t=1;
    for (int i = 0; i<=9; i++) {
        char c = (char)('0' + i);
        string s = "";
        s = s + c;
        cout << s << '*' << endl;
        generate_all_possibilities(s, 1);
    }
    sort(all(all_possibilities));
    for (int x : all_possibilities) {
        string s = generate_s(x);
        if (cj.find(s) == cj.end()) {
            cj.insert(s);
            minimal_possibilities.pb(x);
        }
    }

    // for (int i = 0; i < 100; i++) cout << minimal_possibilities[i] << endl;

    while(t--) {
        solve();
    }

    return 0;
}