<h2><a href="https://www.geeksforgeeks.org/problems/flattening-a-linked-list/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=flattening-a-linked-list">Flattening a Linked List</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Linked List of size n, where every node represents a sub-linked-list and contains two pointers:<br>(i) a<strong> next </strong>pointer to the next node,<br>(ii) a<strong>&nbsp;bottom</strong>&nbsp;pointer&nbsp;to a linked list where this node is head.<br>Each of the&nbsp;sub-linked-list is in sorted order.<br>Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.&nbsp;</span><br><br><span style="font-size: 18px;"><strong>Note:</strong> The flattened list will be printed using the <strong>bottom</strong> <strong>pointer</strong> instead of the next pointer.<br>For more clarity have a look at the printList() function in the driver code.</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>5 -&gt; 10 -&gt; 19 -&gt; 28
|     |     |     | 
7     20    22   35
|           |     | 
8          50    40
|                 | 
30               45<strong>
Output: </strong> 5-&gt; 7-&gt; 8- &gt; 10 -&gt; 19-&gt; 20-&gt; 22-&gt; 28-&gt; 30-&gt; 35-&gt; 40-&gt; 45-&gt; 50.
<strong>Explanation</strong>: The resultant linked lists has every node in a single level.(<strong>Note: </strong>| represents the bottom pointer.)</span>
</pre>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
5 -&gt; 10 -&gt; 19 -&gt; 28
|          |                
7          22   
|          |                 
8          50 
|                           
30              
<strong>Output:</strong> 5-&gt; 7-&gt; 8-&gt; 10-&gt; 19-&gt; 22-&gt; 28-&gt; 30-&gt; 50
<strong>Explanation: </strong>The resultant linked lists has every node in a single level.(<strong>Note: </strong>| represents the bottom pointer.)</span></pre>
<p><strong><span style="font-size: 14pt;">Note :&nbsp;</span></strong><span style="font-size: 14pt;">In the <strong>output</strong> section of the above <strong>examples</strong> the <strong><span style="font-family: 'arial black', sans-serif;">-&gt;</span> </strong>represents the<strong> bottom pointer.</strong></span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n * n * m)<br><strong>Expected Auxiliary Space:</strong> O(n)</span></p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong></span><br><span style="font-size: 18px;">0 &lt;= <strong>n</strong> &lt;= 50<br>1 &lt;=<strong> m<sub>i</sub> </strong>&lt;= 20<br>1 &lt;= Element of linked list &lt;= 10<sup>3</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Paytm</code>&nbsp;<code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>24*7 Innovation Labs</code>&nbsp;<code>Payu</code>&nbsp;<code>Visa</code>&nbsp;<code>Goldman Sachs</code>&nbsp;<code>Qualcomm</code>&nbsp;<code>Drishti-Soft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Linked List</code>&nbsp;<code>Data Structures</code>&nbsp;