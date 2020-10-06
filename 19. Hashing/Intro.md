 Hash Table Data Structure: Purpose
 ===================================
 - Support insertion, deletion and search in average-case constant time.
 - Order is irrelevant

 Key Components
 ================
 - Hash Function
 - Hash Table
 - Collision Handling Scheme
 
 (Hash Function)
 =============
 hash["string key"] = integer val
 - Key has to be converted into an integer
 - Collisions cannot be avoided
 - Good Hash Function -> Distribute keys uniformly over table, should be fast to compute
 eg:
 	(a) Integer keys: Table Size = prime Number
 	(b) String keys: 
 		1. Sum ASCII values of all characters in key
 		- Anagrams collide
 		2. Treat first 3 characters of string as Base 27 (+1 for space)
 		Key = s[0] + s[1]27 + s[2]27^2
 		- Assumes first 3 characters are randomly distributed
 		3. Use all N characters of string as N-digit base K numbers.
 		Choose K to be the prime number greater than the number of different characters, i.e, K=29, 31, 37

 		h(S) = 


 (Hash Table)
 ===========
 - Hash Table is an array of fixed size
 - Array elements are indexed by a key, which is mapped to an array index (0 to tableSize-1)
 eg: h("pizza") = 5

 	if h("pizza") == h("burger") -> !! COLLISION !!

 Operations ->
 - INSERTION: menu["pizza"] = 120
 - DELETION: menu["pizza"] = NULL
 - SEARCH

 (Collision Handling Schemes)
 =============================
 1. Open Hashing / Separate Chaining
 2. Closed Hashing / Open Addressing
 	- Linear Probing
 	- Quadratic Probing
 3. Double Hashing


