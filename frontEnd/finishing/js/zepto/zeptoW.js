// t_detect extension
;(function($){
    function detect(ua, platform){
        var  towords = this.towords = {}, browser = this.browser  ? this.browser : ( this.browser = {} ),

            // mainstream webview
            //tecent
            mqqbrowser = ua.match(/MQQBrowser\/([\d.]+)/),
            wechat = ua.match(/MicroMessenger\/([\d.]+)/),
            // weibo
            weibo = ua.match(/weibo\/([\d.]+)/) ,
            // DingDing
            // zhi hu
            // jike
            // twitter

            // towords app
            tws = ua.match(/towords\/([\d.]+)/)


        // add above to global
        if (mqqbrowser) browser.mqqbrowser = true, browser.version = mqqbrowser[1]
        if(wechat) browser.wechat = true, browser.version = wechat[1]
        if(tws) towords.istowords  = true, towords.version = tws[1]
    }
    detect.call($, navigator.userAgent, navigator.platform)
    $.t_detect = detect
})(Zepto)



// $.w_fn extension
;(function ($) {
    var fn = $.w_fn ? $.w_fn : $.w_fn = {},
        detectTowordsVersion, //fn ajax
        tryOpenApp, //fn
        downloadApp, //fn
        openAppInAndroid, //fn
        os = $.os['android'] ? 'android' : $.os['ios'] ? 'ios' : 'pc',
        aLink = document.createElement('a') // href直接赋值会导致无法返回


    downloadApp = function (version) {
        if ( os == 'ios') {
            window.location.href = '//itunes.apple.com/cn/app/ta-ci-+-shang-yin-bei-dan-ci/id726029718';
        }
        if (os == 'android') {
            window.location.href = "//new-towords.oss-cn-beijing.aliyuncs.com/download/towords_GuanWang_" + version + ".apk";
        }
        aLink.href = '//www.towords.com/'
        aLink.click()
    }
    openAppInAndroid = function(){
        var timeout,
            t = 100,
            hasApp = true;
        setTimeout(function () {
            if (hasApp) {
                window.location.href = "towords://invite/openwith?" + path;
            } else {
                _this.downloadApp(opt);
            }
            document.body.removeChild(ifr);
        }, 200);

        var t1 = Date.now();
        var ifr = document.createElement("iframe");
        ifr.setAttribute('src', 'towords://invite/openwith?' + path);
        ifr.setAttribute('style', 'display:none');
        document.body.appendChild(ifr);
        timeout = setTimeout(function () {
            var t2 = Date.now();
            if (!t1 || t2 - t1 < t + 100) {
                hasApp = false;
            }
        }, t);
    }
    detectTowordsVersion = function () {
        var _this = this,
            dfd = $.Deferred()
        $ && $.ajax({
            url: '//api.towords.com/tool/get_latest_client_version_info?callback=?',
            type: 'GET',
            dataType: 'JSONP',
            success: function success(data) {
                if (data.code === 200 && data.result) dfd.resolve(data.result)
                else dfd.reject(data)
            },
            error: function (_) {
                dfd.reject(_)
            }


        });

        return dfd
    }

    tryOpenApp = function (path) {
        var version, v,
            versionRE = /\d+.(\d+)/,
            versionKey = 'LastAppVersion'
        $.when(detectTowordsVersion()).then(function (result) {
            if(os == 'pc') return downloadApp()
            v = result[ os +  versionKey].toString().match(versionRE)
            if(v) version = v[0] + ( v[1].length === 1 ? '0' : '' )
            if( os == 'ios' ) window.location.href = 'iOSToWords://com.towords.www/' + path
            if( os == 'android' ) openAppInAndroid(path)
        },function (_) {
            console.log(_);
        })
    }


    fn.downloadApp = downloadApp
    fn.tryOpenApp = tryOpenApp


})($)
