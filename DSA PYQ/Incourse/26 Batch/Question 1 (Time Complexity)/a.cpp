
// Question:

// Distinguish among O, Ω, and Θ-notation. Order the following terms in ascending order.
// O(n), O(100), O(n log n), O(log n), O(n²)

// Answer:

// Big-O (O): Represents the upper bound of a function's growth rate. It describes the worst-case complexity.
// Big-Ω (Ω): Represents the lower bound of a function's growth rate. It describes the best-case complexity.
// Big-Θ (Θ): Represents the tight bound, meaning the function's growth rate is both upper and lower bounded by the same term. 
//            It describes the average-case complexity when the growth rate is well-defined.

// Reasoning:
// O(100): Constant time, always fixed and the smallest growth rate.
// O(log n): Logarithmic growth, slower than linear growth.
// O(n): Linear growth, proportional to the input size.
// O(n log n): Superlinear growth, faster than linear but slower than quadratic.
// O(n²): Quadratic growth, grows much faster than the other terms for large n

// Order:
// O(100) < O(log n) < O(n) < O(n log n) < O(n²)