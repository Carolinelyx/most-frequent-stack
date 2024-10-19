#include <iostream>
#include <stack>
#include <map>
using namespace std;

class FreqStack {
public:
    map<int,int> m; //map the frequency of each number
    map<int,stack<int>> mapf; //map the element in the map based on their frequency
    int Maxf = 0;

    FreqStack() {}
    void push(int val) {
        int f = m[val]++;
        if (f > Maxf) {
            Maxf = f;
        }
        mapf[f].push(val);
    }
    int pop() {
        int val = mapf[Maxf].top();
        if(!mapf[Maxf].empty()) {
            mapf[Maxf].pop();
        }
        if (mapf[Maxf].empty()) {
            Maxf--;
        }
        return val;
    }
};

int main() {
    FreqStack fstack;
    cout << fstack.pop() << endl;
    return 0;
}
