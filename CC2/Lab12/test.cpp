#include <bits/types/locale_t.h>
#include <iostream>
#include <memory>
#include <utility>
using namespace std;
// unique_ptr-based linked list demo
struct List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };
 
    std::unique_ptr<Node> head;
 
    ~List()
    {
        // destroy list nodes sequentially in a loop, the default destructor
        // would have invoked its `next`'s destructor recursively, which would
        // cause stack overflow for sufficiently large lists.
        while (head)
        {
            auto next = std::move(head->next);
            head = std::move(next);
        }
    }
 
    void push(int data)
    {
        head = std::unique_ptr<Node>(new Node{data, std::move(head)});
    }
};
int main() {
    cout << "\n" "6) Linked list demo\n";
    {
        List wall;
        const int enough{1'000'000};
        for (int beer = 0; beer != enough; ++beer)
            wall.push(beer);
 
        /* cout.imbue(locale("en_US.UTF-8")); */
        cout << enough << " bottles of beer on the wall...\n";
    } // destroys all the beers

    int i = 0;
    unique_ptr<int> p = make_unique<int>(i);
    unique_ptr<int> p2(p.release());
    cout<<p.get()<<endl<<p2.get()<<*p2<<endl;
    

}
