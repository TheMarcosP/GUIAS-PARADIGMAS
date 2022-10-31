#include <vector>
#include <iostream>
#include <cstdlib>
#include <cassert>

//transaction header file
//create a transaction class with amount, date, description 
class transaction {
    private:
        double amount;
        std::string date;
        std::string description;
        bool credit;
    public:
        transaction(double amount, bool credit, std::string date, std::string description);
        double get_amount();
        std::string get_date();
        std::string get_description();
        bool isCredit();
};

//transaction cpp file
transaction::transaction(double amount,  bool credit, std::string date, std::string description){
    this->amount = amount;
    this->date = date;
    this->description = description;
    this->credit = credit;
}

double transaction::get_amount(){
    return amount;
}

std::string transaction::get_date(){
    return date;
}

std::string transaction::get_description(){
    return description;
}

bool transaction::isCredit(){
    return this->credit;
}
//account header file
class account{
private:
    std::vector<transaction*> transactions_history;
    std::string _name;
public:
    account(std::string name);
    ~account();
    float get_balance();
    std::string get_name();
    void deposit(float amount);
    void withdraw(float amount);
    void full_report();
    int get_size_transaction();
};


//account cpp file
account::account(std::string name){
    this->_name = name;
};


float account::get_balance(){
    float balance = 0;
    for (auto& trans : transactions_history){
        if ( trans->isCredit() ){
        balance +=trans->get_amount();
        }
        else{
            balance -= trans->get_amount();
        }
    }
    return balance;
};

void account::deposit(float amount){
    if (amount > 0){
        this->transactions_history.emplace_back( new transaction(amount,true, "today", "deposit") );
    }else{
        std::cout << "Invalid amount" << std::endl;
    }

};

void account::withdraw(float amount){
    if (get_balance() >= amount and amount > 0){
        this->transactions_history.emplace_back( new transaction(amount,false, "today", "withdraw") );
    }
    else{
        std::cerr << "invalid amount" << std::endl;
        //assert(false);
    }
};

int account::get_size_transaction(){
    return this->transactions_history.size();
};

void account::full_report(){
    std::cout << "\nAccount: " << this->_name << "\nBalance: " << get_balance() << std::endl;
    std::cout << "Transactions history: " << std::endl;
    for (auto& trans : transactions_history){
        std::cout << trans->get_amount() << " ";
    }
    std::cout << std::endl;
};


std::string account::get_name(){
    return this->_name;
};

account::~account(){
    std::cout << "Account " << this->_name << " destroyed" << std::endl;
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
    assert(a->get_size_transaction() == 3);
    //a->full_report();
    delete a;
    return 0;
}

// metodos solo si son necesarias
// variables aux innecesarias
// esconder la implementacion