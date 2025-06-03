#include<iostream>
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

struct Student
{
    std::string surname;
    int* marks = CreateArray<int>(5);
    double midMark{};
};


void InputAllStudent(Student* allStudent,int quantityStudent)
{
    std::cout << "Input surmane student and his marks:\n";
    for(size_t i{}; i < quantityStudent; ++i)
    {
        std::cin >> allStudent[i].surname;
        for(int j{}; j < 5; ++j)
        {
            std::cin >> allStudent[i].marks[j];
        } 
    }
}

void CountAllStudMidMarks(Student* allStudent,int quantityStudent)
{
    double midMark{};

    for (size_t i{}; i < quantityStudent; ++i)
    {      
        for (int j{}; j < 5; ++j)
        {
            midMark += allStudent[i].marks[j];
        }
        midMark /= 5;
        allStudent[i].midMark = midMark;
    }
}

int compare(const void *arg1, const void *arg2)
{
    return *((int*)arg1) - *((int*)arg2);
}

int main()
{
    std::cout << "Input quantity student";
    int quantityStudent{};
    std::cin >> quantityStudent;
    Student* allStudent;
    InputAllStudent(allStudent,quantityStudent);
    CountAllStudMidMarks(allStudent,quantityStudent);
    qsort(allStudent->marks,quantityStudent,sizeof(int),compare);
    
    return 0;
}