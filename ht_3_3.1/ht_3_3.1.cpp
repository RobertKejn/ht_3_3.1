#include <iostream>
#include "smart_array.h"

int main()
{
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr[1] << std::endl;

        smart_array new_array(2);
        new_array.add_element(44);
        new_array.add_element(34);

        arr = new_array;

        std::cout << arr.get_element(0) << std::endl;
        std::cout << arr[1] << std::endl;
    }
    catch (std::exception& ex) {
        std::cout << ex.what();
    }
}
