#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string s) {
    unordered_map<char, char> mp;
    mp.insert({')','('});
    mp.insert({'}','{'});
    mp.insert({']','['});

    stack<char> st;
    string res;

    for(char c : s){
        if (c == '(' || c == '{' || c == '['){
            st.push(c);
            continue;
        }
        if (st.empty()){
            string r = "NO";
            return r;
        }

        if (c == ')' || c == '}' || c == ']'){
            if (st.top() == mp[c])
                st.pop();
            else 
                st.push(c);
        }
    }
    
    if (!st.empty())
        res = "NO";
    else
        res = "YES";

    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
