<h2><a href="https://www.geeksforgeeks.org/problems/geeks-training/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geeks-training">Geek's Training</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Geek is going for <strong>n</strong> day training program. He can perform any one of these three activities Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Help Geek to maximize his merit points as you are given a 2D array of points <strong>points,</strong> corresponding to each day and activity.</span></p>
<pre><span style="font-size: 18px;"><strong>Example:</strong>
<strong>Input:</strong>
n = 3
points = [[1,2,5],[3,1,1],[3,3,3]]
<strong>Output:</strong>
11
<strong>Explanation:</strong>
Geek will learn a new move and earn 5 point then on second
day he will do running and earn 3 point and on third day
he will do fighting and earn 3 points so, maximum point is 11.<br><br></span></pre>
<pre><strong>Example:</strong>
<strong>Input:</strong>
n = 3
points = [[1,2,5],[3,1,1],[3,2,3]]
<strong>Output:</strong>
11
<strong>Explanation:</strong>
Geek will learn a new move and earn 5 point then on second
day he will do running and earn 3 point and on third day
he will do running and earn 3 points so, maximum point is 11.</pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't have to read input or print anything. Your task is to complete the function <strong>maximumPoints()&nbsp;</strong>which takes the integer <strong>n</strong> and a 2D array <strong>points</strong> and returns the maximum points he can earn.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity: </strong>O(3*n)<br><strong>Expected Space Complexity: </strong>O(3*n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraint:</strong><br>1 &lt;=&nbsp; n &lt;= 10<sup>5</sup><br>1 &lt;=&nbsp; point[i] &lt;= 100</span></p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Arrays</code>&nbsp;