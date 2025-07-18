#include <iostream>
using namespace std;

int Matrix[500][2];
int Dp[500][500];

int mul_mat(int s, int l, int e){
    return Dp[s][s + l] + Matrix[s][0] * Matrix[s + l][1] * Matrix[e][1] + Dp[s + l + 1][e];
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> Matrix[i][0];
        cin >> Matrix[i][1];
    }
    for (int L = 1; L < N; L++){
        for (int i = 0; i + L < N; i++){
            Dp[i][i + L] = mul_mat(i, 0, i + L);
            for (int k = 1; k < L; k++){
                Dp[i][i + L] = min(mul_mat(i, k, i + L), Dp[i][i + L]);
            }
        }
    }
    cout << Dp[0][N - 1];
    return 0;
}