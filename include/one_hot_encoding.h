#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <algorithm>
#include <set>

#include "token.h"
#include "storage_handler.h"
class OneHotEncoding
{
    protected:
        int num_unique_words=0;
        set<string> input_set;

    public:
        StorageHandler<token> encoder_storage;

        OneHotEncoding(vector<string> input) 
        {
            std::cout << "starting one hot encoding function" << std::endl;

            copy(input.begin(), input.end(), inserter(input_set, input_set.end()));

            int const num_unique_words = input_set.size();
            
            for(int i=0; i<num_unique_words; i++)
            {
                token tk(num_unique_words, input[i]);
                tk.encoded_word_vec[i] = true;
                encoder_storage.insert(tk);
            }
        }
        
        ~OneHotEncoding() {} 
};

#endif