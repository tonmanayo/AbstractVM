- AbstractVM
- Wethinkcode - tmack - 2017 - 2nd year
- AbstractVM is a C++ project it is a machine that uses a stack to compute simple arithmetic expressions.
- These arithmetic expressions are provided to the machine as basic assembly programs.
- This project uses Arithmatic Overleads, Interfaces, Classes, Errorhandling, Inheriance, Instantiation, function overleads.

-- to compile
-- cmake .
-- make
-- ./abstractvm (with no comands or with a file)

+ in file or commands can be:

Enum:
{
+  push int8(n)
+  push int16(n)
+  push int32(n)
+  push float(n)
+  push double(n)
} VALUE
+ div
+ mul
+ add
+ sub
+ mod
+ assert VALUE
+ print
+ exit

Example 
{
./abstractvm
push int8(12)
push float(12)
add
dump
}
result: 24
