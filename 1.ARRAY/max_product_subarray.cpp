// is question ka solution iska observation hai:
// case 1: all arr positive number( simple all number ko multiply krdo .)
//   case 2: even number of negative value(simple also all number ko multiply kardo)
//   case 3: odd number of negative value( problem sirf isme ayega to issi ko niche solve kiya gaya hai***************)
//   case 4: zero are there in the array(simple jav v multiply zero ho jaye currentproduct ko 1 kardo aur phr aaage multiply krte jao )

//   case 3:   (solution)
//   iska simple hai ke agar odd number of negative number hai to  first negative ke pahle wale ko mmultiply kare to sb possitive hoga aur uske baad me even negative bacha hoga 
//    uske multiply karege to possitive hoga  yahan me se check karenge badda kon hai 
//                        ya phr:::::
//   last negative ke pahle(left side) even number of negaive nuber hoga aur right side me koi v negative nai haoga to in dono me check kr lenge 

  // code: ek baar iskeo left se side product karenge aur ek baar right se left aur in dono me se jo maximum dega wahi anser hoga..simple 

   int maxProduct(vector<int>& nums) {
        int maxproduct=INT_MIN;
        int pref=1;
        int suff=1;
        int n=nums.size();
        for(int i=0; i<nums.size(); i++){
            if(pref==0) pref=1;
            if(suff==0) suff=1;
            pref*=nums[i];
            suff*=nums[n-1-i];
            maxproduct=max(maxproduct,max(pref,suff));
           
        }
        return maxproduct;
        
    }
 
