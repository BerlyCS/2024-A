/*
 * Utilizando Polimorfismo, desarrolle un programa que permita calcular como m ́ınimo las operaciones de suma,
resta, multiplicaci ́on, divisi ́on y potencia. Tenga en consideraci ́on que las operaciones ser ́an dadas en una
linea de texto (Se considera incorrecto pedir valores num ́ericos y operadores por separado). Por ejemplo:
Operacion 0 : 7+3 * 5 - 2
Operacion 1 : -5*3*2 + 210 - 60/0.5
Operacion 2 : 34/2 * 50/5
Operacion 3 : -3 * -3 - 3 - -3.5

Tenga en consideraci ́on que los resultados deben de respetar la precedencia de operadores. Se tendr ́a pun-
tuaci ́on extra por agregar m ́as operadores al programa.
 */ 
// C++ Program to illustrate how to evalauate a mathematical
// expression that is stored as string
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>

using namespace std;

// Function to check if a character is an operator
bool isOperator(char c)
{
    // Returns true if the character is an operator
    return c == '+' || c == '-' || c == '*' || c == '/'
           || c == '^';
}

// Function to get the precedence of an operator
int precedence(char op)
{
    // Returns the precedence of the operator
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Function to apply an operator to two operands
double applyOp(double a, double b, char op)
{
    // Applies the operator to the operands and returns the
    // result
    switch (op) {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    case '^':
        return pow(a, b);
    default:
        return 0;
    }
}

// Function to parse and evaluate a mathematical expression
double evaluateExpression(const string& expression)
{
    stack<char> operators; // Stack to hold operators
    stack<double> operands; // Stack to hold operands

    stringstream ss(expression); // String stream to parse
                                 // the expression

    string token;
    while (getline(
        ss, token,
        ' ')) { // Parse the expression token by token
        if (token.empty())
            continue; // Skip empty tokens
        if (isdigit(token[0])) { // If the token is a number
            double num;
            stringstream(token)
                >> num; // Convert the token to a number
            operands.push(num); // Push the number onto the
                                // operand stack
        }
        else if (isOperator(token[0])) { // If the token is
                                         // an operator
            char op = token[0];
            // While the operator stack is not empty and the
            // top operator has equal or higher precedence
            while (!operators.empty()
                   && precedence(operators.top())
                          >= precedence(op)) {
                // Pop two operands and one operator
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Apply the operator to the operands and
                // push the result onto the operand stack
                operands.push(applyOp(a, b, op));
            }
            // Push the current operator onto the operator
            // stack
            operators.push(op);
        }
        else if (token[0] == '(') { // If the token is an
                                    // opening parenthesis
            // Push it onto the operator stack
            operators.push('(');
        }
        else if (token[0] == ')') { // If the token is a
                                    // closing parenthesis
            // While the operator stack is not empty and the
            // top operator is not an opening parenthesis
            while (!operators.empty()
                   && operators.top() != '(') {
                // Pop two operands and one operator
                double b = operands.top();
                operands.pop();
                double a = operands.top();
                operands.pop();
                char op = operators.top();
                operators.pop();
                // Apply the operator to the operands and
                // push the result onto the operand stack
                operands.push(applyOp(a, b, op));
            }
            // Pop the opening parenthesis
            operators.pop();
        }
    }

    // While the operator stack is not empty
    while (!operators.empty()) {
        // Pop two operands and one operator
        double b = operands.top();
        operands.pop();
        double a = operands.top();
        operands.pop();
        char op = operators.top();
        operators.pop();
        // Apply the operator to the operands and push the
        // result onto the operand stack
        operands.push(applyOp(a, b, op));
    }

    // The result is at the top of the operand stack
    return operands.top();
}

int main()
{
    string expression = "7.6+3 * 5 - 2";

    // Evaluate the expression
    double result = evaluateExpression(expression);
    // Print the result
    cout << "Result: " << result << endl;

    return 0;
}

