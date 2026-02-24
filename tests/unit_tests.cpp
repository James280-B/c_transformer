#include <filesystem>

#include "data_handler.h"
#include "activation_functions.h"

using namespace std;

//testing csv function : data handler class

void test_csv()
{
    DataHandler data;
    vector<vector<string>> output = data.ReadCSV("data/nn_params.csv");

    for(int i=0; i<2; i++)
    {
        for(int j=0; j<4; j++)
        {
            std::cout << output[i][j] << std::endl;
            std:cout << "csv function tested" << std::endl;
        }
    }
}

//testing softmax function : actfunc class 
void test_act_func_class()
{
    //testing softmax
    vector<double> test_vec = {3.0, 2.0, 4.0}; 
    ActFunc act_func;

    vector<double> output = act_func.compute_softmax(test_vec);

    for(int i=0; i<output.size(); i++)
    {
        std::cout << "testing softmax: \n";
        std::cout << output[i] << std::endl;
    }
}

int main()
{
    //test_csv();
    test_act_func_class();
    
    return 0;
}
