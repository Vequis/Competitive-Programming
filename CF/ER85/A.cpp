#include <iostream>
#include <vector>

using namespace std;

int main(){
    int t;

    cin >> t;

    bool ok = true;

    pair<int, int> V[101];
    vector<string> resp;

    for (int i=0; i<t; i++) {
        int n;
        ok = true;
        cin >> n;
        for (int j=0; j<n; j++){
            int a,b;
            cin >> a >> b;
            if (b>a){
                ok = false;
            }

            V[j] = make_pair(a,b);
            if (j>0){
                if (V[j].first < V[j-1].first or V[j].second < V[j-1].second) {
                    ok = false;
                }
            }
        }
        if (ok) {
            resp.push_back("YES");
        } else {
            resp.push_back("NO");
        }
    }

    for (int i=0; i<(int)resp.size(); i++){
        cout << resp[i]<< endl;
    }

    return 0;
}

