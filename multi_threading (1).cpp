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
    
    /* We are in the main thread ( usual thread ), and before the main
     *  thread finishes executing (i.e. the program quits ), we need to deal 
     *  with the two threads above that we have created and started.
     *  We either wait for them to finish executing (join), 
     *      or we let them run on their own(detach), in which case the results
     *      could be surprising
     */
    first.join();         // we wait until 'first' finishes executing
    second.join();        // wait until 'second' finishes

    // first.detach();
    // second.detach();
    
    std::cout << "Main thread: hello" << std::endl;

    return 0;
}
