/* process.argv 接受命令行参数
[ 'C:\\Program Files\\nodejs\\node.exe',
    'G:\\ncst_life\\CS\\app\\translate\\server\\test.js',
    '1',
    '2',
    '3' ]*/
let {request,get} = require('http');


let args  = [];
args = process.argv.slice(2);
let translateText='';
let translateType= 1 ;

if(args.length<2){
     translateText = args[0];
}else {
     translateText = args[1];
     translateType = args[0]; // 0 C -> E ,   1 E -> C
}


let options = {
    hostname: 'localhost',
    port: 3000,
    path: '/translate',
    method:'POST'
};





let req = request(options,function (res) {
    res.on('data',function ( data) {
        console.log(' '+data);
    });
});
req.write(JSON.stringify({
    translateText,
    translateType
}));















