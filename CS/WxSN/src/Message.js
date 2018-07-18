let convert = require('xml-js');

 class  MessageClass{
    //{ ToUserName: 'gh_af06c905f1e5',
    //    FromUserName: 'o8Tv-wPuWzG3A9B0CaiVGv9M3Oi8',
    //   CreateTime: undefined,
    //    MsgType: 'text',
    //    Content: '你好',
    //   MsgId: undefined }
    constructor(message){
        this.WxUserMessage = null;
        if(typeof  message === 'string'){
            let WxXMLStr  = convert.xml2json(message);
            this.WxUserMessage = this.WxUserMessage=JSON.parse(WxXMLStr).elements[0].elements;
            this.WxUserMessage = this.WxUserMessage = this.xmlObj2Obj(this.WxUserMessage);
        }else if( typeof message === 'object' ){
            this.WxUserMessage = message;
        }
    }
    xmlObj2Obj(xmlObj) {
        let obj={};
        xmlObj.forEach(function (item) {
            //item.name
            obj[item.name] = item.elements[0].cdata;
        });
        return obj;
    };
    getUserMessageInfo(attr){
        return this.WxUserMessage[attr];
    }
    message2XML(opts){
        let content = opts.content;

        return "<xml>" +
        "<ToUserName><![CDATA[" +
            this.getUserMessageInfo("FromUserName")+
        "]]></ToUserName><FromUserName><![CDATA[" +
            this.getUserMessageInfo("ToUserName")+
        "]]></FromUserName><CreateTime>" +
        Date.now().toString() +
        "</CreateTime><MsgType><![CDATA[" +
            opts.type +
        "]]></MsgType><Content><![CDATA[" +

            content+
        "]]></Content><MsgId>" +
            this.getUserMessageInfo("MsgId")+
        "</MsgId></xml>";

    }
}
module.exports = {MessageClass};