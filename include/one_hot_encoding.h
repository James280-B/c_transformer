#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <iostream>
#include <vector>

#include "storage_handler.h"

using namespace std;

class InputEncoders
{
    public:
        StorageHandler<bool[]> storage;

        InputEncoders() {}
        ~InputEncoders() {} 

        void implement_one_hot_encoding(vector<string> input)
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

        bool check_for_repeat(int i)
        {
            //read data set
            //check all elements for i if 1 exists
            //return T if so F if not
            
        }

        void search_arr()
        {

        }
};

#endif