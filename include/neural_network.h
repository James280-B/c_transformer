#ifndef __NN_H__
#define __NN_H__

#include "layer.h"
#include "data_handler.h"
class NeuralNetwork
{
    protected:
        vector<int> network_struct; //number of neruons per embedded layer
        std::string network_name; //check nn_params for list of names

    public:
        NeuralNetwork() {}

        ~NeuralNetwork() {}

        vector<Layer> BuildNetwork()
        {
            const int num_layers = network_struct.size();
            int network_idx = 0;

            Layer input_layer;
            Layer output_layer;
            Layer embedded_layer;

            vector<Layer> network;
            vector<vector<string>> network_params;

            DataHandler data;

            network_params = data.ReadCSV("data/nn_params.csv");

            for (int i=0; i<network_params.size(); i++)
            {
                string nn_names = network_params[i][0];

                if (nn_names == network_name)
                {
                    network_idx = stoi(network_params[i][1]); //not clean (do in read csv func)

                    switch (network_idx)
                    {
                        //builds cbow network
                        case 1:                            
                            //build input layer
                            input_layer.neurons = stoi(network_params[i][2]);   
                            input_layer.activation_function = network_params[i][4]; //TODO make actfunc class
                            input_layer.biases;
                            input_layer.weights;


                            //build output layer
                            output_layer.neurons = stoi(network_params[i][3]);
                            output_layer.activation_function = network_params[i][4]; //TODO make actfunc class
                            output_layer.biases;
                            output_layer.weights;

                            break;
                        
                        default:
                            std::cout << "no idx found" << std::endl; //look up better error handling
                            break;
                    }

                    network.push_back(input_layer);

                    //build embedded layers
                    for(int j=0; j<num_layers; j++)
                    {
                        embedded_layer.neurons = network_struct[j];
                        embedded_layer.activation_function = network_params[i][4]; //TODO make actfunc class
                        embedded_layer.biases;
                        embedded_layer.weights;

                        network.push_back(embedded_layer);
                    }
                }

                else
                {
                    std::cout << "no network found for name: " << network_name << std::endl;
                }
            }
        }

        void ReadTrianingData()
        {
            //input .dat file for training data
        }

        void Train()
        {
            // train neural network
        }

        void feed_forward()
        {
            
        }
    
};

#endif