#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <iostream>

#include "storage_handler.h"
class InputEncoders
{
    protected:
        StorageHandler<vector<bool>> storage;

    public:
        InputEncoders() {}
        ~InputEncoders() {} 

        void read_num_unique_words(vector<string> input)
        {

        }

        void implement_one_hot_encoding(vector<string> input)
        {
            int input_size = input.size();
            for(int i=0; i<input.size(); i++)
            {
                std::cout << "completing run " << i << " of 1he" << std::endl;
                vector<bool> encoded_word_vec(input_size, false);
                encoded_word_vec[i] = true;
                bool check = check_for_repeat(i);
                std::cout << "check value" << std::endl;
                std::cout << check << std::endl;
                if(!check)
                {
                    storage.insert(encoded_word_vec);
                } 
            }
        }

        bool check_for_repeat(int idx)
        {
            std::cout << "completing run " << idx << " of check" << std::endl;
            bool is_one = false;
            vector<vector<bool>> stored_vecs = storage.read_all(); //todo upgrade later
            
            std::cout << "checking for first" << std::endl;
            if(stored_vecs.size() == 0)
            {
                return is_one;
            }

            std::cout << "checking for 1" << std::endl;

            if(stored_vecs[idx][idx])
            {
                is_one = true;
            }

            return is_one;
        }
};

#endif