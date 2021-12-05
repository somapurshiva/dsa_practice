# Lessons Learnt #
## LeetCode ##
#### 3. Longest Substring Without Repeating Characters
Used a sliding window approach where we keep a hashtable that has ASCII value of character as key and the char's last position as the value. If during evaluation we find that the current character on the right end of the window is duplicated within the window, we can use the last postion of the duplicate char from the hashtable to move the left pointer to one position to the right of the duplicate character.
#### 7. Reverse Integer
Remember to handle the edge cases of INT_MAX and INT_MIN. Also, the case where the intermediate result is equal to either INT_MAX/10 or INT_MIN/10. In this latter case, we need to verify that the next char under evaluation is less than 7 for INT_MAX/10 and greater than -8 for INT_MIN/10.
#### 19. Remove Nth Node From End of List ####
Try using a dummy node whose *next pointer points to the head. This will take care of the edge cases where there are null, one or two nodes in the linked list

## AlgoExpert ##
### Easy ###
#### 2. Validate Subsequence ####
Should have read the question carefully. They were going to maintain the sequence of numbers same in both main array and the subsequence array.
#### 3. Sorted Squared Array ####
Again, should have read the question carefully. They were going to give the array in sorted order. Thus, we could check for presence of -ver numbers as their squares would be +ve. Thus we could have filled the result array from either beginning/end by comparing the absolute value of numbers in given array at either ends and then filling the result array.

### Medium ###
#### 1. Three Number Sum ####
Sort the array, choose numbers one by one. Then find the remaining two numbers by using a two pointer approach with left & right pointers calculating sum while moving the pointers towards each other.