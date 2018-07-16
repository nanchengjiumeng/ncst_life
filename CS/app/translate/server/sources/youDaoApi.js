/*
应用名称 node-translate
应用ID 00355896a1172c14
应用密钥 qCSNQ2D3lSbriTBRB0hHgOiElhX2X97w
类别 休闲娱乐
应用描述 自己用
接入方式 API
状态 有效
绑定服务 node-translate;
 */

/*
中文	zh-CHS
日文	ja
英文	EN
韩文	ko
法文	fr
俄文	ru
葡萄牙文	pt
西班牙文	es
越南文	vi
*/



let youDaoAPI = {
    'http':'http://openapi.youdao.com/api',
    'https':'openapi.youdao.com/api'
};
let queryOpts = {
    q:'', //必须是UTF-8编码,要翻译的文本
    from:'', //对应语言 https://ai.youdao.com/docs/doc-trans-api.s#p05
    to:'', //对应语言 https://ai.youdao.com/docs/doc-trans-api.s#p05
    appKey:'00355896a1172c14',
    salt:'', //random number
    sign:'', //签名，通过md5(appKey+q+salt+应用密钥)生成
   // ext: false, //音频格式 mp3
    // voice:0, //0为女声，1为男声
};

let appKey = 'qCSNQ2D3lSbriTBRB0hHgOiElhX2X97w';


module.exports = {youDaoAPI,queryOpts,appKey};


