#ifndef __1HOTENC_H__
#define __1HOTENC_H__

#include "input_encoder.h"
class OneHotEncoding : public InputEncoder
{
    private:
        vector<int> assigned_words;

    public:
        OneHotEncoding() : InputEncoder(InputEncoder::input_words_vec, InputEncoder::d_size)
        {
            std::cout << "starting one hot encoding function" << std::endl;
        }

        void ImplementOneHotEncoding()
        {
            for(int i=0; i<InputEncoder::total_words; i++)
            {

                bool check = CheckAssignedWords();
                if(check)
                {

                }

                else
                {

                    assigned_words.push_back(i);
                }
            }
        }

        bool CheckAssignedWords(int target)
        {
            bool is_completed = false;
            for(int i=0; i<assigned_words.size(); i++)
            {
                std::binary_search(assigned_words.begin(), assigned_words.end(), target);
            }
                
        }
        
        ~OneHotEncoding() {}
};

#endif