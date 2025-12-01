https://szkopul.edu.pl/problemset/problem/n986eRgmdL0DsqT2Hn5aFDRs/site/?key=statement

Problem: WYB - Selective BajtazarPolish Olympiad in Informatics (OI), Stage III
Memory limit: 256 MB.

Problem Statement 
Similar to last year, Bajtazar is preparing for Christmas by decorating his house for the holiday season. He hung a garland with n light bulbs. Each bulb has one of five available colors, which will be denoted by the letters a to e. Bajtazar started modifying the colors of individual bulbs.A modification operation works as follows: Bajtazar selects two colors a and b and additionally a total number p, then replaces the first p occurrences of color a with color b.Since Bajtazar is planning many changes, he asked you to write a program that presents the appearance of the garland after m modifications.InputThe first line of input contains two integers n and m (1 ≤ n, m ≤ 1,000,000), representing the number of bulbs in the garland and the number of color change operations. In the second line, there are n lowercase English letters (without spaces) representing the consecutive colors of the bulbs in the garland.The next m lines contain descriptions of the operations. Each of these lines contains one additional integer p, two different lowercase English letters aᵢ and bᵢ, separated by single spaces. Such a line means that among the first pᵢ bulbs of color aᵢ, you need to change the bulbs to color bᵢ. You can assume that before the operation, there are at least pᵢ bulbs of color aᵢ in the garland.

Output
The output should contain one line with a string of n letters from a to e (without spaces) representing the consecutive colors of the bulbs in the garland after all color change operations.
Example
Input:
10 3
acabbabbac
3 b c
4 a b
3 c a
Output:
babaabcbbc
Explanation: The colors of the bulbs changed in the following way:
acabbabbac → acaccacbac → bcbccbcbbc → babaabcbbc
