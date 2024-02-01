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

int n, t, num;
string s;

vector<char> mp;

int main(){_

    cin >> t;

    while(t--){
        cin >> n;
        cin >> s;

        mp = vector<char>(26);

        num = s[0] - 'A';
        mp[num] = 1;

        for (int i=1; i<n; i++){
            num = s[i] - 'A';
            if (mp[num] > 0 && s[i]!=s[i-1]){
                cout << "NO" << endl;
                break;
            }
            mp[num]++;

            if (i==n-1){
                cout << "YES" << endl;
            }
        }

        if(n==1) cout << "YES" << endl;
        

        mp.clear();

    }

    return 0;
}