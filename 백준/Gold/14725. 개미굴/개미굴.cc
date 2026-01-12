#include <iostream>
#include <algorithm>
#include <vector>
#include <stdexcept>
using namespace std;

void fastIO();
void inputAndMakeTrie();
void inputNumOfInfo();
void inputInfo();
void makeTrie();
void printAnswer();

class ChildNotFoundException : public runtime_error{
public:
    explicit ChildNotFoundException() : runtime_error("Child Not Found") {}
};

struct FOOD{
    int numOfFood;
    string name[15];
};

class NODE{
private:
    vector<NODE*> sortedChild;
    string foodName;
    int depth;

    void pushNewChild(string childFoodName){
        NODE* child = new NODE(childFoodName, this->depth + 1);
        sortedChild.push_back(child);
    }

    void sortChild(){
        sort(this->sortedChild.begin(), this->sortedChild.end(), this->compare);
    }

    static bool compare(const NODE* a, const NODE* b){
        return a->foodName < b->foodName;
    }

    static bool compareWithString(const NODE* a, const string& b){
        return a->foodName < b;
    }

    bool isEqual(vector<NODE*>::iterator searchedNode, const string& targetName){
        if (searchedNode == sortedChild.end())
            return false;
        return (*searchedNode)->foodName == targetName;
    }

    bool isHead(){
        return depth == 0;
    }

    void printHyphenAndName(){
        if (!isHead()){
            this->printHyphen();
            this->printName();
        }
    }

    void printHyphen(){
        for(int i = 0; i < this->depth - 1; i++)
            cout << "--";
    }

    void printName(){
        cout << this->foodName << '\n';
    }

public:
    NODE(string foodName, int depth){
        this->foodName = foodName;
        this->depth = depth;
    }

    void pushChild(string childFoodName){
        this->pushNewChild(childFoodName);
        this->sortChild();
    }

    NODE* findChild(string childFoodName){
        auto searched = lower_bound(sortedChild.begin(), sortedChild.end(), childFoodName, compareWithString);
        if (isEqual(searched, childFoodName))
            return *searched;
        else
            throw ChildNotFoundException();
    }

    void recursivePrint(){
        this->printHyphenAndName();
        for(auto iter = this->sortedChild.begin(); iter < this->sortedChild.end(); iter++)
            (*iter)->recursivePrint();
    }
};

class TRIE{
private:
    NODE* head;
    FOOD foods;
    int curFoodIdx;

    void recursivePush(NODE* curNode){
        string curFood = this->foods.name[curFoodIdx++];
        NODE* nextNode;
        try{
            nextNode = curNode->findChild(curFood);
        }
        catch(ChildNotFoundException& e){
            curNode->pushChild(curFood);
            nextNode = curNode->findChild(curFood);
        }
        if(!isEnd())
            this->recursivePush(nextNode);
    }

    bool isEnd(){
        return curFoodIdx == foods.numOfFood;
    }

public:
    TRIE(){
        head = new NODE("HEAD", 0);
    }

    void setFoods(FOOD foods){
        this->curFoodIdx = 0;
        this->foods.numOfFood = foods.numOfFood;
        for (int i = 0; i < foods.numOfFood; i++)
            this->foods.name[i] = foods.name[i]; 
    }

    void pushFoods(){
        recursivePush(head);
    }

    void printWithPreorder(){
        this->head->recursivePrint();
    }
};


TRIE anthill;
int numOfInfo;
FOOD foods;

int main(void){
    fastIO();
    inputAndMakeTrie();
    printAnswer();
    return 0;
}

void fastIO(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void inputAndMakeTrie(){
    inputNumOfInfo();
    for (int i = 0; i < numOfInfo; i++){
        inputInfo();
        makeTrie();
    }
}

void inputNumOfInfo(){
    cin >> numOfInfo;
}

void inputInfo(){
    cin >> foods.numOfFood;
    for (int i = 0; i < foods.numOfFood; i++){
        cin >> foods.name[i];
    }
}

void makeTrie(){
    anthill.setFoods(foods);
    anthill.pushFoods();
}

void printAnswer(){
    anthill.printWithPreorder();
}