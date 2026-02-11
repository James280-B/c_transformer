#ifndef __NN_H__
#define __NN_H__

#include <iostream>
#include <fstream>
#include <vector>

#include "layer.h"
class NeuralNetwork
{
    protected:
        vector<int> network_struct; //number of embedded layer
        std::string network_name;

    public:
        NeuralNetwork() {}

        ~NeuralNetwork() {}

        vector<Layer> BuildNetwork()
        {
            int num_layers = network_struct.size();
            Layer input_layer;
            Layer output_layer;
            Layer embedded_layer;
            vector<Layer> network;

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