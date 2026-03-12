#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <vector>

using namespace std;

class token
{
    protected:
        string word;
    
    public:
        vector<bool> one_hot_encoded_vec;
        vector<double> pos_encoded_vec;

        token(int const input_vec_size, int const input_set_size, string const input_word) 
        {
            word = input_word;
            pos_encoded_vec.assign(input_vec_size, 0);

            for(int i=0; i<input_set_size; i++)
            {
                one_hot_encoded_vec.push_back(false); //more efficient?
            }
        }
};

#endif