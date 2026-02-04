#include <boost/multi_array.hpp>

int main()
{
    boost::multi_array<double, 3> d(boost::extents[2][2][2]);

    return 0;
}
