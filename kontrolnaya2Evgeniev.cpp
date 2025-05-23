#include <iostream>

template <typename T>
T** CreateMatrix(int32_t rows, int32_t cols)
{
    if (rows <= 0 || cols <= 0) // check
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T** mtr = new T*[rows]; 
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

template <typename T>
void InputMTR(T **&arr, int32_t rows, int32_t cols)
{
    for (size_t i{}; i < rows; ++i)
    {
        std::cin.getline(arr[i],100);
    }
    std::cout << '\n';
}

void OutputStr(char** arrStr, int32_t cols)
{
    for(size_t i{}; i < cols; ++i)
    {
            std::cout << arrStr[i] << '\n';
    }
}

template <typename T>
T* CreateArray(int32_t sizeArr)
{
    if (sizeArr <= 0)
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T* array = new T[sizeArr]{};
    return array;
}

void ExtractNumFromStr(int32_t* arrNum, char** arrStr, int32_t rows)
{
    int32_t k{};
    for(size_t i{},j{}; i < rows; ++i)
    {
        while (arrStr[i][j] != '-' || (arrStr[i][j] >= '1' && arrStr[i][j] <= '9'))
        {
            ++j;
            ++k;
        }
        j = 0;
        std::cout << k;
    }

}

int main()
{
    int32_t n{};
    std::cout << "How many strings you want input?";
    std::cin >> n;

    char** arrStr =  CreateMatrix<char>(n,100);
    InputMTR<char>(arrStr,5,100);
    int64_t summ{};
    int32_t maxNum{}, minNum{};
    int32_t* arrNum = CreateArray<int32_t>(n);
    
    //ExtractNumFromStr(arrNum,arrStr,n);



    OutputStr(arrStr, n);
    DeleteMatrix<char>(arrStr,5,100);
    delete[] arrNum;
}
