#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, a ,b, c;
    cin>>t;
    vector<vector<int> > s(t);
    int k = 0;
    while (t--){
        cin >> a >> b >> c;
        s[k].push_back(a);
        s[k].push_back(b);
        s[k].push_back(c);
        k++;
    }
    string sx = "Yes";
    for(int i=0; i<k-1; i++) {
         if (s[i][0] == s[i+1][0]  && s[i][1] == s[i+1][1]  && s[i][2] == s[i+1][2])
             sx = "No";
         else{
             if (s[i][0] < s[i+1][0]  && s[i][1] >= s[i+1][1]  && s[i][2] >= s[i+1][2])
                 sx = "No";
             if (s[i][0] >= s[i+1][0]  && s[i][1] < s[i+1][1]  && s[i][2] >= s[i+1][2])
                 sx = "No";
             if (s[i][0] >= s[i+1][0]  && s[i][1] >= s[i+1][1]  && s[i][2] < s[i+1][2])
                 sx = "No";             
         }
         
     }
    cout << sx;

    return 0;
}