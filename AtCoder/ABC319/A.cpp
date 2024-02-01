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


    map<string, int> f;

    f["tourist"] =  3858;
    f["ksun48"] = 3679;
    f["Benq"] = 3658;
    f["Um_nik"] = 3648;
    f["apiad"] = 3638;
    f["Stonefeang"] = 3630;  
    f["ecnerwala"] = 3613;
    f["mnbvmar"] = 3555;
    f["newbiedmy"] = 3516;
    f["semiexp"] = 3481;

    string s;
    cin >> s;
    cout << f[s] << endl;

    return 0;
}
