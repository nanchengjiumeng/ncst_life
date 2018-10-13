// 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。
// 请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。
// 你可以假设 nums1 和 nums2 不同时为空。

// 示例 1:
// nums1 = [1, 3]
// nums2 = [2]

// 中位数是 2.0
// 示例 2:

// nums1 = [1, 2]
// nums2 = [3, 4]
// 中位数是 (2 + 3)/2 = 2.5



/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
// var findMedianSortedArrays = function(nums1, nums2) {

//     let arr = [],
//         len1 = nums1.length, 
//         len2 = nums2.length, 
//         len = len1 + len2, 
//         mid = Math.floor(len/2);
//     if( len1 === 0 || len2 ===0 ){
//         arr = len1 > 0? nums1 : nums2;
//         if(len%2 === 1){
//             return arr[mid];
//         }else{
//             return (arr[mid] + arr[mid-1])/2;
//         }
//     }else{
//         arr = merge(nums1,nums2,mid);
//         if(len%2 === 1){
//             return arr[arr.length-1];
//         }else{

//             return (arr[arr.length-1] + arr[arr.length-2])/2;
//         }
//     }  

// };
// function merge(nums1,nums2,stop){
//     let arr = [];
//     let count = 0,i1=0,i2=0;
//     while( nums1[i1] && nums2[i2] && count<=stop){
//         if(nums1[i1] < nums2[i2] ){
//             arr.push(nums1[i1++]);   
//         }else if( nums1[i1] > nums2[i2] ){
//             arr.push(nums2[i2++]);   
//         }else{
//             arr.push(nums1[i1]);
//             i1++;
//             i2++;
//         }
//         count++;  
//     }
//      while(nums1[i1] && count<=stop){
//         arr.push(nums1[i1++]);
//         count++;
//     }
//     while(nums2[i2] && count<=stop){
//         arr.push(nums2[i2++]);
//         count++;
//     }

//     console.log(arr);

//     return arr;
// }


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
    var arr = mergeNums(nums1, nums2);
    let len = arr.length, mid = Math.floor(len / 2);
    if (len % 2 === 1) {
        return arr[mid]
    } else {
        return (arr[mid] + arr[mid - 1]) / 2;
    }
}
function mergeNums(nums1, nums2) {
    let arr = [], len1 = nums1.length, len2 = nums2.length;
    if (len1 === 0) {
        arr = nums2;
    }
    if (len2 === 0) {
        arr = nums1;
    }
    if (len1 && len2) {
        
        let i1 = 0, i2 = 0;
        while (nums1[i1] !== undefined || nums2[i2] !== undefined) {        
            if (nums1[i1] !== undefined && nums2[i2]!==undefined) {
                if (nums1[i1] === nums2[i2]) {          
                    arr.push(nums1[i1++]);
                    arr.push(nums2[i2++]);       
                }else if (nums1[i1] < nums2[i2]) {
                    arr.push(nums1[i1++]);
                }else if (nums1[i1] > nums2[i2]) {
                    arr.push(nums2[i2++]);
                }
            } else if (nums1[i1]!== undefined) {
                arr.push(nums1[i1++]);
            } else if(nums2[i2]!=undefined){
                arr.push(nums2[i2++]);
            }
        }
    }
   
    
    return arr;
}

console.log(findMedianSortedArrays([1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22],[0,6]));
