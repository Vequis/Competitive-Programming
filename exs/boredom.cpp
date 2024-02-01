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
#define maxn 112345

using namespace std;

int n;
int cont[maxn];
int v[maxn];
vi nums;
int dp[maxn];

signed main(){_

    cin >> n;

    for(int i=0; i<n; i++){
        int num;
        cin >> num;
        v[i] = num;
        cont[num]++;
    }

    sort(v, v+n);

    nums.eb(v[0]);
    for(int i=1; i<n; i++){
        if(v[i] == v[i-1]) continue;
        nums.eb(v[i]);
    }

    for(int i=0; i<sz(nums); i++){
        if(i == 0 || (i==1 && nums[1] == nums[0] + 1) ) {
            dp[i] = cont[nums[i]] * nums[i];
            if(i==1) dp[i] = max(dp[i], dp[i-1]);
            continue;
        }

        if(nums[i] == nums[i-1] + 1){
            dp[i] = max(dp[i-1], dp[i-2] + cont[nums[i]] * nums[i]);
        } else {
            dp[i] = dp[i-1] + cont[nums[i]] * nums[i];
        }
    }

    cout << dp[sz(nums) - 1] << endl;

    return 0;
}
