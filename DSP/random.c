int main () {
   int i, n;

   n = 5;

   /* Intializes random number generator */

   /* Print 5 random numbers from 0 to 49 */
   for( i = 0 ; i < n ; i++ ) {
      printf("%d\n", rand() % 50);
   }

   return(0);
}
