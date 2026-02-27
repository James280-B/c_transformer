#ifndef __STORAGE_H__
#define __STORAGE_H__ 

#include <vector>

using namespace std;

template <typename T>

class StorageHandler
{
    protected:
        T data;

    public:
        StorageHandler() 
        {
            vector<T> storage_space;
        }

        ~StorageHandler() {}

        insert(T data)
        {
            //todo
        }
        
        vector<T> read_all()
        {
            return storage_space;
        }
};

#endif