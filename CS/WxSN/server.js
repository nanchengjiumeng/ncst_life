let http = require('http');
let querystring =require('querystring');
let sha1 =  require('simple-sha1');
let {MessageClass} = require('./src/Message');
let {areasArr,isCity} =require('./src/areaObj');
//let { connection,executeSQL } = require('./src/SqlServer/index');




// test SQL
// executeSQL({command:'INSERT INTO wxuser VALUES (\'Gates\')'});

//wechat token
const token = 'wyb';


const TuringRobot = {
    hostname:"www.tuling123.com",
    path:"/openapi/api",
    key: "b7395e6cd7cf4f4daebbf60c854b604e",
    port:80
};


let server = http.createServer(function (req,res) {
    if(req.method.toUpperCase()==='GET'){
       let params = querystring.parse(req.url.split('?')[1]);
       let {signature,echostr,timestamp,nonce} = params;
       let sign = [token,timestamp,nonce];
       sign.sort();
       let signStr ='';
       sign.forEach(function (item,index) {
           signStr+=item;
       });
        try {
            sha1(signStr,function (hash) {
                if (signature === hash ){
                    //加密后进行判断
                    console.log('successful!');
                    res.end(echostr);
                }
            });
        }catch (e) {
           // console.log('wang ');
            throw e;
        }




   }

   //test

   // post
    // get user`s message and rely TuringRobot`s API for automatic reply
    //xXMLStr = convert.xml2json(WxXMLStr);
    //let WxUserMessage=JSON.parse(WxXMLStr).elements[0].elements;
    // console.log(xmlObj);
    //WxUserMessage = xmlObj2Obj(WxUserMessage);
    //{ ToUserName: 'gh_af06c905f1e5',
    //    FromUserName: 'o8Tv-wPuWzG3A9B0CaiVGv9M3Oi8',
    //   CreateTime: undefined,
    //    MsgType: 'text',
    //    Content: '你好',
    //   MsgId: undefined }
    if (req.method.toUpperCase() ==='POST'){
        let WxXMLStr = '';
        req.on('data',function (data) {
            WxXMLStr = data.toString();
            console.log(WxXMLStr);
            let WxUserMessage = new MessageClass(WxXMLStr);
            try {
                if(WxUserMessage.getUserMessageInfo("MsgType") === 'text'){
                    post2Turing(WxUserMessage,res);
                }
            }catch (e) {
                res.end();
            }
        });

    }


});

function post2Turing(message,res) {
    let turingData;
    let message2Turing ={
        "key": TuringRobot.key,
        "info": message.getUserMessageInfo("Content")
    };

    let opts = {
        hostname:TuringRobot.hostname,
        path:TuringRobot.path,
        method:"POST",

    };
    let req = http.request(opts, function (response) {
        response.on('data',function (data) {
            turingData=JSON.parse(data.toString());
           // console.log(turingData);
           // console.log(turingData["text"]);
           /* res.end( "<xml>" +
                "<ToUserName><![CDATA[" +
                message["FromUserName"] +
                "]]></ToUserName><FromUserName><![CDATA[" +
                message["ToUserName"] +
                "]]></FromUserName><CreateTime>" +
                "1348831860" +
                "</CreateTime><MsgType><![CDATA[" +
                "text" +
                "]]></MsgType><Content><![CDATA[" +
                turingData["text"]+
                "]]></Content><MsgId>" +
                "1234567890123456" +
                "</MsgId></xml>");*/
           res.end(message.message2XML({
               type:'text',
               content:turingData['text']
           }))
        })
    });
   //进行地域判断
    if(isCity(message2Turing.info,areasArr)){
        console.log('isCity');
        message2Turing.info+='天气'}


    req.write(JSON.stringify(message2Turing));
    req.end();


}






//start server
let hostname = '127.0.0.1';
let port = 3000;
server.listen(port, hostname, function () {
   console.log('Server running at http: //%s： //%s', hostname,port);
});







