#include <iostream>
#include <string>
using std::string;
using std::cout;

class BankAccount{
public:
    void SetAccNumber(int a){this->accNumber=a;}
    void SetAccName(string a){this->accName=a;}
    void ModFunds(float f);

    int GetAccNumber(){return this->accNumber;}
    string GetAccName(){return this->accName;}
    float CheckBalance();


private:
    int accNumber=211;
    string accName;
    float balance{0};
};

//implement
void BankAccount::ModFunds(float f){
    this->balance+=f;
}

float BankAccount::CheckBalance(){
    return this->balance;
}

int main(){
    BankAccount b1;
    b1.SetAccNumber(3456);
    b1.SetAccName("Harshad");
    b1.ModFunds(5000);

    BankAccount b2;
    b2.SetAccNumber(9871);
    b2.SetAccName("Mehta");
    b2.ModFunds(-900);

    cout<<b1.GetAccName()<<" "<<b1.CheckBalance()<<"\n";
    cout<<b2.GetAccName()<<" "<<b2.CheckBalance()<<"\n";

    b1.ModFunds(8000.101);
    b2.ModFunds(100.999);

    cout<<b1.GetAccName()<<" "<<b1.CheckBalance()<<"\n";
    cout<<b2.GetAccName()<<" "<<b2.CheckBalance()<<"\n";
}