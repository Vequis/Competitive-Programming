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
// #define int long long -> solução divina?

using namespace std;

ll n;
int acertouconta, saldoneg, menor=INT_MAX, pos;
ll soma, somamin;
vector< pair<ll,ll> > v;
set<ll> resp;
bool negativo;

int main(){_
    cin >> n;

    negativo = false;

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;
        if(!negativo) v.eb(num, i);
        soma+=num;
        somamin = min(soma, somamin);
        if(soma<0 and !negativo){
            negativo = true;
            pos = i;
        }
    }
    
    sort(all(v));
    for (int j=0; j<pos; j++){
        // cout << j << ' ' << v[j].fs << endl;
        if (v[j].fs <= somamin){
            resp.insert(v[j].sc);
        } else {
            break;
        }
    }

    if(!negativo){
        cout << "morete chapou: errou conta!" << endl;
        return 0;
    }

    if(sz(resp)==0){
        cout << "morete chapou: ficou com saldo negativo!" << endl;
        return 0;
    }

    cout << resp.size() << endl;
    for (int x : resp){
        cout << x << ' ';
    }
    cout << endl;

    return 0;
}