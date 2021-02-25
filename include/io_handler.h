#pragma once

#include <tuple>
#include <vector>
#include <string>

struct Street {
    int start = 0;
    int end = 0;
    std::string name;
    int time = 0;
};

struct Car {
    std::vector<int> streets;
};

struct Params {
    int duration = 0;
    int numOfIntersects = 0;
    int carBonus = 0;
};

std::tuple<std::vector<Street>, std::vector<Car>, Params> read();

struct LightDuration {
    int street = 0;
    int duration = 0;
};

using Schedule = std::vector<LightDuration>;

void write( const std::vector<Schedule>& schedules, const std::vector<Street>& streets );
