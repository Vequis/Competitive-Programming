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
    int cntcase = 1;
    while(t--) {
        int n;
        cin >> n;

        int av = 41;

        // stack<int> pilha;
        // for(int i = av; i > 0; i--) {
        //     if (n%i == 0) {
        //         av -= i;
        //         n/=i;
        //         pilha.push(i);
        //         cout << n << ' ' << av << ' ' << i << ' '<< endl;
        //         i = av + 1;
        //     }

        // }

        queue<int> pilha;
        for(int i = 2; i <= av; i++) {
            while (n%i == 0 and i <= av) {
                av -= i;
                n/=i;
                pilha.push(i);
                // cout << n << ' ' << av << ' ' << i << ' '<< endl;
            }
        }

        cout << "Case #" << cntcase << ": ";
        if (n > 1) {
            cout << -1 << endl;
        } else {
            cout << av + sz(pilha) << ' ';
            for(int i = 1; i <= av; i++) cout << 1 << ' ';
            while(!pilha.empty()) {
                cout << pilha.front() << ' ';
                pilha.pop();
            }
            cout << endl;
        }

        cntcase++;


    }

    return 0;
}
