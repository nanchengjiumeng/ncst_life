//加密模块
let crypto =  require('crypto');


function _md5(fromStr) {
    let md5 = crypto.createHash('md5');
    md5.update(fromStr);
    return md5.digest('hex');
}

module.exports={_md5};