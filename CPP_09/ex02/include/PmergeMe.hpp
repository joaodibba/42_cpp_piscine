#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <deque>
#include <iostream>
#include <algorithm>

template <typename T,
          template <typename U, typename Alloc = std::allocator<U> > class Container>
class PmergeMe
{
private:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe &operator=(const PmergeMe &);

public:
    static Container<T> sort(const Container<T> &arr);
};
template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
struct PairContainer
{
    Container<std::pair<T, T> > pairs;
    T unpaired;
    bool unpaired_found;

    PairContainer() : unpaired_found(false) {}
};

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
struct MinMaxContainer
{
    Container<T> mins;
    Container<T> maxs;
};

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
PairContainer<T, Container> make_pairs_with_unpaired(const Container<T> &arr)
{
    PairContainer<T, Container> result;

    typename Container<T>::const_iterator it = arr.begin();
    typename Container<T>::const_iterator end = arr.end();

    while (it != end)
    {
        T first = *it;
        ++it;
        if (it == end)
        {
            // We have an unpaired leftover
            result.unpaired = first;
            result.unpaired_found = true;
            break;
        }
        T second = *it;
        ++it;
        result.pairs.push_back(std::make_pair(first, second));
    }
    return result;
}

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
MinMaxContainer<T, Container>
split_mins_and_maxs(const Container<std::pair<T, T> > &pairs)
{
    MinMaxContainer<T, Container> mm;

    typename Container<std::pair<T, T> >::const_iterator it = pairs.begin();
    typename Container<std::pair<T, T> >::const_iterator end = pairs.end();

    for (; it != end; ++it)
    {
        if (it->first < it->second)
        {
            mm.mins.push_back(it->first);
            mm.maxs.push_back(it->second);
        }
        else
        {
            mm.mins.push_back(it->second);
            mm.maxs.push_back(it->first);
        }
    }
    return mm;
}

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
void sorted_insert(Container<T> &sorted, const T &value)
{
    typename Container<T>::iterator it = sorted.begin();
    typename Container<T>::iterator ed = sorted.end();

    for (; it != ed; ++it)
    {
        if (value < *it)
        {
            sorted.insert(it, value);
            return;
        }
    }
    sorted.push_back(value);
}

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
void insert_mins(Container<T> &sorted, const Container<T> &mins)
{
    typename Container<T>::const_iterator it = mins.begin();
    typename Container<T>::const_iterator end = mins.end();

    for (; it != end; ++it)
    {
        sorted_insert(sorted, *it);
    }
}

template <typename T, template <typename U, typename Alloc = std::allocator<U> > class Container>
Container<T> PmergeMe<T, Container>::sort(const Container<T> &arr)
{
    if (arr.size() <= 1)
        return arr;

    PairContainer<T, Container> pc = make_pairs_with_unpaired<T, Container>(arr);
    MinMaxContainer<T, Container> mm = split_mins_and_maxs<T, Container>(pc.pairs);

    Container<T> sorted_maxs = PmergeMe<T, Container>::sort(mm.maxs);
    insert_mins(sorted_maxs, mm.mins);

    if (pc.unpaired_found)
        sorted_insert(sorted_maxs, pc.unpaired);

    return sorted_maxs;
}

#endif
