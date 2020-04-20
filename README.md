# DataStructure
## 1. Range
### Descriptioin
Let S be a set of n integral points on the x-axis. For each given interval [a, b], you are asked to count the points lying inside.

### Input
The first line contains two integers: n (size of S) and m (the number of queries). The second line enumerates all the n points in S. Each of the following m lines consists of two integers a and b and defines an query interval [a, b].

### Output
The number of points in S lying inside each of the m query intervals.

### Example
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Range_example.png)

### Restrictions
0 <= n, m <= 5 * 10^5

For each query interval [a, b], it is guaranteed that a <= b.

Points in S are distinct from each other.

Coordinates of each point as well as the query interval boundaries a and b are non-negative integers not greater than 10^7.

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Solution
1) Sort all points with QuickSort

2) Locate the left border's index ceil[a] and the right border's index floor[b].
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Range_solution.png)
The final answer is floor[b]-ceil[a]+1.


## 2. Zuma
### Description
Let's play the game Zuma! There are a sequence of beads on a track at the right beginning. All the beads are colored but no three adjacent ones are allowed to be with a same color. You can then insert beads one by one into the sequence. Once three (or more) beads with a same color become adjacent due to an insertion, they will vanish immediately.
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Zuma_description.png)
Note that it is possible for such a case to happen for more than once for a single insertion. You can't insert the next bead until all the eliminations have been done.

Given both the initial sequence and the insertion series, you are now asked by the fans to provide a playback tool for replaying their games. In other words, the sequence of beads after all possible eliminations as a result of each insertion should be calculated.

### Input
The first line gives the initial bead sequence. Namely, it is a string of capital letters from 'A' to 'Z', where different letters correspond to beads with different colors.

The second line just consists of a single interger n, i.e., the number of insertions.

The following n lines tell all the insertions in turn. Each contains an integer k and a capital letter Σ, giving the rank and the color of the next bead to be inserted respectively. Specifically, k ranges from 0 to m when there are currently m beads on the track.

### Output
n lines of capital letters, i.e., the evolutionary history of the bead sequence.

Specially, "-" stands for an empty sequence.

### Example
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Zuma_example.png"/>

### Restrictions
0 <= n <= 10^4

0 <= length of the initial sequence <= 10^4

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Solution
Attetion: both 3 beads' elimination and 4 beads' elimination are possible


## 3. LightHouse
### Description
As shown in the following figure, If another lighthouse is in gray area, they can beacon each other. For example, in following figure, (B, R) is a pair of lighthouse which can beacon each other, while (B, G), (R, G) are NOT.
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/LightHouse_description.png"/>

### Input
1st line: N

2nd ~ (N + 1)th line: each line is X Y, means a lighthouse is on the point (X, Y).

### Output
How many pairs of lighthourses can beacon each other ( For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same )

### Example
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/LightHouse_example.png"/>

### Restrictions
For 90% test cases: 1 <= n <= 3 * 10^5

For 95% test cases: 1 <= n <= 10^6

For all test cases: 1 <= n <= 4 * 10^6

For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same.

1 <= x, y <= 10^8

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Hints
The range of int is usually [-2^31, 2^31 - 1], it may be too small.

### Solution
This problem can be converted into an inverted sort pair problem. How many pairs of LightHouse can beacon each other means how many non-inversable pairs.

1) Sort all points(x, y) according to the coordinate x.

2) Divide-and-conquer. MergeSort all points according to the coordinate y, at the same time keep record of the number of inversable pairs I. <img src="http://latex.codecogs.com/gif.latex?C_{n}^{2}-I" border="0"/> is the final answer.


## 4. Train
### Description
Figure shows the structure of a station for train dispatching.
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Train_description.png"/>
In this station, A is the entrance for each train and B is the exit. S is the transfer end. All single tracks are one-way, which means that the train can enter the station from A to S, and pull out from S to B. Note that the overtaking is not allowed. Because the compartments can reside in S, the order that they pull out at B may differ from that they enter at A. However, because of the limited capacity of S, no more that m compartments can reside at S simultaneously.

Assume that a train consist of n compartments labeled {1, 2, …, n}. A dispatcher wants to know whether these compartments can pull out at B in the order of {a1, a2, …, an} (a sequence). If can, in what order he should operate it?

### Input
Two lines:

1st line: two integers n and m;

2nd line: n integers separated by spaces, which is a permutation of {1, 2, …, n}. This is a compartment sequence that is to be judged regarding the feasibility.

### Output
How many pairs of lighthourses can beacon each other ( For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same )

### Example
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Train_example.png"/>

### Restrictions
1 <= n <= 1,600,000

0 <= m <= 1,600,000

Time: 2 sec

Memory: 256 MB You can only use the C++ language. STL is forbidden.

### Solution
This is a question of stack permutation. We repeat this process, if some element is not corresponded, output no; otherwise, print all process.


## 5. Proper Rebuild
### Description
In general, given the preorder traversal sequence and postorder traversal sequence of a binary tree, we cannot determine the binary tree.
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/ProperRebuild_description.png"/>
For example, although they are two different binary tree, their preorder traversal sequence and postorder traversal sequence are both of the same.

But for one proper binary tree, in which each internal node has two sons, we can uniquely determine it through its given preorder traversal sequence and postorder traversal sequence.

Label n nodes in one binary tree using the integers in [1, n], we would like to output the inorder traversal sequence of a binary tree through its preorder and postorder traversal sequence.

### Input
The 1st line is an integer n, i.e., the number of nodes in one given binary tree,

The 2nd and 3rd lines are the given preorder and postorder traversal sequence respectively.

### Output
The inorder traversal sequence of the given binary tree in one line.

### Example
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/ProperRebuild_example.png"/>

### Restrictions
For 95% of the estimation, 1 <= n <= 1,000,00

For 100% of the estimation, 1 <= n <= 4,000,000

The input sequence is a permutation of {1,2...n}, corresponding to a legal binary tree.

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Hints
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/ProperRebuild_hint.png"/>

observe the positions of the left and right children in preorder and postorder traversal sequence.

### Solution
Find L and R child for each node, in-order print


## 6. TSP
### Descriptioin
Shrek is a postman working in the mountain, whose routine work is sending mail to n villages. Unfortunately, road between villages is out of repair for long time, such that some road is one-way road. There are even some villages that can’t be reached from any other village. In such a case, we only hope as many villages can receive mails as possible.

Shrek hopes to choose a village A as starting point (He will be air-dropped to this location), then pass by as many villages as possible. Finally, Shrek will arrived at village B. In the travelling process, each villages is only passed by once. You should help Shrek to design the travel route.

### Input
There are 2 integers, n and m, in first line. Stand for number of village and number of road respectively.

In the following m line, m road is given by identity of villages on two terminals. From v1 to v2. The identity of village is in range [1, n].

### Output
Output maximum number of villages Shrek can pass by.

### Example
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/TSP_example.png)

### Restrictions
1 <= n <= 1,000,000

0 <= m <= 1,000,000

These is no loop road in the input.

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Hints
Topological sorting

### Solution
Topological sort + dynamic programming


## 7. Broadcast
### Descriptioin
A broadcaster wants to set up a radio broadcast transmitter in an area. There are n towns in the area, and each town has a transmitter installed and plays its own program.

However, the company only licensed the two bands FM104.2 and FM98.6, and transmitters using the same band would interfere with each other. It is known that the signal coverage of each transmitter is a circular area with a radius of 20km. Therefore, if two towns with a distance of less than 20km use the same band, they will not be able to function properly due to band interference. Listen to the show. Now give a list of towns with distances less than 20km, and try to determine whether the company can make residents of the entire region hear the broadcasts normally.

### Input
The first line is two integers n, m, which are the number of towns and the number of town pairs that are less than 20km.

The next m lines, 2 integers per line, indicate that the distance between the two towns is less than 20km (numbering starts at 1).

### Output
Output 1 if the requirement is met, otherwise -1.

### Example
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Broadcast_example.png)

### Restrictions
1 ≤ n ≤ 10000

1 ≤ m ≤ 30000

There is no need to consider the spatial characteristics of a given 20km town list, such as whether triangle inequality is satisfied, whether more information can be derived using transitivity, and so on.

Time: 2 sec

Space: 256MB

You can only use the C++ language. STL is forbidden.

### Tips
BFS

### Solution
Once three towns have a distance less than 20km to each other, return -1.



## 12. Cycle
### Descriptioin
Cycle shifting refers to following operation on the sting. Moving first letter to the end and keeping rest part of the string. For example, apply cycle shifting on ABCD will generate BCDA. Given any two strings, to judge if arbitrary times of cycle shifting on one string can generate the other one.

### Input
There m lines in the input, while each one consists of two strings separated by space. Each string only contains uppercase letter 'A'~'Z'.

### Output
For each line in input, output YES in case one string can be transformed into the other by cycle shifting, otherwise output NO.

### Example
![Image text](https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/Broadcast_example.png)

### Restrictions
0 <= m <= 5000

1 <= |S1|, |S2| <= 10^5

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

### Solution
According to its definition strcopy s1's prefix to s1's suffix.

