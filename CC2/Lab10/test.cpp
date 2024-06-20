#include <iostream>
#include <vector>
using namespace std;
void consumingFunction(std::vector<int> vec)
{
    // Some operations
}
int main()
{
    // initialize vec with 1, 2, 3, 4
    std::vector<int> vec{1, 2, 3, 4};
    // Send the vector by move
    consumingFunction(std::move(vec));
    // Here the vec object is in an indeterminate state.
    // Since the object is not destroyed, we can assign it a new content.
    // We will, in this case, assign an empty value to the vector,
    // making it effectively empty
    vec = {};
    // Since the vector as gained a determinate value, we can use it normally.
    vec.push_back(42);
    // Send the vector by move again.
    consumingFunction(std::move(vec));
}