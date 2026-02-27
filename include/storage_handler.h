#ifndef __STORAGE_H__
#define __STORAGE_H__ 

#include <vector>

using namespace std;

template <typename T> class StorageHandler
{
    protected:
        T data;
        vector<T> storage_space;

    public:
        StorageHandler() {}

        ~StorageHandler() {}

        insert(T data)
        {
            storage_space.push_back(data);
            return storage_space;
        }

        vector<T> read_all()
        {
            return storage_space;
        }
};

#endif