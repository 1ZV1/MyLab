#include<iostream>
#include<string>
#include<algorithm>

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

//13.	Дана строка, слова в которой состоят из букв латинского алфавита и десятичных цифр.
/*Остальные символы считаются разделителями между словами.
Получить новую строку, выполняя в заданной строке замены по следующему правилу.
Все слова, имеющие длину менее 7 символов и состоящие только из цифр, заменяются словами,
записанными в обратном порядке. Во всех словах, в которых встречаются как буквы, так и цифры,
строчные буквы заменяются на прописные. Все слова, состоящие только из букв, записываются
строчными буквами.
Слова в новой строке должны разделяться ровно одним пробелом.*/

//fdgf3 34fghdf gFd SDsdss1 SSSR 1234567

//FDGF3 34FGHDF gfd SDSDSS1 sssr 7654321
void FormatingStr(std::string& str, const std::string& delimiters)
{
    size_t j{}, j1{};
    size_t i {str.find_first_of(delimiters)};
    std::string newStr;
    while (i != std::string::npos)
    {
        std::string underStr {str.substr(j, i - j)};
        if (!underStr.empty())
        {
            j1 = j;
            bool isNum{true}, isWord{true};
            while(j1 != i)
            {
                if(str[j1] > '9' || str[j1] < '0')
                {
                    isNum = false;
                    break;
                }
                //++j1;
            }
            if(j1 != 0)
            {
                isWord = false;
            }
            if(isNum && (i - j1) >= 7)
            {
                j1 = j;
                char temp;
                for(;j1 < i/2; ++j1)
                {
                    temp = str[j1];
                    str[j1] = str[i - j1];
                    str[i - j1] = temp;
                }
            }
            if(isWord)
            {
                while(j1 != i)
                {
                    if(str[j1] >= 'A' && str[j1] <= 'Z')
                    {
                        std::cout << 'a';
                    }
                    ++j1;
                }
            }
            newStr += underStr + ' ';
            std::cout << newStr << '\n';
        }
        j = i + 1;
        i = str.find_first_of(delimiters, j);
    }
    std::string lastUnderStr = str.substr(j);
    if (!lastUnderStr.empty())
    {

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
        std::string delimeters{" \\,.\n\0-`"};
        FormatingStr(str, delimeters);



    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout  << '\n'<< str;
    return 0;
}
