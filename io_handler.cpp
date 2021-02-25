#include "io_handler.h"

#include <iostream>
#include <unordered_map>

std::tuple<std::vector<Street>, std::vector<Car>, Params> read()
{
    Params p{};
    int numOfStreets;
    int numOfCars;
    std::cin >> p.duration >> p.numOfIntersects >> numOfStreets >> numOfCars >> p.carBonus;

    std::vector<Street> streets;
    std::unordered_map<std::string, int> streetsIndex;
    streets.reserve( numOfStreets );
    for ( int i = 0; i < numOfStreets; ++i )
    {
        streets.emplace_back();
        std::cin >> streets.back().start >> streets.back().end >> streets.back().name >> streets.back().time;
        streetsIndex[ streets.back().name ] = i;
    }

    std::vector<Car> cars;
    cars.reserve( numOfCars );
    for ( int i = 0; i < numOfCars; ++i )
    {
        cars.emplace_back();
        int numOfCarStreets;
        std::cin >> numOfCarStreets;
        cars.back().streets.reserve( numOfCarStreets );
        for ( int j = 0; j < numOfCarStreets; ++j )
        {
            std::string name;
            std::cin >> name;
            cars.back().streets.emplace_back( streetsIndex[ name ] );
        }
    }
    return { std::move( streets ), std::move( cars ), p };
}

void write( const std::vector<Schedule>& schedules, const std::vector<Street>& streets )
{
    std::cout << schedules.size() << '\n';
    for ( const auto& sch : schedules )
    {
        std::cout << sch.size() << '\n';
        for ( const auto& l : sch )
        {
            std::cout << streets[ l.street ].name << ' ' << l.duration << '\n';
        }
    }
    std::cout.flush();
}
