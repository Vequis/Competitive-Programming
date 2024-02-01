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

int d, sumtime, summin, summax;
int sum;
vii v;

signed main(){_

    cin >> d >> sumtime;

    v = vii(d+1);

    for(int i=1; i<=d; i++){
        int a, b;
        cin >> a >> b;
        v[i] = {a,b};
        summin += a;
        summax += b;
    }

    int i;
    if(summin <= sumtime && summax>=sumtime){
        cout << "YES" << endl;

        sum = summin;
        i=1;
        while(sum<sumtime){
            if(sum + (v[i].sc - v[i].fs) < sumtime){
                sum += (v[i].sc - v[i].fs);
                cout << v[i].sc << ' ';
            } else {
                cout << v[i].fs + (sumtime-sum) << ' ';
                sum=sumtime;
            }
            i++;
        }

        for(int j=i; j<=d; j++){
            cout << v[j].fs << ' ';
        }
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
