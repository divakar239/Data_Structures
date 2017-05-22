# Data Structures



## Dynamic Deque
<p>The Dynamic_deque_as_array class implements a dynamic deque data structure using an array. </p>
<b>1.<u> Member Variables</u></b>:
<p>The Dynamic_deque_as_array class has five member variables:</p>

* <b>int* array</b> - A pointer to be used as an array

* <b>int head </b> - A head index
* <b>int tail </b> - A tail index

* <b>int count</b> - A counter

* <b>int array size</b> - The size of the array

<b>2.<u> Constructor</u></b>:
<p>The constructor takes an argument as the capacity of the array and allocates memory for that array. The default capacity (or number of entries) is 10. If the argument n is less than one, use an array size of 1. 
</p>

<b>3.<u> Accessors</u></b>:
<p>This class has five accessors:</p>

* <b>int head() const</b> – Return the integer at the head of the data deque in O(1). It may throw an underflow exception.

* <b> int tail() const</b> – Return the integer at the tail of the data deque in O(1). It may throw an underflow exception.
* <b> int size() const</b> – Return the number of elements currently stored in the deque in O(1).

* <b> bool empty() const</b> – Return true if deque is empty false otherwise in O(1).

* <b> int capacity() const</b> – Return the capacity of deque in O(1).

<b>4.<u> Mutators</u></b>:
<p>This class has five accessors:</p>

* <b>void enqueue head(int const &)</b> – Insert a new item at the head of the deque in O(1). If the array is full, create a new array with size 2n (where n is current size of the array) and copy the elements from the current array to the new array in O(n).

* <b> void enqueue tail(int const &) </b> – Insert a new item at the tail of the deque in O(1). If the array is full, create a new array with size 2n (where n is current size of the array) and copy the elements from the current array to the new array in O(n).

* <b> int dequeue head() </b> – Remove the element at the head of the deque in O(1). This may throw an underflow exception.

* <b>int dequeue tail() </b> – Remove the element at the tail of the deque in O(1). This may throw an underflow exception.
* <b>void clear()  </b> – Remove all elements from the deque in O(1).






## Hash Map
### Hash Functions
The hash function of linear probing takes the form ofh(𝑘,𝑖)=(h(𝑘)+𝑖)𝑚𝑜𝑑𝑀where h is the primary hash function: h(𝑘) = 𝑘 𝑚𝑜𝑑 𝑀 and 𝑖 is the number of collisions.

<b>1.<u> Member Variables</u></b>:
<p>The LinearHashTable class has at least the following member variables:</p>

* <b>T *array</b> - An array of objects of type T. This array will contain the values placed in the hash table

* <b> state *array_state </b> - An array of objects of type “state” – to store the status of the bin. The state of a bin is one of three possible values: EMPTY, OCCUPIED, or DELETED
* <b> int count</b> - The number of elements currently in the hash table


* <b> int array_size</b> - The capacity of the hash table

* <b> int power</b> - This is associated with the capacity of the hash table (array_size = 2𝑝𝑜𝑤𝑒𝑟)

<b>2. <u>Constructor:</u></b>
<p>LinearHashTable ( int m = 5 )
The constructor takes an argument m and creates a hash table with 2m bins, indexed from 0 to 2m − 1. The default value of m is 5. Notice that you need to allocate and initialize two arrays, one that stores the values in the hash table, and the other that stores the status of the bins.</p>

<b>3. <u>Destructor:</u></b>
<p>LinearHashTable ()
The destructor deletes the memory allocated for the hash table. Notice that the hash table has been represented using two arrays, and they both need to be deleted.</p>

<b>4. <u>Accessors</u></b>
<p>This class has seven accessors:</p>

* <b>int size() const</b> - Return the number of elements currently stored in the hash table. (O(1))

* <b>int capacity() const</b> - Return the number of bins in the hash table. (O(1))
* <b>bool empty() const</b>- Return true if the hash table is empty, false otherwise. (O(1))
* <b>bool member( T const & ) const </b>-Return true if object obj is in the hash table and false otherwise.
(O(1))
* <b>T bin( int ) const</b>-Return the entry in bin n. The behaviour of this function is undefined if the bin
is not filled. It will only be used to test the class with the expected locations. (O(1))
* <b>double load_factor() const </b>– Return the load factor of the hash table. (O(1))

<b>5. <u> Mutators:</u></b>
<p>This class has three mutators:</p>

* <b>void insert( T const & ) </b>- If load factor is less than or equal to 0.75, you have to insert the new object into the hash table in the appropriate bin as determined by the hash function and the rules of linear probing (O(1)). Otherwise, double the size of hash table, rehash all elements, and then insert the new element (O(n)).

* <b>bool remove( T const & ) </b>- If the load factor is greater than 0.25, you have to remove the object from the hash table if it is in the hash table (returning false if it is not) by setting the corresponding flag of the bin to “DELETED”. (O(1)). Otherwise, if the load factor is less than 0.25 and the current capacity of hash table is not equal to the initial capacity (that was assigned in the constructor), you have to shrink the capacity of the hash table to the half of its current size, rehash the elements, and remove the input from the table (O(𝑛)).

* <b>void clear()</b>- Remove all the elements in the hash table. (O(M))



## Trie 
<p>Trie.h contains the root node, from where every other node in the tree can be reached, and Trie_node.h represents each node in the tree.</p>

<b>Trie.h</b>
<p>This is the class that implements a trie. The variable n represents length of a string; that is, the number of characters making up the string. This trie tree is not case sensitive.</p>

<b>1.<u> Member Variables</u></b>:
<p>The Trie class has two member variables:</p>

* A pointer to the root node, and

* An integer variable storing the number of words in the tree (that is, the size).

<b>2. <u>Accessors</u></b>
* <b>bool empty() const </b> - Return true if the trie is empty (the size is 0). (O(1))

* <b> int size() const </b> - Returns the number of words in the trie. (O(1))
* <b> Trie_node *root() const </b> - Returns a pointer to the root node. (O(1))
* <b>bool member( std::String str ) const</b>  - Return true if the word represented by the string is in the Trie and false otherwise. If the string contains any characters other than those of the English alphabet (‘A’ through ‘Z’ or ‘a’ through ‘z’), throw an illegal_argument exception. (O(n))


<b>3. <u>Mutators</u></b>
* <b>bool insert( std::string str)</b> - Insert the word represented by str into the tree. If the string containsany characters other than those of the English alphabet (‘A’ through ‘Z’ or ‘a’ through ‘z’), throw an illegal_argument exception; otherwise if the string is already in the tree, return false; otherwise, return true (the insertion was successful). This is done by calling insert on the root, and if the root node is null, it will be necessary create an instance of the Trie_node class and assign it to the root first. (O(n))

* <b> bool erase( std::string str)</b> - Erase the word represented by str from the tree. If the string contains any characters other than those of the English alphabet (‘A’ through ‘Z’ or ‘a’ through ‘z’), throw an illegal_argument exception; otherwise if the string is not in the tree, return false; otherwise, return true (the erase was successful). If the tree is empty, return false, otherwise this function calls erase on the root. If the word erased is the last one in the tree, delete the root node. (O(n))
* <b> void clear()</b> - Delete all the nodes in the tree. Again, if the tree is not empty, it should just call clear on the root and set the appropriate member variables. (O(N) where N is the number of words in the tree)


<b>Trie_node.h</b>
<p>This class implements the nodes of trie.</p>

<b>1.<u> Member Variables</u></b>:
<p>This Trie_node has two member variables:</p>

* A pointer to an array of pointers to trie nodes, and

* A Boolean flag indicating whether a node represents a terminal node for a word

<b>2. <u>Accessors</u></b>
* <b>Trie_node *child( int n ) const</b> - Return a pointer to the n-th child. If the children array is empty, return nullptr; otherwise, just return children[i]. This member function will never be called with a
value outside 0 to 25. (O(1))

* <b> bool member( std::string const &str, int depth ) const </b>- The string being searched for is being passed recursively; however, as we go deeper into the tree, we must have access to the character corresponding to the depth. You can assume that the characters are all alphabetical, as the Trie class should have checked for invalid characters. The trie tree is not case sensitive, so you must map letters to the range 0 to 25. If we are at the end of the word, the is_terminal member variable will determine the appropriate return value; otherwise, we need to call member recursively or return false, as appropriate. You must return the appropriate values in all cases, including: when children are null, when the appropriate child pointer is assigned null, and otherwise. (O(n)).


<b>3. <u>Mutators</u></b>
* <b>bool insert( std::string const &str, int depth )</b> - Like member accessor function, we need to recurse into the tree. If we reach a node and we are at the end of the word we are attempting to insert, we need only check and possibly modify the member variable is_terminal to determine the appropriate return value. If we are not yet at the end of the word, we must recurse through the appropriate sub-tree. This may require first assigning an array of 26 pointers to Trie nodes to children in some cases, and it may require assigning a new Trie node to the kth sub-tree of this array. (O(n))

* <b>bool erase(std::string const &, int depth, B, Trie_node *&ptr_to_this)</b>- Like member accessor function, we need to recurse into the tree. If we reach the end of branch of the tree before we get to the end of the word, it is clear the word is not stored in this tree and thus cannot be erased. If we get to a node when we are the end of the word, we must choose the appropriate course of action and the appropriate return value based on the value of is_terminal. If this node is a leaf node (children is assigned null), we should delete this node. While we are recursing back, if the children array became entirely unassigned as a result of our erase, the current node must also be erased. For example, in Figure 1, if the word "thoughts" was erased, then the nodes containing “o”, “u”, “g”, “h”, ”t”, and “s” must be deleted and the appropriate sub-child of the node containing “h” must be set to null. (O(n))
* <b> void clear() </b> - Calls clear on all sub-trees and deletes this node.
