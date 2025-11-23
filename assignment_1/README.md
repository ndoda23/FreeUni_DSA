Security

Emil recently created a genius internet page. As a computer science student, he made sure it was secure. Unfortunately, he recently forgot what his password was. To recover it, he needs to go through a simple verification, which he himself wrote...

On the screen he can now see n numbers (written in decimal). The system now allows him to change the password. However, Emil cannot wait too long because after he doesn't complete the verification, the system will ask him to enter a much larger number, i.e., not allow him to change the password quickly. Enough - he needs to enter just one rest from dividing through m (Emil's favorite number) the minimal number of digits that Emil must add to change the password.

Entry

In the first line of entry there are two integers n and m (1 ≤ n ≤ 5 · 10⁵, 1 < m ≤ 10⁹ + 7) separated by a single space, indicating respectively how many numbers are on the screen and Emil's favorite number. In the second line there are n pairs of different integers aᵢ, (1 ≤ aᵢ ≤ 10⁶) separated by single spaces. These are fork digits on the screen.

Output

In the output write one integer - the rest from dividing through m the minimal number of digits that must be added to change the password.

Examples

Entry for test without b0a:

3 100

1 3 4

Output for test without b0a:

3

Explanation: It's enough to add 3 digits - 2, 6, 12. On the screen then all divisors of the number 12 will be present and the system will allow the password to be changed.

Entry for test without b0b:

8 2

1 2 4 5 8 10 20 40

Output for test without b0b:

0

Explanation: On the screen all divisors of the number 40 are already present.

Entry for test without b0c:

7 12

3 5 7 9 11 13 15

Output for test without b0c:

5

Explanation: Adding 41 digits, we get divisors for the number 45045. The rest from dividing 41 by 13 is 2.

Grading

SubtaskConstraintsPoints1aᵢ ≤ 30352No additional constraints65



Author: Tomasz Kwiatkowski

