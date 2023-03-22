/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntanjaou <ntanjaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:06:08 by ntanjaou          #+#    #+#             */
/*   Updated: 2023/03/22 15:06:09 by ntanjaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {};

PmergeMe::PmergeMe(const PmergeMe & cp)
{
    this->deq_nums = cp.deq_nums;
    this->vec_nums = cp.vec_nums;
}

PmergeMe & PmergeMe::operator=(const PmergeMe & cp)
{
    this->deq_nums = cp.deq_nums;
    this->vec_nums = cp.vec_nums;
    return *this;
}

PmergeMe::~PmergeMe() {};

template <typename Container>
void sort_insert(Container & my_container, int start, int midle , int end)
{
    int i = start;
    int j = midle + 1;
    int k = start;
    int tmp[end + 1];

    while(i <= midle && j <= end)
    {
        if(my_container[i] <= my_container[j])
        {
            tmp[k] = my_container[i];
            k++;
            i++;     
        }
        else
        {
            tmp[k] = my_container[j];
            k++;
            j++;
        }
    }
    while(i <= midle)
    {
        tmp[k] = my_container[i];
        k++;
        i++;
    }
    while(j <= end)
    {
        tmp[k] = my_container[j];
        k++;
        j++;
    }
    for(int a = start; a <= end; a++)
    {
        my_container[a] = tmp[a];
    }
}

void merge_sortVector(std::vector<int> & my_vec, int start, int end)
{
    if(start < end)
    {
        int midle; // to get the midle of the vector
        midle = (start + end) / 2;
        merge_sortVector(my_vec, start, midle);
        merge_sortVector(my_vec, midle + 1, end);
        sort_insert(my_vec, start, midle, end);
    }
}

void merge_sortDeque(std::deque<int> & my_deq, int start, int end)
{
    if(start < end)
    {
        int midle; // to get the midle of the deque
        midle = (start + end) / 2;
        merge_sortDeque(my_deq, start, midle);
        merge_sortDeque(my_deq, midle + 1, end);
        sort_insert(my_deq, start, midle, end);
    }
}

void PmergeMe::print_vector(std::vector<int> & my_vec)
{
    for(size_t i = 0; i < my_vec.size(); i++)
    {
        std::cout << my_vec[i] << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::sortVector(std::vector<int> & my_vec)
{   
    timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    merge_sortVector(my_vec, 0, my_vec.size() - 1);
    gettimeofday(&end_time, NULL);
    long elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000000) + end_time.tv_usec - start_time.tv_usec;
    this->elapsed_time_vec = static_cast<double>(elapsed_time);
}

void PmergeMe::sortDeque(std::deque<int> & my_deq)
{
    timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
    merge_sortDeque(my_deq, 0, my_deq.size() - 1);
    gettimeofday(&end_time, NULL);
    long elapsed_time = ((end_time.tv_sec - start_time.tv_sec) * 1000000) + end_time.tv_usec - start_time.tv_usec;
    this->elapsed_time_deq = static_cast<double>(elapsed_time);
}

void PmergeMe::fill_vector(int num)
{
    this->vec_nums.push_back(num);
}

void PmergeMe::fill_deque(int num)
{
    this->deq_nums.push_back(num);
}