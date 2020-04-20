#include <vector>
template <typename T>
T maxSubSum( const std::vector<T> & a )
{
    T maxSum {};
    for( size_t i {}; i < a.size( ); ++i )
        for( size_t j = i; j < a.size( ); ++j )
        {
            T thisSum {};
            for( int k = i; k <= j; ++k )
            {
                thisSum += a[ k ];
                if ( thisSum > maxSum )
                    maxSum = thisSum;
            }
        }
    return maxSum;
}
