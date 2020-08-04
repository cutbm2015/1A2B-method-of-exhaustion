# 1A2B-method-of-exhaustion 1A2B 窮舉法破解 1A2B 破解程式

# Introduction
    
    使用窮舉法列出 1A2B 遊戲中的所有可能，並推斷出正確答案。
    Perform an method of exhaustion for 1A2B games and infer the correct answer.



# Abbreviation

  1. Words

    gue - guess.
    ans - answer.
    ip - input.
    num - number.

  2. Prefix

    v_ - vector.

# Function

  1. void possiblePoolInit() - 
    
    寫入 0 ~ 9999 到 possiblePool 中，不考慮是否合乎遊戲規則。
    Write a number from 0 to 9999 to 'possiblePool'.

  2. void validNum(int ip) - 
  
    檢查 ip 是否遵循以下規則
      1. 四個數字中，沒有任何重複。
    check whether ip('ip' is a four-digit number and it's short for 'input') follows the following rules
      1. There are no duplicates in the four digits.

  3. void deleteNum(int i) - 
  
    從 possiblePool 中刪除 i 這個數字。 
    delete 'i' from 'possiblePool'.

  4. void deleteNumInclude(int target) - 
  
    刪除 possiblePool 中與 target 相符的數字(只要有任一數字相符即刪除).
      舉例來說：在 possiblePool 中有 1234, 1345, 1456, 1567, 1678, 1789 這幾個數字， target 現在為 2379 ，表示只要 possiblePool 中含有 2,3,7,9 均會被刪除.
      結果： possiblePool 中僅剩下 1456, 1678。
    Delete the number in possiblePool that matches 'target'(When at least one digit matches).
      for example : In possiblePool we have 1234, 1345, 1456, 1567, 1678, 1789 and the 'target' is 2379 then the number contain 2,3,7,9 in the possiblePool will be deleted.
      result : 1456, 1678 will be left.

  5. int verifyA(int ans, int gue) - 
  
    回傳 gue 在 ans 下，符合幾個 A 。
    return how many 'A's.

  6. int verifyB(int ans, int gue) - 
  
    回傳 gue 在 ans 下，符合幾個 B 。
    return how many 'B's.

  7. void exhaustion(int gue, int A, int B) - 
  
    刪除不符合 A, B 數量的值。
    Remove numbers that do not follow 'A' and 'B' rules.
    
# Keywords
  
    #1A2B Games #1A2B 遊戲 #1A2B 破解器 #1A2B 破解程式
