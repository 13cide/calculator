#include "calc.h"

unsigned long long itc_len(string str) {
    unsigned long long a = 0;
    while (str[a] != '\0') a++;
    return a;
}

bool isneg(string b) {
    return b[0] == '-';
}

string itc_reverse_str(string str) {
    string ans;
    for (int i = 1; i < itc_len(str) + 1; i++) ans += str[itc_len(str) - i];
    return ans;
}

string del_zero(string str) {
    string ans = "";
    int i;
    if (isneg(str)) i = 1;
    else i = 0;
    while (str[i] == '0' && str[i] != '\0') i++;
    for (; str[i] != '\0'; i++) ans += str[i];
    if (ans != "" && !isneg(str)) return ans;
    else if (ans != "" && isneg(str)) return '-' + ans;
    else return "0";
}

string zero_zero(string a) {
    if (a[0] == '-' && a[1] == '-') {
        string ans = itc_reverse_str(a);
        ans.pop_back();
        ans.pop_back();
        return itc_reverse_str(ans);
    }
    return a;
}