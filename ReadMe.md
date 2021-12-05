# Lessons Learnt #
## LeetCode ##
### 3. Longest Substring Without Repeating Characters ###
` Used a sliding window approach where we keep a hashtable that has ASCII value of character as key and the char's last position as the value. If during evaluation we find that the current character on the right end of the window is duplicated within the window, we can use the last postion of the duplicate char from the hashtable to move the left pointer to one position to the right of the duplicate character.`
### 7. Reverse Integer ###
` Remember to handle the edge cases of INT_MAX and INT_MIN. Also, the case where the intermediate result is equal to either INT_MAX/10 or INT_MIN/10. In this latter case, we need to verify that the next char under evaluation is less than 7 for INT_MAX/10 and greater than -8 for INT_MIN/10. `
### 19. Remove Nth Node From End of List ###
` Try using a dummy node whose *next pointer points to the head. This will take care of the edge cases where there are null, one or two nodes in the linked list `
## AlgoExpert ##
