// https://codeforces.com/contest/1692/problem/D

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

bool isPalindrome(string clock){
    if(clock[0] == clock[4] && clock[1] == clock [3]) return true;
    else return false;
}

string calcNewtime(string clock, int timeToCheck){
    int minutes = timeToCheck + stoi(clock.substr(0, 2)) * 60 + stoi(clock.substr(3, 2));
    minutes = minutes % 1440;
    
    int hour = minutes / 60;
    minutes = minutes % 60;

    string newTime = "";
    
    if(hour < 10) newTime += "0" + to_string(hour) + ":";
    else newTime += to_string(hour) + ":";

    if(minutes < 10) newTime += "0" + to_string(minutes);
    else newTime += to_string(minutes);

    return newTime;
}

void solve(){
    string clock, initialClock;
    int timeToCheck, answer = 0;
    cin >> clock >> timeToCheck;
    
    initialClock = clock;
    while (true)
    {
        if(isPalindrome(clock)) answer++;
        clock = calcNewtime(clock, timeToCheck);
        if(clock.compare(initialClock) == 0) break;
    }
    cout << answer << endl;
}

int32_t main(){ sws; 
    int cases;
    cin >> cases;

    loop(i, 0, cases){
        solve();
    }
    return 0;
}
