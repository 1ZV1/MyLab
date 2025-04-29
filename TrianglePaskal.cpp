#include<iostream>
#include<stdexcept>

void OutputPaskalTriangle(int32_t**& mtr, int32_t n)
{
    if (n == 1)
    {
        std::cout << '1';
    }
    else
    {
        std::cout << "1\n";
        for (int32_t i{}; i <= n; ++i)
        {
            mtr[0][i] = 1;
            for (int32_t j{}; j <= i; ++j)
            {
                mtr[1][j] = mtr[0][j - 1] + mtr[0][j];
                std::cout << mtr[1][j] << ' ';
            }
            std::cout << "1\n";
            for (int32_t k{}; k <= i; ++k)
            {
                mtr[0][k] = mtr[1][k];
            }
        }
    }
}

template <typename T>
T** CreateMatrix(int32_t rows, int32_t cols)
{
    if (rows <= 0 || cols <= 0)
    {
        throw std::invalid_argument("Size of the array must be greater than zero.");
    }
    T** mtr = new T* [rows];
    for (int32_t i{}; i < rows; ++i)
    {
        mtr[i] = new T[cols]{};
    }
    return mtr;
}

template <typename T>
void DeleteMatrix(T** &mtr, int32_t rows)
{
    for (int32_t i{}; i < rows; ++i)
    {
        delete[] mtr[i];
    }
    delete[] mtr;
    mtr = nullptr;
}

int main()
{
    int32_t n{};
    std::cin >> n;

    int32_t** triangle = CreateMatrix<int32_t>(2, n);
    triangle[0][0] = 1;
    triangle[0][1] = 1;

    OutputPaskalTriangle(triangle, n);

    DeleteMatrix(triangle, 2);
    return 0;
}
