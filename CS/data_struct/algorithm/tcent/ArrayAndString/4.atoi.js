/**
 * @param {string} str
 * @return {number}
 */
// const letters = '1234567890';
// var myAtoi = function (str) {
//     let numQue = [];
//     let len = str.length;
//     let i = 0, char = str[i], isNegative = false;
//     while (char === ' ') {
//         char = str[++i];
//     }
//     if (char === '-') { isNegative = true; char = str[++i] }else if( char === '+'){ isNegative = false; char = str[++i] }
//     while (i < str.length && 0 <= char <= 9 && (letters.indexOf(char) > 0 ) {
//         numQue.push(char);
//         char = str[++i];
//     }
//     return numQue.length === 0 ? 0 : parseToInt32(numQue, isNegative);
// };


// function parseToInt32(numQue, isNegative) {
//     const max_base = Math.pow(2, 31);
//     const max = max_base - 1;
//     const min = max_base * -1;

//     let number = 0, len = numQue.length, start = 0;
//     while (start < numQue.length) {
//         number += (numQue[start] * Math.pow(10, len - (start++) - 1));
//     }
//     number = isNegative ? number * -1 : number;
//     if (number <= min) {
//         return min;
//     } else if (number >= max) {
//         return max;
//     } else {
//         return number;
//     }
// }



/**
 * @param {string} str
 * @return {number}
 */

var myAtoi = function (str) {
    const err = 0;
    let p = 0, pChar = str[p], start = 0, numBit = 0, isNevigate = false;
    while(pChar === ' ' ){
        pChar = str[++p]
    }
    if( pChar === '-' ||  pChar === '+'){
        isNevigate = pChar === '-';     
        pChar = str[++p]
        if(isNaN( pChar - 0)){
            return err;
        }
    }else if( isNaN(pChar - 0) ){        
        return err;
    }
    start = p;
    while(pChar !==' ' && !isNaN(pChar - 0)){  
        numBit++;
        pChar = str[++p];
    }

    
    return parseToInt32( str.substr(start, numBit), isNevigate )
};
function parseToInt32(str, isNegative) {
    const max_base = Math.pow(2, 31);
    const max = max_base - 1;
    const min = max_base * -1;

    let number = 0, len = str.length, start = 0;
    while (start < str.length) {
        number += (str[start] * Math.pow(10, len - (start++) - 1));
    }
    number = isNegative ? number * -1 : number;
    if (number <= min) {
        return min;
    } else if (number >= max) {
        return max;
    } else {
        return number;
    }
}


console.log(myAtoi("   00123"));
