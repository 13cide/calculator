#include "calc.h"

string big_sum(string n1, string n2) {
    if ((itc_len(n1) != itc_len(n2)) && ((isneg(n1) && isneg(n2)) || (!isneg(n1) && !isneg(n2)))) {
        if (itc_len(n1) > itc_len(n2)) while (itc_len(n1) != itc_len(n2)) n2 = addzero(n2);
        if (itc_len(n2) > itc_len(n1)) while (itc_len(n1) != itc_len(n2)) n1 = addzero(n1);
    }
    else if (isneg(n1) && !isneg(n2) && itc_len(n1) > itc_len(n2) + 1) while (itc_len(n1) != itc_len(n2) + 1) n2 = addzero(n2);
    else if (isneg(n1) && !isneg(n2) && itc_len(n1) <= itc_len(n2) + 1) while (itc_len(n1) != itc_len(n2) + 1) n1 = addzero(n1);
    else if (!isneg(n1) && isneg(n2) && itc_len(n2) > itc_len(n1) + 1) while (itc_len(n1) + 1 != itc_len(n2)) n1 = addzero(n1);
    else if (!isneg(n1) && isneg(n2) && itc_len(n2) <= itc_len(n1) + 1) while (itc_len(n1) + 1 != itc_len(n2)) n2 = addzero(n2);
    if (!isneg(n1) && !isneg(n2)) return sum(to_big(n1), to_big(n2));
    if (isneg(n1) && isneg(n2)) return '-' + sum(to_big(delf(n1)), to_big(delf(n2)));
    return dif(to_big(n1), to_big(n2));
}

string sum(big b1, big b2) {
    string ans = "";
    short int odd = 0;
    for (unsigned long long i = 0; i != b1.size(); i++) {
        int tmp = odd + b2[i] + b1[i];
        if (tmp > 9) odd = 1;
        else odd = 0;
        ans += char((tmp % 10) + 48);
    }
    return del_zero(itc_reverse_str(ans));
}

string dif(big b1, big b2) {
    big res;
    for (int i = b1.size() - 1; -1 < i; i--) res.push_back(b1[i] + b2[i]);
    res = big_del_zero(res);
    for (int i = res.size() - 1; -1 < i; i--) {
        if (res[i] < 0 && res[0] > 0) {
            res[i] += 10;
            res[i - 1] -= 1;
        }
        if (res[i] > 0 && res[0] < 0) {
            res[i] -= 10;
            res[i - 1] += 1;
        }
    }
    return del_zero(big_to_string(res));
}