#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cstring>
#include <sys/time.h>

class PmergeMe
{
    public:
        double elapsed_time_vec;
        double elapsed_time_deq;
        std::vector<int> vec_nums;
        std::deque<int> deq_nums;
        PmergeMe();
        PmergeMe(const PmergeMe & cp);
        PmergeMe & operator= (const PmergeMe & cp);
        ~PmergeMe();
        void sortVector(std::vector<int> & my_vec);
        void sortDeque(std::deque<int> & my_deq);
        void print_vector(std::vector<int> & my_vec);
        void fill_vector(int num);
        void fill_deque(int num);
};

#endif