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

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    
    int t;
    cin >> t;

    for (int i=0; i<t; i++){
        int n;
        cin >> n;

        int movsPar = 0;
        int movsImpar = 0;
        for (int j=0; j<n; j++){
            int num;
            cin >> num;

            if (num%2==1 and j%2==0){
                movsImpar++;
            } else if (num%2==0 and j%2==1){
                movsPar++;
            }

        }
        if (movsPar == movsImpar) cout << movsPar << endl;
        else cout << -1 << endl;
    }

	return 0;
}
