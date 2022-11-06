#include <iostream>
#include <cstdlib>
#include <set>
#include <algorithm>

using namespace std;

class test{
    private:
    int x;
    int y;

    public:
    test(int a,int b){
        x = a;
        y = b;
    }

    bool operator<(const test& rhs) const{
        if(x == rhs.x){
            return y < rhs.y;
        } else{
            return x < rhs.x;
        }
    }

    friend ostream& operator<<(ostream& os, const test& t){
        os << "(" << t.x << ","<< t.y <<")";
        return os;
    }
};

int main(){
    test t1(3,3);
    test t2(3,4);
    test t3(4,2);
    test t4 (1, 3);
    test t5(5, 6);
    test t6(5, 7);

    set<test> coords;
    coords.insert(t2);
    coords.insert(t3);
    coords.insert(t1);
    coords.insert(t6);
    coords.insert(t4);
    coords.insert(t5);

    for(auto t: coords){
        cout << t << endl;
    }
    
    return 0;

}