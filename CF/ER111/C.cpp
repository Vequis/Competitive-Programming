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
#define MAXE 312345

using namespace std;

int t, n, ptr, limitante, resp;
int a[MAXE];
int maior[MAXE], menor[MAXE];
stack<ii> pilhamaior, pilhamenor;

signed main(){_

    cin >> t;
    while(t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
            while(!pilhamaior.empty() && a[i] >= pilhamaior.top().fs){
                maior[pilhamaior.top().sc] = i;
                pilhamaior.pop();
            }
            while(!pilhamenor.empty() && a[i] <= pilhamenor.top().fs){
                menor[pilhamenor.top().sc] = i;
                pilhamenor.pop();
            }

            pilhamaior.push({a[i], i});
            pilhamenor.push({a[i], i});
        }

        while(!pilhamaior.empty()){
            maior[pilhamaior.top().sc] = n;
            pilhamaior.pop();
        }
        while(!pilhamenor.empty()){
            menor[pilhamenor.top().sc] = n;
            pilhamenor.pop();
        }

        resp=0;
        for(int i=0; i<n; i++){
            ptr=i+1;
            limitante=n-1;
            while(ptr < limitante){
                if(a[i] < a[ptr]) limitante = min(limitante, maior[ptr] - 1);
                else if(a[i] > a[ptr]) limitante = min(limitante, menor[ptr] - 1);
                else limitante = ptr;

                ptr++;
            }

            cout << i << ' ' << limitante << endl;

            resp += limitante - i+1;
        }

        cout << resp << endl;
    }

    return 0;
}
