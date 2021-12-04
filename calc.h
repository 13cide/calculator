#ifndef CALCULATOR_CALC_H
#define CALCULATOR_CALC_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

string menu_start();
unsigned long long itc_len(string str);
typedef vector<short int> big;
big to_big(string s);
big negative(big b);
string big_sum(string n1, string n2);
int fill_and_return_len(big b1, big b2);
bool isneg(string b);
string sum(big b1, big b2);
string itc_reverse_str(string str);
string del_zero(string str);
string zero_zero(string a);
string delf(string a);
string addzero(string str);
string dif(big b1, big b2);
string big_to_string(big b);
big big_del_zero(big b);
bool isok(big b);

#endif //CALCULATOR_CALC_H
