#include <cstdlib>
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// header
class Transaction {
  private:
    char kind; // ??? deberia poner const? esta variable no deberia cambiar nunca
    int amount;
    Transaction( char kind, int amount ); // !!!1
  public:
    static Transaction* Withdraw( int amount ) { return new Transaction( 'W', amount ); } // !!!1 haces el constructor privado, enctonces ya no podes instanciar desde afuera de la clase
    static Transaction* Deposit( int amount ) { return new Transaction( 'D', amount ); } // !!!1 y con estos dos metodos que se acceden asi !!!2 creas instancias nuevas, NOTAR el static para que funcione
    //se dice que es un contexto estatico el del {} anterior 
    ~Transaction();
    int value();
    bool isDeposit();
    int operator+=(const Transaction&);
};

class Account {
  private:
    vector<Transaction*> transactions;
  public:
    Account();
    ~Account();
    int balance();
    void deposit( int amount );
    void withdraw( int amount );
    vector<string> report();
};

// cpp
Transaction::Transaction( char k, int a ):kind(k),amount(a){}
int Transaction::value(){
    return amount;
}
bool Transaction::isDeposit(){
    return kind == 'D';
}

int Transaction::operator+=(const Transaction& t){
    if( isDeposit() ) {
            return amount;
        } else {
            return -amount;
        }
};

Account::Account() {}
Account::~Account() {}
int Account::balance(){ 
    int total = 0;
    for (auto& trans : transactions) {
        total += trans->value();
    }
    return total;
}
void Account::deposit( int amount ){ 
    transactions.emplace_back( Transaction::Deposit( amount ) ); // !!!2
}
void Account::withdraw( int amount ){ 
    if( (balance() - amount ) >= 0 ) {
        transactions.emplace_back( Transaction::Withdraw( amount ) ); // !!!2
    } 
}
vector<string> Account::report(){ 
    vector<string>  report;

    for (auto each = transactions.begin(); each != transactions.end(); each++) { 
        if( (*each)->isDeposit() ) {
            report.emplace_back( "deposito de " + to_string( (*each)->value() ) );
        } else {
            report.emplace_back( "retiro de " + to_string( (*each)->value() ) );
        }
    }
    return report;
}

int main(void) {
    Account *cuenta = new Account();
    assert( cuenta->balance() == 0 );
    
    cuenta->deposit( 10 );
    assert( cuenta->balance() == 10 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().size() == 1 );

    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );
    cuenta->withdraw( 10 );
    assert( cuenta->balance() == 0 );
    assert( cuenta->report().front() == "deposito de 10" );
    assert( cuenta->report().back() == "retiro de 10" );
    assert( cuenta->report().size() == 2 );

    cout << "ok " << std::endl;

    delete cuenta;

    return 0;
}