#include "vector_add_one.h"
int IncrementAndComputeVectorSum(vector<int> v){
    int total=0;
    //传入引用
    AddOneToEach(v);

    for(auto i:v){
        total+=i;
    }
    return total;
}