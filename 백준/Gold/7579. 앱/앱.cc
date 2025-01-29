#include <iostream>
#include <algorithm>
using namespace std;

#define MAX(a, b) (a > b ? a : b)

int N, M;
pair<int, int> A[101];
int arr[102][10002] = {};
int tot = 0;
int MIN = 10e9;
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++){
	    cin >> A[i].first;
	}
	for (int i = 1; i <= N; i++){
	    cin >> A[i].second;
	    tot += A[i].second;
	}
	
	for (int i = 2; i <= N + 1; i++){
	    for (int j = 2; j <= tot + 2; j++){
	        if (A[i - 1].second > j - 2)
	            arr[i][j] = MAX(arr[i][j - 1], arr[i - 1][j]);
	        else
	            arr[i][j] = MAX(arr[i - 1][j - A[i - 1].second] + A[i - 1].first, arr[i - 1][j]);
	        if (arr[i][j] >= M){
	            MIN = MIN < j - 2 ? MIN : j - 2;
	        }
	    }
	}
	cout << MIN;
	return 0;
}