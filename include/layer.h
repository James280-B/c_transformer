#ifndef __LAYER_H__
#define __LAYER_H__

#include <iostream>
#include <vector>

using namespace std;

struct Layer
{
    int neurons;
    string activation_function;
    vector<double> biases;
    vector<vector<double>> weights; //TODO: make matrix class?
};

#endif