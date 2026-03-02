#ifndef __STORAGE_H__
#define __STORAGE_H__ 

#include <vector>

using namespace std;

template <typename T> class StorageHandler
{
    protected:
        vector<T> storage_space;
    public:
        StorageHandler() {}

        ~StorageHandler() {}

        void insert(T data)
        {
            storage_space.push_back(data);
        }

        vector<T> read_all()
        {
            return storage_space;
        }
};

#endif