#include <iostream>
#include<algorithm>
template <typename T>
std::pair<std::array<size_t, 2>, T> maxCrossingSubArray( const std::vector<T>& vec, const size_t & low, const size_t & high)
{
    size_t mid {(low + high) / 2};

    std::pair<std::array<size_t, 2>, T> toBeReturned{{mid, mid + 1}, T()};
    size_t leftItr {mid + 1};
    T leftSum { std::numeric_limits<T>::min() }, tempSum {};


    while(leftItr-- > low ){
        tempSum += vec[leftItr];
        if(tempSum > leftSum) {
            leftSum = tempSum;
            toBeReturned.first[0] = leftItr;
        }
    }
    toBeReturned.second += leftSum;

    size_t rightItr {mid};
    T rightSum { std::numeric_limits<T>::min() }; tempSum = 0;
    while(rightItr++ < high ){
        tempSum += vec[rightItr];
        if(tempSum > rightSum) {
            rightSum = tempSum;
            toBeReturned.first[1] = rightItr;
        }
    }
    toBeReturned.second += rightSum;

    return toBeReturned;
}


template <typename T>
std::pair<std::array<size_t, 2>, T> maxSubArray( const std::vector<T>& vec, const size_t & low, const size_t & high)
{
    if(low == high) return {{low, high}, vec[low]};
    std::pair maxLeftArray = maxSubArray(vec, low, (low + high) / 2);
    std::pair maxRightArray = maxSubArray(vec, (low + high) / 2 + 1, high);
    std::pair maxMidArray = maxCrossingSubArray(vec, low, high);
    if( maxLeftArray.second > maxMidArray.second && maxLeftArray.second > maxRightArray.second ) return maxLeftArray;
    if( maxMidArray.second > maxLeftArray.second && maxMidArray.second > maxRightArray.second ) return maxMidArray;
    return maxRightArray;
}



int main(){
    std::vector<double> vec = {1000, 3, -7, -1000, 9,30, 5, -9, -10, 1000.5};
    auto[firstInd, lastInd] = maxSubArray(vec, 0, vec.size()-1).first;

    std::cout << "The whole array is ";
    size_t i = 0;
    for(; i < vec.size() - 1; ) std::cout << vec[i++] << ", ";
    std::cout << vec[i] << "}\n";

    std::cout << "The first index of the maximum array is: " << firstInd << " and the last index is: "
    << lastInd<<"\nThe maximum array is {";
    i = firstInd;
    for(; i < lastInd; ) std::cout << vec[i++] << ", ";
    std::cout << vec[i] << "}";
}
