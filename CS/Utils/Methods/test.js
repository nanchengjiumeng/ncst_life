function Methods() {
    function isChrome() {
        var ua = navigator.userAgent;
        return !(ua.indexOf('Chrome')<0);
    }
    function screenXY() {
        return {
            x:screen.width,
            y:screen.height,
        }
    }


    // 例如当前网址是 https://juejin.im/timeline/frontend?a=10&b=10#some
    console.log(location.href)  // https://juejin.im/timeline/frontend?a=10&b=10#some
    console.log(location.protocol) // https:
    console.log(location.pathname) // /timeline/frontend
    console.log(location.search) // ?a=10&b=10
    console.log(location.hash) // #some...

    // history.back()
    // history.forward()

    return {
        isChrome,
        screenXY,

    }
}
