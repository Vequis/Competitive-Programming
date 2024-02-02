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

int infectados[1010];

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    
    int n, m;
    int o, r;
    cin >> n >> m;
    cin >> o >> r;

    infectados[o] = 1;

    vector<int> presentes;

    for (int i=1; i<=m; i++){
        int limpa = true;
        int a;
        cin >> a;
        for (int j=0; j<a; j++){
            int presente;
            cin >> presente;
            presentes.push_back(presente);
            if (infectados[presente] == 1 and i>=r){
                limpa = false;
            }
        }

        if (!limpa) {
            for (int j=0; j<a; j++){
                infectados[presentes[j]] = 1;
            }
        }

        presentes.clear();
    }

    int cont = 0;
    for (int i=1; i<=n; i++){
        if (infectados[i] == 1)cont++;
    }

    cout << cont << endl;

	return 0;
}
