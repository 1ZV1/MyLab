#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

template <typename T>
T* CreateArray(int32_t sizeArr)
{
    if (sizeArr <= 0)
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T* array = new T[sizeArr] {};
    return array;
}

void CheckInputFile(std::ifstream& fin)
{
    if(!fin.good())
    {
        throw "file isn`t exist!\n";
    }
    if(!fin)
    {
        throw "input file error!\n";
    }
    if(fin.peek() == EOF)
    {
        throw "file is empty!\n";
    }
}

void CheckOutputFile(std::ofstream& fout)
{
    if(!fout.good())
    {
        throw "file isn`t exist!\n";
    }
    if(!fout)
    {
        throw "output file error!\n";
    }
}

template<typename T>
size_t CountFile(std::ifstream& fin)
{
    size_t counter{};
    T num{};
    while (fin >> num)
    {
        ++counter;
    }
    return counter;
}

template<typename T>
void FillArr(std::ifstream& fin, T* arr, size_t sizeArr)
{
    fin.clear();
    fin.seekg(0);
    for(size_t i{}; i < sizeArr; ++i)
    {
        fin >> arr[i];
    }
}

template<typename T>
void FileOutputArr(std::ostream& fout, T* arr, size_t sizeArr)
{
    for(size_t i{}; i < sizeArr; ++i)
    {
        fout << arr[i] << ' ';
    }
    fout <<'\n';
}

template<typename T>
void Merge(T* arr,int left,int mid,int right)
{
    const int sizeLArr{mid - left + 1};
    const int sizeRArr{right - mid};
    T* leftArr = CreateArray<T>(sizeLArr);
    T* rightArr = CreateArray<T>(sizeRArr);
    for (int i{}; i < sizeLArr; ++i)
    {
        leftArr[i] = arr[left + i];
    }
    for (int i{}; i < sizeRArr; ++i)
    {
        rightArr[i] = arr[mid + 1 + i];
    }
    int i{},j{},k{left};
    for(; i < sizeLArr && j < sizeRArr; ++k)
    {
        if(leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
    }
    while(i < sizeLArr)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }
    while(j < sizeRArr)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
    delete[] leftArr;
    delete[] rightArr;
}

int compareIncrease(const void *arg1, const void *arg2)
{
    return *((double*)arg1) - *((double*)arg2);
}

int compareDecrease(const void *arg1, const void *arg2)
{
    return  *((double*)arg2) - *((double*)arg1);
}

template<typename T>
void MergeSort(T* arr,int left,int right)
{
    if(left >= right)
    {
        return;
    }
    int mid{left + (right - left) / 2};
    MergeSort<T>(arr,left,mid);
    MergeSort<T>(arr,mid + 1,right);
    Merge<T>(arr,left,mid,right);
}

template<typename T>
void SelectionSort(T* arr,int sizeArr,bool increase)
{
    int minElemIndex{};
    for(int i{}; i < sizeArr - 1; ++i)
    {
        minElemIndex = i;
        if(increase)
        {
            for(int j{i + 1}; j < sizeArr; ++j)
            {
                if(arr[j] < arr[minElemIndex])
                {
                    minElemIndex = j;
                }
            }
        }
        else
        {
            for(int j{i + 1}; j < sizeArr; ++j)
            {
                if(arr[j] > arr[minElemIndex])
                {
                    minElemIndex = j;
                }
            }
        }

        if(minElemIndex != i)
        {
            std::swap(arr[minElemIndex],arr[i]);
        }
    }
}

template<typename T>
void BubbleSort(T* arr, const int sizeArr, bool increase)
{
    if(increase)
    {
        for (int j{1}; j < sizeArr; j++)
        {
            bool isSorted{false};
            for (int i{}; i < sizeArr - j; i++)
            {
                if (arr[i] > arr[i + 1])
                {
                    std::swap(arr[i],arr[i + 1]);
                    isSorted = true;
                }
            }
            if (isSorted == false)
            {
                break;
            }
        }
    }
    else
    {
        for (int j{1}; j < sizeArr; j++)
        {
            bool isSorted{false};
            for (int i{}; i < sizeArr - j; i++)
            {
                if (arr[i] < arr[i + 1])
                {
                    std::swap(arr[i],arr[i + 1]);
                    isSorted = true;
                }
            }
            if (isSorted == false)
            {
                break;
            }
        }
    }
}

bool CheckChoise(int a)
{
    return a == 1 || a == 2;
}

int CountAfterDot(double num)
{
    std::string str{std::to_string(num)};
    str.erase(str.find_last_not_of('0'),std::string::npos);
    size_t dotPos{str.find('.')};
    if(dotPos == std::string::npos)
    {
        return 0;
    }
    return str.length() - dotPos;
}

int CompareFractionalIncrease(const void* arg1, const void* arg2)
{
    const double num1{*((double*)arg1)};
    const double num2{*((double*)arg2)};
    int digits1{CountAfterDot(num1)};
    int digits2{CountAfterDot(num2)};
    return digits1 - digits2;
}

int CompareFractionalDecrease(const void* arg1, const void* arg2)
{
    const double num1{*((double*)arg1)};
    const double num2{*((double*)arg2)};
    int digits1{CountAfterDot(num1)};
    int digits2{CountAfterDot(num2)};
    return digits2 - digits1;
}

template<typename T>
void InsertionSort(T* arr,int sizeArr,bool increase)
{
    if(increase)
    {
        for(int i{ 1 },j{}; i < sizeArr; ++i)
        {
            T temp{arr[i]};
            j = i - 1;
            while(j >= 0 && arr[j] > temp)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = temp;
        }
    }
    else
    {
        for(int i{ 1 },j{}; i < sizeArr; ++i)
        {
            T temp = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] < temp)
            {
                arr[j + 1] = arr[j];
                --j;
            }
            arr[j + 1] = temp;
        }
    }
}

int main()
{
    std::ifstream fin("in.txt");
    try
    {
        CheckInputFile(fin);
        std::ofstream fout("in.txt",std::ios::app);
        CheckOutputFile(fout);
        int sizeArr{CountFile<double>(fin)};
        std::cout << "What sort do you want explore: \n1.Qsort\n2.Merge sort\n3.Bubble sort\n";
        std::cout << "4.Selection sort.\n5.Insertion sort.\n6.Qsort by the number of digits in the fraction.\n";
        int choise{};
        std::cin >> choise;
        double* arr = new double[sizeArr];
        FillArr<double>(fin,arr,sizeArr);
        switch (choise)
        {
        case 1:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    qsort(arr,sizeArr,sizeof(double),compareIncrease);
                }
                else
                {
                    qsort(arr,sizeArr,sizeof(double),compareDecrease);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        case 2:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    MergeSort<double>(arr,sizeArr,true);
                }
                else
                {
                    MergeSort<double>(arr,sizeArr,false);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        case 3:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    BubbleSort<double>(arr,sizeArr,true);
                }
                else
                {
                    BubbleSort<double>(arr,sizeArr,false);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        case 4:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    SelectionSort<double>(arr,sizeArr,true);
                }
                else
                {
                    SelectionSort<double>(arr,sizeArr,false);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        case 5:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    InsertionSort<double>(arr,sizeArr,true);
                }
                else
                {
                    InsertionSort<double>(arr,sizeArr,false);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        case 6:
        {
            std::cout << "How you want sort array?\n1.Increase.\n2.Decrease.\n";
            int choise{};
            std::cin >> choise;
            if(CheckChoise(choise))
            {
                if(choise == 1)
                {
                    qsort(arr,sizeArr,sizeof(double),CompareFractionalIncrease);
                }
                else
                {
                    qsort(arr,sizeArr,sizeof(double),CompareFractionalDecrease);
                }
                std::cout << "Result sorting of array:" << '\n';
                FileOutputArr<double>(fout,arr,sizeArr);
            }
            else
            {
                std::cout << "Wrong value";
            }
            break;
        }
        default:
        {
            std::cout << "Input real value.\n" << '\n';
            break;
        }
        }
        delete[] arr;
        fout.close();
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
