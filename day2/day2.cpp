#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>

bool safe_input_solver(std::vector<std::string> &input)
{
    bool is_safe = true;
    int last_num = 0;
    bool is_series_lowering = false;
    int cur_num = 0;

    for (long unsigned int i = 0; i < input.size(); i++)
    {
        cur_num = atoi(input[i].c_str());

        if (i == 1)
        {
            int delta = last_num - cur_num;
            if (delta == 0 || delta > 3 || delta < -3)
            {
                is_safe = false;
                break;
            }
            if (delta > 0)
            {
                is_series_lowering = true;
            }

        }

        if (i > 1)
        {
            int delta = last_num - cur_num;
            if (is_series_lowering)
            {
                if (delta <= 0 || delta > 3)
                {
                    is_safe = false;
                    break;
                }
            }
            else
            {
                if (delta >= 0 || delta < -3)
                {
                    is_safe = false;
                    break;
                }
            }
        }
        last_num = cur_num;
    }
    return is_safe;
}

int num_of_safe_inputs(FILE* f)
{
    if (f == NULL)
        return -1;

    char line[256];
    int total_safe = 0;
    std::vector<std::vector<std::string>> total;
    long unsigned int c = 0;

    while (fgets(line, sizeof(line), f))
    {
        std::istringstream iss(line);
        std::string s;
        total.push_back(std::vector<std::string>());
        while (getline(iss, s, ' '))
        {
            total[c].push_back(s);
        }
        c++;
    }
    for (long unsigned int i = 0; i < total.size(); i++)
    {
        if (safe_input_solver(total[i]))
            total_safe++;
    }


    return total_safe;
}

int num_of_safe_inputs_redone(FILE* f)
{
    if (f == NULL)
        return -1;

    char line[256];
    int total_safe = 0;
    std::vector<std::vector<std::string>> total;
    long unsigned int c = 0;

    while (fgets(line, sizeof(line), f))
    {
        std::istringstream iss(line);
        std::string s;
        total.push_back(std::vector<std::string>());
        while (getline(iss, s, ' '))
        {
            total[c].push_back(s);
        }
        c++;
    }

    for (long unsigned int row = 0; row < total.size(); row++)
    {
        bool is_already_safe = safe_input_solver(total[row]);
        if (!is_already_safe)
        {
            std::vector<std::string> interp;
            for (long unsigned int ignore_item = 0; 
                    ignore_item < total[row].size(); ignore_item++)
            {
                for (long unsigned int item = 0; item < total[row].size(); 
                        item++)
                {
                    if (item != ignore_item)
                    {
                        interp.push_back(total[row][item]);
                    }
                }
                if (safe_input_solver(interp))
                {
                    total_safe++;
                    break;
                }
                interp.clear();
            }
        }
        else
            total_safe++;
    }
    return total_safe;
}

int main()
{  
    FILE* fi = fopen("input.txt", "r");
    FILE* fi1 = fopen("input.txt", "r");
    int t = num_of_safe_inputs(fi);
    int i = num_of_safe_inputs_redone(fi1);
    fclose(fi);
    fclose(fi1);
    printf("Number of safe inputs: %d\n", t);
    printf("Number of safe inputs changed: %d\n", i);
    return 0;
}
