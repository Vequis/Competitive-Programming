#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>


int max1 = 1e9;

using namespace std;

vector<vector< pair<int,int> > > grafo(50050);
int visitados[50050];
vector<int> vistemp;
pair<int,int> visperm[50050];

int dfs(int node, int atual){
    visitados[node] = 1;
    vistemp.push_back(node);
    int maior1 = 1, maior0 = 1;
    for (int i=0; i<grafo[node].size(); i++){
        int temp = 1;
        if (grafo[node][i].second != atual and visitados[grafo[node][i].first] == 0){
            temp = dfs(grafo[node][i].first, grafo[node][i].second) + 1; 
        }

        if (temp> maior1 and grafo[node][i].second == 1){
            maior1=temp;
        }

        if (temp> maior0 and grafo[node][i].second == 0){
            maior0=temp;
        }
    }
    visperm[node] = make_pair(maior0, maior1);
    return max(maior1,maior0);
}

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    

    int n;
    cin >> n;

    for (int i=0; i<n-1; i++){
        int a, b, empresa;
        cin >> a >> b >> empresa;

        grafo[a].push_back(make_pair(b,empresa));
        grafo[b].push_back(make_pair(a,empresa));
    }


    int maior = 0;
    int tempor;
    for (int i=1; i<=n; i++){
        if (visperm[i].first==0 and visperm[i].second == 0){
            for (int j=0; j<grafo[i].size(); j++){
                tempor = dfs(i, grafo[i][j].second) + 1;
                if (tempor > maior) maior = tempor;

                for (int k=0; k<vistemp.size(); k++) visitados[vistemp[k]] = 0;
                vistemp.clear();
            }
        } else {
            tempor = visperm[i].first+visperm[i].second;
            cout << "HOHO" <<  tempor << " " << visperm[i].first << " " << visperm[i].second << endl;
            if (tempor > maior) maior = tempor;
        }    
    }

    cout << maior << endl;

	return 0;
}
