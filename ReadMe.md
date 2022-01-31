# Lessons Learnt
## LeetCode
### Blind 75
#### 1. Two Sum (Easy)
Use a HashMap to store all values with their index in the array in first traversal. In next traversal, check if the complement (target - current num) of the number exists in the HashMap.
#### 3. Longest Substring Without Repeating Characters (Medium)
Used a sliding window approach where we keep a hashtable that has ASCII value of character as key and the char's last position as the value. If during evaluation we find that the current character on the right end of the window is duplicated within the window, we can use the last postion of the duplicate char from the hashtable to move the left pointer to one position to the right of the duplicate character.
#### 5. Longest Palindromic Substring (Medium)
Start array traversal from index 1. For each character at current index, get the start & end indexes of the largest palindrome that can be formed with even characters and odd characters with the current character in the middle. One of the current strings among odd & even no of characters will be the current longest. compare the current longest with overall longest string. At the end of traversal, we will have the largest palindrome.
#### 11. Container With Most Water (Medium)
Use two pointers left and right. Left at 0, right at array.length-1. Calculate area for current pointers. Move that pointer at which the tower is of lower height as that is the limiting factor for the max area. When the two pointers cross each other, we will have our max area available with us.
#### 15. 3Sum (Medium)
Sort the input array to line the elements in ascending order and also so that we don't process the same value twice. Here as the target sum is zero (0), we can stop processing as soon as we reach numbers that are > 0 since our array is sorted. For each element under consideration, choose two pointers (leftPtr at i + 1 & rightPtr at arr.length-1). Add three numbers at i, leftPtr, rightPtr. If sum = 0, capture the numbers and move both pointers. Else if sum < 0, move leftPtr ahead else if sum > 0, move rightPtr back. When the two pointers cross, you would have analyzed all possible combos for element at index i.
#### 19. Remove Nth Node From End of List (Medium)
Create dummy node pointing to head. Create first & second pointers equal to dummy. Move first pointer N+1 steps. If first pointer isn't null, move both pointers. When we reach the end of the list, we can remove the element that second pointer is pointing to by using second.next = second.next.next
#### 20. Valid Parentheses (Easy)
Create a Map of closing brackets ), }, ] as keys and their corresponding opening brackets as values. Traverse the array. If opening bracket is present, push to stack. If closing bracket is encountered, pop the stack and comapre against the current value with the expected value in the map. In the end if the stack is empty, the expression is valid.
#### 21. Merge Two Sorted Lists (Easy)
If either of the lists are null, return the other list. Create three pointers: p1 (pointing to first list), p2 (pointing to second list), p1Prev (will be pointing to the previous element in final list all the time). If p1 < p2, move p1 to next and p1Prev to p1. Otherwise, point p1Prev.next to p2, move p1Prev to p2, p2 moves to its next, p1Prev.next points to p1 now. When either p1 or p2 reach the end of their list, p1Prev can point to the remaining list to form the final ordered list.
#### 23. Merge k Sorted Lists (Hard)
Create a dummy node and a pointer "ptr" pointing to it. Add the first element of all the lists to a minHeap. So long as the minHeap is not empty, pop the lowest element from the minHeap and set ptr.next to this element and move ptr to next. If the current added element is pointing to next node, add that next node to the minHeap. When the minHeap is out of elements, we will have a sorted list with us.
#### 33. Search in Rotated Sorted Array (Medium)
Approach 1:- Use binary search to find the rotated index (the position where arr[i] > arr[i+1]). Once found, We can check if target num is at the rotated index itself. Otherwise, it will be to left or right of the rotated index. Perform normal binary search for target num on the correct sub-array once you found out the right half to look at.

Approach 2:- Follow usual binary search itself. When we find mid, we have to check on which side of mid do we have the non-rotated array. If target falls in the non-rotated array, ensure to update the pointers to consider the non-rotated array section. e.g. if for a given mid, non-rotated array falls on left and target also falls on left, update `end = mid - 1` otherwise `start = mid + 1`
#### 39. Combination Sum (Medium)
Use backtracking to invoke a function which receives a target sum and the remaining sum to be explored. If the remaining sum reaches zero, we have a solution so capture the accumulator list at that instant. 
#### 48. Rotate Image (Medium)
For matrix related questions, check if transpose and rotations help in deriving the result. In this Q, we had to transpose the matrix and then take a reflection of it vertically to rotate it clockwise once. For anticlockwise rotation, we would need to take a reflection horizontally.
#### 49. Group Anagrams (Medium)
Create a HashMap where key will be the sorted character array of all the words and value will be a list of words. For each word, generate its sorted char array. Pick the key for this sorted array from the map and add the current word to the list pointed by the key in the HashMap.
#### 53. Maximum Subarray (Easy)
Set currSum and maxSum to the first element of the array. Start traversal from second element. At each element, currSum will be maximum of current num + currSum or just current num i.e. if a -ve number is coming, it will reduce the sum so it has to be ignored. Once currSum is identified for current element, we can update the maxSum to the maximum of currSum and maxSum.
#### 54. Spiral Matrix (Medium)
Setup the four boundaries: top, bottom, left and right. Loop through boundary rows and columns and reduce the boundaries in each loop by incrementing/decrementing. Handle edge cases of having just one row/column by checking if boundary values are same (left != right and top != bottom) when traversing back on a row/column
#### 55. Jump Game (Medium)
Approach 1 - Backtrack --> Create a backtrack function that takes a position in the array as input. Check the maximum index we can jump to based on the value in the array at current position. Call backtrack again iteratively from the max position we can reach till current position decrementing. If in any backtrack call, we are able to reach the end of the array, return true.

Approach 2 - DP --> Create an enum Index { GOOD, BAD, UGLY } and declare an Index[] array for all positions. Initially set all positions in the Index[] array to UGLY. Set the last position as GOOD as we can reach the last position if we are already in the last position. Start iterating down from N-2 index in the array, if from any position we are able to reach a position where the value set for that position in the Index[] array is GOOD, set the value of current position to GOOD. Finally check if the Index[0] is set to GOOD after this iteration.

Approach 3 - Greedy --> Set a variable `lastPos` to N-1. Iterate from `lastPos` down to 0. If at any index `i`, based on the value at the index, we are able to reach `lastPos`, set `lastPos` to `i`. Finally, check if `lastPos` is set to 0 or not. 
#### 56. Merge Intervals (Medium)
First sort the intervals based on the starting value of all the intervals. Initiate a LinkedList (LL) object. If the LL is empty (when still at first interval) or if the starting value of current interval is greater than the ending value of the interval in the last node of LL, add the current interval to the LL. Otherwise the ending value of the last node in LL will be the bigger of the node's current ending value or the ending value of the current interval under consideration.
#### 57. Insert Interval (Medium)
Start a pointer at index 0. First add all the intervals that start before the start time of new interval to be inserted into a result list. Now, if either the result list is empty or there is no overlap between last entry of result list and new interval to be inserted, just append the new interval to the list without checks. Otherwise, there is overlap. Therefore, merge the new interval with the last entry in the result list. For the remaining entries, keep incrementing the pointer and merge the intervals to the result list.
#### 62. Unique Paths (Medium)
Approach - DP --> As robot can either move down or right, there is only one way to reach the last cell in the first row i.e. right->right->right... Similarly, there is only one way to reach the last cell in the first column viz. down->down->down... Therefore, fill all the cells with the value 1. Now the cell [1][1] can be reached by two ways: right->down from [0][0] or down->right from [0][0]. Thus, any cell at [m][n] can be reached by no of ways = ways to reach cell [m-1][n] + [m][n-1]. Update all the cells using this calculation. Finally, return the value in the cell: [m-1][n-1]
#### 70. Climbing Stairs (Easy)
Step 1 on the stairs can be reached in only one way: directly step on step 1. Similarly, Step 2 on the stairs can be reached by two ways: directly step on step 2 or go to step 1 and then to step 2. At step 3, we can reach by taking single step from step 2 or two steps from step 1. Thus, any step N can be reached by no of ways to reach step N-2 + no of ways to reach step N-1 as step N can be reached from N-1 & N-2 is one way each. Create the DP array using the previous formula and return Nth element from the DP array
#### 73. Set Matrix Zeroes (Medium)
If any cell has zero, we need to mark the entire row & column of that cell to zero. For this we choose the first cells in the first row and first cells in the first column to zero to indicate that the entire row/column has to be updated with 0s. Now, since the cell: [0][0] will be used for both the first row and first column, we can use it to indicate if the first row has to be set to zero and use a separate boolean value to identify if the first column has to be updated with 0s. First set the indicator cells (in first row/col) to zero based on one time traversal of the matrix. Then set zeros in cells other than first row/col based onthe indicator cells. Then fix the first row based on the value in cell: [0][0]. Finally, fix the first column based on whether the boolean set earlier.
#### 76. Minimum Window Substring (Hard)
If either of passed strings S/T are empty, return blank string.
Form a map of characters and their counts within T in a variable dicT.
Set a variable "required" whose value is equal to number of keys within dicT.
Created a new list "filteredS" that contains relevant pairs of characters that are present in T and their positions within S.
Declare two pointers l & r (for left and right), start traversing the filteredS list incrementing r. At each point, add the character within filteredS pointed by r into a map "windowCounts" that keeps counts of characters in current window.
If the current processed character's count in windowCount is same as the count of the same character in dicT, increment the variable "formed".
Now, try shortening the window by moving the left pointer l while l <= r and the variable formed = required. each time calculate the window length based on characters that l & r are pointing. If less that current window length, update the current window length. Before incrementing l, check if the removal of character pointed by l disturbs the count of this character within windowCounts wrt the count in dicT. If so, decrement the variable "formed".
Continue doing this till we reach the end of the filteredS list.
#### 79. Word Search (Medium)
Approach - Backtracking --> At any cell, we have four directions we can search for next char: top, right, down, left. Write a backtracking function that takes the board as input along with a particular cell (row:col pair) plus the index from which to search in the target word. If the index has reached the end of target string, we have found the word so return true. Else check if we are going out of row/col boundaries in the passed row:col pair or if the current char in the cell is not the same as the one at the passed index. In that case, return false. Otherwise, we have a match; update the content of current cell to `$` so that we don't match this one again. Now, backtrack in all 4 available directions. If any direction returns true, return true from the function.
#### 91. Decode Ways (Medium)
Approach 1 - Recursion with memoization --> Create a `memo` HashMap to store the index,(no of ways) combo. Create recursive function that takes an index and the target string as input. If the `memo` has a value for current index, return that answer. If index has reached end of String, return 1 indicating 1 way to decode is possible. If the current character is 0, return 0 as we cannot form any alphabet whose numeric equivalent will start with 0. After the above two conditions, we can check if we are at the last index of the string and return 1; this is to avoid index issues later when we try to evaluate two chars at once starting from current index. Next, for single char consideration, simple call recursive function again pointing to next index and capture that answer. Then, consider next two chars at once. If the value of next two chars is less than 26, call recursive function again with index + 2 to skip two chars and add the answer returned by that function to the current answer value. Put the answer for current index into the `memo` map.

Approach 2 - DP with Array --> Create a DP array of length N + 1. Initiate the values at 0 & 1 to 1. Index 0's value = 1 is just to provide a base count when considering the first two characters together for counting. Index 1's value = 1 is because with a single char, we have 1 way to decode. Start iteration of DP array from index 1 till N. If the char at current index is not 0, set value at index + 1 = (value at index) as this is a valid char to count for decoding. Next form the two digit number for previous index and current index. If this two digit number lies between 10 and 26, add the value from (index - 1) in DP array to (index + 1) to count the decode way that considers two chars at once. In the end return the value at index N in the DP array to get the answer.

Approach 3 - DP with constant space --> In the previous DP approach, at any point in time, we are only considering three values: value at current index, value at (index - 1) and value at (index - 2). We can thus replace these with two simple variables: `oneBack` and `twoBack`. In each iteration, for single char consideration, set `current` count value equal to `oneBack` and for two char consideration, add the value stored in `twoBack` variable to `current` count. At the end of each iteration perform: `twoBack = oneBack;` and `oneBack = current;`. In the end, return the value of `oneBack` as the answer.
#### 98. Validate Binary Search Tree (Medium)
Recursive validate method: Set highVal and lowVal to null and invoke the validate() method on root node. Inside validate method, if node is null, return true. If the node value is smaller than passed lowVal or greater then passed highVal (provided they are non-null), return false. Otherwise invoke validate on left and right children of the current node with updated low & high vals.
#### 100. Same Tree (Easy)
In the function `isSameTree` which is passed the root nodes of both trees, return true if both nodes are null. Else if both are not null and have the same value, recursively call the left nodes and right nodes of both the trees and AND the boolean results. In all other cases, return false.
#### 102. Binary Tree Level Order Traversal (Medium)
Approach 1 - Iterative --> Create a list of list to store results. Inside the function, create a queue that will hold the nodes for our BFS. Add the passed root node to the queue to begin with and set a local variable `level` to 0. While the queue is not empty, inside the loop add a new array list for current level into results. Set a variable `levelSize` equal to the current queue size to store the nodes in the current level. Iterate till the `levelSize` value from zero and pop nodes from the queue. For each node popped, add their children back to the queue. Also, add the popped node to the results list for the current level value. At the end of the `levelSize` loop, increment the level value to start considering the next level.

Approach 2 - Recursive --> Create a recursive function that takes in a node and level value. If the current level value isn't present in results list, add a new list in the results list for the current passed level. Then add the current passed node for the level it is passed into the results list. Further, recursively invoke the function for left and right child by passing level + 1 as second argument.
#### 104. Maximum Depth of Binary Tree (Easy)
Write a recursive function which accepts a node. If the node is `null`, return 0. Otherwise, return the max value of recursive calls of left chils and right child + 1.
#### 105. Construct Binary Tree from Preorder and Inorder Traversal(Medium)
Preorder traversal follows `Root -> Left -> Right` i.e. we have easy access to root using preorder[0]. Also, inorder traversal follows `Left -> Root -> Right` i.e. if we know the position of `Root`, we can recursively split the entire array into two subtrees. Create a value to index map from the inorder array to get O(1) operation access to get the position of the next root of the subtree from inorder array easily. After this, recursively call a method on the preorder array elements each time passing a subset of indexes to search from the inorder array to form the left and right subtrees. 
#### 121. Best Time to Buy and Sell Stock (Easy)
Kadane's algorithm: Set `maxProfit = 0` and `minBuyPrice = arr[0]`. Iterate through the array. If any price is lower than current min buy price, set that as new min buy price. Calculate profit with current price by checking against the min buy price. If the current profit goes over max profit so far, update the max profit to the new value.
#### 124. Binary Tree Maximum Path Sum (Hard)
* Initiate max_sum as the smallest possible integer and call max_gain(node = root).
* Implement max_gain(node) with a check to continue the old path/to start a new path:
  * Base case : if node is null, the max gain is 0.
  * Call max_gain recursively for the node children to compute max gain from the left and right subtrees : left_gain = max(max_gain(node.left), 0) and
  right_gain = max(max_gain(node.right), 0).
  * Now check to continue the old path or to start a new path. To start a new path would cost price_newpath = node.val + left_gain + right_gain. Update max_sum if it's better to start a new path.
  * For the recursion return the max gain the node and one/zero of its subtrees could add to the current path : node.val + max(left_gain, right_gain).
#### 128. Longest Consecutive Sequence (Medium)
Add all the numbers to a HashSet: `numSet`. Iterate through the array for each N. If N-1 is not part of the `numSet`, we can start counting a new sequence by starting at N and checking if N+1 is available in the `numSet` then further incrementing N. At the end of the inner loop, we can check if the current streak is greater than the longest streak seen and thus update the longest streak.
#### 133. Clone Graph (Medium)
Use either BFS or DFS using recursion to traverse the graph. The `visited` set can be replaced with a Map that holds the original node as key and a cloned node as value. During traversal, we will add the cloned nodes for all nodes in the `visited` map. Also, during traversal we will populate the neighbor array for each node by using the clones from the same `visited` map.
#### 139. Word Break (Medium)
TBD
#### 143. Reorder List (Medium)
Step 1 -> Find middle of the list using slow and fast pointers

Step 2 -> Reverse the second part of the list

Step 3 -> Merge the two parts
#### 141. Linked List Cycle (Easy)
Keep two pointers: slow and fast. slow pointer moves one step at a time. fast pointer moves two steps at a time. If at any point, the fast and slow pointers point to the same node, we have a cycle. Otherwise if at any point fast or fast.next point to null, we don't have any cycle.
#### 152. Maximum Product Subarray (Medium)
Keep 3 variables: `result`, `maxSoFar` and `minSoFar`. Initialize all of these to the first element in the array. Iterate from the second element. In each iteration, find `maxSoFar` which is maximum of current element, `maxSoFar` * current element and `minSoFar` * current element. Also, update `minSoFar` to the minimum of these three values. Now, if `maxSoFar` is greater than result, update result to `maxSoFar`. At the end of iteration, return result.
#### 153. Find Minimum in Rotated Sorted Array (Medium)
If array length is 1 or if first element is less than last element, the array isn't rotated. Hence, return the first element. Otherwise, we use binary search. Set low pointer to 0 and high pointer to N - 1. While low pointer is less than high pointer, set pivot = (low+high)/2. If the pivot is such that, pivot is within the limits of the array and either pivot - 1 is greater than pivot or pivot is greater than pivot + 1, we have found our element. Otherwise, if the number at pivot is greater than number at 0 index, set low = pivot + 1 or set high = pivot - 1.
#### 190. Reverse Bits (Easy)
Initiate variables `retVal = 0;`, `mask = 1;`. Iterate 31 times. Each time AND number with mask and if it is 1, OR `retVal` with 1 shifted left by bits - current iteration count. Shift `mask` variable left by 1 each time. At the end of iteration, return `retVal`.
#### 191. Number of 1 Bits (Easy)
Initiate variable `mask = 1;`. Iterate on the number 32 times. Each time AND with `mask`. If the result is != 0, increment count. In any case shift left `mask` by 1.
#### 206. Reverse Linked List (Easy)
Keep two pointers: curr and prev. Traverse the list inside a loop. Use a temp variable tempNext inside loop that points to curr.next. Within the loop, set curr.next to prev. Point prev to curr and point curr to tempNext. do this till curr becomes null (i.e. we reached end of list). Return the prev pointer in the end.
#### 235. Lowest Common Ancestor of a Binary Search Tree (Easy)
Traverse the BST. If both p & q values are less than the current node, travers the left child. If both p & q values are greater than the current node, traverse the right child. Otherwise p & q are on either side of the current node and tus the current node is the answer.
#### 242. Valid Anagram (Easy)
Create a count array for alphabets with 26 slots. Traverse the first string and update the count for each alphabet in the count array. Traverse the second string and start reducing the count for each encountered character in the second string. If at any point the count at any index goes -ve, the two strings are not valid anagrams.
#### 252. Meeting Rooms (Easy)
A person can attend all the meetings if there are no overlaps. Sort all the intervals and traverse the intervals array to ensure there are no overlaps between intervals.
#### 253. Meeting Rooms II (Medium)
Consider this as a meeting room finder and solve using priority queue which holds all meeting rooms in the order of the earliest getting free or use two separate arrays for start times and end times to check if at any given point the current end time is earlier than current start time requested. In either approaches, we need to sort the values. In case of priority queue, store the first interval on it and start traversing from second interval. If the current interval's start time comes after the top of priority queue's end time, tha last meeting room got free and can be evicted from the PQ. further add the current interval to the PQ to show that the meeting room is booked. At the end of the loop, no. of elements remaining in the PQ show how many meeting rooms we need. 
#### 268. Missing Number (Easy)
XOR approach is best approach as it avoids any overflow errors related with summation of N numbers. Set a variable "missing" = array.length. Then traverse the array. For each element, XOR the element with its index and XOR that result with variable "missing" (missing ^= i ^ nums[i]). In the end, variable "missing" will hold the missing number in the array.
#### 322. Coin Change (Medium)
Approach 1 - Recursion with Memoization --> Create a recursive function that accepts the coins array and amount remaining. If the amount remaining is 0, return 0. If the amout remaining is < 0, return -1. If the amount remaining is not null in the memo array, return that. Otherwise, iterate over the available coins and invoke the recursive function with the same coins array and the remaining amount = current remaining amount - coin value. If this returns -1, ignore the result. Otherwise, store it as current `minCount`. If at the end of the iteration, `minCount` value has changed, store it in the memo array for the current remaining amount and return the same. From the main method, invoke the recursive function with the passed coins array and the total amount expected as the remining amount input.

Approach 2 - DP --> Create a DP array with `amount + 1` slots. Fill it with the value `amount + 1` as using Integer.MAX_VALUE will overflow the result when we add 1 to the current value during our calculations. Iterate over the DP array to fill a value in all the slots. Within each iteration, iterate over the provided coins array and choose a coin value that is less than the current index under consideration in the DP array. The DP array value for current index can be set as `Math.min(dp[i], dp[i - coin] + 1)` i.e. adding current coin to the count of minimum no of coins needed if current coin is deducted from current index value.

### Others
#### 7. Reverse Integer
Remember to handle the edge cases of INT_MAX and INT_MIN. Also, the case where the intermediate result is equal to either INT_MAX/10 or INT_MIN/10. In this latter case, we need to verify that the next char under evaluation is less than 7 for INT_MAX/10 and greater than -8 for INT_MIN/10.
#### 22. Generate Parentheses
Use the back-tracking approach to keep appending '(' till the time they are < n. Then, start adding ')' till they reach a num equal to no of '('s. When we form a string with length = n, start removing the last character and regenerate.

## AlgoExpert
### Easy
#### 2. Validate Subsequence
Should have read the question carefully. They were going to maintain the sequence of numbers same in both main array and the subsequence array.
#### 3. Sorted Squared Array
Again, should have read the question carefully. They were going to give the array in sorted order. Thus, we could check for presence of -ver numbers as their squares would be +ve. Thus we could have filled the result array from either beginning/end by comparing the absolute value of numbers in given array at either ends and then filling the result array.

### Medium
#### 1. Three Number Sum
Sort the array, choose numbers one by one. Then find the remaining two numbers by using a two pointer approach with left & right pointers calculating sum while moving the pointers towards each other.
