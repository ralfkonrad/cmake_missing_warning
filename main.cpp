#include <iostream>
#include <boost/multi_array.hpp>

int main()
{
    boost::multi_array<double, 3> d(boost::extents[2][2][2]);
    d[0][0][0] = 1.0;
    return 0;
}
