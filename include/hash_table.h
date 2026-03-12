#ifndef __HASH_H__
#define __HASH_H__

#include <iostream>
#include <vector>
#include <cstdint>

class HashTable
{
    private:
        uint32_t const kInitialFNV1AValue = 2166136261UL;
        uint32_t const kFNV1AConstant = 16777619;
        struct line
        {
            uint32_t index=-1;
            std::string value="";
        };

        struct table
        {
            int capacity;
        };

    protected:
        int capacity;

    public:
        HashTable(size_t table_size)
        {
            int const capacity = table_size;
            std::vector<line> table(capacity);
        }
        
        void Insert(std::string input_word)
        {
            uint8_t data=0;
            uint32_t index_value = ComputeHashFunction(input_word, data);

            //check for collisions
            if()

            //if collisions reslove

            //else add to table
        }

        uint32_t ComputeHashFunction(std::string input_word, uint8_t data) //using FNV1a from: https://github.com/amakukha/minimal_hashes/blob/main/test_minimal_hash.c#L378
        {
            uint32_t hash = kInitialFNV1AValue;
            size_t word_size = input_word.length();
            for (size_t i=0; i < word_size; i++) 
            {
                data = int(input_word[i]);
                hash *= kFNV1AConstant;
                hash ^= data;
            }

            return hash;
        }

        void Remove()
        {

        }

        int Search()
        {

        }
};

#endif
