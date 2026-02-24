#ifndef __CSV_HANDLER_H__
#define __CSV_HANDLER_H__

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

class DataHandler
{
    protected:
        std::string line="", cell="";

    public:
        DataHandler() {}

        ~DataHandler() {}

        std::vector<std::vector<std::string>> ReadCSV(std::string file_name) //TODO: template implemntation needed

        {
            std::vector<std::vector<std::string>> file_output;  //matrix class? df class?
            std::ifstream file;

            file.open(file_name);

            if (!file.is_open())
            {
                perror("Error");
            }

            while (getline(file, line))
            {
                std::vector<std::string> row;
                std::stringstream lineStream(line);

                while (std::getline(lineStream, cell, ','))
                {
                    row.push_back(cell);
                }

                file_output.push_back(row);
            }

            return file_output;
        }
};

#endif