// https://codeforces.com/contest/1692/problem/E

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
    int n,s; cin>>n>>s;
    unordered_map<int,int> frente,tras;
    int numuns = 0;
    vi nums(n);
    int custo = 1;
    for (auto &it : nums){ 
        cin >> it;
        if(it==1){
            numuns++;
            frente[numuns]=custo;
        }
        custo++;
    }
    for(auto i : frente){
        tras[numuns+1-i.ff]=n+1-i.ss;
    }
    if(numuns<s){
        cout<<-1<<endl;
        return;
    }
    int menorOp = LLINF;
    loop(i,0,1+numuns-s){
       menorOp =min(frente[i]+tras[numuns-s-i],menorOp);
            
    }
    cout<<menorOp<<endl;
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