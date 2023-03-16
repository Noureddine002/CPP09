#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <cstring>
#include <cstdlib>

class BitcoinExchange 
{
    private:
        std::map<std::string, float, std::greater<std::string> > data_csv;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange & btc);
        BitcoinExchange & operator= (const BitcoinExchange & btc);
        ~BitcoinExchange ();
        int btc_readFromData_CSV(std::string csv_file);
        void printData_CSV();
        void printData_CSV_fileTXT(std::string date, float value);
};

#endif