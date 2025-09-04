#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n;
    int A[4000], B[4000], C[4000], D[4000];
    vector<long long> SumCD;
    long long Answer = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            SumCD.push_back(C[i] + D[j]);
            
    sort(SumCD.begin(), SumCD.end());
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            auto EqualRange = equal_range(SumCD.begin(), SumCD.end(), -(A[i] + B[j]));
            Answer += distance(EqualRange.first, EqualRange.second);
        }
    }
    
    cout << Answer;
    return 0;
}