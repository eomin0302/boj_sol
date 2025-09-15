#include <iostream>
#include <algorithm>
using namespace std;

#define MAXCOUNT 10

enum{
    U, D, L, R
};

enum{
    RED, BLUE
};

int N, M;
char Board[10][10];
pair<int, int> Red;
pair<int, int> Blue;
int MinDepth = 100;
int Answer;

bool BlueinHole;
bool RedinHole;

int Dir[4] = {U, D, L, R};


void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            cin >> Board[i][j];
            if (Board[i][j] == 'R'){
                Red.first = i;
                Red.second = j;
            }
            if (Board[i][j] == 'B'){
                Blue.first = i;
                Blue.second = j;
            }
        }
}

void move_up(int Color){
    if (Color == RED){
        int x = Red.second;
        int y = Red.first;
        int ny;
        Board[y][x] = '.';
        for (ny = y; Board[ny][x] == '.'; ny--);
        if (Board[ny][x] == 'B')
            for (move_up(BLUE); Board[ny][x] == '.'; ny--);
        if (Board[ny][x] == 'O'){
            RedinHole = true;
            return;
        }
        Board[++ny][x] = 'R';
        Red.first = ny;
    }
    else if (Color == BLUE){
        int x = Blue.second;
        int y = Blue.first;
        int ny;
        Board[y][x] = '.';
        for (ny = y; Board[ny][x] == '.'; ny--);
        if (Board[ny][x] == 'O'){
            BlueinHole = true;
            return;
        }
        Board[++ny][x] = 'B';
        Blue.first = ny;
    }
    
    return;
}

void move_down(int Color){
    if (Color == RED){
        int x = Red.second;
        int y = Red.first;
        int ny;
        Board[y][x] = '.';
        for (ny = y; Board[ny][x] == '.'; ny++);
        if (Board[ny][x] == 'B')
            for (move_down(BLUE); Board[ny][x] == '.'; ny++);
        if (Board[ny][x] == 'O'){
            RedinHole = true;
            return;
        }
        Board[--ny][x] = 'R';
        Red.first = ny;
    }
    else if (Color == BLUE){
        int x = Blue.second;
        int y = Blue.first;
        int ny;
        Board[y][x] = '.';
        for (ny = y; Board[ny][x] == '.'; ny++);
        if (Board[ny][x] == 'O'){
            BlueinHole = true;
            return;
        }
        Board[--ny][x] = 'B';
        Blue.first = ny;
    }
    
    return;
}

void move_left(int Color){
    if (Color == RED){
        int x = Red.second;
        int y = Red.first;
        int nx;
        Board[y][x] = '.';
        for (nx = x; Board[y][nx] == '.'; nx--);
        if (Board[y][nx] == 'B')
            for (move_left(BLUE); Board[y][nx] == '.'; nx--);
        if (Board[y][nx] == 'O'){
            RedinHole = true;
            return;
        }
        Board[y][++nx] = 'R';
        Red.second = nx;
    }
    else if (Color == BLUE){
        int x = Blue.second;
        int y = Blue.first;
        int nx;
        Board[y][x] = '.';
        for (nx = x; Board[y][nx] == '.'; nx--);
        if (Board[y][nx] == 'O'){
            BlueinHole = true;
            return;
        }
        Board[y][++nx] = 'B';
        Blue.second = nx;
    }
    
    return;
}

void move_right(int Color){
    if (Color == RED){
        int x = Red.second;
        int y = Red.first;
        int nx;
        Board[y][x] = '.';
        for (nx = x; Board[y][nx] == '.'; nx++);
        if (Board[y][nx] == 'B')
            for (move_right(BLUE); Board[y][nx] == '.'; nx++);
        if (Board[y][nx] == 'O'){
            RedinHole = true;
            return;
        }
        Board[y][--nx] = 'R';
        Red.second = nx;
    }
    else if (Color == BLUE){
        int x = Blue.second;
        int y = Blue.first;
        int nx;
        Board[y][x] = '.';
        for (nx = x; Board[y][nx] == '.'; nx++);
        if (Board[y][nx] == 'O'){
            BlueinHole = true;
            return;
        }
        Board[y][--nx] = 'B';
        Blue.second = nx;
    }
    
    return;
}

void BruteForce(int Direction, int Depth){
    pair<int, int> RedBackup = {Red.first, Red.second};
    pair<int, int> BlueBackup = {Blue.first, Blue.second};
    
    BlueinHole = false;
    RedinHole = false;
    switch (Direction){
    case U:
        move_up(RED);
        move_up(BLUE);
        break;
    case D:
        move_down(RED);
        move_down(BLUE);
        break;
    case L:
        move_left(RED);
        move_left(BLUE);
        break;
    case R:
        move_right(RED);
        move_right(BLUE);
        break;
    default:
        break;
    }
    
    if (RedinHole && !BlueinHole){
        if (MinDepth > Depth)
            MinDepth = Depth;
    }
    else if (!RedinHole && !BlueinHole){
        if (Depth < MAXCOUNT && Depth < MinDepth){
            for (int i = 0; i < 4; i++){
                BruteForce(Dir[i], Depth + 1);
            }
        }
    }
    Board[Red.first][Red.second] = '.';
    Board[RedBackup.first][RedBackup.second] = 'R';
    Board[Blue.first][Blue.second] = '.';
    Board[BlueBackup.first][BlueBackup.second] = 'B';
    Red.first = RedBackup.first;
    Red.second = RedBackup.second;
    Blue.first = BlueBackup.first;
    Blue.second = BlueBackup.second;
    
    return;
}

void solve(){
    BruteForce(-1, 0);
    Answer = MinDepth;
    if (Answer == 100)
        Answer = -1;
    
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
    
    input();
    solve();
    print_answer();
    
    return 0;
}