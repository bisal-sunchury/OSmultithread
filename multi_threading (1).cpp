#include <iostream>
#include <thread>

void my_first_task(std::string display_string)
{
    int i = 20;

    while (i) {
        std::cout << "T1(" << (20-i) << "): " << display_string << std::endl;
        i--;
    }
}

void my_second_task(int num)
{
    int i = 20;
    while (i) {
        std::cout << "T2(" << (20-i) << "): " << num % 3 << std::endl;
        i--;
    }
}

int main()
{
    // create threads here; they start executing
    std::thread first(my_first_task, "Bishal");
    std::thread second(my_second_task, 17);
    
    
    first.join();         
    second.join();        

    // first.detach();
    // second.detach();
    
    std::cout << "Main thread: hello" << std::endl;

    return 0;
}
