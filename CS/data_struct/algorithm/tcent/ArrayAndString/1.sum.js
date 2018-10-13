// 给定 nums = [2, 7, 11, 15], target = 9

// 因为 nums[0] + nums[1] = 2 + 7 = 9
// // 所以返回 [0, 1]

// /**
//  * @param {number[]} nums
//  * @param {number} target
//  * @return {number[]}
//  */
// var twoSum = function(nums, target) {
//     let n = 0, m = -1, res = null;
//     while (n < nums.length ){
//        m =  nums.indexOf( target - nums[n] );
//        if( m >= 0 && m !== n){
//            break;
//        }
//        ++n;
//     }
//     if( n > m){
//         return [m,n] 

//     }else{
//         return [n,m] 
//     }
// };



var twoSum = function(nums, target) {
    for( let aIndex =  nums.length - 1; aIndex > 0; aIndex--){
        for( let bIndex = aIndex - 1; bIndex > -1; bIndex--){
            if( nums[aIndex] + nums[bIndex] === target ){
                return [aIndex, bIndex ]
            }
        }
    }
}
console.log( twoSum( [3,3], 6 )  );
