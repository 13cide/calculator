#include "calc.h"

typedef vector<short int> big;

big negative(big b) {
    for (unsigned long long i = 0; i < b.size(); i++) b[i] *= -1;
    return b;
}

big to_big(string s) {
    big num;
    int g = -1;
    if (isneg(s)) g++;
    for (unsigned long long i = itc_len(s) - 1; i != g; i--) num.push_back(int(s[i] - 48));
    if (isneg(s)) num = negative(num);
    num.push_back(0);
    return num;
}
