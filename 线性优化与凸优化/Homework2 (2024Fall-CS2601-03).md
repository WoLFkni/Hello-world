## Definite matrices


### Problem 1

Let $\mathbf{A}=\left(\begin{array}{ccc}2 & 2 & a \\ 2 & 4 & -2 \\ a & -2 & 2\end{array}\right)$.
- If $a=-1$, compute the eigenvalues of $\mathbf{A}$ and show that $\mathbf{A}$ is *positive definite*.
- If $a=-2$, use Sylvester's criterion to show that $\mathbf{A}$ is *positive semidefinite*.
- For what real numbers $a$ is matrix $\mathbf{A}$ *positive semidefinite*? You can use any criterion you like.



## Convex Sets

### Problem 2

Let $f(\mathbf{x})=\mathbf{A} \mathbf{x}+\mathbf{b}$ be an affine function from $\mathbb{R}^n$ to $\mathbb{R}^m$, where $\mathbf{A} \in \mathbb{R}^{m \times n}$ and $\mathbf{b} \in \mathbb{R}^m$. 
- Show that if $D\subseteq \mathbb R^n$ is a convex set, then so is $f(D)\triangleq \{f(\mathbf x)\in \mathbb R^m: \mathbf x\in D\}$.
- Show that if $C \subseteq \mathbb{R}^m$ is a convex set, so is its inverse image $f^{-1}(C) \triangleq\{\mathbf{x}\in\mathbb R^n: f(\mathbf{x}) \in C\}$.



### Problem 3


Suppose that $C$ is a convex set.
- Show that its *interior* $\text{int}(C)$ is convex.
- Show that its *closure* $\text{cl}(C)$ is convex. 

### Problem 4

The *Minkowski sum* of two sets $A+B$ is defined by $$A+B \triangleq \{a + b\mid a\in A, b\in B\}\,.$$Similarly, define $\alpha A \triangleq \{\alpha a \mid a\in A\}$ where $\alpha \in \mathbb{R}_+$.
1. Let $A$, $B$ be two convex sets. Show that $A+B$ is also convex.
2. Now given a convex set $C$ and two real numbers $\alpha, \beta > 0$, show that $$\alpha C + \beta C = (\alpha + \beta) C\,.$$
3. Suppose $C$ is not convex. Which one of the following is true?
    (1) It always holds that $\alpha C + \beta C = (\alpha +\beta)C$.
    (2) There exists $\alpha, \beta, C$ such that $\alpha C + \beta C = (\alpha + \beta)C$. But there also exists $\alpha, \beta, C$ such that $\alpha C + \beta C \neq (\alpha + \beta)C$.
    (3) It always holds that $\alpha C + \beta C \neq (\alpha + \beta)C$.
    Give your reasons.
