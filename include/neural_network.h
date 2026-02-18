#ifndef __NN_H__
#define __NN_H__

#include "layer.h"
#include "csv_handler.h"
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
            int num_layers = network_struct.size();
            int network_idx = 0;
            Layer input_layer;
            Layer output_layer;
            Layer embedded_layer;
            vector<Layer> network;
            vector<vector<string>> network_params;
            CSVHandler csv;

            network_params = csv.ReadCSV("data/nn_params.csv");

            for (int i=0; i<network_params.size(); i++)
            {
                string nn_names = network_params[i][0];

                if (nn_names == network_name)
                {
                    network_idx = stoi(network_params[i][1]);

                    switch (network_idx)
                    {
                        case 1:
                            //build input layer
                            input_layer.neurons = 1;  //TODO define parameters
                            input_layer.activation_function = "a";
                            input_layer.biases;
                            input_layer.weights;


                            //build output layer
                            output_layer.neurons = 1;  //TODO define parameters
                            output_layer.activation_function = "a";
                            output_layer.biases;
                            output_layer.weights;

                            break;
                        
                        default:
                            std::cout << "no idx found" << std::endl; //look up better error handling
                            break;
                    }
                }
            }

            network.push_back(input_layer);

            //build embedded layers
            for(int i=0; i<num_layers; i++)
            {
                embedded_layer.neurons = network_struct[i];

                network.push_back(embedded_layer);
                
            }
        }

        void ReadTrianingData()
        {

        }

        void ReadNetworkType()
        {

        }

        void Train()
        {
            // train neural network
        }
    
};

#endif