#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::BitcoinExchange(const BitcoinExchange & btc)
{
    this->data_csv = btc.data_csv;
}

BitcoinExchange & BitcoinExchange::operator= (const BitcoinExchange & btc)
{
    this->data_csv = btc.data_csv;
    return *this;
}

BitcoinExchange::~BitcoinExchange(){};

int BitcoinExchange::btc_readFromData_CSV(std::string csv_file)
{
     std::ifstream data_csv(csv_file.c_str());
        if(data_csv.fail())
        {
            std::cerr << "Could not open the data_csv, check again !" << std::endl;
            return 0;
        }
        else
        {
            std::string line;
            std::getline(data_csv, line); // Read the first line and ignore it
            while(std::getline(data_csv, line))
            {
                std::string::size_type pos = line.find(",");
                std::string key = line.substr(0, pos);
                std::string value_str = line.substr(pos + 1);
                float value = atof(value_str.c_str());
                this->data_csv[key] = value;
            }
        }
    return 1;
}

void BitcoinExchange::printData_CSV()
{
    std::map<std::string, float>::iterator iter;
    for(iter = this->data_csv.begin(); iter!= this->data_csv.end(); ++iter)
    {
        std::cout << iter->first << " : " << iter->second << std::endl;
    }
}

void BitcoinExchange::printData_CSV_fileTXT(std::string date, float value)
{
    std::cout << date << " => " << value << " = " << (this->data_csv.lower_bound(date)->second * value) << std::endl;
}