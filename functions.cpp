#include <iostream>
#include <stdexcept>
#include <random>
#include <ctime>

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

template <typename T>
void InputArray(T arr, int32_t sizeArr)
{
    for (int32_t i{}; i < sizeArr; ++i)
    {
        std::cin >> arr[i];
    }
}

int32_t CalculatingSignChanges(int32_t *arr, int32_t sizeArr) //++
{
    int32_t k{};
    for (int32_t i{}; i < sizeArr - 1; ++i)
    {
        if ((arr[i] >= 0 && arr[i + 1] < 0) || (arr[i] < 0 && arr[i + 1] >= 0))
        {
            k++;
        }
    }
    return k;
}

int64_t MultiplikateArrElemBetweenTwoZero(int32_t *arr, int32_t sizeArr) // ++
{
    int64_t multiplikate{1};
    int32_t indexZero1{-1}, indexZero2{-1};
    for (int32_t i{}; i < sizeArr; ++i)
    {
        if (arr[i] == 0 && indexZero1 != -1)
        {
            indexZero2 = i;
            break;
        }
        if (arr[i] == 0 && indexZero1 == -1)
        {
            indexZero1 = i;
        }
    }

    if (indexZero1 == -1 || indexZero2 == -1 || indexZero2 == indexZero1 + 1)
    {
        throw std::invalid_argument("No elements present between two zeros\n");
    }
    else
    {
        for (int32_t i{indexZero1 + 1}; i < indexZero2; ++i)
        {
            multiplikate *= arr[i];
        }
        return multiplikate;
    }
}

void SortFirstEvenArrElem(int32_t *arr, int32_t sizeArr) // ++
{
    int32_t temp{};
    for(int32_t i{}; i < sizeArr; ++i)
    {
        if (arr[i] % 2 != 0)
        {
            for (int32_t j{i + 1}; j < sizeArr; ++j)
            {
                if (abs(arr[j]) % 2 == 0)
                {
                    temp = arr[j];
                    for (int32_t k{j}; k >= i; --k)
                    {
                        arr[k] = arr[k - 1];
                    }
                    arr[i] = temp;
                    break;
                }
            }
        }
    }
}

template <typename T>
void OutPutArray(T arr, int32_t sizeArr)
{
    std::cout << '\n';
    for (int32_t i{}; i < sizeArr; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';
}

int32_t CountElemArrLargeP(double *arr, int32_t sizeArr, int32_t P) // ++
{
    int32_t k{};
    for (int32_t i{}; i < sizeArr; ++i)
    {
        if (arr[i] > P)
        {
            k++;
        }
    }
    return k;
}

double MultiplikateElemArrAfterLastMax(double *arr, int32_t sizeArr) // ++
{
    double multiplikate{1};
    int32_t indexMaxElem{};
    for (int32_t i{}; i < sizeArr; ++i)
    {
        if (arr[indexMaxElem] < arr[i])
        {
            indexMaxElem = i;
        }
    }

    if (indexMaxElem + 1 > sizeArr)
    {
        std::cout << "Haven`t any elements after max!\n";
    }
    else
    {
        for (int32_t i{indexMaxElem}; i < sizeArr; ++i)
        {
            multiplikate *= arr[i];
        }
    }
    return multiplikate;
}

void SortNegativeElemArr(double *arr, int32_t sizeArr) // ++
{
    double temp{};
    for (int32_t i{}; i < sizeArr; ++i)
    {
        for (int32_t j{i + 1}; j < sizeArr; ++j)
        {
            if (arr[j] < 0)
            {
                temp = arr[j];
                for (int32_t k{j}; k >= i; --k)
                {
                    arr[k] = arr[k - 1];
                }
                arr[i] = temp;
                break;
            }
        }
    }
}

template<typename T>
void RandomInputMTR(T** arr, int32_t rows, int32_t cols)
{
    std::random_device rd;   
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1,9); 

    for (int i = 0; i < rows; ++i) 
    {
        for(int32_t j{}; j < cols; ++j)
        {
            arr[i][j]  = dist(gen);
        }
    }
}

template<typename T>
void RandomInputArray(T* arr, int32_t n, int32_t a, int32_t b)
{
    std::random_device rd;   
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(a,b); 

    for (int i = 0; i < n; ++i) 
    {
            arr[i]  = dist(gen);
    }
}

template <typename T>
T* CreateMatrix(int32_t rows, int32_t cols)
{
    if (rows <= 0 || cols <= 0) // check
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T** mtr = new T*[rows]; 
    for (int32_t i = 0; i < rows; ++i) {
        mtr[i] = new T[cols]; 
    }
    return mtr;
}

template <typename T>
T* DeleteMatrix(T**& mtr, int32_t rows, int32_t cols)
{
    for (int32_t i = 0; i < rows; ++i) {
        delete[] mtr[i]; 
    }
    delete[] mtr; 
    mtr = nullptr; 
}
