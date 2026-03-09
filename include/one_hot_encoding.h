#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <algorithm>
#include <set>

#include "input_encoder.h"
class OneHotEncoding : public InputEncoder
{
    private:
        const set<string> input_set={};

    public:
        OneHotEncoding() : InputEncoder(InputEncoder::input_words_vec, InputEncoder::d_size)
        {
            std::cout << "starting one hot encoding function" << std::endl;

            copy(InputEncoder::input_words_vec.begin(), 
                 InputEncoder::input_words_vec.end(), 
                 inserter(input_set, input_set.end())
                ); //turn vec into set

            for(int i=0; i<InputEncoder::total_words; i++) //fix sizing issue
            {
                InputEncoder::input_encoder_storage.storage_space[i].one_hot_encoded_vec[i] = true;
            }
        }
        
        ~OneHotEncoding() {}
};

#endif