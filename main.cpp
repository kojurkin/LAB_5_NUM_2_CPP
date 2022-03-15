#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>

static const int MAX_SIZE = 50;

int main()
{
    double array[MAX_SIZE][MAX_SIZE];
    int  width, height;
    do
    {
        std::cout << "Enter width and height < " << MAX_SIZE;
        std::cin >> width >> height;
    } while (width > MAX_SIZE && height > MAX_SIZE);
    std::ifstream inputfile ("output.txt");
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            if(inputfile.peek() == EOF)
            {
                std::cout << "ERROR: not enough elements in file";
                return 1;
            }
            inputfile >> array[i][j];
        }
    }
    for(int i = 0; i < width; i++)
    {
        for(int j = 0; j < height; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
    inputfile.close();
    return 0;
}
