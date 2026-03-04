#ifndef __TOKEN_H__
#define __TOKEN_H__

#include <iostream>
#include <vector>

class token
{
    protected:
        std::string word;
    
    public:
        std::vector<bool> encoded_word_vec;
        token(int vec_size, std::string input) 
        {
            word = input;
            for(int i=0; i<vec_size; i++)
            {
                encoded_word_vec.push_back(false); //more efficient?
            }
        }
};

#endif