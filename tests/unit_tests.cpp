#include <filesystem>

#include "data_handler.h"
#include "activation_functions.h"
#include "one_hot_encoding.h"

using namespace std;

//testing csv function : data handler class

void TestCSV()
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
void TestActFuncClass()
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
void TestStorageClass()
{
    StorageHandler<vector<bool>> storage;
    for(int i=0; i<2; i++)
    {
        vector<bool> a(2, true);
        a[i] = false;
        storage.Insert(a);
    }
    vector<vector<bool>> data = storage.ReadStorageSpace();

    for(int j=0; j<data.size(); j++)
    {
        for(int g=0; g<data[j].size(); g++)
        {
            std::cout << data[j][g] << std::endl;
        }
    }
}

//testing one hot encoding class
void TestOneHotEncodingClass()
{
    DataHandler data;
    vector<string> input_vec = data.read_input_data("data/test_input_data.txt");

    std::cout << "data read" << std::endl;

    OneHotEncoding one_hot_encoder(input_vec);
    vector<token> output = one_hot_encoder.encoder_storage.ReadStorageSpace();

    std::cout << "output size " << output.size() << std::endl;

    std::cout << "outputting 1he result \n";
    for(int i=0; i<output.size(); i++)
    {
        std::cout << "word " << i << std::endl;
        for(int j=0; j<output[i].one_hot_encoded_vec.size(); j++)
        {
            std::cout << output[i].one_hot_encoded_vec[j] << std::endl;
        }
    }
    std::cout << "finish testing 1he class" << std::endl;
}

int main()
{
    //TestCSV();
    //TestActFuncClass();
    //TestStorageClass();
    TestOneHotEncodingClass();
    
    return 0;
}
