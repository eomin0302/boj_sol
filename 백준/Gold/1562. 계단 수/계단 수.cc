#include <iostream>
using namespace std;

#define MOD 1000000000

int N;
long long Answer;
long long DP[10][1<<10];
long long nDP[10][1<<10];

void input(){
    cin >> N;
    
    return;
}

void init_DP(){
    for (int i = 1; i <= 9; i++)
        DP[i][1<<i] = 1;
        
    return;
}

void reset_nDP(){
    for (int i = 0; i <= 9; i++)
        for (int j = 1; j < (1<<10); j++)
            nDP[i][j] = 0;
            
}

void nDP_to_DP(){
    for (int i = 0; i <= 9; i++)
        for (int j = 1; j < (1<<10); j++)
            DP[i][j] = nDP[i][j];
            
    return;
}

void fill_nDP(){
    reset_nDP();
    for (int i = 0; i <= 9; i++){
        for (int Mask = 1; Mask < (1<<10); Mask++){
            if (i != 0){
                nDP[i - 1][Mask | (1<<(i - 1))] += DP[i][Mask]; 
                nDP[i - 1][Mask | (1<<(i - 1))] %= MOD;
            }
            if (i != 9){
                nDP[i + 1][Mask | (1<<(i + 1))] += DP[i][Mask];
                nDP[i + 1][Mask | (1<<(i + 1))] %= MOD;
            }
        }
    }
    nDP_to_DP();
    
    return;
}

void fill_DP_N(){
    init_DP();
    for (int i = 2; i <= N; i++)
        fill_nDP();
        
    return;
}

void calculate_answer(){
    long long Target = (1<<10) - 1;
    for (int i = 0; i <= 9; i++){
        Answer += DP[i][Target];
        Answer %= MOD;
    }
    
    return;
}

void print_answer(){
    calculate_answer();
    cout << Answer;
    
    return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    input();
    fill_DP_N();
    print_answer();
    
    return 0;
}