#include <iostream>
using namespace std;


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int C, N, MaxCount = 0;
    int Info[20][2];
    int Dp[1101] = {};
    cin >> C >> N;
    for (int i = 0; i < N; i++){
        cin >> Info[i][0] >> Info[i][1];
        if (Info[i][1] > MaxCount)
            MaxCount = Info[i][1];
    }
    for (int i = 1; i <= C + MaxCount; i++){
        int m = 1e9;
        for (int j = 0; j < N; j++){
            if(i - Info[j][1] >= 0)
                m = min(m, Dp[i - Info[j][1]] + Info[j][0]);
        }
        Dp[i] = m;
    }
    
    int Ans = 1e9;
    for (int i = C; i <= C + MaxCount; i++)
        Ans = min(Ans, Dp[i]);
    cout << Ans;
    return 0;
}