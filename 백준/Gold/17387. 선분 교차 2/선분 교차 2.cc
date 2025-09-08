#include <iostream>
using namespace std;

struct Dot{
    double x;
    double y;
};

Dot A, B, C, D;

void input(){
    cin >> A.x >> A.y >> B.x >> B.y;
    cin >> C.x >> C.y >> D.x >> D.y;
    return;
}

void swap(double& a, double& b){
    double temp = a;
    a = b;
    b = temp;
    return;
}

int sgn(double A){
    if (A == 0)
        return 0;
    return A > 0 ? 1 : -1;
}

int cross_product(const Dot& D1, const Dot& D2, const Dot& T){
    Dot P, Q;
    double Result;
    P.x = D2.x - D1.x;
    P.y = D2.y - D1.y;
    Q.x = T.x - D1.x;
    Q.y = T.y - D1.y;
    Result = P.x*Q.y - Q.x*P.y;
    return sgn(Result);
}

int OppositeTest(const Dot& D1, const Dot& D2, const Dot& T1, const Dot& T2){
    int CrossProduct1 = cross_product(D1, D2, T1);
    int CrossProduct2 = cross_product(D1, D2, T2);
    
    if (CrossProduct1 == 0 && CrossProduct2 == 0)
        return 0;
    if (CrossProduct1 == 0 || CrossProduct2 == 0)
        return -1;
    return CrossProduct1*CrossProduct2;
}

bool isOverlapping(){
    double p1, p2, p3, p4;
    if (A.x != B.x){
        p1 = A.x;
        p2 = B.x;
        p3 = C.x;
        p4 = D.x;
    }
    else{
        p1 = A.y;
        p2 = B.y;
        p3 = C.y;
        p4 = D.y;
    }
    
    
    if (p1 > p2)
        swap(p1, p2);
    if (p3 > p4)
        swap(p3, p4);
    return !(p2 < p3 || p4 < p1);
}

bool isCross(){
    int Test1 = OppositeTest(A, B, C, D);
    int Test2 = OppositeTest(C, D, A, B);
    
    if (Test1 == 0)
        return isOverlapping();
    if (Test1 == -1 && Test2 == -1)
        return true;
    return false;
}

void print_answer(){
    if (isCross())
        cout << 1;
    else
        cout << 0;
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    input();
    print_answer();
    
    return 0;
}