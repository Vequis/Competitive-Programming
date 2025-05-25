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

map<string, bool> f;

void solve() {

    f["BR-AC"] = 1;
    f["BR-AL"] = 1;
    f["BR-AP"] = 1;
    f["BR-AM"] = 1;
    f["BR-BA"] = 1;
    f["BR-CE"] = 1;
    f["BR-ES"] = 1;
    f["BR-GO"] = 1;
    f["BR-MA"] = 1;
    f["BR-MT"] = 1;
    f["BR-MS"] = 1;
    f["BR-MG"] = 1;
    f["BR-PA"] = 1;
    f["BR-PB"] = 1;
    f["BR-PR"] = 1;
    f["BR-PE"] = 1;
    f["BR-PI"] = 1;
    f["BR-RJ"] = 1;
    f["BR-RN"] = 1;
    f["BR-RS"] = 1;
    f["BR-RO"] = 1;
    f["BR-RR"] = 1;
    f["BR-SC"] = 1;
    //f["BR-SP"] = 1;
    f["BR-SE"] = 1;
    f["BR-TO"] = 1;
    f["BR-DF"] = 1;


    string confusa;
    cin >> confusa;
    if (confusa == "BR?SP") {
        cout << "S" << endl;
        return;
    }

    int pos_conf = -1;
    for (int i = 0; i < 5; i++) {
        pos_conf = i;
        if (confusa[i] == '?') break;
    }

    bool pode_ser_sp = 0;
    bool pode_ser_outras = 0;
    for(int i = 0; i < 26; i++) {
        char c = 'A' + i;
        confusa[pos_conf] = c;

        if (confusa == "BR-SP") pode_ser_sp = 1;
        if (f[confusa] == 1) pode_ser_outras = 1;
    }

    if (!pode_ser_sp) {
        cout << "N" << endl;
    } else {
        if (pode_ser_outras) {
            cout << "T" << endl;
        } else {
            cout << "S" << endl;
        }
    }


}

signed main(){_
    int t;
    // cin >> t;
    t=1;

    while(t--) {
        solve();
    }

    return 0;
}