#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the larrysArray function below.
string larrysArray(vector<int> a) {
    int i,j, temp ,n = a.size();
    string s;
    for (i=0; i<=n-3; i++) {
        for (j=1; j<=3; j++) {
            if (a[i] < a[i+1] && a[i] < a[i+2]) break;
            temp = a[i];
            a[i] = a[i+1];
            a[i+1] = a[i+2];
            a[i+2] = temp;
        }
        if (i>0 && a[i]<a[i-1]) i-=2;
    }
    if (i<=n-3) 
        s = "NO";
    else {
        if (a[n-2] < a[n-1]) s = "YES";
        else s = "NO";
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string A_temp_temp;
        getline(cin, A_temp_temp);

        vector<string> A_temp = split_string(A_temp_temp);

        vector<int> A(n);

        for (int i = 0; i < n; i++) {
            int A_item = stoi(A_temp[i]);

            A[i] = A_item;
        }

        string result = larrysArray(A);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

