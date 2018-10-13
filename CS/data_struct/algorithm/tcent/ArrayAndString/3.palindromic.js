/**
 * 
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为1000。

示例 1：

输入: "babad"
输出: "bab"
注意: "aba"也是一个有效答案。
示例 2：

输入: "cbbd"
输出: "bb"


 * @param {string} s
 * @return {string}
 */

 function extandPalindromeLength(string,index){
    let start = index, l = -1, r = -1, len = 0;
    if( string[index] === string[index+1] ){
        len = 2;
        l = start - 1;
        r = start + 2;
        while( l >=0 && string[start] === string[l]){
            l--;
            len++;
        }
        while( r< string.length && string[start] === string[r]){
            r++
            len++;
        }
    }else{
        len = 1;
        l = start - 1;
        r = start +1;
    }
    while( !(l < 0 || r >= string.length + 1 ) && ( string[l] === string[r])){
        len += 2;
        l--;
        r++; 
    }
    return [len,++l];
 }

function longestPalindrome( string ) {
    let subPalindromeLengths = [];
    let subPalindromes = [];
    for( let i = 0; i < string.length; ++i ){
        subPalindromes[i] = extandPalindromeLength(string, i);
        subPalindromeLengths[i] = subPalindromes[i][0];
    }
    let longestSubPalindromeLength = Math.max(...subPalindromeLengths);
    let start = subPalindromeLengths.lastIndexOf(longestSubPalindromeLength);
   
    
    return start > -1 ? string.substr( subPalindromes[start][1],  longestSubPalindromeLength) : "";

    
    
    

    // 1.  从 string[i] 开始向 i--,i++ 拓展，并判断是否位回文，直到拓展到最长后保存该长度 long
    // 2.  i++ , 重复步骤 1， 直到 long/2>string.length-1 - i
    // 3.  取左右的long里面最大的最大值
    

}

console.log(longestPalindrome("babad"));


