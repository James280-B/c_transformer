#include <iostream>
#include <vector>

#include "csv_handler.h"

using namespace std;

int main()
{
    CSVHandler csv;
    vector<vector<string>> output = csv.ReadCSV("nn_params.csv");

    int len_output = sizeof(output);
    for(int i=0; i<len_output; i++)
    {
        for(int j=0; j<len_output; j++)
        {
            std::cout << output[i][j] << std::endl;
        }
    }

    return 0;
}
