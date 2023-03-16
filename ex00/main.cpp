#include "BitcoinExchange.hpp"

bool check_y_m_d(std::string year, std::string month, std::string day)
{
	int yearr, monthh, dayy;
	yearr = atoi(year.c_str());
	monthh = atoi(month.c_str());
	dayy = atoi(day.c_str());

	if(dayy < 1 || dayy > 31)
		return false;
	if(monthh < 1 || monthh > 12)
		return false;
	if(yearr < 2009 || yearr > 2023)
		return false;
	if(monthh == 2 && dayy > 29)
		return false;
	return true;
}

bool check_date(std::string date)
{
	if(date.size() != 10)
		return false;
	for(int i = 0; i < 10; i++)
	{
		if(i == 4 || i == 7)
		{
			if(date[i] != '-')
				return false;
		}
		else if(!isdigit(date[i]))
			return false;
	}
	if(!check_y_m_d(date.substr(0, 4), date.substr(5, 2), date.substr(8, 2)))
		return false;
	return true;
}

int check_value(float value)
{
	if(value < 0)
		return 0;
	if(value > 1000)
		return 2;
	return 1;
}

int check_value_str(std::string value)
{
	int i = 0;
	int k = 0;
	while(value[i])
	{
		if(value[i] != '.' && !isdigit(value[i]))
		{
			return 0;
		}
		if (value[i] == '.')
			k++;
		i++;
	}
	if(k > 1)
		return 0;
	return 1;
}

int main(int ac, char **av)
{
	if(ac == 2)
	{
		BitcoinExchange btc;
		if(!btc.btc_readFromData_CSV("data.csv"))
		{
			std::cerr << "The data csv is corrupted !!" << std::endl;
		}
		std::ifstream file_txt(av[1]);
		if(file_txt.fail())
		{
			std::cerr << "Could not open the FILE" << av[1] << "check again !" << std::endl;
			return 0;
		}
		else
		{
			std::string line;
			std::getline(file_txt, line); // Read the first line and ignore it
			while(std::getline(file_txt, line))
			{
				int i = 0;
				int k = 0;
				while(line[i])
				{
					if(line[i] == '|')
						k++;
					i++;
				}
				if(k != 1)
				{
					std::cerr << "Error: bad input => " << line << std::endl;
					continue;
				}
				char *cstr = new char[line.size() + 1];
				strcpy(cstr, line.c_str());
				char *token = strtok(cstr, " |");
				if(!token)
				{
					std::cerr << "Error: bad input => " << line << std::endl;
					continue;
				}
				std::string date = token;
				token = strtok(NULL, " |");
				if(!token)
				{
					std::cerr << "Error: bad input => " << line << std::endl;
					continue;
				}
				if(!check_value_str(token))
				{
					std::cerr << "Error: bad input => " << line << std::endl;
					continue;
				}
				float value = std::atof(token);
				if(!check_date(date))
				{
					std::cout << "Error: invalid date." << std::endl;
					delete[] cstr;
					continue;
				}
				if(check_value(value) == 0)
				{
					std::cout << "Error: not a positive number." << std::endl;
					delete[] cstr;
					continue;
				}
				if(check_value(value) == 2)
				{
					std::cout << "Error: too large a number." << std::endl;
					delete[] cstr;
					continue;
				}
				else
					btc.printData_CSV_fileTXT(date, value);
				delete[] cstr;
			}
		}
	}
	else
	{
		std::cerr << "The number or args is WRONG !" << std::endl;
	}
	return 0;
}