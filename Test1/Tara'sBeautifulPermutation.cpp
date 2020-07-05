#include <bits/stdc++.h>
using namespace std;

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

ll fact[100005], mod=10e8+7;

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


// Another DP solution by D Chandak 3 states
const int mod =  1000000007;
int dp[2001][2001][2];

int rec(int one, int two, int ban)
{
    if(one==0 && two==0)
        return 1;
    int& ret=dp[one][two][ban];
    if(ret!=-1)
        return ret;
    ret=0;
    if(one>0)
        ret=(ret+1LL*rec(one-1, two, 0)*(one-ban))%mod;
    if(two>0)
        ret=(ret+1LL*rec(one+1, two-1, 1)*two)%mod;
    return ret;
}

int beautifulPermutations(vector<int> arr) {
   memset(dp,-1,sizeof dp);
    
   int one=0,two=0;
   unordered_map<int, int> hash;
   for(int i=0;i<arr.size();++i)
        hash[arr[i]]++;

    unordered_map<int, int>:: iterator it ;
    for(it = hash.begin(); it!=hash.end(); ++it)
    {
        if(it->second == 2)
            ++two;
        else 
            ++one;
    }

    return rec(one,two,0);

  }



// DP  by author
  
#include <bits/stdc++.h>  
using namespace std ;

#define fr(i, a, b) for(i=a; i<=b; i++)
#define fb(i, a, b) for(i=a; i>=b; i--)

const int mod = 1e9 + 7;
const int maxn = 2 * 1e3 + 5;

int F[ maxn ], dp[ maxn ][ maxn ], inv[ maxn ];

int power(int a, int b, int m = mod) {
    int res = 1;
    while( b ) {
        if( b & 1 ) {
            res = 1LL * res * a % m;
        }
        a = 1LL * a * a % m;
        b /= 2;
    }
    return res;
}

void pre() {
    int i, j;
    dp[0][0] = F[0] = inv[0] = 1;
    fr(i, 1, 2000) {
        F[i] = 1LL * F[i-1] * i % mod;
        dp[i][0] = F[i];
        inv[i] = power(F[i], mod-2) % mod;
    }

    fr(i, 0, 2000) {
        int s1 = 0, s2 = 0;
        fr(j, 1, 2000) {
            if(i-1 >= 0) 
                dp[i][j] = 1LL * i * dp[i-1][j] % mod;
            dp[i][j] += 1LL * j * dp[i][j-1] * (i + 2 * (j-1)) % mod;

            if( dp[i][j] >= mod )   dp[i][j] -= mod;

            dp[i][j] += 1LL * ( s1 + s2 ) * F[j] % mod;

            if( dp[i][j] >= mod )   dp[i][j] -= mod;

            int x = 1LL * dp[i][j-1] * inv[j-1] % mod;

            s1 += 1LL * i * x % mod; 
            if( s1 >= mod )    s1 -= mod;
            s2 += 1LL * x * (2 * j - 1) % mod;
            if( s2 >= mod )    s2 -= mod;
        }
    }
}

int main() {
    pre();
    int t; cin >> t;
    int sm = 0;
    while( t-- ) {
        map<int, int> M;
        int n, m1 = 0, m2 = 0; cin >> n;
        sm += n;
        int i; 
        fr(i, 1, n) {
            int x; cin >> x;
            M[x] ++;
            if( M[x] == 2 ) {
                m2 ++; 
                m1 --;
            } 
            else {
                m1 ++;
            }
        }
        cout << dp[m1][m2] << "\n";
    }
    return 0;
}




