#include <iostream>
#include <ctime>
#include <random>

template <typename T>
void OutputMTR(T **mtr, int32_t n, int32_t m)
{
    for (int32_t i{}; i < n; ++i)
    {
        for (int32_t j{}; j < m; ++j)
        {
            std::cout << mtr[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

template <typename T>
void RandomInputArray(T **arr, int32_t rows, int32_t cols)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 9);

    for (int i = 0; i < rows; ++i)
    {
        for (int32_t j{}; j < cols; ++j)
        {
            arr[i][j] = dist(gen);
        }
    }
}

template <typename T>
void UlitkaOutput(T **mtr, int32_t n, int32_t m) 
{
    int32_t i{}, j{}, ots{};
    int64_t k{};
    int64_t elemArr{n * m};

    
    while (k < elemArr) {
        
        for (j = ots  ; j < m; ++j)
        {
            if (k < elemArr) 
            {
                std::cout << mtr[ots][j] << ' '; 
                ++k;
            }
        }
        std::cout << '\n';
        ++ots;
        for (i = ots; i < n; ++i) 
        {
            if (k < elemArr)
            {
                std::cout << mtr[i][m - 1] << ' ';
                ++k;
            }
        }
        std::cout << '\n'; 
        --m;

        if (ots <= n) 
        {
            for (j = m - 1; j >= ots - 1; --j)
            {
                if (k < elemArr)
                {
                    std::cout << mtr[n - 1][j] << ' '; 
                    ++k;
                }
            }
            std::cout << '\n';
            --n; 
        }

        if (ots < n)
        {
            for (i = n - 1; i >= ots; --i)
            {
                if (k < elemArr)
                {
                    std::cout << mtr[i][ots - 1] << ' ';
                    ++k;
                }
            }
            std::cout << '\n';
        }
    }
}

template <typename T>
T** CreateMatrix(int32_t rows, int32_t cols)
{
    if (rows <= 0 || cols <= 0) // check
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T **mtr = new T *[rows];
    for (int32_t i = 0; i < rows; ++i)
    {
        mtr[i] = new T[cols];
    }
    return mtr;
}

template <typename T>
void DeleteMatrix(T **&mtr, int32_t rows, int32_t cols)
{
    for (int32_t i = 0; i < rows; ++i)
    {
        delete[] mtr[i];
    }
    delete[] mtr;
    mtr = nullptr;
}

int32_t main()
{
    int32_t n{}, m{};
    std::cin >> n >> m;
    int32_t **mtr = CreateMatrix<int32_t>(n, m);

    RandomInputArray(mtr, n, m);
    OutputMTR(mtr, n, m);
    std::cout << '\n';
    UlitkaOutput(mtr, n, m);

    DeleteMatrix<int32_t>(mtr, n, m);
    return 0; 
}