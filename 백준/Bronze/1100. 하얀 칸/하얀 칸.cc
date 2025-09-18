#include <iostream>
using namespace std;

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    bool isWhite = true;
    int Count = 0;
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char F;
            cin >> F;
            if (F == 'F' && isWhite)
                Count++;
            isWhite = !isWhite;
        }
        isWhite = !isWhite;
    }
    
    cout << Count;
    return 0;
}