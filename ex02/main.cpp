#include "PmergeMe.hpp"

bool is_correct(int ac, char **av)
{
    for(int i = 1; i < ac; i++)
    {
        if(!std::isdigit(av[i][0]))
            return false;
        if(atoi(av[i]) < 0)
            return false;
    }
    return true;
}

int main(int ac, char **av)
{
    PmergeMe pme;
    if(ac < 3)
    {
        std::cerr << "The number or args is WRONG !" << std::endl;
        return 0;
    }
    if(!is_correct(ac, av))
    {
        std::cerr << "Error " << std::endl;
        return 0;
    }
    std::cout << "Before: ";
    int i = 1;
    while(i < ac)
    {
        std::cout << av[i] << " ";
        pme.fill_vector(atoi(av[i]));
        //fill the deque later
        i++;
    }
    std::cout << std::endl;
    pme.sortVector(pme.vec_nums);
    std::cout << "After: ";
    pme.print_vector(pme.vec_nums);
    std::cout << "Time to process a range of " << pme.vec_nums.size()  << " elements with std::vector: " << pme.elapsed_time_vec << " us" << std::endl;
    //add later time elapse of deque
    return 0;
}