#include "functions.h"

int32_t main()
{
    int32_t sizeArr{};
    const int32_t ARR_SIZE{20};
    try
    {
        std::cout << "Input array size, no more 20 : ";
        std::cin >> sizeArr;
        std::cout << "Input boards randow interval!\n";
        int32_t Aboard{},Bboard{};
        std::cin >> Aboard >> Bboard;
        try
        {
            if(sizeArr > ARR_SIZE || sizeArr <= 0)
            {
                throw std::invalid_argument("Size of the array must be large than zero or no more input size.");
            }
            else
            {   
                //int32_t** mtr = CreateMatrix<int32_t>(rows, cols);;  // Выделяем массив указателей на строки
                int32_t arr[ARR_SIZE]{};
                
                RandomInputArray<int32_t>(arr,sizeArr, Aboard, Bboard);
                std::cout << "\nWith random things\n";
                std::cout << "\nNumber of sign changes: " << CalculatingSignChanges(arr, sizeArr);
                std::cout << "\nThe product of the array elements located between the first and second zero elements: " << MultiplikateArrElemBetweenTwoZero(arr, sizeArr) << '\n';
                SortFirstEvenArrElem(arr, sizeArr);
                std::cout << "\nOutput sort first even array: ";
                OutPutArray(arr, sizeArr);


                std::cout << "Input statik integer array: ";
                InputArray(arr, sizeArr);
                std::cout << "\nNumber of sign changes: " << CalculatingSignChanges(arr, sizeArr);
                std::cout << "\nThe product of the array elements located between the first and second zero elements: " << MultiplikateArrElemBetweenTwoZero(arr, sizeArr) << '\n';
                SortFirstEvenArrElem(arr, sizeArr);
                std::cout << "\nOutput sort first even array: ";
                OutPutArray(arr, sizeArr);
                {
                    int32_t P{};
                    std::cout << "\nInput max element: ";
                    std::cin >> P;
                    double arr[ARR_SIZE]{};//input
                    RandomInputArray<double>(arr,sizeArr, Aboard, Bboard);
                    std::cout << "Count Elem Arr Large P : " << CountElemArrLargeP(arr, sizeArr, P);
                    std::cout << "\nMultiplikate elements of array after last max elem for mod" << MultiplikateElemArrAfterLastMax(arr, sizeArr);
                    std::cout << "\nOutput sort first negative array: ";
                    SortNegativeElemArr(arr, sizeArr);
                    OutPutArray(arr, sizeArr);
                    

                    std::cout << "Input statik double array: ";
                    InputArray(arr, sizeArr);
                    std::cout << "Count Elem Arr Large P : " << CountElemArrLargeP(arr, sizeArr, P);
                    std::cout << "\nMultiplikate elements of array after last max elem for mod" << MultiplikateElemArrAfterLastMax(arr, sizeArr);
                    std::cout << "\nOutput sort first negative array: ";
                    SortNegativeElemArr(arr, sizeArr);
                    OutPutArray(arr, sizeArr);
                }
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
        int32_t *arr = CreateArray<int32_t>(sizeArr);
        RandomInputArray<int32_t>(arr,sizeArr, Aboard, Bboard);
        std::cout << "\nWith random things\n";
        std::cout << "\nNumber of sign changes: " << CalculatingSignChanges(arr, sizeArr);
        std::cout << "\nThe product of the array elements located between the first and second zero elements: " << MultiplikateArrElemBetweenTwoZero(arr, sizeArr) << '\n';
        SortFirstEvenArrElem(arr, sizeArr);
        std::cout << "\nOutput sort first even array: ";
        OutPutArray(arr, sizeArr);

        
        std::cout << "\nInput dinamik integer array:\n";
        InputArray(arr, sizeArr);
        std::cout << "Number of sign changes: " << CalculatingSignChanges(arr, sizeArr) << '\n';
        std::cout << "The product of the array elements located between the first and second zero elements: " << MultiplikateArrElemBetweenTwoZero(arr, sizeArr) << '\n';
        std::cout << "\nOutput sort first even array: ";
        SortFirstEvenArrElem(arr, sizeArr);
        OutPutArray(arr, sizeArr);
        delete[] arr;

        {
            int32_t P{};
            std::cout << "\nInput max element: ";/////////
            std::cin >> P;
            double *arr = CreateArray<double>(sizeArr);
            std::cout << "Input dinamic double array: ";
            InputArray(arr,sizeArr);
            std::cout << "Count Elem Arr Large P : " << CountElemArrLargeP(arr, sizeArr, P);
            std::cout << "\nMultiplikate elements of array after last max elem for mod" << MultiplikateElemArrAfterLastMax(arr, sizeArr);
            std::cout << "\nOutput sort first negative array: ";
            SortNegativeElemArr(arr, sizeArr);
            OutPutArray(arr, sizeArr);
            delete[] arr;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
