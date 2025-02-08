

# Proof of the Lower Bound of the Height of a Binary Tree

## Statement
Prove that the lower bound of the height $ h $ of a binary tree with $ N $ nodes is:

$$
h \geq \log_2 (N + 1) - 1
$$

## Derivation of $ N = 2^{(h+1)} - 1 $
A **perfect binary tree** is a binary tree where every internal node has exactly two children, and all leaf nodes are at the same depth.

For a perfect binary tree of height $ h $, the tree consists of multiple levels indexed from $ 0 $ (root) to $ h $ (last level).

### Number of Nodes at Each Level
- Level $ 0 $ (root) has $ 2^0 = 1 $ node.
- Level $ 1 $ has $ 2^1 = 2 $ nodes.
- Level $ 2 $ has $ 2^2 = 4 $ nodes.
- Level $ k $ has $ 2^k $ nodes.
- Level $ h $ (last level) has $ 2^h $ nodes.

### Total Number of Nodes
The total number of nodes $ N $ in a perfect binary tree is the sum of the nodes at all levels:

$$
N = 2^0 + 2^1 + 2^2 + \dots + 2^h
$$

This is a geometric series with sum formula:

$$
S = \frac{a (r^{n} - 1)}{r - 1}
$$

where:
- $ a = 1 $ (first term),
- $ r = 2 $ (common ratio),
- $ n = h+1 $ (number of terms).

Applying the formula:

$$
N = \frac{1 (2^{(h+1)} - 1)}{2 - 1} = 2^{(h+1)} - 1
$$

## Deriving the Lower Bound of Height
Rearranging the equation for $ N $:

$$
N + 1 = 2^{(h+1)}
$$

Taking log base 2:

$$
\log_2 (N + 1) = h + 1
$$

Solving for \( h \):

$$
h = \log_2 (N + 1) - 1
$$

Since a perfect binary tree has the minimum height for $ N $ nodes, this establishes the lower bound:

$$
h \geq \log_2 (N + 1) - 1
$$
