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

int inv(int n) {
    if (n<=1) return n;
    return (MODN - ( (MODN/n) * inv(MODN%n) ) % MODN ) %MODN;
}

int power(int a, int b) {
    int resp = 1;
    int pot = a;

    while(b > 0) {
        if (b&1)resp = (resp*pot)%MODN;
        pot = (pot*pot)%MODN;
        b = (b>>1);
    }

    return resp;
}

int mult(int a, int b){
    return (a*b)%MODN;
}

signed main(){_
    int t;
    cin >> t;

    int numdiv = 1;
    int sumdiv = 1;
    int proddiv = 1;

    int expo = numdiv;
    int aa = 1;

    while(t--) {
        int p, a;
        cin >> p >> a;

        int cur = (p*(power(p, a) - 1))%MODN;
        cur = (cur * inv(p-1))%MODN;
        cur = (cur * (sumdiv))%MODN;
        cur = (cur + sumdiv)%MODN;
        aa = (power(p, a) * aa)%MODN;
        int cur2 = power(p, (a*(a+1)/2)%(MODN - 1));
        cur2 = power(cur2, expo);
        cur2 = mult(power(proddiv, a + 1), cur2);
        sumdiv = cur;
        proddiv = cur2;
        expo = (expo*(a+1))%(MODN - 1);
        numdiv = (numdiv*(a + 1))%MODN;
    }

    // cout << expo << endl;
    // cout << aa << endl;
    // cout << power(2, MODN-1 - 2) << endl;

    cout << numdiv << ' ' << sumdiv << ' ' << proddiv << endl;

    return 0;
}
