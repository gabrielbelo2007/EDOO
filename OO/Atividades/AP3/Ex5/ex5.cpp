#include <iostream>
#include "tool1.h"
#include "tool2.h"

int main() {

    double result_sum = tool1::calculate(2, 3);
    std::cout << result_sum << std::endl;

    double result_product = tool2::calculate(2, 3);
    std::cout << result_product << std::endl;

    return 0;
}