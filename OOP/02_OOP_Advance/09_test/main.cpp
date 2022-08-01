#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cout;

// TODO: Add the correct template specification
template<typename KeyType,typename ValueType>
class Mapping{
public:
    Mapping(KeyType k,ValueType v):key(k),value(v){}
    string Print() const{
        std::ostringstream stream;
        stream<<key<<": "<<value;
        return stream.str();
    }

    KeyType key;
    ValueType value;
};

int main(){
    Mapping<string,int> mapping("age",20);
    cout<<mapping.Print()<<"\n";
}