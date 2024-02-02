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
        int a, b, r;
        cin >> a>> b >> r;

        //1101000111
        //0010100101
        //1111000010
        
        //1000011110

        if (a<b)swap(a,b);
        int it = 1;
        while(it <= max(a, b)) it = (it << 1);

        it = (it >> 1);

        if ((a & it) && (b&it)) {
            if(it != 0) it = (it >> 1);
            while((a & it) == (b&it) && it != 0) it = (it>>1);
            if ( (a & (it<<1)) && (b&(it<<1)) && (a & it) && !(b&it)) it = (it>>1);
        }

        int resposta = 0;

        // cout << it << endl;

        while(it >= 0) {
            // cout << resposta << endl;    
            // cout << it << endl;
            if ( (a & it) && !(b&it) && resposta + it <= r) {
                if (resposta + it <= r) resposta += it;
            }

            if (it == 0) break;
            it = (it>>1);
        }

        // for(int i = 63; i>=0; i--) cout << ((a>>i) & 1);
        // cout << endl;
        // for(int i = 63; i>=0; i--) cout << ((b>>i) & 1);
        // cout << endl;
        // for(int i = 63; i>=0; i--) cout << ((resposta>>i) & 1);
        // cout << endl;
        // // for(int i = (1<<63); i>=0; i = (i>>1)) cout << (bool)(b & i);
        // cout << endl;
        // for(int i = (1<<63); i>=0; i = (i>>1)) cout << (bool)(resposta & i);
        // cout << endl;


        // cout << (resposta xor a) << endl;
        // cout << (resposta xor b) << endl;
        int x = (resposta xor a) - (resposta xor b);

        cout << x << endl;
    }
    


    return 0;
}
