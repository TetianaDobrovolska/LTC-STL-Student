#include "impl.h"

size_t convertMarkTo5PointSystem(size_t markIn100Point)
{
    const std::map <size_t, size_t> converter {{0, 1}, {30, 2}, {50, 3}, {70, 4}, {90, 5}};
    const auto result = --(converter.upper_bound(markIn100Point));
    return result->second;
}
