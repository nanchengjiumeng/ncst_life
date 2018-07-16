let express = require('express');
let queryString = require('querystring'); //查询字符串模块
let {request,get} = require('http');

let {setBytesFromString} = require('utf-8');
let {_md5} = require('./sources/md5model'); // md5加密模块
let {youDaoAPI,queryOpts,appKey} = require('./sources/youDaoApi');



let app = express();

app.post('/translate',function (req,res) {



    let traslateMessage;
    req.on('data',function ( d) {

        // 拿到需翻译信息
        traslateMessage=JSON.parse(d);

        // 将信息打包成发向有道的对象，并转换成url
        let {translateText,translateType} = traslateMessage;
        queryOpts.q=translateText;
        queryOpts.from = translateType?'zh-CHS':'EN';
        console.log(translateText,translateType);
        queryOpts.to = translateType?'EN':'zh-CHS';
        queryOpts.salt = Math.random();
        //签名，通过md5(appKey+q+salt+应用密钥)生成

        queryOpts.sign = _md5(queryOpts.appKey+queryOpts.q+queryOpts.salt+appKey);



        let youDaoQueryStr = queryString.encode(queryOpts);


        // 将对象发往有道，并将返回信息返回给客户端
       get(youDaoAPI.http+ '?'+youDaoQueryStr,
       function (res) {
            res.on('data',function (data) {
                console.log(JSON.parse(data));
                console.log('ttt');
            })
        });
        /*request({
            hostname:youDaoAPI.http,
            query:url,
            method:'get'
        },function (res) {
            res.on('data',function (data) {
                console.log(JSON.parse(data));
            })
        })
*/


    });
   
    res.end();
});



app.listen(3000);


/*有道翻译API HTTP地址：

http://openapi.youdao.com/api

有道翻译API HTTPS地址：

https://openapi.youdao.com/api
*/



