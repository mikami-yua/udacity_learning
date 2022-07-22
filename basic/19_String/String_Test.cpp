#include <iostream>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::istringstream;

void istringstream_test(){
    cout<<__func__<<"\n";//__func__显示当前函数的name

    string a("1 2 3");
    istringstream my_stream(a);

    int n;
    my_stream>>n;
    cout<<n<<"\n";//1
}

void use_isstringstream_as_boolen_read_all(){
    cout << __func__<< "\n";

    string a("1 2 3");

    istringstream my_stream(a);

    int n;
    //测试流是否成功并打印结果
    while (my_stream)
    {
        my_stream>>n;
        if (my_stream)
        {
            cout << "That stream was successful: " << n << "\n";
        }
        else {
            cout << "That stream was NOT successful!" << "\n";            
        }
    }
    /*That stream was successful: 1
    That stream was successful: 2
    That stream was successful: 3
    That stream was NOT successful!*/

}

void common_way_to_use_istringstream_in_while(){
    cout << __func__<< "\n";

    istringstream myreader("1 2 3");
    int n;
    while(myreader>>n){
        cout << "read: "<< n << "\n";
    }
    cout << "The stream has failed or ended." << "\n";
    /*
    read: 1
    read: 2
    read: 3
    The stream has failed or ended.
    */
}

void string_with_MIX_types_not_space(){
    cout << __func__<< "\n";

    string b("1,2,3,4,6q7p8o9");

    istringstream mixstring(b);

    //need two type of tmp value
    char c;
    int n;

    while(mixstring >> n >> c){
        cout << "read int: "<< n << ", read char: " << c << "\n";
    }
    cout << "The stream has failed or ended." << "\n";

    /*
    read int: 1, read char: ,
    read int: 2, read char: ,
    read int: 3, read char: ,
    read int: 4, read char: ,
    read int: 6, read char: q
    read int: 7, read char: p
    read int: 8, read char: o
    The stream has failed or ended.
    */
   /*
   数字9未被打印，是因为mixstring >> n >> c
   tried to stream an int followed by a char
   因为9之后没有char，不符合while的条件
   */

}

int main(){
    //stream with all INT type
    istringstream_test();
    use_isstringstream_as_boolen_read_all();
    common_way_to_use_istringstream_in_while();

    //stream with MIX type
    //the INT spreated by only one char not space
    string_with_MIX_types_not_space();
}