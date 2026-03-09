#ifndef __ENCODER_H__
#define __ENCODER_H__

#include <set>
#include <algorithm>

#include "token.h"
#include "storage_handler.h"

class InputEncoder
{
    protected:
        const int total_words = input_words_vec.size();
        const int total_unique_words = input_words_set.size();
        int d_size;

    public:
        set<string> input_words_set;
        vector<string> input_words_vec;
        StorageHandler<token> input_encoder_storage;

        InputEncoder(vector<string> input, const int dimension_size)
        {
            input_words_vec = input;
            d_size = dimension_size;
            
            copy(InputEncoder::input_words_vec.begin(), 
                 InputEncoder::input_words_vec.end(), 
                 inserter(input_words_set, input_words_set.end())
                ); //turn vec into set

            //create empty storage space of token
            for(int i=0; i<total_words; i++)
            {
                token tk(total_words, total_unique_words, input_words_vec[i]);
                input_encoder_storage.Insert(tk);
            }
        }

        ~InputEncoder() {}
};

#endif