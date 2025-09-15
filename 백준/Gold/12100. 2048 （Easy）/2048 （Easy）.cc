#include <iostream>
using namespace std;

#define MAXCOUNT 5

enum{
    U, D, R, L
};

int N;
int Board[20][20];
int Answer;
int GlobalMax;
int LocalMax;
const int Dir[4] = {U, D, L, R};


void input(){
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            cin >> Board[i][j];
            if (Board[i][j] > LocalMax)
                LocalMax = Board[i][j];
        }
}

void move_up(){
    for (int i = 0; i < N; i++){
        int Destination = 0;
        for (int j = 0; j < N; j++){
            if (Board[j][i] != 0){
                for (int k = j + 1; k < N; k++){
                    if (Board[k][i] != 0){
                        if (Board[k][i] == Board[j][i]){
                            Board[k][i] = 0;
                            Board[j][i] *= 2;
                        }
                        break;
                    }
                }
                Board[Destination][i] = Board[j][i];
                if (Destination != j)
                    Board[j][i] = 0;
                if (Board[Destination][i] > LocalMax)
                    LocalMax = Board[Destination][i];
                Destination++;
            }
        }
    }
}

void move_down(){
    for (int i = 0; i < N; i++){
        int Destination = N - 1;
        for (int j = N - 1; j >= 0; j--){
            if (Board[j][i] != 0){
                for (int k = j - 1; k >= 0; k--){
                    if (Board[k][i] != 0){
                        if (Board[k][i] == Board[j][i]){
                            Board[k][i] = 0;
                            Board[j][i] *= 2;
                        }
                        break;
                    }
                }
                Board[Destination][i] = Board[j][i];
                if (Destination != j)
                    Board[j][i] = 0;
                if (Board[Destination][i] > LocalMax)
                    LocalMax = Board[Destination][i];
                Destination--;
            }
        }
    }
}

void move_left(){
    for (int i = 0; i < N; i++){
        int Destination = 0;
        for (int j = 0; j < N; j++){
            if (Board[i][j] != 0){
                for (int k = j + 1; k < N; k++){
                    if (Board[i][k] != 0){
                        if (Board[i][k] == Board[i][j]){
                            Board[i][k] = 0;
                            Board[i][j] *= 2;
                        }
                        break;
                    }
                }
                Board[i][Destination] = Board[i][j];
                if (Destination != j)
                    Board[i][j] = 0;
                if (Board[i][Destination] > LocalMax)
                    LocalMax = Board[i][Destination];
                Destination++;
            }
        }
    }
}

void move_right(){
    for (int i = 0; i < N; i++){
        int Destination = N - 1;
        for (int j = N - 1; j >= 0; j--){
            if (Board[i][j] != 0){
                for (int k = j - 1; k >= 0; k--){
                    if (Board[i][k] != 0){
                        if (Board[i][k] == Board[i][j]){
                            Board[i][k] = 0;
                            Board[i][j] *= 2;
                        }
                        break;
                    }
                }
                Board[i][Destination] = Board[i][j];
                if (Destination != j)
                    Board[i][j] = 0;
                if (Board[i][Destination] > LocalMax)
                    LocalMax = Board[i][Destination];
                Destination--;
            }
        }
    }
}

int BruteForce(int Direction, int depth){
    int Backup[20][20];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Backup[i][j] = Board[i][j];
    switch (Direction){
    case U:
        LocalMax = 0;
        move_up();
        break;
    case D:
        LocalMax = 0;
        move_down();
        break;
    case L:
        LocalMax = 0;
        move_left();
        break;
    case R:
        LocalMax = 0;
        move_right();
        break;
    default:
        break;
    }
    
    int Ret;
    if (depth == 5)
        Ret = LocalMax;
    else{
        if (GlobalMax >= (1 << (5-depth)) * LocalMax)
            Ret = 0;
        else{
            Ret = GlobalMax;
            for (int i = 0; i < 4; i++)
                Ret = max(Ret, BruteForce(Dir[i], depth + 1));
            if (Ret > GlobalMax)
                GlobalMax = Ret;
        }
    }
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            Board[i][j] = Backup[i][j];
            
    return Ret;
}

void solve(){
    BruteForce(-1, 0);
    Answer = GlobalMax;
    
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