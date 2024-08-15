
---

# Trie from Policy-Based Data Structures (PBDS) in C++

This tutorial will guide you through the process of setting up and using the `trie` from Policy-Based Data Structures (PBDS) in C++. The `trie` structure is particularly useful for efficiently handling prefix-based searches, such as autocomplete or dictionary-like applications.

## Table of Contents

- [Basic Setup](#basic-setup)
- [Basic Operations](#basic-operations)
- [Examples](#examples)

## Basic Setup

First, you need to define the `trie` using PBDS. Here’s how you can do it:

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

// Define the trie type
template <typename Key, typename Value = null_type>
using trie = trie<Key, Value, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;
```

### Explanation

- `Key`: The type of elements in the trie (commonly `string` or `char`).
- `Value`: The type of values associated with keys (optional; set to `null_type` if not needed).
- `trie_string_access_traits<>`: Specifies the access traits for strings, managing how the trie navigates through the characters.
- `pat_trie_tag`: Specifies that the structure is a PATRICIA trie, a space-efficient version of a standard trie.
- `trie_prefix_search_node_update`: Enables efficient prefix-based searches within the trie.

## Basic Operations

### Insertion

To insert keys (or key-value pairs) into the `trie`:

```cpp
trie<string> t;
t.insert("apple");
t.insert("banana");
t.insert("apricot");
```

### Deletion

To remove keys from the `trie`:

```cpp
t.erase("banana");
```

### Prefix Search

You can perform a prefix search to find all elements with a specific prefix:

```cpp
string prefix = "ap";
auto range = t.prefix_range(prefix);
for (auto it = range.first; it != range.second; ++it) {
    cout << *it << endl; // Outputs all keys with the prefix "ap"
}
```

### Checking Existence

To check if a key exists in the `trie`:

```cpp
if (t.find("apple") != t.end()) {
    cout << "'apple' exists in the trie" << endl;
} else {
    cout << "'apple' does not exist in the trie" << endl;
}
```

## Examples

Here's a complete example demonstrating these operations:

```cpp
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename Key, typename Value = null_type>
using trie = trie<Key, Value, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>;

int main() {
    trie<string> t;

    // Inserting keys
    t.insert("apple");
    t.insert("banana");
    t.insert("apricot");

    // Checking if a key exists
    if (t.find("apple") != t.end()) {
        cout << "'apple' exists in the trie" << endl;
    }

    // Prefix search for keys starting with "ap"
    string prefix = "ap";
    auto range = t.prefix_range(prefix);
    cout << "Keys with prefix '" << prefix << "':" << endl;
    for (auto it = range.first; it != range.second; ++it) {
        cout << *it << endl;
    }

    // Deleting a key
    t.erase("banana");

    return 0;
}
```

