#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>> &array, int k, int low, int high);

int main()
{
    std::vector<std::vector<int>> array = {{1,2,3,4,5}, {11,12,13,14,15}, {21,22,23,24,25}, {31,32,33,34,35},{41,42,43,44,45}};
    int k = 4;
    int rows = array.size();
    int cols = array[0].size();
    
    std::cout << "rows = " << rows << ", cols = " << cols << std::endl;
    
    for(int i=0; i<rows/2; ++i)
        rotate(array, k, i, rows-1-i);
    
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
            std::cout << array[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}

void rotate(std::vector<std::vector<int>> &array, int k, int low, int high)
{
    int rows = array.size();
    int cols = array[0].size();
    std::vector<int> swap;
    std::cout << "rows = " << rows << ", cols = " << cols << std::endl;
    
    for(int i=low,j=low; j<=high; ++j)
    {
        swap.push_back(array[i][j]);
        std::cout << array[i][j] << std::endl;
    }
    
    for(int i=high,j=low+1; j<=high; ++j)
    {
        swap.push_back(array[j][i]);
        std::cout << array[j][i]<< std::endl;
    }
    
    for(int i=high,j=high-1; j>=low; --j)
    {
        swap.push_back(array[i][j]);
        std::cout << array[i][j]<< std::endl;
    }
    
    for(int i=low,j=high-1; j>low; --j)
    {
        swap.push_back(array[j][i]);
        std::cout << array[j][i] << std::endl;
    }
    
    int swap_size = swap.size();
    std::cout << swap_size << std::endl;
    for(int i=0; i<swap_size; ++i)
        std::cout << swap[i] << ", ";
    std::cout << std::endl;
    
    std::vector<int> temp;
    for(int i=swap_size-k; i<swap_size; ++i)
        temp.push_back(swap[i]);
        
    for(int i=swap_size-k-1,j=1; i>=0,j<=swap_size-k; --i,++j)
    {
        swap[swap_size-j] = swap[i];
    }
    
    for(int i=0; i<k; ++i)
    {
        swap[i] = temp[i];
    }
    
    for(int i=0; i<swap_size; ++i)
        std::cout << swap[i] << ", ";
    std::cout << std::endl;
    
    int index = 0;
    for(int i=low,j=low; j<=high; ++j)
    {
        array[i][j] = swap[index];
        index++;
    }
    
    for(int i=high,j=low+1; j<=high; ++j)
    {
        array[j][i] = swap[index];
        index++;
    }
    
    for(int i=high,j=high-1; j>=low; --j)
    {
        array[i][j] = swap[index];
        index++;
    }
    
    for(int i=low,j=high-1; j>low; --j)
    {
        array[j][i] = swap[index];
        index++;
    }
     
    /*for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
            std::cout << array[i][j] << " ";
        std::cout << std::endl;
    }*/
}
