#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, a ,b , k = 0;
    cin>>n;
    while (n--){
        cin >> a>> b;
        k++;
    }
    if (k % 2 == 0)
        cout<<0;
    else
        cout<< 1 ;
    return 0;
}