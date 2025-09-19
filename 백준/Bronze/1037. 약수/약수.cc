#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int Min = 10000000;
    int Max = 0;
    int N, Num;
    
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> Num;
        Min = Min < Num ? Min : Num;
        Max = Max > Num ? Max : Num;
    }
    cout << Min * Max;
    
    return 0;
}