#include <vector>
#include <iostream>

extern "C" {
    std::vector<int> create_list(int size) {
        std::vector<int> my_list(size);
        for (int i = 0; i < size; i++) {
            my_list[i] = i + 1;
        }
        return my_list;
    }

    void remove_elements(std::vector<int>& my_list) {
        std::cout << "Original list: ";
        for (int num : my_list) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        while (!my_list.empty()) {
            std::cout << "Removing: " << my_list.front() << std::endl;
            my_list.erase(my_list.begin());
            std::cout << "Updated list: ";
            for (int num : my_list) {
                std::cout << num << " ";
            }
            std::cout << std::endl;
        }
        std::cout << "List is now empty." << std::endl;
    }
}