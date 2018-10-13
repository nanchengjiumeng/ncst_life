function expandAroundCenter(string, l, r) {
    while ( l >= 0 && r < string.length && string[l] === string[r] ){
        l --;
        r ++;
    }
    return r - l -1
}


function longestPalindrome( string ) {
    if( !string ) return false
    let start = 0, end = 0
    for( let i = 0; i < string.length; ++i){
        let len_1 = expandAroundCenter( string, i, i )
        let len_2 = expandAroundCenter( string, i, i + 1 )
        let len = Math.max( len_1, len_2 )
        if( len > end - start ){
            start  = i - ( len -1 ) / 2
            end = i + len / 2
        }
    }
    return string.slice( start, end );
}


console.log(longestPalindrome('babaad'));
