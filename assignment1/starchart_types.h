#pragma once
#ifndef STARCHART_TYPES_H
#define STARCHART_TYPES_H
#include <vector>
#include <tuple>

typedef signed int distance;
typedef unsigned int index;
typedef std::vector<std::vector<distance>> matrix;
typedef std::tuple<index, index, distance> wormhole;

#endif // STARCHART_TYPES_H
