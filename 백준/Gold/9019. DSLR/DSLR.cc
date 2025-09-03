#include <iostream>
using namespace std;

int D(int n){
    int Ret = 2*n;
    if (Ret > 9999)
        Ret -= 10000;
    return Ret;
}

int S(int n){
    int Ret = n - 1;
    if (Ret < 0)
        Ret = 9999;
    return Ret;
}

int L(int n){
    int d[4];
    for(int i = 0; i < 4; i++){
        d[i] = n % 10;
        n /= 10;
    }
    return d[3] + 10*d[0] + 100*d[1] + 1000*d[2]; 
}

int R(int n){
    int d[4];
    for(int i = 0; i < 4; i++){
        d[i] = n % 10;
        n /= 10;
    }
    return d[1] + 10*d[2] + 100*d[3] + 1000*d[0]; 
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int T;
    cin >> T;
    
    while(T--){
        int A, B;
        int Bfs[200000][3] = {};
        bool Visited[10000] = {};
        int s = 0, e = 0;
        cin >> A >> B;
        Bfs[e][0] = A;
	    Bfs[e][1] = 0;
	    Bfs[e++][2] = 0;
        
        while(s < e){
            int CurNum = Bfs[s++][0];
            
            int NextNum = D(CurNum);
            if (!Visited[NextNum]){
                Visited[NextNum] = true;
                Bfs[e][0] = NextNum;
                Bfs[e][1] = s - 1;
                Bfs[e][2] = 'D';
                if (Bfs[e++][0] == B)
                    break;
            }
            
            NextNum = S(CurNum);
            if (!Visited[NextNum]){
                Visited[NextNum] = true;
                Bfs[e][0] = NextNum;
                Bfs[e][1] = s - 1;
                Bfs[e][2] = 'S';
                if (Bfs[e++][0] == B)
                    break;
            }
            
            NextNum = L(CurNum);
            if (!Visited[NextNum]){
                Visited[NextNum] = true;
                Bfs[e][0] = NextNum;
                Bfs[e][1] = s - 1;
                Bfs[e][2] = 'L';
                if (Bfs[e++][0] == B)
                    break;
            }
            
            NextNum = R(CurNum);
            if (!Visited[NextNum]){
                Visited[NextNum] = true;
                Bfs[e][0] = NextNum;
                Bfs[e][1] = s - 1;
                Bfs[e][2] = 'R';
                if (Bfs[e++][0] == B)
                    break;
            }
        }
        char Ans[10000];
        int Length = 0;
        int Tail = e - 1;
        while(Bfs[Tail][2] != 0){
            Ans[Length++] = Bfs[Tail][2];
            Tail = Bfs[Tail][1];
        }
        
        for(int i = Length - 1; i >= 0; i--){
            cout << Ans[i];
        }
        cout << '\n';
    }
    
    
    return 0;
}