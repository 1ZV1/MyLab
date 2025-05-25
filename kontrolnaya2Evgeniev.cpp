#include<iostream>
#include<cstring>
#include<stdexcept>
#include<cstdlib>

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
void InputMTR(T**& arr, int32_t rows, int32_t cols)
{
    for (size_t i{}; i < rows; ++i)
    {
        std::cin.getline(arr[i],cols);
    }
    std::cout << '\n';
}

void OutputStr(char** arrStr, int32_t rows)
{
    for(size_t i{}; i < rows; ++i)
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
    int32_t k{ 1 };
    for(size_t i{}, j{}; i < rows; ++i)
    {
        k = 1;
        j = 0;
        arrNum[i] = 0;
        while(arrStr[i][j] != ' ')
        {
            ++j;
        }
        ++j;
        if(arrStr[i][j] == '-')
        {
            k *= -1;
            ++j;
        }
        while(arrStr[i][j] >= '0' && arrStr[i][j] <= '9')
        {
            arrNum[i] = (arrStr[i][j] - '0') + arrNum[i]*10;
            ++j;
        }
        arrNum[i] *= k;
    }
}

void SortString(int32_t* arrNum, char**& arrStr, int32_t rows, int32_t(*FindIndex)(int32_t*,int32_t,int32_t))
{
    int32_t k{ 1 },num{}, index{};
    for(size_t i{}, j{}; i < rows; ++i)
    {
        k = 1;
        j = 0;
        num = 0;
        while(arrStr[i][j] != ' '&& arrStr[i][j] != '\0')
        {
            ++j;
        }
        if (arrStr[i][j] == '\0') 
        {
            continue;
        }
        ++j;
        if(arrStr[i][j] == '-')
        {
            k *= -1;
            ++j;
        }
        while(arrStr[i][j] >= '0' && arrStr[i][j] <= '9')
        {
            num = (arrStr[i][j] - '0') + num*10;
            ++j;
        }
        num *= k;
        index = FindIndex(arrNum,rows,num);
        std::cout << index << ' ';
        if (index < 0 || index >= rows)
        {
            std::cerr << "Index out of bounds for value: " << num << std::endl;
            continue;
        }
        if (i != index)
        {
            char* temp = arrStr[i];
            arrStr[i] = arrStr[index];
            arrStr[index] = temp;
        }
    }
}

int32_t IndexBinaryFindInARR(int32_t* arr, int32_t sizeArr, int32_t num)
{
    int32_t left = 0;
    int32_t right = sizeArr - 1;
    while (left <= right)
    {
        int32_t mid = left + (right - left) / 2;
        
        if (arr[mid] == num)
        {
            return mid;
        }
        else if (arr[mid] < num)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    std::cerr << "Not find num " << num << " in array!!";
    return -1;
}

template <typename T> 
void OtputArr(T* arr, size_t size)
{
    for(size_t i{}; i < size; ++i)
    {
        std::cout << arr[i] << ' ';
    }
}

int64_t SummArrElem(int32_t* arr, int32_t size)
{
    int64_t summ{};
    for(int32_t i{}; i < size; ++i)
    {
        summ += arr[i]; 
    }
    return summ;
}

int32_t compare(const void* x1, const void* x2)
{
    return *((int32_t*)x1) - *((int32_t*)x2);
}

int main()
{
    int32_t n{};
    std::cout << "How many strings you want input?\n";
    std::cin >> n;

    char** arrStr =  CreateMatrix<char>(n,100);
    std::cin.ignore();
    InputMTR<char>(arrStr,n,100);
    int64_t summ{};
    int32_t maxNum{}, minNum{};
    int32_t* arrNum = CreateArray<int32_t>(n);
    
    ExtractNumFromStr(arrNum,arrStr,n);
    summ = SummArrElem(arrNum,n);
    std::cout << "Summ all numbers from strings " << summ;

    qsort(arrNum,n,sizeof(int32_t),compare);
    SortString(arrNum,arrStr,n,IndexBinaryFindInARR);
    
    OtputArr<int32_t>(arrNum,n);
    std::cout << '\n';
    OutputStr(arrStr, n);
    DeleteMatrix<char>(arrStr,n,100);
    delete[] arrNum;
    return 0;
}
