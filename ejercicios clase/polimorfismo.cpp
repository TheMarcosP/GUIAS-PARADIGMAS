//https://www.mygreatlearning.com/blog/polymorphism-in-cpp/#:~:text=in%20C%2B%2B-,What%20is%20Polymorphism%20in%20C%2B%2B%3F,in%20numbers%2C%20it%20performs%20addition.
#include <iostream>
using namespace std;
class Addition {
public:
    int ADD(int X,int Y){   // Function with parameter 
        return X+Y;     // this function is performing addition of  two Integer value
    }

    int ADD(int X,int Y,int Z){  // Function with same name but with different parameter
        return X+Y+Z;       // this function is performing addition of three Integer value
    }

    string ADD(string X,string Y){  // Function with same name but with different parameter
        return X+Y;       // this function is performing addition of two String value
    }

    int ADD() {              // Function with same name but without parameter
        string a= "HELLO";
        string b="SAM";   // in this function concatenation is performed
        string c= a+b;
        cout<<c<<endl;
        return 0;
    }

};


int main(void) {
    // ADD function is called with different parameters
    Addition obj;   // Object is created  
    cout<<obj.ADD(128, 15)<<endl; //first method is called
    cout<<obj.ADD(128, 15, 100)<<endl; //second method is called
    cout<<obj.ADD("HELLO", " TIMOTEO")<<endl; //third method is called
    obj.ADD();  // second method is called
    return 0;
}


// #include <iostream>  
// using namespace std;  
// class A  
// {  
//     string x;  
//     public:  
//     A(){}  
//     A(string i)  
//     {  
//        x=i;  
//     }  
//     void operator+(A);  
//     void display();  
// };  
   
// void A:: operator+(A a)  
// {  
      
//     string m = x+a.x;  
//     cout<<"The result of the addition of two objects is : "<<m;  
   
// }  
// int main()  
// {  
//     A a1("Welcome");  
//     A a2("back");  
//     a1+a2;  
//     return 0;  
// }