#include<iostream>
#include<string>
#include<algorithm>

void CheckWordCondition(std::string& subStr)
{
    bool isNum{true};
    for (size_t i{}; i < subStr.length(); ++i)
    {
        if (!isdigit(subStr[i]))
        {
            isNum = false;
            break;
        }
    }
    if (isNum && subStr.length() < 7)
    {
        std::reverse(subStr.begin(), subStr.end());
    }
    else
    {
        if (!isNum)
        {
            bool isWord = true;
            for (size_t i{}; i < subStr.length(); ++i)
            {
                if (!isalpha(subStr[i]))
                {
                    isWord = false;
                    break;
                }
            }
            if (isWord)
            {
                for (size_t i{}; i < subStr.length(); ++i)
                {
                    subStr[i] = tolower(subStr[i]);
                }
            }
            else
            {
                for (size_t i{}; i < subStr.length(); ++i)
                {
                    if (!isdigit(subStr[i]))
                    {
                        subStr[i] = toupper(subStr[i]);
                    }
                }
            }
        }
    }
}

void FormatingStr(std::string& str, const std::string& delimiters)
{
    size_t j{};
    size_t i {str.find_first_of(delimiters)};
    std::string newStr;
    for(size_t k{}; k < delimiters.length(); ++k)
    {
        if(str[j] == delimiters[k])
        {
            delim = true;
        }
    }
    if(i == std::string::npos)
    {
        CheckWordCondition(str);
        newStr = str;
    }
    else
    {
        while (i != std::string::npos)
        {
            while (i != std::string::npos && i == j) 
            {
                j = i + 1;
                i = str.find_first_of(delimiters, j);
            }
            if (i == std::string::npos)
            {
                break;
            }
            std::string subStr{str.substr(j, i - j)};
            if (!subStr.empty())
            {
                CheckWordCondition(subStr);
                newStr += subStr + ' ';
                j = i + 1;
                i = str.find_first_of(delimiters, j);
            }
            std::string lastSubStr = str.substr(j);
            if (!lastSubStr.empty())
            {
                CheckWordCondition(lastSubStr);
                newStr += lastSubStr;
            }
        }
        str = newStr;
    }
}

int main()
{
    std::cout << "Input string: ";
    std::string str;
    getline(std::cin,str);
    try
    {
        if(str.empty())
        {
            throw std::invalid_argument("Empty string");
        }
        std::string delimeters{" \\,.\n\0-`!&=@#$%^&*)(+/"};
        FormatingStr(str, delimeters);
        std::cout << str;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
