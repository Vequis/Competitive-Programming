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

int n;
// void tornar_bit_1(int mask) {
//     n = n | mask;
// }

void solve() {
    cin >> n;

    //tornar_bit_1(1<<20);

    int ptr_low, ptr_high;
    ptr_low = 0;
    ptr_high = 0;

    while( (1LL << (ptr_high + 1) ) <= n) ptr_high++;

    int n_init = n;

    if ((1LL << ptr_high) == n) {
        if (n==1) cout << 1 << endl;
        else cout << n - 1 << endl;
        return;
    }

    while(ptr_high >= ptr_low) {
        bool bit_high = n & (1LL << ptr_high);

        if (bit_high == 0) {
            n = n & ~(1LL << ptr_low);
        } else {
            n = n | (1LL << ptr_low);   
        }
    
        ptr_low++;
        ptr_high--;
    }

    if (n <= n_init) {
        cout << n << endl;
        return;
    } else {
        ptr_high++;
        ptr_low--;

        bool bit_high = n & (1LL << ptr_high);
        while(bit_high == 0) {
            ptr_high++;
            ptr_low--;

            bit_high = n & (1LL << ptr_high);
        }
        n = n & ~(1LL << ptr_low);
        n = n & ~(1LL << ptr_high);

        ptr_low++;
        ptr_high--;
        while (ptr_high >= ptr_low) {
            n = n | (1LL << ptr_low);
            n = n | (1LL << ptr_high);

            ptr_low++;
            ptr_high--;
        }
    }

    cout << n << endl;
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