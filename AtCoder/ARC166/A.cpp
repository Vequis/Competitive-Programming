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

char x[212345];
char y[212345];

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        for(int i = 0; i < n; i++) {
            char c;
            cin >> c;
            x[i] = c;
        }
        char esp;
        // cin >> esp;
        for(int i = 0; i < n; i++) cin>>y[i];


        int cntxa, cntxb;
        int cntya, cntyb;
        cntxa = 0;
        cntya = 0;
        cntxb = 0;
        cntyb = 0;
        int deltaA = 0;
        int cntxc = 0;
        bool impossivel = 0;
        for(int i = 0; i < n; i++) {
            if (y[i] == 'C' and x[i] != 'C') {
                impossivel = 1;
            } else if (y[i] == 'C' and x[i] == 'C') {
                if(cntxa > cntya) impossivel = 1;
                if(cntxb > cntyb) impossivel = 1;
                cntxa = 0;
                cntya = 0;
                cntxb = 0;
                cntyb = 0;
                cntxc = 0;
            } else {
                if (y[i] == 'A') cntya++;
                if (x[i] == 'A') cntxa++;
                if (y[i] == 'B') cntyb++;
                if (x[i] == 'B') cntxb++;
                if (x[i] == 'C') cntxc++;

                if (cntya  > cntxc + cntxa) impossivel = 1;
                
                while(cntya > cntxa and cntya <= cntxc + cntxa) {
                    cntxa++;
                    cntxc--;
                }
            }
        }

        if(cntxa > cntya) impossivel = 1;
        if(cntxb > cntyb) impossivel = 1;

        if (impossivel) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }

    return 0;
}
