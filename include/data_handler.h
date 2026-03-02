#ifndef __CSV_HANDLER_H__
#define __CSV_HANDLER_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;
class DataHandler
{
    protected:
        string line="", cell="";

    public:
        DataHandler() {}
        ~DataHandler() {}

        vector<vector<string>> read_csv(string file_name) //TODO: template implemntation needed

        {
            vector<vector<string>> file_output;  //matrix class? df class?
            ifstream file;

            file.open(file_name);

            if (!file.is_open())
            {
                perror("Error");
            }

            while (getline(file, line))
            {
                vector<string> row;
                stringstream lineStream(line);

                while (getline(lineStream, cell, ','))
                {
                    row.push_back(cell);
                }

                file_output.push_back(row);
            }

            return file_output;
        }

        vector<string> read_input_data(string file_name)
        {
            vector<string> output;
            string str;
            ifstream file;
            char del = ' ';

            file.open(file_name);

            if (!file.is_open())
            {
                perror("Error");
            }

            while(getline(file, str))
            {
                stringstream ss(str);
                string t;

                while(getline(ss, t, del))
                {
                    output.push_back(t);
                }
            }

            return output;
        }

        void write_to_dat(string file_name)
        {
            ofstream file(file_name);
        }
};

#endif