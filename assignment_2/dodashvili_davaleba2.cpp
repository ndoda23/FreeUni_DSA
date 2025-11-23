#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int minAmount,maxAmount,index=0;
    string str;
    cin >> str;

    stack<pair<array<int,3>,array<int,3>>> stk;

    for(int i = str.length() - 1; i >= 0; i--) {
        char ch = str[i];
        if(ch == '0') {
            // leaf
            // RED GREEN BLUE
            stk.push({{0,1,0},{0,1,0}});
        }else if (ch=='1') {
            auto temp=stk.top();
            stk.pop();
            auto[childMin,childMax]=temp;
            array<int,3> minRes,maxRes;

            for (int p = 0; p < 3; p++) {
                minRes[p] = INT_MAX;
                maxRes[p] = 0;
                for (int c = 0 ; c < 3; c++) {
                    if (p==c) continue;
                    minRes[p] = min(minRes[p], (p == 1) + childMin[c]);
                    maxRes[p] = max(maxRes[p], (p == 1) + childMax[c]);
                }

            }
            stk.push({minRes,maxRes});
        }else{
            auto left = stk.top();
            stk.pop();
            auto right = stk.top();
            stk.pop();
            auto[leftMin,leftMax]=left;
            auto[rightMin,rightMax]=right;

            array<int,3> minRes,maxRes;

            for (int p = 0; p < 3; p++) {
                minRes[p] = INT_MAX;
                maxRes[p] = 0;
                for (int l = 0 ; l < 3; l++) {
                    if (p==l) continue;
                    for (int r = 0 ; r < 3; r++) {
                        if (p == r || l == r) continue;

                        minRes[p] = min(minRes[p], (p == 1) + leftMin[l] + rightMin[r]);
                        maxRes[p] = max(maxRes[p], (p == 1) + leftMax[l] + rightMax[r]);
                    }
                }
            }

            stk.push({minRes,maxRes});
        }
    }

    auto root = stk.top();
    auto[minG,maxG]=root;

     minAmount = min({minG[0], minG[1], minG[2]});
     maxAmount = max({maxG[0], maxG[1], maxG[2]});
    cout << maxAmount << " " << minAmount << endl;


    return 0;
}