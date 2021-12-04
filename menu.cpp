#include "calc.h"

bool is_correct_num(string s) {
    if (s == "") return false;
    if (s[0] != '-') for (unsigned long long i = 0; s[i] != '\0'; i++) if (s[i] < '0' || s[i] > '9') return false;
    if (s[0] == '-') for (unsigned long long i = 1; s[i] != '\0'; i++) if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

string menu_start() {
    string num1, num2;
    char operation;
    cout << "input first number:";
    cin >> num1;
    if (!(is_correct_num(num1))) return "incorrect input";
    cout << "input second number:";
    cin >> num2;
    if (!(is_correct_num(num2))) return "incorrect input";
    cout << "input operation (+, *, -)";
    cin >> operation;
    if (!(operation == '+' || operation == '-' || operation == '*')) return "incorrect operation";

    if (operation == '+') return big_sum(del_zero(num1), del_zero(num2));
    if (operation == '-') return big_sum(del_zero(num1), del_zero(zero_zero('-' + num2)));
    //if (operation == '*') return big_mult(to_big(num1), to_big(num2));
}