#include "../include/ptest.hpp"
#include <vector>
#include <iostream>

P_TEST(CanAddToVector) {
    std::vector<int> vec;
    vec.push_back(3);
    P_ASSERT(vec.size() == 1);
    vec.push_back(5);
    P_ASSERT(vec.size() == 2);
    vec.push_back(4);
    P_ASSERT(vec.size() == 3);
    vec.clear();
    // Assertion will fail.
    P_ASSERT(vec.size() != 0);
    // This will not run.
    printf("You shouldn't see me!\n");
    vec.push_back(4);
    P_ASSERT(vec.size() == 3);
}

P_TEST(CanReserveVector) {
    std::vector<int> vec;
    vec.reserve(10);
    
    P_ASSERT(vec.capacity() >= 10);
    P_ASSERT(vec.size() == 0);
    
    for(int i = 0; i < 11; ++i) {
        vec.push_back(3);
    }
    
    P_ASSERT(vec.capacity() > 10);
}

P_TEST(CanInsertVector) {
    std::vector<int> vec;
    
    for(int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }
    
    for(int i = 0; i < 10; ++i) {
        P_ASSERT(vec[i] == i);
    }
}

int main() {
    return PTest::PTestRegistry::Get().RunAllTests();
}