#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T;
int Row, Col;
int Answer;
char Board[102][102];
string StartKey;
bool visited[102][102];
vector<pair<int, int>> Doors[26];
bool Keys[26];
queue<pair<int, int>> BFSQueue;
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

void input(){
    for (int i = 0; i < 26; i++){
        Keys[i] = 0;
        Doors[i].clear();
    }
    cin >> Row >> Col;
    Row += 2;
    Col += 2;
    for (int i = 0; i < Row; i++)
        for (int j = 0; j < Col; j++)
            if (i == 0 || i == Row - 1 || j == 0 || j == Col - 1)
                Board[i][j] = '.';
            else
                cin >> Board[i][j];
    cin >> StartKey;
    for (int i = 0; i < StartKey.length(); i++)
        if (StartKey[i] != '0')
            Keys[StartKey[i] - 'a'] = true;
}

void init_variables(){
    Answer = 0;
    for (int i = 0; i < Row; i++)
        for (int j = 0; j < Col; j++)
            visited[i][j] = false;
}

bool canVisit(int y, int x){
    if (y < 0 || y >= Row || x < 0 || x >= Col)
        return false;
    if (visited[y][x])
        return false;
    if (Board[y][x] == '*')
        return false;
    if (Board[y][x] >= 'A' && Board[y][x] <= 'Z'){
        if (!Keys[Board[y][x] - 'A']){
            Doors[Board[y][x] - 'A'].push_back(make_pair(y, x));
            return false;
        }
    }
    return true;
}

void check_area(int y, int x){
    if (Board[y][x] >= 'a' && Board[y][x] <= 'z'){
        Keys[Board[y][x] - 'a'] = true;
        for (auto iter = Doors[Board[y][x] - 'a'].begin(); iter < Doors[Board[y][x] - 'a'].end(); iter++){
            BFSQueue.push(*iter);
            visited[(*iter).first][(*iter).second] = true;
        }
    }
    else if (Board[y][x] == '$')
        Answer++;
}

void BFS(){
    while(!BFSQueue.empty()){
        int y = BFSQueue.front().first;
        int x = BFSQueue.front().second;
        BFSQueue.pop();
        check_area(y, x);
        
        for (int i = 0; i < 4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (canVisit(ny, nx)){
                BFSQueue.push(make_pair(ny, nx));
                visited[ny][nx] = true;
            }
        }
    }
}

void get_answer(){
    BFSQueue.push(make_pair(0, 0));
    visited[0][0] = true;
    BFS();
}

void solve(){
    init_variables();
    get_answer();
    
    return;
}

void print_answer(){
    cout << Answer << '\n';
    
    return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int T;
    cin >> T;
    while(T--){
        input();
        solve();
        print_answer();
    }
    
    return 0;
}