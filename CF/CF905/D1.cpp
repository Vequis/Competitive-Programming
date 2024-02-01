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

signed main(){_

    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;

        vi c;
        vi b;
        c.eb(1);

        for(int i = 0; i < n-1; i++) {
            int a;
            cin >> a;
            c.eb(a);
        }
        for(int i = 0; i < n; i++) {
            int a;
            cin >> a;
            b.eb(a);
        }

        sort(all(c));
        sort(all(b));

        int ptr1, ptr2;
        ptr1 = n-1;
        ptr2 = n-1;
        int removidos = 0;

        vi pc;
        vi pb;
        vi rem;

        bool usou = 0;

        while(ptr1 >= 0) {
            if (b[ptr2] > c[ptr1]) {
                pc.eb(c[ptr1]);
                pb.eb(b[ptr2]);

                ptr2--;

                if (ptr1 == 0) usou = 1;

            } else {
                rem.eb(c[ptr1]);
                removidos++;
            }

            ptr1--;
        }

        int resp = 0;
        int x = 0;

        if(sz(pb) == 0) {
            cout << n*m << endl;
            continue;
        }

        int ptr = sz(pb) - 2;

        x=pb[ptr+1] - 1;

        while (ptr >= 0 and pb[ptr+1] > pc[ptr]) {

            ptr--;
            x=pb[ptr+1] - 1;
        }

        if (removidos != 0 and rem[sz(rem) - 1] < pb[ptr+1]) x = m;
        if(!usou) x = m;

        if (m < x) x = m;
        cout << x*removidos + (m-x)*(removidos + 1) << endl;

        // cout << x << ' ' << removidos << endl;

    }

    return 0;
}
