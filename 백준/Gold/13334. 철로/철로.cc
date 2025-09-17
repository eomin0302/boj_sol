#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct rail{
    int s;
    int e;
    int l;
};

int N, D;
vector<rail> L;
int MaxCount;
int Answer;

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
    
    return;
}

void input(){
	cin >> N;
	for (int i = 0; i < N; i++){
	    rail L1;
	    cin >> L1.s >> L1.e;
	    if (L1.s > L1.e)
	        swap(L1.s, L1.e);
	    L1.l = L1.e - L1.s;
	    L.push_back(L1);
	}
	cin >> D;
	
	return;
}

bool compare_length(const rail &a, const rail &b){
    return a.l < b.l;
}

bool compare_e(const rail &a, const rail &b){
    return a.e < b.e;
}

void sort_L(){
    sort(L.begin(), L.end(), compare_length);
    auto Iter = L.end() - 1;
    while ((*Iter).l > D){
        Iter--;
        L.pop_back();
    }
    sort(L.begin(), L.end(), compare_e);
    
    return;
}

void get_maxcount(){
    priority_queue<int, vector<int>, greater<int>> PQ;
    for (auto iter = L.begin(); iter < L.end(); iter++){
        int WindowStart = (*iter).e - D;
        PQ.push((*iter).s);
        while (!PQ.empty()){
            if (WindowStart > PQ.top())
                PQ.pop();
            else
                break;
        }
        if (PQ.size() > MaxCount)
            MaxCount = PQ.size();
    }
    
    return ;
}

void solve(){
    sort_L();
    get_maxcount();
    Answer = MaxCount;
    
    return;
}

void print_answer(){
    cout << Answer;
    
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