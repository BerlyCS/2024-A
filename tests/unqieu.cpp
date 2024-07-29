
#include <memory>
#include <utility>

auto f(std::unique_ptr<int>&& ptr) 
    /* -> std::unique_ptr<int> */
{

    *ptr = 9;
    return ptr;
}
int main(){
    std::unique_ptr<int> ptr(new int(7));
    std::unique_ptr<int> ptr2;
    ptr2 = f(std::move(ptr));
}
