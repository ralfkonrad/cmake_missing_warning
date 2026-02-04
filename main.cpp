#pragma push_macro("BOOST_DISABLE_ASSERTS")
#ifndef BOOST_DISABLE_ASSERTS
#define BOOST_DISABLE_ASSERTS
#endif
#include <boost/multi_array.hpp>
#pragma pop_macro("BOOST_DISABLE_ASSERTS")

int main()
{
    boost::multi_array<double, 3> d(boost::extents[2][2][2]);
    d[0][0][0] = 1.0;
    return 0;
}
