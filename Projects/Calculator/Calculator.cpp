
#include <iostream>
using namespace std;


class Classification_Calculator {

private:
    float _Result = 0;
    float _LastNumber = 0;
    string _LastOperation = "Clear";
    float _PreviousResult = 0;

    bool IsZero(float Number) {

        return (Number == 0);
    }

public:
    void Add(float Number) {

        _LastNumber = Number;
        _LastOperation = "Adding";
        _PreviousResult = _Result;
        _Result += Number;
    }

    void Subtract(float Number) {

        _LastNumber = Number;
        _LastOperation = "Subtracting";
        _PreviousResult = _Result;
        _Result -= Number;
    }

    void Multiply(float Number) {

        _LastNumber = Number;
        _LastOperation = "Multiplying";
        _PreviousResult = _Result;
        _Result *= Number;
    }

    void Divide(float Number) {

        _LastNumber = Number;
        if (IsZero(Number))
            Number = 1;

        _LastOperation = "Dividing";
        _PreviousResult = _Result;
        _Result /= Number;
    }

    void PrintResult() {

        cout << "Result " << "after " << _LastOperation << " " << _LastNumber << " is: " << _Result << "\n";
    }

    int GetFinalResults() {
    
        return _Result;
    }

    void CancelLastOperation() {
    
        _LastNumber = 0;
        _LastOperation = "Canceling last operation";
        _Result = _PreviousResult;
    }

    void Clear() {

        _LastNumber = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }
};



int main() {
    cout << "Hello World!\n\n\n\n\n";





    Classification_Calculator Calculator;

    Calculator.Clear();
    
    Calculator.Add(10);
    Calculator.PrintResult();
    
    Calculator.Add(100);
    Calculator.PrintResult();
    
    Calculator.Subtract(20);    
    Calculator.PrintResult();
    
    Calculator.Divide(0);  
    Calculator.PrintResult();    
    
    Calculator.Divide(2); 
    Calculator.PrintResult();  
    
    Calculator.Multiply(3);  
    Calculator.PrintResult();  
    
    Calculator.CancelLastOperation();   
    Calculator.PrintResult();
    
    Calculator.Clear();  
    Calculator.PrintResult();













    cout << "\n\n\n\n\nHello World!";
}
