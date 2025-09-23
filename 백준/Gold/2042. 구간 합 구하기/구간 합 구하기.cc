#include <iostream>
using namespace std;

enum{
    CHANGE = 1, SUM
};

int N, M, K;
long long Num[1000001];
long long SegTree[2097153];

void input(){
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	    cin >> Num[i];
	
	return;
}

void make_segtree(int idx, int s, int e){
    if (s == e){
        SegTree[idx] = Num[s];
        return;
    }
    
    int mid = (s + e) / 2;
    make_segtree(2*idx, s, mid);
    make_segtree(2*idx + 1, mid + 1, e);
    SegTree[idx] = SegTree[2*idx] + SegTree[2*idx + 1];
    
    return;
}

void change_num(int NumIdx, long long Diff, int TreeIdx, int s, int e){
    int mid = (s + e) / 2;
    SegTree[TreeIdx] += Diff;
    if (s == e)
        return;
        
    if (NumIdx > mid)
        change_num(NumIdx, Diff, 2*TreeIdx + 1, mid + 1, e);
    else
        change_num(NumIdx, Diff, 2*TreeIdx, s, mid);
        
    return;
}

long long get_sum(int l, int r, int idx, int s, int e){
    int mid = (s + e) / 2;
    
    if (r < s || l > e)
        return 0;
    
    if (l <= s && r >= e)
        return SegTree[idx];
    
    return get_sum(l, r, 2*idx, s, mid) + get_sum(l, r, 2*idx + 1, mid + 1, e);
}

void solve(){
    long long a, b, c;
    make_segtree(1, 1, N);
    while (K){
        cin >> a >> b >> c;
        if (a == CHANGE){
            long long Diff = c - Num[b];
            Num[b] = c;
            change_num(b, Diff, 1, 1, N);
        }
        else if (a == SUM){
            cout << get_sum(b, c, 1, 1, N) << '\n';
            K--;
        }
    }
    
    return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    input();
    solve();
    
    return 0;
}