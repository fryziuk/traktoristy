#include "io_handler.h"

#include <iostream>

int main()
{
    auto input = read();
    auto streets = std::get<0>( input );
    auto cars = std::get<1>( input );
    auto params = std::get<2>( input );

    std::cout << "OK" << std::endl;

    return 0;
}
