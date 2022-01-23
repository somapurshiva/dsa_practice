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
#### 48. Rotate Image (Medium)
For matrix related questions, check if transpose and rotations help in deriving the result. In this Q, we had to transpose the matrix and then take a reflection of it vertically to rotate it clockwise once. For anticlockwise rotation, we would need to take a reflection horizontally.
#### 49. Group Anagrams (Medium)
Create a HashMap where key will be the sorted character array of all the words and value will be a list of words. For each word, generate its sorted char array. Pick the key for this sorted array from the map and add the current word to the list pointed by the key in the HashMap.
#### 53. Maximum Subarray (Easy)
Set currSum and maxSum to the first element of the array. Start traversal from second element. At each element, currSum will be maximum of current num + currSum or just current num i.e. if a -ve number is coming, it will reduce the sum so it has to be ignored. Once currSum is identified for current element, we can update the maxSum to the maximum of currSum and maxSum.
#### 54. Spiral Matrix (Medium)
Setup the four boundaries: top, bottom, left and right. Loop through boundary rows and columns and reduce the boundaries in each loop by incrementing/decrementing. Handle edge cases of having just one row/column by checking if boundary values are same (left != right and top != bottom) when traversing back on a row/column
#### 56. Merge Intervals (Medium)
First sort the intervals based on the starting value of all the intervals. Initiate a LinkedList (LL) object. If the LL is empty (when still at first interval) or if the starting value of current interval is greater than the ending value of the interval in the last node of LL, add the current interval to the LL. Otherwise the ending value of the last node in LL will be the bigger of the node's current ending value or the ending value of the current interval under consideration.
#### 98. Validate Binary Search Tree (Medium)
Recursive validate method: Set highVal and lowVal to null and invoke the validate() method on root node. Inside validate method, if node is null, return true. If the node value is smaller than passed lowVal or greater then passed highVal (provided they are non-null), return false. Otherwise invoke validate on left and right children of the current node with updated low & high vals.
#### 206. Reverse Linked List (Easy)
Keep two pointers: curr and prev. Traverse the list inside a loop. Use a temp variable tempNext inside loop that points to curr.next. Wihin the loop, set curr.next to prev. Point prev to curr and point curr to tempNext. do this till curr becomes null (i.e. we reached end of list). Return the prev pointer in the end.
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
#### 33. Search in Rotated Sorted Array (Medium)
Approach 1:- Use binary search to find the rotated index (the position where arr[i] > arr[i+1]). Once found, We can check if target num is at the rotated index itself. Otherwise it will be to left or right of the rotated index. Perform normal binary search for target num on the correct sub-array once you found out the right half to look at.

Approach 2:- Follow usual binary search itself. When we find mid, we have to check on which side of mid do we have the non-rotated array. If target falls in the non-rotated array, ensure to update the pointers to consider the non-rotated array section. e.g. if for a given mid, non-rotated array falls on left and target also falls on left, update `end = mid - 1` otherwise `start = mid + 1` 
#### 76. Minimum Window Substring (Hard)
If either of passed strings S/T are empty, return blank string. 
Form a map of characters and their counts within T in a variable dicT. 
Set a variable "required" whose value is equal to number of keys within dicT.
Created a new list "filteredS" that contains relevant pairs of characters that are present in T and their positions within S.
Declare two pointers l & r (for left and right), start traversing the filteredS list incrementing r. At each point, add the character within filteredS pointed by r into a map "windowCounts" that keeps counts of characters in current window.
If the current processed character's count in windowCount is same as the count of the same character in dicT, increment the variable "formed".
Now, try shortening the window by moving the left pointer l while l <= r and the variable formed = required. each time calculate the window length based on characters that l & r are pointing. If less that current window length, update the current window length. Before incrementing l, check if the removal of character pointed by l disturbs the count of this character within windowCounts wrt the count in dicT. If so, decrement the variable "formed".
Continue doing this till we reach the end of the filteredS list.

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
