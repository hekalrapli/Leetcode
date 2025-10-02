class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int fullBottles = numBottles;
   int emptyBottles = 0;
  

   emptyBottles = fullBottles;
   fullBottles = 0;
   while(emptyBottles >= numExchange) {
        emptyBottles -= numExchange;
        fullBottles++;
        numExchange++;

   }
   numBottles += fullBottles;
   emptyBottles += fullBottles;
   fullBottles = 0;
   while(emptyBottles  >= numExchange) {
        emptyBottles -= numExchange;
        fullBottles++;
        numExchange++;

   }
     numBottles += fullBottles;
     return numBottles;
    }
};