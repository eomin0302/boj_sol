#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct node{
    int Early;
    int notEarly;
    int Parent;
    vector<int> Edges;
};

int N;
int Answer;
bool Visited[1000001];
node Nodes[1000001];


void input(){
	cin >> N;
	for (int i = 0; i < N - 1; i++){
	    int v1, v2;
	    cin >> v1 >> v2;
	    Nodes[v1].Edges.push_back(v2);
	    Nodes[v2].Edges.push_back(v1);
	}
	return;
}

void dfs(){
    stack<int> DFSStack;
    DFSStack.push(1);
    Visited[1] = true;
    while(!DFSStack.empty()){
        int CurNode = DFSStack.top();
        bool hasChild = false;
        
        for (int i = 0; i < Nodes[CurNode].Edges.size(); i++){
            int nNode = Nodes[CurNode].Edges[i];
            if (!Visited[nNode]){
                DFSStack.push(nNode);
                Visited[nNode] = true;
                hasChild = true;
                Nodes[nNode].Parent = CurNode;
            }
        }
        if (hasChild)
            continue;
        
        if (Nodes[CurNode].Edges.size() == 1 && Nodes[CurNode].Parent != 0){
            Nodes[CurNode].Early = 1;
            Nodes[CurNode].notEarly = 0;
        }
        else{
            for (int i = 0; i < Nodes[CurNode].Edges.size(); i++){
                int nNode = Nodes[CurNode].Edges[i];
                if (Nodes[CurNode].Parent == nNode)
                    continue;
                Nodes[CurNode].Early += min(Nodes[nNode].Early, Nodes[nNode].notEarly);
                Nodes[CurNode].notEarly += Nodes[nNode].Early;
            }
            Nodes[CurNode].Early++;
        }
    
        DFSStack.pop();
    }
    
    return;
}

void get_answer(){
    Answer = min(Nodes[1].Early, Nodes[1].notEarly);
    
    return;
}

void solve(){
    dfs();
    get_answer();
    
    
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