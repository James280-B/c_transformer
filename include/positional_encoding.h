#ifndef __POS_ENC_H__
#define __POS_ENC_H__

#include <cmath>

#include "input_encoder.h"

class PositionalEnconding : InputEncoder
{
    private:
        const int param_conant = 10000; //todo fix constants 
        double exp_term = 0.0;

    public:
        PositionalEnconding() : InputEncoder(InputEncoder::input_words_vec, InputEncoder::d_size) //make into functions
        {
            for(int pos=1; pos<InputEncoder::total_words+1; pos++)
            {
                for(int i=0; i<InputEncoder::d_size; i++)
                {
                    double exp_term = (2*i)/d_size;

                    if(i%2==0)
                    {
                        double pos_encoder_i = sin(pos/pow(param_conant, exp_term));
                        InputEncoder::input_encoder_storage.storage_space[pos].pos_encoded_vec[i] = pos_encoder_i;
                    }

                    else
                    {
                        double pos_encoder_i = cos(pos/pow(param_conant, exp_term));
                        InputEncoder::input_encoder_storage.storage_space[pos].pos_encoded_vec[i] = pos_encoder_i;
                    }
                }
            }
        }

        ~PositionalEnconding() {}
};
#endif