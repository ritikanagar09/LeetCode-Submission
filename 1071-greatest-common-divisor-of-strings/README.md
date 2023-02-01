<h2><a href="https://leetcode.com/problems/greatest-common-divisor-of-strings/">1071. Greatest Common Divisor of Strings</a></h2><h3>Easy</h3><hr><div><p>For two strings <code>s</code> and <code>t</code>, we say "<code>t</code> divides <code>s</code>" if and only if <code>s = t + ... + t</code> (i.e., <code>t</code> is concatenated with itself one or more times).</p>

<p>Given two strings <code>str1</code> and <code>str2</code>, return <em>the largest string </em><code>x</code><em> such t<lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);">hat </lighter></lighter></lighter></lighter></em><code><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);">x</lighter></lighter></lighter></lighter></code><em><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"> divides both </lighter></lighter></lighter></lighter></em><code><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);">str1</lighter></lighter></lighter></lighter></code><em><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"> and </lighter></lighter></lighter></lighter></em><code><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);">str2</lighter></lighter></lighter></lighter></code><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);"><lighter data-id="lgt9997162399295474" data-bundle-id="0" data-slot-id="0" style="background-color: rgb(255, 255, 131);">.</lighter></lighter></lighter></lighter></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre><strong>Input:</strong> str1 = "ABCABC", str2 = "ABC"
<strong>Output:</strong> "ABC"
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre><strong>Input:</strong> str1 = "ABABAB", str2 = "ABAB"
<strong>Output:</strong> "AB"
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre><strong>Input:</strong> str1 = "LEET", str2 = "CODE"
<strong>Output:</strong> ""
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= str1.length, str2.length &lt;= 1000</code></li>
	<li><code>str1</code> and <code>str2</code> consist of English uppercase letters.</li>
</ul>
</div>