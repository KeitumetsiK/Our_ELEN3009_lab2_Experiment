// size_capacity.cpp
// Vector size versus capacity
//Exercise 2.1
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int> vec;
    cout << "vec: size: " << vec.size()
         << " capacity: " << vec.capacity() << endl;

    for(int i = 0; i < 24; i++) {
        vec.push_back(i);
        cout << "vec: size: " << vec.size()
             << " capacity: " << vec.capacity() << endl;
    }

    /*Q: Explain the difference between a vector’s size and its capacity.

      The SIZE of a vector is the number of elements that it contains. This depends on how many
      elements you insert into the vector. While the CAPACITY of a vector is the amount of space
      the vector is currently using. A vector uses a "hidden" array that we do not see, the capacity
      is always equal to or larger than the size.

    */

     /*Q: Explain why the vector’s capacity grows as it does.

       The capacity grows because an element is added to the vector that makes the size greater than the capacity. This
       cannot happen, therefore, the capacity has to increase in order to make space for the size to increase.
       For example, if the size of the vector is 8 and the capacity is 8. When an element is added to the vector
       the capacity doubles up to 16 in order to make room for the element being added. So, the size becomes 9
       and the capacity becomes 16.

     */

    return 0;
}
