#include "calc.h"

string delf(string a) {
    string ans = "";
    for (int i = 1; a[i] != '\0'; i++) ans += a[i];
    return ans;
}

string addzero(string str) {
    string ans = "-0";
    if (!isneg(str)) {
        str = '0' + str;
        return str;
    }
    else for (int i = 1; str[i] != '\0'; i++) ans += str[i];
    return ans;
}

string big_to_string(big b) {
    string ans = "";
    if (b[0] < 0) {
        ans += '-';
        b = negative(b);
    }
    for (int i = 0; i < b.size(); i++) ans += char(b[i] + 48);
    return ans;
}

big big_del_zero(big b) {
    while (b.size() >= 1 && b[0] == 0) b.erase(b.begin());
    if (b.size() == 0) b.push_back(0);
    return b;
}