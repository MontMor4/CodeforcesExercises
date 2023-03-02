// https://codeforces.com/contest/1692/problem/F

#include <bits/stdc++.h>
using namespace std;
//alias comp='g++ -std=c++17 -g -O2 -Wall -Wconversion -Wshadow -fsanitize=address,undefined -fno-sanitize-recover -ggdb -o out'

#define sws std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); //Melhora o desempenho
#define int long long //Melhor linha de codigo ja escrita
#define endl "\n" //Evita flush
#define loop(i,a,n) for(int i=a; i < n; i++)
#define input(x) for (auto &it : x) cin >> it
#define pb push_back
#define all(x) x.begin(), x.end()
#define ff first
#define ss second
#define mp make_pair
#define TETO(a, b) ((a) + (b-1))/(b)
#define dbg(x) cout << #x << " = " << x << endl
#define print(x,y) loop(it,0,y){cout << x[it] << " ";} cout << "\n";

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef priority_queue<int, vector<int>, greater<int>> pqi;

const ll MOD = 1e9+7;
const int MAX = 1e4+5;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);

void solve(){
    int n;
    string s;
    vi v;
    unordered_map<int,int> m;
    cin>>n;
    loop(i,0,n){
        cin>>s;
        m[stoi(s.substr(s.length()-1,1))]++;
        if(m[stoi(s.substr(s.length()-1,1))]<4)
        v.pb(stoi(s.substr(s.length()-1,1)));


        
    }
    loop(i,0,v.size()){
        loop(j,i+1,v.size()){
            loop(k,j+1,v.size()){
                if((v[i]+v[j]+v[k])%10==3){

                    cout<<"YES"<<endl;
                    return;
                }
            }
        }
    }   
    cout<<"NO"<<endl;
    return;

}

int32_t main(){ sws; 
    int t;
    cin>>t;
    loop(i,0,t){
        solve();
    }
    
    return 0;
}