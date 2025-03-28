#include "../include/PmergeMe.hpp"

struct Pair
{
    std::vector<std::pair<int, int> > pairs;
    int unpaired;
    bool unpaired_found;
    Pair() : unpaired_found(false){};
};

struct MinMax
{
    std::vector<int> mins;
    std::vector<int> maxs;
};

Pair make_pairs_with_unpaired(const std::vector<int> &arr)
{
    Pair result;
    std::size_t i = 0;

    for (; i + 1 < arr.size(); i += 2)
        result.pairs.push_back(std::make_pair(arr[i], arr[i + 1]));

    if (arr.size() % 2 == 1)
    {
        result.unpaired = arr[arr.size() - 1];
        result.unpaired_found = true;
    }

    return result;
}

MinMax split_mins_and_maxs(const std::vector<std::pair<int, int> > &pairs)
{
    MinMax result;
    for (std::size_t i = 0; i < pairs.size(); ++i)
    {
        int a = pairs[i].first;
        int b = pairs[i].second;

        if (a < b)
        {
            result.mins.push_back(a);
            result.maxs.push_back(b);
        }
        else
        {
            result.mins.push_back(b);
            result.maxs.push_back(a);
        }
    }
    return result;
};

void binary_insert(std::vector<int> &sorted, int value)
{
    std::vector<int>::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
    sorted.insert(pos, value);
};

void insert_mins(std::vector<int> &sorted, const std::vector<int> &mins)
{
    for (std::size_t i = 0; i < mins.size(); ++i)
        binary_insert(sorted, mins[i]);
};

std::vector<int> PmergeMe::sort(const std::vector<int> &arr)
{
    if (arr.size() <= 1)
        return arr;

    Pair pair = make_pairs_with_unpaired(arr);
    MinMax split = split_mins_and_maxs(pair.pairs);

    std::vector<int> sorted_maxs = sort(split.maxs);
    insert_mins(sorted_maxs, split.mins);

    if (pair.unpaired_found)
        binary_insert(sorted_maxs, pair.unpaired);

    return sorted_maxs;
};
