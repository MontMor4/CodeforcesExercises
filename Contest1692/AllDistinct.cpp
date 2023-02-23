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
const ll LLINF = 0x3f3f3f3f3f3f3f3f; //escrevemos 3f 8 vezes
const double PI = acos(-1);

void solve(){
    unordered_map<int,int> m;
    int q,a,remove=0;
    cin>>q;
    int total = q;
    while(q-- > 0){
        cin>>a;
        m[a]++;
    }
    vi v;
    for(auto &i:m){
        if(i.ss%2==1){
            total-= i.ss-1;
            i.ss = 1;
        }
        if(i.ss%2==0){
            total-= i.ss-2;
            i.ss = 2;
        }
        v.pb(i.ss);

    }
    sort(all(v),greater<>());
    loop(i,0,v.size()-1){
        if(v[i]>1){
            if(v[i+1]>0){
                v[i]-=1;v[i+1]-=1;
                total-=2;
            }else{
                v[i]-=2;
                total-=2;
            }
        }
    }
    if(v[v.size()-1]==2)total-=2;
    cout<<total<<endl;
    
    
}

int32_t main(){ sws; 
    
    int t;
    cin>>t;
    while(t-- > 0){
        solve();
    }
    
    return 0;
}
