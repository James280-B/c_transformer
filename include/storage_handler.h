#ifndef __STORAGE_H__
#define __STORAGE_H__ 

#include <vector>

using namespace std;

template <typename T> class StorageHandler
{
    public:
        vector<T> storage_space;

        StorageHandler() {}
        ~StorageHandler() {}

        void Insert(T data)
        {
            storage_space.push_back(data);
        }

        vector<T> ReadStorageSpace()
        {
            return storage_space;
        }
};

#endif