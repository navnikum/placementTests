#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the closestNumbers function below.
vector<int> closestNumbers(vector<int> arr) {
    vector<int> ans;
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int diff = arr[1]-arr[0];
    for (int i = 0 ; i < n-1 ; i++)
        if (arr[i+1] - arr[i] < diff) 
            diff = arr[i+1] - arr[i];
    
    for (int i = 0 ; i < n-1 ; i++)
        if(arr[i+1]-arr[i]==diff)
        {
            ans.push_back(arr[i]);
            ans.push_back(arr[i+1]);
        }
    return ans;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split_string(arr_temp_temp);

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    vector<int> result = closestNumbers(arr);

    for (int i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}
