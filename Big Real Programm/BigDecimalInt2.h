#include<bits/stdc++.h>
using namespace std;

#ifndef BIGDECIMALINT2_H
#define BIGDECIMALINT2_H

class BigDecimalInt2 {
public:
    string number;
    char signint;
    bool checkInput(string input);
    BigDecimalInt2(string bigInteger);
};
#endif
