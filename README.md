Frequency Counting:

A vector ans of size 26 is initialized to count the frequency of each letter.

The first loop iterates through the string s and increments the count for each character using the expression s[i] - 'a'. This maps the characters 'a' to 'z' into indices 0 to 25.

Finding the First Unique Character:

After the frequency counts are complete, the second loop goes through the string again.

For each character, it checks if its corresponding frequency in the ans vector is 1.

When it finds a character with a frequency of 1, it immediately returns the index, ensuring that it’s the first unique character.

Complexity Consideration:

Time Complexity: The solution runs in O(n) time, where n is the length of the string, because it makes two passes over the string.

Space Complexity: It uses constant extra space, O(1), since the frequency vector is always of fixed size 26.
