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
#define maxn

using namespace std;

vi v;

// Often used in "find k-th number"
// bs in answer is a very often method as well

//Implementation
// Always think in a problem as 
// 0000111111
// Find first '1', first "YES"
// You want to keep 1s in your set -> fim = mid
// 0 you want to discard -> ini = mid + 1
// at the end, ini = fim -> your answer is in ini

// 11111111111111 -> ini = fim = 0
// 00000000000000 -> ini = R + 1

// Prefer to use recursive implementation

int bb(int x){
    int ini = 0, fim = sz(v), mid;

    while(ini<fim) {
        mid = ini + (fim-ini)/2;
        if(v[mid] == x) return mid;
        else if (v[mid] > x) fim = mid;
        else ini = mid + 1;
    }

    return -1;
}

bool f(int x, int idx) {
    return v[idx] >= x;
}

// Always start with real_r + 1 -> 
// You can have a case in 000000000 -> return real_r + 1
int bb_rec(int x, int l, int r) {
    if (l==r) return l;

    int mid = l + (r-l)/2;

    return f(x, mid) ? bb_rec(x, l, mid) : bb_rec(x, mid+1, r);
}

set<int> s;
// lower_bound
// When exists a element = x -> return iterator to element
// index? -> distance

// se n tem nenhum igual maior que ele -> retorna s.end -> 
// se ele e o menor de todos, retorna s.begin() - interpretar igual a um elemento no meio
int idx_lb(int x) {
    return distance(s.begin(), s.lower_bound(x));
}


signed main(){_

    int n;
    cin >> n;

    for(int i = 0; i<n; i++){

        int num;
        cin >> num;

        v.eb(num);
        s.insert(num);
    }

    int x;
    cin >> x;

    // Find first element greater or equal to x
    cout << bb_rec(x, 0, n) << endl;
    cout << idx_lb(x) << endl;

    return 0;
}

