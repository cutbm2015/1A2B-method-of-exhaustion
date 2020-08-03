# 1A2B-method-of-exhaustion

Introduction: Perform an method of exhaustion for 1A2B games and infer the correct answer.

Abbreviation:

  1. Words

    gue - guess.
    ans - answer.
    ip - input.
    num - number.

  2. Prefix

    v_ - vector.

Function:

  void possiblePoolInit() : Write a number from 0 to 9999 to 'possiblePool'.

  void validNum(int ip) : check whether ip('ip' is a four-digit number and it's short for 'input') follows the following rules
  1.There are no duplicates in the four digits.

  void deleteNum(int i) : delete 'i' from 'possiblePool'.

  void deleteNumInclude(int target) : Delete the number in possiblePool that matches 'target'(When at least one digit matches).
  for example : In possiblePool we have 1234, 1345, 1456, 1567, 1678, 1789 and the 'target' is 2379 then the number contain 2,3,7,9 in the possiblePool will be deleted.
  result : 1456, 1678 will be left.

  int verifyA(int ans, int gue) : return how many 'A's.

  int verifyB(int ans, int gue) : return how many 'B's.

  void exhaustion(int gue, int A, int B) : Remove numbers that do not follow 'A' and 'B' rules.
  
