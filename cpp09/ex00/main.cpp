#include "BitcoinExchange.hpp"

//take the exchange rate from that line -> check 0 >= exchange rate <= 1000 (float or int)
//find the value of the line in database which equals date if not look for older date --date
//
//multiply value found * exchange rate

void calculateConversion(BitcoinExchange& historicalBTC, std::ifstream& inputFile)
{
    std::string line;
    while (std::getline(inputFile, line))
    {
        std::string date = line.substr(0, 10);
        float exchangeRate = strToNum<float>(line.substr(line.find("|") + 1));
        if (!errorLine(date, exchangeRate))
            historicalBTC.getConversion(date, exchangeRate);
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: program takes a file as argument" << std::endl;
        return 1;
    }
    std::ifstream db("./data.csv");
    if (!(db.is_open() && db.good()))
    {
        std::cerr << "Error: couldn't open db" << std::endl;
        return 1;
    }
    BitcoinExchange historicalBTC(db);

    //read line from input file
    std::ifstream inputFile(argv[1]);
    
    calculateConversion(historicalBTC, inputFile); 
    
    return 0;
}
