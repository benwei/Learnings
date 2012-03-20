#include <iostream>
using namespace std;

class B {
public:
   int value;
};

// origin sample start here
class A {
public:
A(int sz) { sz_ = sz; v = new B[sz_]; }
~A() { delete v; }
// ...
private:
// // ...
B * v;
int sz_;
};
// origin sample end

int main()
{
    A *a = new A(333);
    cout << sizeof(a) << endl;
    return 0;
}
