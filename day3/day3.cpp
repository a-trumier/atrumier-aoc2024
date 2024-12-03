#include <stdio.h>
#include <vector>
#include <string>
#include <stdlib.h>

#define MAX_BUF_SIZE 100

int correct_mul_do_it(FILE* fptr)
{
    char cur_char;
    std::string num1;
    std::string num2;
    bool is_num_1 = true;

    bool do_it = true;
    bool is_do_it = false;
    bool is_dont_it = false;
    int do_it_c = 0;

    char mul_char = 0;
    int return_val = 0;
    bool correct_mul_statement = false;
    while (true)
    {
        cur_char = fgetc(fptr);
        printf("Cur Char: %c\n", cur_char);
        if (cur_char == EOF)
        {
            break;
        }

        if (cur_char == 'd' && !is_do_it && !is_dont_it && do_it_c == 0)
        {
            printf("Setting doit and dont do it to true.\n");
            is_do_it = true;
            is_dont_it = true;
            do_it_c++;
        }
        else if (cur_char != 'o' && is_do_it && is_dont_it && do_it_c == 1)
        {
            printf("Setting dont do it and do it to false. No o.\n");
            is_do_it = false;
            is_dont_it = false;
            do_it_c = 0;
        }
        else if (cur_char != 'n' && is_dont_it && dont_it_c == 2)
        {
            printf("Setting dont do it to false. No n\n");
            is_dont_it = false;
        }
        else if (cur_char != 39 && is_dont_it && dont_it_c == 3)
        {
            printf("Setting dont do it to false. No apostrophe\n");
            is_dont_it = false;
        }
        else if (cur_char != 't' && is_dont_it && dont_it_c == 4)
        {
            printf("No t\n");
            is_dont_it = false;
            do_it_c = 0;
        }
        else if (cur_char != '(' && is_dont_it && do_it_c == 5)
        {
            printf("Setting dont to it to false. No opening bracket.\n");
            is_dont_it = false;
        }
        else if (cur_char != '(' && is_do_it && do_it_c == 2)
        {
            printf("Setting do it to false. No opening bracket\n");
            is_do_it = false;
        }
        else if (cur_char != ')' && is_dont_it && do_it_c == 5)
        {
            printf("Setting dont do it to false. No closing bracket\n");
            is_dont_it = false;
        }
        else if (cur_char != ')' && is_do_it && do_it_c == 3)
        {
            printf("Setting do it to false. no closing bracket.");
            is_do_it = false;
        }
        else
        {
            if (is_do_it)
            {
                do_it = true;
            }

            if (is_dont_it)
            {
                do_it = false;
            }
        }
        
        if (mul_char == 0 && cur_char == 'm')
        {
            num1 = "";
            num2 = "";
            correct_mul_statement = true;
            mul_char++;
            is_num_1 = true;
        }

        else if (mul_char == 1 && cur_char == 'u')
        {
            mul_char++;
        }
        else if (mul_char == 2 && cur_char == 'l')
        {
            mul_char++;
        }
        else if (mul_char == 3 && cur_char == '(')
        {
            mul_char++;
        }
        else if (mul_char > 3 && cur_char != ')' && cur_char != ',')
        {
            char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            if (cur_char == '0' && mul_char == 4)
            {
                num1 = "";
                num2 = "";
                correct_mul_statement = false;
                mul_char = 0;
                is_num_1 = true;
            }
            else
            {
                bool is_num = false;
                for (int i = 0; i < 10; i++)
                {
                    if (nums[i] == cur_char)
                    {
                        is_num = true;
                        break;
                    }
                }
                if (is_num)
                {
                    if (is_num_1)
                    {
                        num1 += cur_char;
                        mul_char++;
                    }
                    else
                    {
                        num2 += cur_char;
                        mul_char++;
                    }
                }
                else
                {
                    num1 = "";
                    num2 = "";
                    correct_mul_statement = false;
                    mul_char = 0;
                    is_num_1 = true;
                }
            }
        }
        else if (mul_char > 3 && cur_char == ',')
        {
            is_num_1 = false;
        }

        else if (mul_char > 3 && cur_char == ')' && !is_num_1)
        {
            if (do_it)
            {
                long int n1 = strtol(num1.c_str(), NULL, 0);
                long int n2 = strtol(num2.c_str(), NULL, 0);
                return_val += n1 * n2;
                num1 = "";
                num2 = "";
                correct_mul_statement = false;
                mul_char = 0;
                is_num_1 = true;
            
            }
            else
            {

                num1 = "";
                num2 = "";
                correct_mul_statement = false;
                mul_char = 0;
                is_num_1 = true;
            }
        }
        else
        {
            num1 = "";
            num2 = "";
            correct_mul_statement = false;
            mul_char = 0;
            is_num_1 = true;
        }

    }
    return return_val;
}

int correct_mul(FILE* fptr)
{
    char cur_char;
    std::string num1;
    std::string num2;
    bool is_num_1 = true;

    char mul_char = 0;
    int return_val = 0;
    bool correct_mul_statement = false;
    while (true)
    {
        cur_char = fgetc(fptr);
        printf("Cur Char: %c\n", cur_char);
        if (cur_char == EOF)
        {
            break;
        }
        
        if (mul_char == 0 && cur_char == 'm')
        {
            printf("mul_char 0 and m\n");
            num1 = "";
            num2 = "";
            correct_mul_statement = true;
            mul_char++;
            is_num_1 = true;
        }

        else if (mul_char == 1 && cur_char == 'u')
        {
            mul_char++;
        }
        else if (mul_char == 2 && cur_char == 'l')
        {
            mul_char++;
        }
        else if (mul_char == 3 && cur_char == '(')
        {
            mul_char++;
        }
        else if (mul_char > 3 && cur_char != ')' && cur_char != ',')
        {
            char nums[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
            if (cur_char == '0' && mul_char == 4)
            {
                num1 = "";
                num2 = "";
                correct_mul_statement = false;
                mul_char = 0;
                is_num_1 = true;
            }
            else
            {
                bool is_num = false;
                for (int i = 0; i < 10; i++)
                {
                    if (nums[i] == cur_char)
                    {
                        is_num = true;
                        break;
                    }
                }
                if (is_num)
                {
                    if (is_num_1)
                    {
                        num1 += cur_char;
                        mul_char++;
                    }
                    else
                    {
                        num2 += cur_char;
                        mul_char++;
                    }
                }
                else
                {
                    printf("Wasn't a number. clear it.");
                    num1 = "";
                    num2 = "";
                    correct_mul_statement = false;
                    mul_char = 0;
                    is_num_1 = true;
                }
            }
        }
        else if (mul_char > 3 && cur_char == ',')
        {
            is_num_1 = false;
        }

        else if (mul_char > 3 && cur_char == ')' && !is_num_1)
        {
            long int n1 = strtol(num1.c_str(), NULL, 0);
            long int n2 = strtol(num2.c_str(), NULL, 0);
            printf("N1: %ld\nN2: %ld\n", n1, n2);
            return_val += n1 * n2;
            num1 = "";
            num2 = "";
            correct_mul_statement = false;
            mul_char = 0;
            is_num_1 = true;
        }
        else
        {
            printf("didn't hit anything. reset\n");
            printf("num1: %s num2: %s\n", num1.c_str(), num2.c_str());
            num1 = "";
            num2 = "";
            correct_mul_statement = false;
            mul_char = 0;
            is_num_1 = true;
        }

    }
    return return_val;
}

int main()
{ 
    FILE* p = fopen("input.txt", "r");
    FILE* P = fopen("input_test.txt", "r");
    int i = correct_mul(p);
    int j = correct_mul_do_it(P);
    printf("Output: %d\n %d\n", i, j);
    fclose(p);
    return 0;
}
