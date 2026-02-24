#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <iostream>
#include <vector>

#include "storage_handler.h"

using namespace std;

class InputEncoders
{
    public:
        InputEncoders() {}

        ~InputEncoders() {}

        void implement_one_hot_encoding(vector<string> input)
        {
            StorageHandler storage();
            
            int input_size = input.size();
            for(int i=0; i<input.size(); i++)
            {
                bool encoded_word_vec[input_size] = {false};
                encoded_word_vec[i] = true;
                if(!check_repeat)
                {
                    storage.insert();
                }
            }
        }

        bool check_repeat()
        {

        }

        void search_arr()
        {

        }
};

#endif