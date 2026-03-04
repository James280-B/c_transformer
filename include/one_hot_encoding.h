#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include <algorithm>

#include "token.h"
#include "storage_handler.h"
class OneHotEncoding
{
    protected:
        int input_size;
        vector<string> completed_words;
        vector<token> duplicated_tokens;

    public:
        StorageHandler<token> encoder_storage;

        OneHotEncoding(vector<string> input) 
        {
            std::cout << "starting one hot encoding function" << std::endl;

            int const input_size = input.size();

            for(int i=0; i<input_size; i++)
            {
                std::cout << "currently on word: " << i << std::endl;

                auto it = find(completed_words.begin(), completed_words.end(), input[i]);

                if(it != completed_words.end())
                {
                    std::cout << "duplicated word found" << std::endl;
                    
                    int idx = distance(completed_words.begin(), it);
                    token tk(input_size, input[i]);
                    tk.encoded_word_vec = duplicated_tokens[idx].encoded_word_vec;
                    encoder_storage.insert(tk);
                }

                else
                {
                    std::cout << "adding new word" << std::endl;

                    completed_words.push_back(input[i]);
                    token tk(input_size, input[i]);
                    tk.encoded_word_vec[i] = true;
                    duplicated_tokens.push_back(tk);
                    encoder_storage.insert(tk);
                }
            }
        }
        
        ~OneHotEncoding() {} 
};

#endif