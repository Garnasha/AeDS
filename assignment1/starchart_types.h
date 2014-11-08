#pragma once
#ifndef STARCHART_TYPES_H
#define STARCHART_TYPES_H
#include <vector>
#include <tuple>
#include <utility>

/* note: negative distances are pathological but trivially caught by using
 * signed ints, which does not give up significant range, nor does it risk
 * type errors. Thus the otherwise arbitrary choice to make distance signed.
 */

typedef signed int distance;
typedef unsigned int index;
typedef std::vector<std::vector<distance>> matrix;
/*wormhole is legacy and should be a proper struct, but this would break earlier
 *code. TODO: refactor if code is ever re-used. Not worth it before then.
 */
typedef std::tuple<index, index, distance> wormhole;

#endif // STARCHART_TYPES_H
