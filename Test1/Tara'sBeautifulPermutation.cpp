	#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef long long ll;

ll modexp(ll base,ll pow1,ll mod)
{
    ll res=1;
    for(;pow1>0;pow1=pow1>>1)
    {
        if(pow1&1)
        {
            res=(res*base)%mod;
        }
        base=(base*base)%mod;
    }
    return res;
}

ll a[100005],fact[100005], mod=10e8+7;

int beautifulPermutations(vector<int> a) {
    int i,n = a.size();
    fact[0]=1;
    for(i=1;i<2005;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
    map<ll,ll> mp;
    ll count=0;
    for(i=0;i<n;i++)
    {
        mp[a[i]]++;
        if(mp[a[i]]==2)
            count++;
    }
    ll ans=0;
    ll p=1;
    for(i=0;i<=count;i++)
    {
        if(i%2==0)
            ans=(ans+(((p*fact[n-i])%mod)*modexp(modexp(2,count-i,mod),mod-2,mod))%mod)%mod;
        else
            ans=(ans-(((p*fact[n-i])%mod)*modexp(modexp(2,count-i,mod),mod-2,mod))%mod)%mod;
        
        p=(((p*(count-i))%mod)*modexp(i+1,mod-2,mod))%mod;

        if(ans<0)
            ans+=mod;
    }
    return ans;   

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int arr_count;
        cin >> arr_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string arr_temp_temp;
        getline(cin, arr_temp_temp);

        vector<string> arr_temp = split_string(arr_temp_temp);

        vector<int> arr(arr_count);

        for (int arr_itr = 0; arr_itr < arr_count; arr_itr++) {
            int arr_item = stoi(arr_temp[arr_itr]);

            arr[arr_itr] = arr_item;
        }

        int result = beautifulPermutations(arr);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
