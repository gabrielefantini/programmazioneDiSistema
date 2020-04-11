#include <iostream>
#include "Message.h"

int main() {

    Message m1(40);
    std::cout<<m1<<std::endl;
    m1 = Message(50);
    std::cout<<m1<<std::endl;
    Message m2 = std::move(m1);
    std::cout<<m2<<std::endl;
    std::cout<<m1<<std::endl;

}
