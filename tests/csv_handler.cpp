#include <filesystem>

#include "csv_handler.h"

using namespace std;

//testing csv handler class

int main()
{
    CSVHandler csv;
    vector<vector<string>> output = csv.ReadCSV("data/nn_params.csv");

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            std::cout << output[i][j] << std::endl;
        }
    }

    return 0;
}
