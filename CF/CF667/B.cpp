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
#define vvi vector<vi>
#define vvii vector<vii>
#define endl '\n'
#define ll long long int
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int a,b,x,y,n, minimo;
long long resp;

int main(){_

    int t;
    cin >> t;
    while(t--){
        cin >> a >> b >> x >> y >> n;
        minimo = min(a-x, b-y);
        minimo = min(n, minimo);

        resp = (a-minimo)*(b-minimo);
        cout << resp << endl;
    }

    return 0;
}