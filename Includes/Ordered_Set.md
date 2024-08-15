---

# Ordered Set from Policy-Based Data Structures (PBDS) in C++

This tutorial will guide you through the process of setting up and using the `ordered_set` from Policy-Based Data Structures (PBDS) in C++. This structure is useful for efficiently handling order statistics, such as finding the k-th smallest/largest element or the number of elements smaller/larger than a given value.

## Table of Contents

- [Basic Setup](#basic-setup)
- [Basic Operations](#basic-operations)
- [Examples](#examples)


## Basic Setup

First, you need to define the `ordered_set` using PBDS. Here’s how you can do it:

```cpp
using namespace __gnu_pbds;
using namespace std;

// Define the ordered_set type
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
```

### Explanation

- `T`: The type of elements in the set.
- `null_type`: We are not mapping keys to values, so this is set to `null_type`.
- `less<T>`: This defines the sorting order; in this case, it's ascending.
- `rb_tree_tag`: Specifies that the data structure is based on a red-black tree.
- `tree_order_statistics_node_update`: Ensures that the tree supports order statistics.

## Basic Operations

### Insertion

To insert elements into the `ordered_set`:

```cpp
ordered_set<int> os;
os.insert(5);
os.insert(1);
os.insert(10);
```

### Deletion

To remove elements:

```cpp
os.erase(5);
```

### Finding the k-th smallest element

You can find the k-th smallest element using the `find_by_order` method:

```cpp
int k = 1;
auto it = os.find_by_order(k); // Returns an iterator to the k-th smallest element (0-based index).
if (it != os.end()) {
    cout << "The " << k << "-th smallest element is " << *it << endl;
}
```

### Finding the number of elements less than a given value

To find the number of elements less than a specific value, use `order_of_key`:

```cpp
int value = 6;
int count = os.order_of_key(value); // Number of elements strictly less than 6
cout << "Number of elements less than " << value << " is " << count << endl;
```

## Examples

Here's a complete example demonstrating these operations:

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_set<int> os;

    // Inserting elements
    os.insert(5);
    os.insert(1);
    os.insert(10);

    // Finding k-th smallest element
    int k = 1;
    auto it = os.find_by_order(k);
    if (it != os.end()) {
        cout << "The " << k << "-th smallest element is " << *it << endl;
    }

    // Number of elements less than 6
    int value = 6;
    int count = os.order_of_key(value);
    cout << "Number of elements less than " << value << " is " << count << endl;

    return 0;
}
```

