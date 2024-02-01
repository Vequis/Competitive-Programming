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

int a[11123];
stack<int> side_street;
int principal;

signed main(){_

    int n;

    while((cin >> n) && (n!=0)){
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }

        principal = 0;

        for(int i=1; i<=n; i++){
            if(a[i] == principal + 1){
                principal = a[i];
                while (!side_street.empty() && side_street.top() == principal+1) {
                    principal++;
                    side_street.pop();
                }
            } else {
                side_street.push(a[i]);
            }
        }

        bool flag = true;

        while(!side_street.empty()){
            if (!side_street.empty() && side_street.top() != principal + 1) flag = false;
            else principal++;
            side_street.pop();
        }

        if(flag){
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }


    }

    return 0;
}
