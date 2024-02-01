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

int a[1123], b[1123];

signed main(){_

    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++) cin >> a[i];
    for(int i=0; i<m; i++) cin >> b[i];

    int ptr1 = 0;
    int ptr2 = 0;
    int ok = 0;

    sort(a, a+n);
    sort(b, b+m);

    while(ptr1<n &&ptr2<m){
        if(a[ptr1] == b[ptr2]) {
            cout << a[ptr1] << endl;
            ok = 1;
            ptr1++;
            while(a[ptr1] == a[ptr1-1])ptr1++;
            ptr2++;
            while(b[ptr2] == b[ptr2-1])ptr2++;
        } else if (a[ptr1] < b[ptr2]) {
            ptr1++;
        } else {
            ptr2++;
        }
    }

    if(!ok){
        cout << '*' << endl;
    }

    return 0;
}
