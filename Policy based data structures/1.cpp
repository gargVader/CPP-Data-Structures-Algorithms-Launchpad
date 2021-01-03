/*
Policy based data structures
============================
- works like a set
- find_by_order(K) -> return the iterator to the kth largest element (logn)
- order_of_key(K) -> returns the number of elements in the set which are strictly less than K (logn)
*/

// Header files
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
// Including tree_order_statistics_node_update

using namespace __gnu_pbds;

// Declaration of tree-based container
template <
    // Key type
    typename Key,

    // Mapped Policy
    typename Mapped,

    // Key comparison functor
    typename Cmp_Fn = std::less<Key>,

    // Specifies which underlying data structure to use
    typename Tag = rb_tree_tag,

    template <
        typename Const_Node_Iterator,
        typename Node_Iterator,
        typename Cmp_Fn,
        typename Allocator_ >

    // A policy for updating node invariants
    class Node_Update = null_node_update,

    // An allocator type
    typename Allocator = std::allocator<char>
    >

class tree;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> new_data_set;

Tree Structures

rb_tree_tag (red black tree)
splay_tree_tag (splay tree)
ov_tree_tag (ordered vector tree)