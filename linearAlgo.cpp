#include <iostream>
#include <vector>
#include <algorithm>
template <typename T>
std::pair<std::pair<size_t, size_t>, T> maxSubSum( const std::vector<T> & a )
{
    T maxSum {};
    //if all elements are -ve
    if (auto maxPos = std::max_element(a.begin(), a.end()); *maxPos < 0 ){
        return std::make_pair(std::make_pair(maxPos - a.begin(), maxPos - a.begin() + 1), *maxPos);
    }
    T currentSum {};
    size_t begin{ };
    size_t tempBegin{ };
    size_t end;
    for( size_t i {}; i < a.size( ); ++i )
    {
        currentSum += a[ i ];
        if(currentSum > maxSum) {
            maxSum = currentSum;
            end = i + 1;
        }
        else if (currentSum < T{}) //the first series won't harm as long as it > 0
        {
            currentSum = T{};
            tempBegin = begin;
            begin = i + 1;
        }
    }
    if (begin >= end ) begin = tempBegin;
    return std::make_pair(std::make_pair(begin, end), maxSum);
}


int main(){
    std::vector vec { -9, -1000};
    auto res = maxSubSum(vec);
    std::cout << res.second << " " << res.first.first << " "<< res.first.second;
}
