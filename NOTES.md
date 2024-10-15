# Loop Invariant

A loop invariant is some predicate the holds true for every iteration of the loop.
Loop invariant can be used in similar fashion to proof by mathematical induction.

Example:
```C
int j = 9;
for (int i = 0; i < 10; ++i)
    j--;
```

Invariant `i + j = 9` holds true for above shown loop.
Weaker invariant could be `i >=0  && i <= 10` which also holds true.

**Loop invariant has three conditions:**

1) **Initialization** (Base Case): It is true prior to first iteration of the loop.
2) **Maintenance** (Induction): It is true before an iteration of the loop and remains true before next iteration.
3) **Termination**: The loop must terminate and the invariant gives useful property that helps to show algorithm correctness.


# RAM Model

A simplified version of computer architecture constructed to make analysis of algorithms runtime easier.
Using RAM Model we calculate the **number of instructions** and **amount of times each of those instructions get executed**
during the algorithm's runtime.

RAM Model characteristics:

- Single Processor; no concurrency
- Single memory (RAM); no memory hierarchy
- Has three data types: integer, floating points, and character
- Data movement (load, store, copy) take O(1) time
- Arithmetic operations (add, sum, div, multiply, mod, ceiling, floor) takes O(1) time
- Logical and bitwise operations (and, or, xor, shifts) takes O(1) time
- Control operations (conditional and unconditional branch, subroutine call and return) takes O(1) time
