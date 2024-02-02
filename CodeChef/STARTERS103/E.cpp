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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int resp = 0;

        for(int i = 0; i < min(n, k); i++) {
            int contt = 0;
            int cont1 = 0;
            for(int j = i; j < n; j+=k) {
                contt++;
                if (s[j] == '1') cont1++;
            } 

            if (contt == 1) {
                resp += 1;
            } else if (cont1%2){
                resp += min(contt - cont1, cont1/2 + 2);
            } else {
                resp += min(contt - cont1, cont1/2);
            }
        }

        cout << resp << endl;
    }

    return 0;
}
