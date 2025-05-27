#include <iostream>
#include <exception>
#include <cstring>

template <typename T>
T *CreateArray(int32_t sizeArr)
{
    if (sizeArr <= 0)
    {
        throw std::invalid_argument("Size of the array must be large than zero.");
    }
    T *array = new T[sizeArr]{};
    return array;
}

bool IsEmpty(char *str)
{
    return *str == '\0';
}

bool isDigitWord(const char* word, int len)
{
    for(int32_t i{}; i < len; ++i)
    {
        if(!(word[i] >= '0' && word[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

void SortWordInSTR(char*& str1)
{
    bool stepNum{true};
    char* str2 = new char[strlen(str1) + 1]{};
    int32_t k{};
    for(int32_t pass{}; pass < 2; ++pass) 
    {
        char* wordEnd = str1;
        while(*wordEnd) 
        {
            while(*wordEnd == ' ')
            {
                ++wordEnd;
            }
            if(!*wordEnd)
            {
                break;
            }
            char* wordStart = wordEnd;
            while(*wordEnd && *wordEnd != ' ') 
            {
                ++wordEnd;
            }

            int64_t wordLen {wordEnd - wordStart};
            bool isDigit {isDigitWord(wordStart, wordLen)};

            if((pass == 0 && ((stepNum && isDigit) || (!stepNum && !isDigit))) || pass == 1)
            {
                if(k > 0) 
                {
                    str2[k++] = ' ';
                }

                for (int32_t i{}; i < wordLen; ++i)
                {
                    str2[k++] = wordStart[i];
                }
                
                memset(wordStart, ' ', wordLen);
                
                if(pass == 0)
                {
                    stepNum = !stepNum;
                }
            }
        }
    }
    str2[k] = '\0';
    strcpy(str1, str2);
    delete[] str2;
}


int32_t main()
{
    char *str = CreateArray<char>(100);
    std::cout << "Input string:\n";
    std::cin.getline(str, 100);
    try
    {
        if (IsEmpty(str))
        {
            throw std::invalid_argument("Is empty!\n");
        }
        SortWordInSTR(str);
        std::cout << str << '\n';
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    delete []str;
    return 0;
}