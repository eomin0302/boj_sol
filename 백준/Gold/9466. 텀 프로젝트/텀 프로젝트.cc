#include <iostream>
using namespace std;

bool Visited[100001];
int Select[100001];
int Head[100001];
bool isCycle;
int Dup;
int N;
int Ans;

void dfs(int n, int head){
    if (Head[n] == head){
        if (Select[n] != n)
            isCycle = true;
        Dup = n;
        Ans--;
        return;
    }
    if (Visited[n])
        return;
    
    Visited[n] = true;
    if (head == -1)
        Head[n] = n;
    else
        Head[n] = head;
    
    dfs(Select[n], Head[n]);
    
    if (isCycle){
        if (n == Dup)
            isCycle = false;
        else
            Ans--;
    }
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	int T;
	cin >> T;
    while (T--){
        cin >> N;
        Ans = N;
        for (int i = 1; i <= N; i++){
            cin >> Select[i];
            Head[i] = -2;
            Visited[i] = false;
        }
        for (int i = 1; i <= N; i++){
            Dup = -1;
            isCycle = false;
            dfs(i, -1);
        }
        cout << Ans << '\n';
    }
	return 0;
}