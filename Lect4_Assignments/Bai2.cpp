Ap dung cong thuc : h(i) = 2i + 5 mod 11
Khoa       Vi tri
12          7
44          5
13          9
88          5
23          7
94          6
11          5
39          6
20          1
16          4
5           4
a, Bang bam(xu ly va cham chaining) : su dung linked list
0 : NULL
1 : 20
2 : NULL
3 : NULL
4 : 16 -> 5->NULL
5 : 44 -> 88 ->11->NULL
6 : 94 -> 39->NULL
7 : 12 -> 23->NULL
8 : NULL
9 : 13->NULL
10 : NULL

b, Bang bam(xu ly va cham bang tham do tuyrn tinh - linear probing) :
	0 : 11
	1 : 39
	2 : 20
	3 : 5
	4 : 16
	5 : 44
	6 : 88
	7 : 12
	8 : 23
	9 : 13
	10 : 94
