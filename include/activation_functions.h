#ifndef __ACTFUNC_H__
#define __ACTFUNC_H__

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

class ActFunc
{
    public:
        ActFunc() {} 

        ~ActFunc() {}

        vector<double> compute_softmax(vector<double> input)
        {
            vector<double> output;
            double sum = 0.0;
            double value = 0.0;

            int iter = input.size();

            vector<double> exp_value(iter);

            for(int i=0; i<iter; i++)
            {
                exp_value[i] = exp(input[i]);
                sum += exp_value[i];
            }

            for(int j=0; j<iter; j++)
            {
                value = exp_value[j] / sum;
                output.push_back(value);
            }

            return output;
        }
};

#endif