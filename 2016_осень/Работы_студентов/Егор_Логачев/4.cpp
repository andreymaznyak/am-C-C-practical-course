#include <ctime>
#include <cstdlib>
#include <iostream>
 
void randomize(int **matrix, int rows, int cols)
{
    srand(time(0));
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            matrix[i][j] = rand() % 100;
        }
    }
}
 
void print(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; ++i)
    {
        int last = cols - 1;
        for (int j = 0; j < last; ++j)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << matrix[i][last] << std::endl;
    }
}
 
int main()
{
    int rows = 0, cols = 0;
    
    std::cout << "Введите число эл-ов в матр: " << std::endl;
    std::cin >> rows >> cols;
 
    int **matrix = new int*[rows];
    for (int i = 0; i < rows; ++i)
    {
        matrix[i] = new int[cols]();
    }
 
    randomize(matrix, rows, cols);
 
    std::cout << "Матрица: " << std::endl;    
    print(matrix, rows, cols);
 
    int max = 0, col = 0;
    for (int i = 0; i < rows; ++i)
    {
       max += matrix[i][0];
    }
    
    for (int j = 1; j < cols; ++j)
    {
        int temp = 0;
        for (int i = 0; i < rows; ++i)
        {
            temp += matrix[i][j];
        }
 
        if (temp > max)
        {
            max = temp;
            col = j;
        }
    }
 
    std::cout << "Макс сумма " << max << " " 
              << "Кол: " << col << std::endl;
 
 
    for (int i = 0; i < rows; ++i)
        delete[] matrix[i];
    delete[] matrix;
 
    return 0;}
