Exercise number 9
-----------------

A set of integers, all in the range MIN through MAX, can be represented
by a boolean array b of size MAX-MIN+1. Element b[i-MIN] is true if i belongs
to the set and false if not.

Define a class set that represents sets of integers in this way. MAX and MIN
will be defined as constants and apply to all objects of class set.

Provide class set with constructors set() (no arguments), which creates an
empty set, and set ( int n ) which creates a one-element set containing only
the integer n.

Equip the class with operators +, - (unary and binary), *, +=, -=, *=, ==,
!=, <, >, <=, >=, and <<. Operators +, binary -, *, ==, !=, <, >, <=, >=,
have the same meaning they have in Pascal, unary - represents the complement
of a set (contains those elements im the specified range that do not belong
to the given set), operator << prints a set: the set containing 3, 5 and 7
is printed as {3, 5, 7}.

Also provide the member functions insert(n), remove(n), and member(n) for
inserting an integer, removing an integer, and testing whether an integer
belongs to the set.

Prepare a header file, a source file, and a test file with a main() function
using the set class.

Example:

const MIN = 10;
const MAX = 30;
The universal set is { 10 .. 30 } .
union:         { 10, 15, 17 } + { 12, 15 } = { 10, 12, 15, 17 }
difference:    { 10, 15, 17 } - { 12, 15 } = { 10, 17 }
intersection:  { 10, 15, 17 } * { 12, 15 } = { 15 }
complement:    - { 10 .. 20 } = { 21 .. 30 }

All the following relations will return true:
   { 10, 15 } == { 15, 10 }
   { 10, 15 } < { 10, 15, 20 }
   { 10, 15 } <= { 10, 15, 20}
   { 10, 15 } <= { 10, 15 }
   { 10, 15, 20 } > { 10, 15 }
   { 10, 15 , 20 } >= { 10, 15 }
   { 10, 15 } >= { 10, 15 }

All the following relations will return false:
   { 10, 15 } < { 10, 15 }
   { 11, 12 } < { 13, 14, 15 }
   { 10, 15 } > { 10, 15 }
   { 13, 14, 15 } > { 11, 12 }
