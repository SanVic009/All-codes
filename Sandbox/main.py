def maximumLengthSubstring(s):
        """
        :type s: str
        :rtype: int
        """
        length = 0
        max_length = 0
        occurence = {}
        for letters in s:
            
            if (letters not in occurence) or (occurence[letters] == 0):
                occurence[letters] = 1
                
            elif (letters in occurence) and (occurence[letters] <= 2):
                occurence[letters] += 1
            
            if occurence[letters] > 2:
                for letters in occurence:
                    occurence[letters] = 0
                length = 0
                continue

            length += 1
            if length > max_length:
                max_length = length
       
        return max_length

string = "bbbab"
print(maximumLengthSubstring(string))