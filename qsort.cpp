#include <iostream>
#include <stdexcept>
#include <random>
#include <stdlib.h>

template <typename T>
void InputArray(T arr, int32_t sizeArr)
{
    for (int32_t i{}; i < sizeArr; ++i)
    {
        std::cin >> arr[i];
    }
    std::cout << '\n';
}

int32_t Devider(int32_t *arr, int32_t low, int32_t high)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(low, high);
    int32_t pivotIndex = dist(gen);
    int32_t pivotValue = arr[pivotIndex];

    std::swap(arr[pivotIndex], arr[high]);
    int32_t storeIndex = low;

    for (int32_t i = low; i < high; i++)
    {
        if (arr[i] < pivotValue)
        {
            std::swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    std::swap(arr[storeIndex], arr[high]);
    return storeIndex;
}

void QSortIntegerARR(int32_t *arr, int32_t low, int32_t high)
{
    int32_t p{};
    if (low < high)
    {
        p = Devider(arr, low, high);
        QSortIntegerARR(arr, low, p - 1);
        QSortIntegerARR(arr, p + 1, high);
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

// int compare(const void *arg1, const void *arg2)
// {
//     int32_t num1 = *(const int32_t*)arg1;
//     int32_t num2 = *(const int32_t*)arg2;
//     if (num1 < num2)
//     {
//         return -1;
//     }
//     else
//     if (num1 > num2)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

int32_t main()
{
    int32_t sizeArr{}, num{};
    std::cout << "Input size array: ";
    std::cin >> sizeArr;
    try
    {
        int32_t* arrF = CreateArray<int32_t>(sizeArr);
        InputArray(arrF, sizeArr);

        std::cout << "Quick sorted array: ";
        QSortIntegerARR(arrF, 0, sizeArr - 1);
        // qsort(arrF,sizeArr,sizeof(int32_t),compare);//<stdlib.h> function
        OutPutArray(arrF, sizeArr);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }    
    return 0;
}
