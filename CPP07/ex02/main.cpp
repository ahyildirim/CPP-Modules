#include "Array.hpp"

int main()
{
    std::cout << "Creating NULL(default constructor) integer array class" << std::endl;
    Array<int> arr1;
    std::cout << std::endl;

    std::cout << "Creating integer array class with size 5" << std::endl;
    Array<int> arr2(5);
    std::cout << "Array size is " << arr2.size() << std::endl;
    std::cout << "Assigning values to array elements" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        arr2[i] = i * 2;

    std::cout << "Array values are: ";
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating copy of the integer array using copy constructor" << std::endl;
    Array<int> arr3(arr2);
    std::cout << "Copied Array size is " << arr3.size() << std::endl;
    std::cout << "Copied Array values are: ";
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    //Orijinal array'in değişmediğinin kanıtı
    std::cout << "Changing some values in copied array" << std::endl;
    arr3[0] = 42;
    arr3[1] = 84;
    std::cout << "Copied Array values after modification are: ";
    for (unsigned int i = 0; i < arr3.size(); i++)
        std::cout << arr3[i] << ", ";
    std::cout << std::endl;
    std::cout << "Original Array values are: ";
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << arr2[i] << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating copy of the integer array using copy assignment operator" << std::endl;
    Array<int> arr4;
    arr4 = arr2;
    std::cout << "Assigned Array size is " << arr4.size() << std::endl;
    std::cout << "Assigned Array values are: ";
    for (unsigned int i = 0; i < arr4.size(); i++)
        std::cout << arr4[i] << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Accessing elements of the original array with [] operator" << std::endl;
    for (unsigned int i = 0; i < arr2.size(); i++)
        std::cout << "arr2[" << i << "] = " << arr2[i] << std::endl;
    std::cout << std::endl;

    std::cout << "Trying to access an invalid index" << std::endl;
    try{
        std::cout << arr2[10] << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "Creating a string array size of 3" << std::endl;
    Array<std::string> arr5(3);
    std::cout << "Array size is " << arr5.size() << std::endl;
    std::cout << "Assigning values to array elements" << std::endl;
    arr5[0] = "Ahmet";
    arr5[1] = "Hakan";
    arr5[2] = "Yıldırım";

    std::cout << "Array values are: ";
    for (unsigned int i = 0; i < arr5.size(); i++)
        std::cout << arr5[i] << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "Creating a float array size of 7" << std::endl;
    Array<float> arr6(7);
    std::cout << "Array size is " << arr6.size() << std::endl;
    std::cout << "Assigning values to array elements" << std::endl;
    for (unsigned int i = 0; i < arr6.size(); i++)
        arr6[i] = i * 1.5f;

    std::cout << "Array values are: ";
    for (unsigned int i = 0; i < arr6.size(); i++)
        std::cout << arr6[i] << ", ";
    std::cout << std::endl;

    return 0;
}