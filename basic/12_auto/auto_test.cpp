#include <iostream>
#include <vector>
using std::vector;
using std::cout;

int main(){
    auto i=5;
    auto v_6={1,2,3,4,5,6};
    cout << "Variables declared and initialized without explicitly stating type!" << "\n";

    for (auto i : v_6)
    {
        cout<<i<<" ";
    }
    cout<<"\n";

}