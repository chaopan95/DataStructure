# DataStructure
## Range
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
## Zuma
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
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/zuma_example.png"/>

### Restrictions
0 <= n <= 10^4

0 <= length of the initial sequence <= 10^4

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.
# LightHouse
## Description
As shown in the following figure, If another lighthouse is in gray area, they can beacon each other. For example, in following figure, (B, R) is a pair of lighthouse which can beacon each other, while (B, G), (R, G) are NOT.
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/LightHouse_description.png"/>
## Input
1st line: N

2nd ~ (N + 1)th line: each line is X Y, means a lighthouse is on the point (X, Y).

## Output
How many pairs of lighthourses can beacon each other ( For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same )
## Example
<img src="https://raw.githubusercontent.com/chaopan1995/DataStructure/master/_images/LightHouse_example.png"/>

## Restrictions
For 90% test cases: 1 <= n <= 3 * 10^5

For 95% test cases: 1 <= n <= 10^6

For all test cases: 1 <= n <= 4 * 10^6

For every lighthouses, X coordinates won't be the same , Y coordinates won't be the same.

1 <= x, y <= 10^8

Time: 2 sec

Memory: 256 MB

You can only use the C++ language. STL is forbidden.

## Hints
The range of int is usually [-2^31, 2^31 - 1], it may be too small.
## Solution
This problem can be converted into an inverted sort pair problem. How many pairs of LightHouse can beacon each other means how many non-inversable pairs.

1) Sort all points(x, y) according to the coordinate x.

2) Divide-and-conquer. MergeSort all points according to the coordinate y, at the same time keep record of the number of inversable pairs I. <img src="http://latex.codecogs.com/gif.latex?C_{n}^{2}-I" border="0"/> is the final answer.

