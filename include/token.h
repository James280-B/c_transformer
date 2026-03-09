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

        token(int const vec_size, string input) 
        {
            word = input;
            for(int i=0; i<vec_size; i++)
            {
                one_hot_encoded_vec.push_back(false); //more efficient?
            }
        }
};

#endif