#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
#include<cstdlib>

struct Student
{
    char name[30];
    int group{};
    double grade{};
};

int ReadFile(Student* students, int quantityStudent,const char* fileName) 
{
    std::ifstream file(fileName);
    char str[100];
    int count{};
    while (file.getline(str,sizeof(str)) && count < 100)
    {
        char* subStr{strtok(str, ";")};
        if (subStr)
        {
            strcpy(students[count].name, subStr);
        }
        subStr = strtok(NULL, ";");
        if (subStr)
        {
            students[count].group = atoi(subStr);
        }
        subStr = strtok(NULL, ";");
        if (subStr)
        {
            students[count].grade = atof(subStr);
        }
        count++;
    }
    file.close();
    return count;
}

void WriteFile(Student* students, int count,const char* filename)
{
    std::ofstream file(filename);
    for (int i = 0; i < count; ++i)
    {
        file << students[i].name << ";" << students[i].group << ";" << students[i].grade << '\n';
    }
    file.close();
}

void SortByName(Student* students, int count)
{
    for (int i = 0; i < count - 1; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (strcmp(students[i].name, students[j].name) > 0)
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void SearchByName(Student students[], int count, const char* name)
{
    bool found {false};
    for (int i{}; i < count; ++i)
    {
        if (strcmp(students[i].name, name) == 0)
        {
            std::cout << students[i].name << ", группа: " << students[i].group << ", балл: " << students[i].grade << '\n';
            found = true;
        }
    }
    if (!found)
    {
        std::cout << "Студент с такой фамилией не найден.\n";
    }
}

void SortGroupAndName(Student students[], int count)
{
    for (int i{}; i < count - 1; ++i)
    {
        for (int j = i + 1; j < count; ++j)
        {
            if (students[i].group > students[j].group || (students[i].group == students[j].group && strcmp(students[i].name, students[j].name) > 0))
            {
                Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

void AverageGroup(Student students[], int count)
{
    int groups[100];
    int groupCount{};

    for (int i = 0; i < count; ++i)
    {
        bool exists {false};
        for (int j = 0; j < groupCount; ++j)
        {
            if (groups[j] == students[i].group)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
        {
            groups[groupCount++] = students[i].group;
        }
    }
    for (int i = 0; i < groupCount; ++i)
    {
        int group = groups[i];
        double total{};
        int num{};
        for (int j = 0; j < count; ++j)
        {
            if (students[j].group == group)
            {
                total += students[j].grade;
                num++;
            }
        }
        if (num > 0) {
            std::cout << "Группа " << group << ": средний балл = " << total / num << '\n';
        }
    }
}

int main()
{
    Student students[100];
    int count = ReadFile(students,100,"input.txt");
    int choice;
    try
    {
        std::cout << "\nМеню:\n1.Sort by surname.\n2.Find by surname.\n3.Sort groops and surnames.\n4.Groops` mid marks.\n5.Exit.\nChoose move";
        std::cin >> choice;
        switch (choice)
        {
            case 1:
            {
                SortByName(students, count);
                WriteFile(students,count,"students.txt");
                std::cout << "Completed.\n";
                break;
            }
            case 2: 
            {
                char surname[30];
                std::cout << "Input surname: ";
                std::cin.ignore();
                std::cin.getline(surname, 30);
                SearchByName(students, count, surname);
                break;
            }
            case 3:
            {
                SortGroupAndName(students, count);
                for (int i = 0; i < count; ++i)
                {
                    std::cout << students[i].name << ", groop: " << students[i].group << ", mark: " << students[i].grade << '\n';
                }
                break;
            }
            case 4:
            {
                AverageGroup(students, count);
                break;
            }  
            case 5:
            {
                std::cout << "Exit.\n";
                break;
            }
            default:
                std::cout << "Uncorrect choose.\n";
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
