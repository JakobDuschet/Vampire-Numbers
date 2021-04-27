# Vampire-Numbers
A solution to the Vampire Numbers problem
 This program checks a given number > 99 for the vampire property.

    In number theory, a vampire number is a composite natural number with an even number of digits, 
    that can be factored into two natural numbers each with half as many digits as the original number, where the two factors contain precisely all the digits of the original number, 
    in any order, counting multiplicity. The first vampire number is 1260 = 21 × 60. The split up numbers (here 21 and 60) are called fangs.
    Numbers with odd number of digits that have the corresponding property are called psuedo-vampires. Their fangs will have an uneven number of digits, leading to more possible combinations.
    For example, 126 = 21 * 6
    
    
    The way this program works is not the most elegant, but the motivation was exercising with as little help from the internet and pre-established solutions as possible
    This is also why the program uses a lot of different concepts that may not be the most efficient solution, but serve a good purpose for practise.

    The program will prompt the user for a number, then hand it to a function as a STRING which computes all possible permutations.
    The permutations will be stored in a Set, since the function will not eliminate double entries automatically

    After that, the set of permutations (strings) is handed to a function splitting them up into fangs, depending on if the number of digits is even or odd
    The fangs then are stored in a vector (not a set, because double entries need to be allowed) as neighboring entries. The first pair of fangs will be the 0-th and 1st entry of the vector
    The set stores the fangs in pairs, so it has to be iterated over in steps of 2. 
    The second pair of fangs will be the 2nd and 3rd entry and so on. This means, when checking for the vampire condition (left neighbor * right neighbor == original number) 
    we have iterate over the vector in steps of 2. This is unintuitive but easily implemented
    
    Finally, depending on the outcome and the number of digits, a string is returned to main, stating if the number is a true, pseudo- or not a vampire at all.
   
    
