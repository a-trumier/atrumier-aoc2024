#include <stdio.h>
#include <vector>
#include <algorithm>

bool read_vectors(std::vector<int> &l1, std::vector<int> &l2)
{
    FILE* f = fopen("input2.txt", "r");
    if (f == NULL)
    {
        return false;
    }

    int i = 0;
    int j = 0;
    while (fscanf(f, "%d,%d\n", &i, &j) != EOF)
    {
        l1.push_back(i);
        l2.push_back(j);
    }
    return true;
}

long unsigned int find_list_difference(std::vector<int> &l1, 
        std::vector<int> &l2)
{
    long unsigned int total_dist = 0;
    long unsigned int c = 0;
    while (c < l1.size())
    {
        total_dist += abs(l1[c] - l2[c]);
        c++; // HEY!
    }

    return total_dist;
}

long unsigned int find_list_similarity(std::vector<int> &l1, 
        std::vector<int> &l2)
{
    long unsigned int total_similarity = 0;

    for (long unsigned int i = 0; i < l1.size(); i++)
    {
        int appearances = 0;
        for (long unsigned int j = 0; j < l1.size(); j++)
        {
            if (l1[i] == l2[j])
                appearances++;
        }
        total_similarity += appearances * l1[i];
    }
    return total_similarity;
}

int main()
{
    std::vector<int> list1;
    std::vector<int> list2;
    read_vectors(list1, list2);

    if (list1.size() != 0)
    {
        printf("Good size of list\n");
    }

    
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    long unsigned int d = find_list_difference(list1, list2);
    long unsigned int s = find_list_similarity(list1, list2);
    
    printf("List difference: %ld\n", d);
    printf("List similarity: %ld\n", s);
    return 0;
}
