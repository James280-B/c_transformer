#include <filesystem>

#include "data_handler.h"
#include "activation_functions.h"
#include "one_hot_encoding.h"

using namespace std;

//testing csv function : data handler class

void test_csv()
{
    DataHandler data;
    vector<vector<string>> output = data.read_csv("data/nn_params.csv");

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
    std::cout << "testing softmax: \n";
    vector<double> test_vec = {3.0, 2.0, 4.0}; 
    ActFunc act_func;

    vector<double> output = act_func.compute_softmax(test_vec);

    for(int i=0; i<output.size(); i++)
    {
        std::cout << output[i] << std::endl;
    }
}

//testing storage class
void test_storage_class()
{
    StorageHandler<vector<bool>> storage;
    for(int i=0; i<2; i++)
    {
        vector<bool> a(2, true);
        a[i] = false;
        storage.insert(a);
    }
    vector<vector<bool>> data = storage.read_all();

    for(int j=0; j<data.size(); j++)
    {
        for(int g=0; g<data[j].size(); g++)
        {
            std::cout << data[j][g] << std::endl;
        }
    }
}

//testing one hot encoding class
void test_1he_class()
{
    DataHandler data;
    InputEncoders encoder;
    StorageHandler<vector<bool>> storage;

    vector<string> input_vec = data.read_input_data("data/test_input_data.txt"); //issue with data needing to be added
    encoder.implement_one_hot_encoding(input_vec);
    vector<vector<bool>> output = storage.read_all();

    std::cout << "outputting 1he result \n";
    for(int i=0; i<output.size(); i++)
    {
        std::cout << "word " << i << std::endl;
        for(int j=0; j<output[i].size(); j++)
        {
            std::cout << output[i][j] << std::endl;
        }
    }

    std::cout << "finish testing 1he class" << std::endl;
}

int main()
{
    //test_csv();
    //test_act_func_class();
    //test_storage_class();
    test_1he_class();
    
    return 0;
}
