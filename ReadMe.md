# Lessons Learnt #
## LeetCode ##
### 3. Longest Substring Without Repeating Characters ###
` Used a sliding window approach where we keep a hashtable that has ASCII value of character as key and the char's last position as the value. If during evaluation we find that the current character on the right end of the window is duplicated within the window, we can use the last postion of the duplicate char from the hashtable to move the left pointer to one position to the right of the duplicate character.`

## AlgoExpert ##
