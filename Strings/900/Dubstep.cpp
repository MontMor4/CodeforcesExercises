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

// a funcao z gera um vetor z com o tamanho da string s
//z[i] = tamanho do maior prefixo de s que eh sufixo de s[i..n-1]
//Complexidade: O(n)

vector<int> z_function(string s) {
    int n = (int) s.length();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r)
            z[i] = min (r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
    }
    return z;
}

int32_t main(){ sws; 
    
    string input, output = "";
    vi vetor;
    getline(cin, input); //pega toda a linha (com espaços)

    input = "WUB#" + input;

    vetor = z_function(input);

    // WUB#WUBTESTEWUBWUBDOISWUBWWU
    // 0000300000003003000000300120
    
    bool space;
    loop(i, 4, vetor.size()){
        if(vetor[i] == 3){
            i = i + 2;
            space = true;
        } else {
            if(space){
                output = output + " ";
                space = false;
            }
            output = output + input[i];
        }
    }
 
    if(output[0] == ' ') output.erase(output.begin());
    cout << output << endl;

    return 0;
}
