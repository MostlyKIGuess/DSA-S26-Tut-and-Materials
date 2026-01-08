#import "@preview/polylux:0.4.0": *
#import "@preview/metropolis-polylux:0.1.0" as metropolis
#import metropolis: new-section, focus


#show: metropolis.setup

#slide[
  #set page(header: none, footer: none, margin: 3em)

  #text(size: 1.3em)[
    *Sorting Algorithms*
  ]

  Data Structures and Algorithms Tutorial

  #metropolis.divider

  #set text(size: .8em, weight: "light")
  IIITH - S26

  #v(1em)
  _Bubble, Selection, Insertion, Merge, Quick Sort_
]

#slide[
  = Agenda

  #metropolis.outline
]

#new-section[Overview]

#slide[
  = What is Sorting?

  *Definition*
  - Arranging elements in a specific order (ascending/descending)

]

#new-section[Simple Sorts]

#slide[
  = Bubble Sort
  *Main Idea*
  - Repeatedly swap adjacent elements if they're in wrong order
  - $O(n^2)$ time, $O(1)$ space

  *Algorithm*
  1. Compare adjacent elements from left to right
  2. Swap if left element > right element
  3. One pass = largest element at correct position
  4. Repeat until no swaps needed

  *Insight*
  - After $i$ passes, last $i$ elements are sorted
  - Can _early exit_ if no swaps in a pass (already sorted!)
  - Best case: $O(n)$ when already sorted
]

#slide[
  = Selection Sort

  *Main Idea*
  - Find minimum element in unsorted portion -> Place it at front
  - $O(n^2)$ time, $O(1)$ space

  *Algorithm*
  1. Find minimum in unsorted portion (index $i$ to $n-1$)
  2. Swap it with element at position $i$
  3. Move boundary: $i$++
  4. Repeat until sorted

  *Insight*
  - _Minimal swaps_: Only $n-1$ swaps total (great for expensive swaps!)
  - Not adaptive: Always $O(n^2)$ even for sorted arrays
  - Good when: Write operations are expensive (e.g., flash memory)
]

#slide[
  = Insertion Sort

  *Main Idea*
  - Build sorted array one element at a time
  - $O(n^2)$ time, $O(1)$ space

  *Algorithm*
  1. Take next element from unsorted portion
  2. Insert it into correct position in sorted portion
  3. Shift elements to make space

  *Insight*
  - _Adaptive_: Fast for nearly sorted data ($O(n)$ best case!)
  - _Stable_: Maintains relative order of equal elements
  - _Online_: Can sort as it receives data (Timsort uses it!)
]

#new-section[Merge Sort]

#slide[
  = Merge Sort: Intuition

  How would you sort LOTS of numbers?
  - Don't tackle it all at once
  - _Split_ into smaller problems -> _Solve_ each small problem
  - _Combine_ solutions!

  *Analogy ig?*
  - Two students each have sorted piles of exam papers
  - To merge: Look at top of both piles, pick smaller one
  - Repeat until both piles empty

  *Insight*
  - Merging two sorted lists takes $O(n)$ time
  - If we split recursively, we get $O(n log n)$ total!
]

#slide[
  = Merge Sort: Visualization

  #align(center, [

  #link("https://opendsa-server.cs.vt.edu/embed/mergesortAV")[Merge Sort Viz]
  ]
  )
]

#slide[
  = Merge Sort: Why O(n log n)?

  *Recurrence Relation:* $T(n) = 2 T(n/2) + O(n)$

  - Split into 2 halves: $2 T(n/2)$
  - Merge takes linear time: $O(n)$

  *Tree Method*
  - Level 0: 1 problem of size $n$ → cost: $n$
  - Level 1: 2 problems of size $n/2$ → cost: $n$
  - Level 2: 4 problems of size $n/4$ → cost: $n$
  - ...
  - Level $log n$: $n$ problems of size 1 → cost: $n$

  Total: $n × log n$ levels = $O(n log n)$

  *Space complexity*: $O(n)$ for temporary arrays during merge
]

#slide[
  = Merge Sort: Pros and Cons

  *Advantages*
  + _Guaranteed performance_: Always $O(n log n)$, no worst case!
  + _Stable sort_: Maintains order of equal elements
  + _External sorting_: Works well with files too large for memory (Here memory refers to RAM)
  + _Parallelizable_: Left and right halves can be sorted independently

  *Disadvantages*
  - _Space complexity_: Requires $O(n)$ extra space, basically not in-place!
  - _Slower in practice_: Quick Sort often faster due to cache locality

  *When to use?*
  - When guaranteed $O(n log n)$ is critical
  - When stability is required
]

#slide[
	#image("stable_vs_not_stable.png"
	)
]

#new-section[Quick Sort]

#slide[
  = Quick Sort: Intuition

  *Insight*

  Don't worry about sorting everything perfectly immediately. Just:
  - Pick one element as "_pivot_"
  - Put everything smaller on left
  - Put everything larger on right
  - Pivot is now in _correct final position_!
  - Recursively sort left and right

  *Analogy ig?*
  - Organizing books by a reference book
  - Pick a book, place all "earlier" books on left, "later" on right
  - Reference book is now correctly positioned
  - Repeat for each pile
]

#slide[
  = Quick Sort: Partition Algorithm

  *Partition *
  Goal: Rearrange array so that:
  - Elements $<$ pivot are on left
  - Elements $>$ pivot are on right
  - Pivot is in correct final position

  *Lomuto Partition Scheme* (using last element as pivot)

  1. Choose pivot: `pivot = arr[high]`
  2. Maintain pointer `i` for "boundary" of smaller elements
  3. For each element `j` from `low` to `high-1`:
     - If `arr[j] < pivot`: swap with position `i`, increment `i`
  4. Finally: swap pivot with position `i+1`
  5. Return pivot position
]

#slide[
  = Quick Sort: Visualization

  #align(center, [

  #link("https://opendsa-server.cs.vt.edu/embed/quicksortAV")[Quick Sort Viz]
  ]
  )
]

#slide[
  = Quick Sort: Algorithm

  *Time Complexity*
  - _Best case_: Pivot divides array evenly
    $
      T(n) = 2 T(n/2) + O(n) = O(n log n)
    $
  - _Worst case_: Pivot is smallest/largest (already sorted!)
    $
      T(n) = T(n-1) + O(n) = O(n^2)
    $
  - _Average case_: $O(n log n)$

  *Space complexity*: $O(log n)$ for recursion stack
]

#slide[
  = Quick Sort: Pivot Selection

  *The Problem*
  - Bad pivot choices -> worst case $O(n^2)$
  - Already sorted array is worst case for "last element" strategy!

  *Strategies*

  1. _Random pivot_: Choose random element (probabilistic guarantee)
  2. _Median-of-three_: Pick median of first, middle, last
  3. _IntroSort_: Switch to Heap Sort if recursion too deep

  *In practice*
  - With good pivot selection, Quick Sort is often _fastest_ comparison sort
  - Cache-friendly: Works on contiguous memory
]

#slide[
  = Quick Sort: Pros and Cons

  *Advantages*
  + _Fast in practice_: Cache-friendly, small constants
  + _In-place_: Only $O(log n)$ space for recursion
  + _Average case_: $O(n log n)$ with good pivot selection

  *Disadvantages*
  - _Worst case_: $O(n^2)$ if bad pivots (rare with good strategy)
  - _Not stable_: Equal elements might be reordered
  - _Fragile_: Easy to implement incorrectly (e.g., overflow in midpoint)

  *When to use?*
  - _Default choice_ for general-purpose sorting
  - When memory is constrained
]

#new-section[Practice Problems]

#slide[
  = Problem 1: Distinct Numbers

  *Problem Statement*
  Given $n$ numbers, count how many _distinct_ numbers are present.

  *Link*: https://cses.fi/problemset/task/1621

  *Intuition*
  - If array is _sorted_, equal numbers are adjacent
  - Just count how many times the value changes!

  *Solution*
  1. Sort the array: $O(n log n)$
  2. Scan through, count when `arr[i] != arr[i-1]`

  *Time*: $O(n log n)$ | *Space*: $O(1)$
]

#slide[
  = Problem 2: Sort Colors

  *Problem Statement*
  Sort an array containing _only_ 0s, 1s, and 2s in a _single pass_.

  *Link*: https://leetcode.com/problems/sort-colors/

  *Intuition*
  - This is _3-way partitioning_ (used in Quick Sort optimization!)
  - Maintain three regions:
    - `[0...low-1]`: all 0s
    - `[low...mid-1]`: all 1s
    - `[high+1...n-1]`: all 2s
    - `[mid...high]`: unknown/unprocessed


]

#slide[
	=== Solution:
  1. Initialize: `low = 0, mid = 0, high = n-1`
  2. While `mid <= high`:
     - If `arr[mid] == 0`: swap with `low`, `low++`, `mid++`
     - If `arr[mid] == 1`: `mid++`
     - If `arr[mid] == 2`: swap with `high`, `high--`

  *Time*: $O(n)$ | *Space*: $O(1)$

]

#slide[
  = Problem 3: Sum of Two Values

  *Problem Statement*
  Given $n$ numbers and target $x$, find two numbers whose sum is $x$.

  *Link*: https://cses.fi/problemset/task/1640

  *Brute Force Intuition*
  - Try all pairs: $O(n^2)$
  - Too slow for $n = 2 times 10^5$!

  *Insight*
  - If array is _sorted_, we can use _two pointers_!
  - Start with smallest and largest
  - If sum too small: move left pointer right (need larger sum)
  - If sum too large: move right pointer left (need smaller sum)

]

#slide[
	=== Solution
  1. Store `(value, original_index)` pairs
  2. Sort by value
  3. Two pointers: `left = 0`, `right = n-1`
  4. Move pointers based on sum comparison

  *Time*: $O(n log n)$ for sorting + $O(n)$ for two pointers = $O(n log n)$

  *Space*: $O(n)$ for storing pairs
]


#slide[
  = Comparison Table

  #align(center,[


  #table(
    columns: (auto, auto, auto, auto, auto),
    stroke: 1pt,
    fill: (x, y) => if y == 0 { blue.lighten(80%) },
    align: center,
    table.header([Algorithm], [Time (Avg)], [Time (Worst)], [Space], [Stable]),
    [Bubble], [$O(n^2)$], [$O(n^2)$], [$O(1)$], [Yes],
    [Selection], [$O(n^2)$], [$O(n^2)$], [$O(1)$], [No],
    [Insertion], [$O(n^2)$], [$O(n^2)$], [$O(1)$], [Yes],
    [Merge], [$O(n log n)$], [$O(n log n)$], [$O(n)$], [Yes],
    [Quick], [$O(n log n)$], [$O(n^2)$], [$O(log n)$], [No],
  )
  ])
]


#slide[
	= Takeaway Problems!
		=== #link("https://cses.fi/problemset/task/1090")[Ferris Wheel]
		There are $n$ children with given weights. Each gondola holds 1-2 children with total weight `<= x`. Find _minimum_ gondolas needed.
		=== #link("https://cses.fi/problemset/task/1629")[Movie Festival]
  	$n$ movies with start and end times. Maximum number of movies you can watch _entirely_?

]




#slide[
  #set page(header: none, footer: none, margin: 3em)

  #align(center)[
    #text(size: 1.5em)[_Questions?_]

    #v(2em)
    Thank you!

    #v(1em)
    #set text(size: .7em)
  ]
]
