#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <iostream>
#include <vector>

#include "storage_handler.h"

using namespace std;
class InputEncoders
{
    public:
        vector<string> input;
        StorageHandler<vector<bool>> storage;

        InputEncoders() {}
        ~InputEncoders() {} 

        void implement_one_hot_encoding()
        {
            int input_size = input.size();
            for(int i=0; i<input.size(); i++)
            {
                bool encoded_word_vec[input_size] = {false};
                encoded_word_vec[i] = true;
                if(!check_for_repeat)
                {
                    storage.insert(encoded_word_vec);
                } 
            }
        }

        bool check_for_repeat()
        {
            bool is_one = false;
            vector<vector<bool>> stored_vecs = storage.read_all();

            for(int i=0; i<stored_vecs.size(); i++)
            {
                
            }

            return is_one;
        }

        bool search_arr(vector<bool>)
        {   
            
        }
};

#endif