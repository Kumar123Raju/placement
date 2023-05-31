// This is very very important question because when we solve pow funciton using recursion time complexity reduce to 0(long(n) ) which is very importantn
// its implementation is used in many question because of log(n) time complexity sor remember this concept very usefull:
 long long myPow(int a,long long n){
        if(n==0) return 1;
        if(n%2==0) {
            long long y=myPow(a,n/2);

            return (y*y);
        }else{
            return a*myPow(a,n-1);
        }
    }


// when range of n is negative also:
  double myPow(double x, int n) {
          if(n==0) return 1;
    
//     to convert negative to positive
       else if (n < 0) {
        x = 1 / x;          // Invert x if n is negative
        long long exponent = n;  // Use long long for exponent
        exponent = -exponent;    // Negate the exponent
//  when n is negative;
        if (exponent % 2 == 0) {
            double y = myPow(x, exponent / 2);
            return y * y;
        } else {
            return x * myPow(x, exponent - 1);
        }
    }
    
//     when n is possitive:
       if(n%2==0){
           double y=myPow(x,n/2);
           return y*y;
       }else{
           return x*myPow(x,n-1);
       }
        
    } 
