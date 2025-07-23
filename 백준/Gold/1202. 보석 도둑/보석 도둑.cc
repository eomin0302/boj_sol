#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N, K, MaxMi = 0;
    vector<pair<int, int>> Juwel;
    vector<int> Bag;
    cin >> N >> K;
    for (int i = 0; i < N; i++){
        int Mi, Vi;
        cin >> Mi >> Vi;
        Juwel.push_back({Mi, Vi});
        if (Mi > MaxMi)
            MaxMi = Mi;
    }
    for (int i = 0; i < K; i++){
        int Ci;
        cin >> Ci;
        Bag.push_back(Ci);
    }
    sort(Bag.begin(), Bag.end());
    sort(Juwel.begin(), Juwel.end());
    long long Ans = 0;
    int Index = 0;
    vector<int> H;
    for (int i = 0; i < Bag.size(); i++){
        while(Index < Juwel.size() && Bag[i] >= Juwel[Index].first){
            H.push_back(Juwel[Index].second);
            push_heap(H.begin(), H.end());
            Index++;
        }
        if (!H.empty()){
            Ans += H[0];
            pop_heap(H.begin(), H.end());
            H.pop_back();
        }
    }
    cout << Ans;
    return 0;
}