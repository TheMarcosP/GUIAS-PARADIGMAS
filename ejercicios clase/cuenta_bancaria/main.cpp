#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

//header file
// create a transaction class with amount, date, description 




//header file
class account{
private:
    std::vector<float> transactions_history;
    std::string _name;
public:
    account(std::string name);
    ~account();
    float get_balance();
    std::string get_name();
    void deposit(float amount);
    void withdraw(float amount);
    void full_report();
    std::vector<float> get_transactions_history();
};


// cpp file
account::account(std::string name){
    this->_name = name;
};

account::~account(){
    std::cout << "Account " << this->_name << " destroyed" << std::endl;
};

float account::get_balance(){
    float balance = 0;
    for (auto& trans : transactions_history){
        balance +=trans;
    }
    return balance;
};

std::string account::get_name(){
    return this->_name;
};

void account::deposit(float amount){
    if (amount > 0){
        this->transactions_history.push_back(amount);
    }else{
        std::cout << "Invalid amount" << std::endl;
    }

};

void account::withdraw(float amount){
    if (get_balance() >= amount and amount > 0){
        this->transactions_history.emplace_back(-amount);
    }
    else{
        std::cerr << "invalid amount" << std::endl;
        //assert(false);
    }
};

void account::full_report(){
    std::cout << "\nAccount: " << this->_name << "\nBalance: " << get_balance() << std::endl;
    std::cout << "Transactions history: " << std::endl;
    for (auto& trans : transactions_history){
        std::cout << trans << " ";
    }
    std::cout << std::endl;
};

std::vector<float> account::get_transactions_history(){
    return this->transactions_history;
};

//main.cpp
int main(){
    account *a = new account("John");
    assert(a->get_balance() == 0);

    a->deposit(50);
    assert(a->get_balance() == 50);
    a->deposit(25);
    assert(a->get_balance() == 75);
    a->withdraw(50);
    assert(a->get_balance() == 25);
    a->withdraw(50);
    assert(a->get_balance() == 25);
    assert(a->get_transactions_history().size() == 3);
    a->full_report();
    delete a;
    return 0;
}