#include<bits/stdc++.h>


#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<int> cur;
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);

        int indmax = 0, indmin = 0;

        for (int i = 1; i < n; i++) {
            printf("? %d %d %d %d\n", indmax, indmax, i, i);
            fflush(stdout);

            char response[3];
            scanf("%s", response);
            if (strcmp(response, "<") == 0) {

                indmax = i;
            }
        }

        int resp = 0;
        cur.clear();
        cur.emplace_back(0);
        for (int i = 1; i < n; i++) {
            printf("? %d %d %d %d\n", indmax, resp, indmax, i);
            fflush(stdout);

            char response[3];
            scanf("%s", response);
            if (strcmp(response, "<") == 0) {
                resp = i;
                cur.clear();
                cur.emplace_back(i);
            } else if (strcmp(response, "=") == 0) {
                cur.emplace_back(i);
            }
        }

        int indmaioragain = 0;
        for (int i = 1; i < cur.size() ; i++) {
            printf("? %d %d %d %d\n", cur[indmaioragain], cur[indmaioragain], cur[i], cur[i]);
            fflush(stdout);

            char response[3];
            scanf("%s", response);
            if (strcmp(response, ">") == 0) {
                indmaioragain = i;
            }
        }

        printf("! %d %d\n", indmax, cur[indmaioragain]);
        fflush(stdout);
    }
}