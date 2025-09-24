#include <iostream>
#include <vector>
using namespace std;

struct Count{
    long long n[10];
    Count(long long a, long long b, long long c, long long d, long long e, long long f, long long g, long long h,long long i, long long j){
        n[0] = a;
        n[1] = b;
        n[2] = c;
        n[3] = d;
        n[4] = e;
        n[5] = f;
        n[6] = g;
        n[7] = h;
        n[8] = i;
        n[9] = j;
    }
};

int N;
int Diff[10] = {0, 0, 9, 108, 1107, 11106, 111105, 1111104, 11111103, 111111102};
long long Answer[10];
vector<Count> EachNum;

void input(){
	cin >> N;
	
	return;
}

void init_eachnum(){
    EachNum.push_back(Count(0, 0, 0, 0, 0, 0, 0, 0, 0, 0));
    EachNum.push_back(Count(0, 1, 1, 1, 1, 1, 1, 1, 1, 1));
    EachNum.push_back(Count(18, 20, 20, 20, 20, 20, 20, 20, 20, 20));
    EachNum.push_back(Count(297, 300, 300, 300, 300, 300, 300, 300, 300, 300));
    EachNum.push_back(Count(3996, 4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000, 4000));
    EachNum.push_back(Count(49995, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000, 50000));
    EachNum.push_back(Count(599994, 600000, 600000, 600000, 600000, 600000, 600000, 600000, 600000, 600000));
    EachNum.push_back(Count(6999993, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000, 7000000));
    EachNum.push_back(Count(79999992, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000, 80000000));
    EachNum.push_back(Count(899999991, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000, 900000000));
    
    return;
}

void solve(){
    int Unit = 1000000000;
    int Digit = 10;
    int DigitOrigin;
    int Head;
    while (Unit > N){
        Unit /= 10;
        Digit--;
    }
    DigitOrigin = Digit;
    
    Answer[0] -= Diff[Digit - 1];
    
    while(N){
        Head = N / Unit;
        while(N >= Unit){
            for (int i = 0; i < 10; i++){
                Answer[i] += EachNum[Digit - 1].n[i];
            }
            
            if (Unit >= 10){
                if (Digit != DigitOrigin || N / Unit != 1){
                    Answer[N / Unit - 1] += Unit;
                    if (N / Unit - 1 == 0)
                        Answer[0]--;
                }
                Answer[0] += Digit - 1;
            }
            else
                Answer[N / Unit]++;
                
                
            N -= Unit;
            
            if (N / Unit == 0 && Unit >= 10)
                Answer[Head] += N + 1;
        }
        
        if (Head == 0)
            Answer[0] += N;
        
        Unit /= 10;
        Digit--;
    }
    
    return;
}

void print_answer(){
    for (int i = 0; i < 10; i++){
        cout << Answer[i] << ' ';
    }
    
    return;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    input();
    init_eachnum();
    solve();
    print_answer();
    
    return 0;
}