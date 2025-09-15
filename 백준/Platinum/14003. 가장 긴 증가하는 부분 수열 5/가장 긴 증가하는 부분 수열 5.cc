#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define LENGTH 1000001

int N;
pair<int, int> NumParent[1000001];
int LastNum[LENGTH];
int LastIdx[LENGTH];
int Longest = 0;
vector<int> Answer;

void input(){
	cin >> N;
	
	return;
}

void fill_memo(){
    for (int i = 1; i <= N; i++){
        int CurNum;
        cin >> CurNum;
        NumParent[i].first = CurNum;
        NumParent[i].second = i;
        auto iter = lower_bound(LastNum + 1, LastNum + 1 + Longest, CurNum);
        if (iter == LastNum + 1 + Longest){
            if (Longest > 0)
                NumParent[i].second = LastIdx[Longest];
            LastNum[++Longest] = CurNum;
            LastIdx[Longest] = i;
        }
        else{
            int prevIdx = iter - LastNum;
            NumParent[i].second = LastIdx[prevIdx - 1];
            LastNum[prevIdx] = CurNum;
            LastIdx[prevIdx] = i;
        }
    }
    
    return;
    
}

void get_answer(){
    int idx = LastIdx[Longest];
    for (int i = 0; i < Longest; i++){
        Answer.push_back(NumParent[idx].first);
        idx = NumParent[idx].second;
    }
    reverse(Answer.begin(), Answer.end());
}

void solve(){
    fill_memo();
    get_answer();
    
    return;
}

void print_answer(){
    cout << Longest << '\n';
    for (auto ans = Answer.begin(); ans < Answer.end(); ans++)
        cout << *ans << ' ';
    
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