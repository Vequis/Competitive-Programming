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

using namespace std;

int n, m, t, a, b, bat, tim;

int main(){_

    cin >> n >> m >> t;

    bat=n;

    for(int i=0; i<m; i++){
        cin >> a >> b;
        bat-=(a-tim);
        if (bat<=0){
            cout << "No" << endl;
            return 0;
        }
        bat+=(b-a);
        if (bat>n) bat = n;
        tim=b;
    }

    bat-=(t-tim);
    if(bat<=0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}