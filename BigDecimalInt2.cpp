#include "BigDecimalInt2.h"
#include<regex>
bool BigDecimalInt2::checkInput(string input)
{
    regex validInput("[-+]?[0-9]+");
    return regex_match(input, validInput);
}

BigDecimalInt2::BigDecimalInt2(string bigInteger) {
    if (checkInput(bigInteger)) {
        number = bigInteger;
        if (number[0] == '+') { number.erase(0, 1); signint = '+'; }
        else if (number[0] == '-') { number.erase(0, 1); signint = '-'; }
        else signint = '+';
    }
    else { cout << "Invalid" << "\n"; exit(1); }
}

