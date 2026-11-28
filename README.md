*This project has been created as part of the 42 curriculum by boadopo, marigal.*

# push_swap

Sort integers on a stack with a very limited set of instructions, using as few operations as possible.

## Description

**push_swap** is a C program that receives a list of distinct integers and prints, on the standard output, a list of
operations (one per line) that sorts them in ascending order.

- Two stacks are available: **a** (filled with the input, the first argument is the top) and **b** (empty at the start).
- The goal is to end with all numbers sorted in **a** (smallest on top) and **b** empty.
- Only 11 operations are allowed: `sa sb ss pa pb ra rb rr rra rrb rrr`.
- The program does not sort the numbers itself: it **generates the program** (the sequence of operations) that sorts them.
  The shorter the sequence, the better.

The project is about algorithmic complexity: the complexity of each algorithm is measured in the **number of push_swap
operations generated**, not in CPU time.

### Features

- Four sorting strategies: simple `O(n^2)`, medium `O(n sqrt(n))`, complex `O(n log n)` and an adaptive strategy.
- A disorder metric (0 to 1) computed on the initial stack, used by the adaptive strategy.
- Strategy selection at runtime with `--simple`, `--medium`, `--complex`, `--adaptive` (default).
- A benchmark mode `--bench` that prints statistics on `stderr`.
- Error management (`Error` on `stderr`), no global variable, no memory leak.
- Bonus: a `checker` program that verifies the generated operations.

## Instructions

### Compilation

```bash
make          # builds ./push_swap
make bonus    # builds ./checker
make clean    # removes object files
make fclean   # removes object files and binaries
make re       # fclean + all
```

The project is compiled with `cc -Wall -Wextra -Werror` and does not relink when nothing changed.

### Execution

```bash
./push_swap [strategy] [--bench] <integers...>
```

| Option | Effect |
|---|---|
| `--simple` | Forces the `O(n^2)` algorithm |
| `--medium` | Forces the `O(n sqrt(n))` algorithm |
| `--complex` | Forces the `O(n log n)` algorithm |
| `--adaptive` | Chooses the algorithm from the disorder (default) |
| `--bench` | Prints the benchmark on `stderr` after sorting |

### Usage examples

```bash
$> ./push_swap 2 1 3 6 5 8
$> ./push_swap --simple 5 4 3 2 1
$> ARG="4 67 3 87 23"; ./push_swap --complex $ARG | ./checker $ARG
OK
$> ./push_swap --bench --adaptive $ARG 2> bench.txt | ./checker $ARG
OK
$> cat bench.txt
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt(n))
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

### Error handling

`Error` followed by a newline is printed on `stderr` for: a non-integer argument, an integer outside the `int` range,
a duplicate value. With no number to sort, nothing is printed.

```bash
$> ./push_swap 0 one 2 3
Error
$> ./push_swap 3 2 3
Error
```

### Testing

```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) 2> bench.txt

ARG="3 2 1 0"; ./push_swap --bench $ARG 


```

Run it many times: the benchmark thresholds must be respected on every draw, not only on average.

## Algorithms

### Preliminary steps (shared by all strategies)

1. **Parsing and validation**: every argument is converted with an overflow-safe `atoi` (accepts an optional sign and
   digits only, must fit in an `int`). Duplicates are rejected.
2. **Disorder measure**: computed on the initial stack, before any move (see below).
3. **Normalization**: each value is replaced by its **rank** (0 for the smallest, n-1 for the largest). After that the
   stack is a permutation of `0..n-1`, and the goal becomes `0, 1, 2, ..., n-1` from top to bottom. The algorithms only
   manipulate ranks, so negative numbers and huge values need no special case.
4. **Small cases**: an already sorted stack produces no operation; two or three elements are handled directly
   (at most 2 operations for three elements).

Stacks are implemented as **singly linked lists**: `pa`/`pb`/`sa`/`sb` are `O(1)` pointer changes. The counters,
options and both stacks live in one context structure passed to every function (no global variable).

### Disorder metric

Disorder is the proportion of **inversions** among all pairs of the initial stack:

```
disorder = (number of pairs (i < j) with a[i] > a[j]) / (n * (n - 1) / 2)
```

It is `0` for a sorted stack, `1` for a reversed one, and about `0.5` for a random permutation (on average half of
the pairs are inverted). With fewer than two elements there is no pair and the disorder is defined as `0`.

### 1. Simple algorithm: selection sort, `O(n^2)`

**Idea**: repeatedly extract the minimum.

- While **a** has more than 3 elements: find the smallest element, bring it on top with `ra` or `rra` (whichever is
  shorter), then `pb`.
- Sort the remaining 3 elements in **a**.
- Push everything back with `pa`. Elements were pushed from the smallest to the largest, so the last pushed (the
  largest of the pushed ones) comes back first and lands just above the three largest: **a** ends sorted.

**Complexity (operations)**: each of the `n` extractions costs at most `n/2` rotations plus one push, and the
final phase costs `n` pushes: at most `n * (n/2 + 2)` operations, i.e. `O(n^2)`.
**Space**: `O(1)` extra memory (the `n` elements only move between the two stacks).

**Why we keep it**: it is simple, correct on any input, and cheap when the stack is nearly sorted (the minimum is
already close to the top, so rotations are short).

### 2. Medium algorithm: chunks, `O(n sqrt(n))`

**Idea**: split the rank range into about `sqrt(n)`-sized chunks and send them to **b** chunk by chunk, so that **b**
is roughly ordered by chunk and the final extraction is cheap.

- Chunk boundaries are computed on the ranks (`0..n-1` split in equal ranges).
- **Phase 1 (push)**: for each chunk, from the lowest to the highest, repeatedly take the element of that chunk that
  is the **closest to the top or to the bottom** of **a** (shortest rotation) and `pb` it. Elements from the lower half
  of the chunk are additionally rotated to the bottom of **b** (`rb`), which keeps **b** in a "half sorted" state.
- **Phase 2 (pull back)**: while **b** is not empty, bring the **largest** element of **b** on top with `rb` or `rrb`
  (shortest way) and `pa`. **a** is filled from the largest to the smallest, hence sorted at the end.

**Complexity (operations)**: with a chunk size of order `sqrt(n)`, an element of the current chunk is, for typical
inputs, found within `O(sqrt(n))` rotations, and in phase 2 the largest element of **b** is always inside the most
recently pushed chunk, so it is at distance `O(sqrt(n))` of the top. Each of the `n` elements therefore costs
`O(sqrt(n))` operations in both phases: `O(n sqrt(n))`. (The bound is an average-case argument for non-adversarial
inputs; the number of chunks is a tuned parameter.)
**Space**: `O(1)` extra memory.

### 3. Complex algorithm: radix sort, `O(n log n)`

**Idea**: LSD radix sort on the **binary representation of the ranks**.

- `bits` = number of bits needed to write `n - 1`.
- For each bit, from the least significant to the most significant: look at the top of **a** `n` times; if the bit is
  `0`, `pb`, otherwise `ra`. Then `pa` everything back.
- Each pass is a **stable** partition, so after the last bit the stack is sorted. The loop stops early as soon as **a**
  is already sorted.

**Complexity (operations)**: each pass costs at most `n` (`pb`/`ra`) + `n` (`pa`) = `2n` operations and there are
`ceil(log2 n)` passes: at most `2 n ceil(log2 n)` operations, i.e. `O(n log n)`, **independently of the initial order**.
**Space**: `O(1)` extra memory.

### 4. Adaptive algorithm

The strategy is chosen from the disorder measured **before any move**:

| Disorder | Regime | Method | Operation bound |
| `< 0.2` | low | selection sort (simple) | `O(n^2)` |
| `0.2 <= d < 0.5` | medium | chunks (medium) | `O(n sqrt(n))` |
| `>= 0.5` | high | radix sort (complex) | `O(n log n)` |

**Rationale for the thresholds**

- A random permutation has a disorder of about `0.5`. Anything `>= 0.5` is as messy as random input or worse
  (up to `1` for a reversed stack): we want a method whose cost does **not** depend on the order, which is exactly
  the radix sort (fixed `~2 n log2 n` operations).
- Below `0.2` the stack is mostly in place: only a few elements are far from their final position. Radix would
  still pay its full `log n` passes, whereas selection sort finds the minimum near the top and uses short rotations.
- Between `0.2` and `0.5` the stack is partially ordered: chunks exploit the existing structure (elements of the
  same chunk are often already close to each other) while keeping a guaranteed `O(n sqrt(n))` order of magnitude.

**Complexity argument**: the adaptive strategy executes exactly one of the three methods above, so its number of
operations is bounded by the bound of the selected regime (`O(n^2)`, `O(n sqrt(n))` or `O(n log n)`).
Computing the disorder costs `O(n^2)` comparisons but **zero push_swap operations**, and the model counts operations
only. **Space**: `O(n)` for the two stacks (the `n` elements as list nodes), `O(1)` of additional memory.

## Benchmark mode

With `--bench`, after sorting, the program prints on **stderr** (so it never pollutes the operations on `stdout`):

- the computed disorder as a percentage with two decimals;
- the strategy name and its theoretical complexity class (for `--adaptive`, the class of the method actually used);
- the total number of operations;
- the count of each operation (`sa sb ss pa pb ra rb rr rra rrb rrr`).

`ss`, `rr` and `rrr` each count as **one** operation.

### Results (to fill with our own measurements)

| Input | Pass | Good | Excellent | Our result (max over N runs) |



| 100 random numbers | < 2000 | < 1500 | < 700 | 574 < 700 (Excellent)|
| 500 random numbers | < 12000 | < 8000 | < 5500 | 5262 < 8000 (Excellent) |

## Technical choices

- Language C, compiled with `cc -Wall -Wextra -Werror`, 42 Norm compliant.
- Allowed functions only: `read`, `write`, `malloc`, `free`, `exit` (and our own helpers).
- Operations are split in two layers: **pure** functions that only modify the stacks, and wrappers that also print and
  count the operation. The same pure functions are reused by the bonus `checker`.
- All allocated memory is freed on every exit path, including error paths.

## Bonus: checker

`./checker <integers...>` reads operations on the standard input (one per line), applies them to the stack and prints
`OK` if **a** is sorted and **b** is empty, `KO` otherwise. `Error` is printed on `stderr` for invalid arguments or
an unknown / badly formatted operation.

```bash
shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) 2> bench.txt | ./checker $(cat args.txt) 
```

## Contributions

| Member | Contributions |

| boadopo |(stack, operations, normalization, simple and medium algorithms, benchmark) |
| marigal| (disorder metric, radix, adaptive strategy, checker) |
| Both | parsing, optimizations, Makefile, testing, README, code review (each member can explain every part of the code) |

## Resources

### References

- Wikipedia, *Selection sort*: https://en.wikipedia.org/wiki/Selection_sort
- Wikipedia, *Radix sort*: https://en.wikipedia.org/wiki/Radix_sort
- Wikipedia, *Bucket sort*: https://en.wikipedia.org/wiki/Bucket_sort
- Wikipedia, *Big O notation*: https://en.wikipedia.org/wiki/Big_O_notation
- Wikipedia, *Inversion (discrete mathematics)*: https://en.wikipedia.org/wiki/Inversion_(discrete_mathematics)
- Wikipedia, *Stack (abstract data type)*: https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- D. E. Knuth, *The Art of Computer Programming, Vol. 3: Sorting and Searching*
- Norminette: https://github.com/42School/norminette
- `man 2 read`, `man 2 write`, `man 3 malloc`, Valgrind documentation: https://valgrind.org/docs/manual/

### Use of AI

> To fill honestly with what we really did. Example of the expected level of detail:

- **Understanding the subject**: AI was used to rephrase the subject and the operations, and to explain the notions of complexity and disorder.
- **README**: AI helped structure this document; the content was reviewed and adapted by us to match our code.
