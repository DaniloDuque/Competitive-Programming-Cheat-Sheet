---

# Ordered Map from Policy-Based Data Structures (PBDS) in C++

This tutorial will guide you through the process of setting up and using the `ordered_map` from Policy-Based Data Structures (PBDS) in C++. This structure is useful for efficiently handling key-value pairs with order statistics, such as finding the k-th smallest/largest key or the number of keys smaller/larger than a given value.

## Table of Contents

- [Basic Setup](#basic-setup)
- [Basic Operations](#basic-operations)
- [Examples](#examples)

## Basic Setup

First, you need to define the `ordered_map` using PBDS. Here’s how you can do it:

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define the ordered_map type
template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;
```

### Explanation

- `Key`: The type of keys in the map.
- `Value`: The type of values associated with the keys.
- `less<Key>`: This defines the sorting order of the keys; in this case, it's ascending.
- `rb_tree_tag`: Specifies that the data structure is based on a red-black tree.
- `tree_order_statistics_node_update`: Ensures that the tree supports order statistics.

## Basic Operations

### Insertion

To insert key-value pairs into the `ordered_map`:

```cpp
ordered_map<int, string> om;
om[5] = "apple";
om[1] = "banana";
om[10] = "cherry";
```

### Deletion

To remove key-value pairs:

```cpp
om.erase(5);
```

### Finding the k-th smallest key

You can find the k-th smallest key using the `find_by_order` method:

```cpp
int k = 1;
auto it = om.find_by_order(k); // Returns an iterator to the k-th smallest key (0-based index).
if (it != om.end()) {
    cout << "The " << k << "-th smallest key is " << it->first << " with value " << it->second << endl;
}
```

### Finding the number of keys less than a given value

To find the number of keys less than a specific value, use `order_of_key`:

```cpp
int key = 6;
int count = om.order_of_key(key); // Number of keys strictly less than 6
cout << "Number of keys less than " << key << " is " << count << endl;
```

## Examples

Here's a complete example demonstrating these operations:

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename Key, typename Value>
using ordered_map = tree<Key, Value, less<Key>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    ordered_map<int, string> om;

    // Inserting elements
    om[5] = "apple";
    om[1] = "banana";
    om[10] = "cherry";

    // Finding k-th smallest key
    int k = 1;
    auto it = om.find_by_order(k);
    if (it != om.end()) {
        cout << "The " << k << "-th smallest key is " << it->first << " with value " << it->second << endl;
    }

    // Number of keys less than 6
    int key = 6;
    int count = om.order_of_key(key);
    cout << "Number of keys less than " << key << " is " << count << endl;

    return 0;
}
```

