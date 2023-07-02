#include <iostream>

using namespace std;

// defining operation functions first
float add (float a, float b){
    return (a + b);
}

float subtract (float a, float b){
    return (a - b);
}

float multiply (float a, float b){
    return (a * b);
}

float divide (float a, float b){
    return (a / b);
}


// main funciton definition below
void calculator() {
     
  
    char oper;
    int answer;
    float num1, num2;
    bool should_continue{1};
    
    cout << "Welcome to the calculator." << endl;
    cout << "Enter the first number: " << endl;
    cin >> num1;
    
    while (should_continue == 1) {
        
    cout << "Enter an operator (+, -, *, /): " << endl;
    cin >> oper;
    cout << "Enter the next number: " << endl;
    cin >> num2;
    
    switch (oper) {
        case '+':
            cout << num1 << " + " << num2 << " = " << add(num1, num2)  << endl;
            answer = add(num1, num2);
            break;
        case '-':
            cout << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
            answer = subtract(num1, num2);
            break;
        case '*':
            cout << num1 << " * " << num2 << " = " << multiply(num1, num2) << endl;
            answer = multiply(num1, num2);
            break;
        case '/':
            cout << num1 << " / " << num2 << " = " << divide(num1, num2) << endl;
            answer = divide(num1, num2);
            break;
        default:
            // operator is doesn't match any case constant (+, -, *, /)
            cout << "Error! The operator is not correct";
            break;
    }
    
    cout << "Type 'y' to continue calculating with " << answer << ", or type 'n' to start a new calculation.: ";
    
    char decision_to_contiune;
    cin >> decision_to_contiune;
    decision_to_contiune = tolower(decision_to_contiune);
    
    if (decision_to_contiune == 'y') {
        num1 = answer;
    }
    else {
        should_continue = 0;
        system("cls");
        calculator();
        }
    }
}

int main(){
    
    calculator();
      
    return 0;
}
