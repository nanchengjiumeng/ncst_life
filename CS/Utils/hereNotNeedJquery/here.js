function f() {



    /*
            AJAX
    json

    $.getJSON('/my/url', function(data) {
    });
    */

    function getJSON(url, successful, reject, error) {
        var request = new XMLHttpRequest();
        request.open('GET', url, true);
        request.onload = function () {
            if (request.status >= 200 && request.status < 400) {
                callback(JSON.parse(request.responseText));
            } else {
                reject(request)
            }
        };
        request.onerror = function () {
            error(this);
        };
        request.send();
    }

    /* POST */
    function Post(url, data) {
        var request = new XMLHttpRequest();
        request.open('POST', '/my/url', true);
        request.setRequestHeader('Content-Type', 'application/x-www-form-urlencoded; charset=UTF-8');
        request.send(data);
    }

    /*request*/
    function Request(url, successful, error) {
        var request = new XMLHttpRequest();
        request.open('GET', url, true);
        request.onload = function () {
            if (request.status >= 200 && request.status < 400) {
                successful(request.responseText)
            } else {
                error(request)
            }
        };
        request.onerror = function () {
            error(request);
        };
        request.send();
    }


    /* EFFECTS */

    function fadeIn(el) {
        el.style.opacity = 0;

        var last = +new Date();
        var tick = function () {
            console.log(el.style.opacity, (new Date() - last) / 400);
            el.style.opacity = +el.style.opacity + (new Date() - last) / 400;
            last = +new Date();

            if (+el.style.opacity < 1) {
                (window.requestAnimationFrame && requestAnimationFrame(tick)) || setTimeout(tick, 16);
            }
        };

        tick();
    }


    function Hide(el) {
        el.style.display = 'none';
    }

    function Show(el) {
        el.style.display = '';
    }


    /* ELEMENTS */
    function AddClass(el, className) {
        if (el.classList) {
            el.classList.add(className)
        } else {
            el.className += ' ' + className;
        }
    }

    function After(el, htmlString) {
        el.insertAdjacentHTML('afterend', htmlString);
    }

    function Append(parent, el) {
        parent.append(el);
    }

    function Before(el, htmlString) {
        el.insertAdjacentHTML('beforebegin', htmlString);
    }

    function Children(el) {
        return el.children;
    }

    function Clone(el) {
        return el.cloneNode(true);
    }

    function Contains(el, child) {
        return el !== child && el.contains(child);
    }

    function ContainsSelector(selector) {
        return el.querySelector(selector) !== null;
    }

    function Each(selector, cb) {
        var els = document.querySelectorAll(selector);
        Array.prototype.forEach.call(els, cb);
    }

    function Empty(el) {
        el.innerHTML = '';
    }

    function Filter(selector, cb) {
        var els = document.querySelectorAll(selector);
        Array.prototype.filter.call(els, cb);
    }

    function FindChildren(el, selector) {
        return el.querySelectorAll(selector);
    }

    function FindElements(selector) {
        return document.querySelectorAll(selector);

    }

    function getAttribute(el, attr) {
        return el.getAttribute(attr);

    }

    function getHTML(el) {
        return el.innerHTML;
    }

    function getStyle(el, ruleName) {
        return getComputedStyle(el)[ruleName];
    }

    function getText(el) {
        return el.textContent;
    }

    function hasClass(el, className) {
        if (el.classList) {
            el.classList.contains(className);
        } else {
            new RegExp('(^| )' + className + '( |$)', 'gi').test(el.Name);
        }
    }

    function Matches(el, otherEl) {
        return el === otherEl;
    }

    function MatchesSelector(el, selector) {
        var matches = function (el, selector) {
            return (el.matches || el.matchesSelector || el.msMatchesSelector || el.mozMatchesSelector || el.webkitMatchesSelector || el.oMatchesSelector).call(el, selector);
        };

        matches(el, selector);
    }

    function Next(el) {
        el.nextElementSibling;
    }

    function Offset(el) {
        var rect = el.getBoundingClientRect();

        return {
            top: rect.top + document.body.scrollTop,
            left: rect.left + document.body.scrollLeft
        }
    }

    function OffsetParent(el) {
        return el.offsetParent || el;
    }

    function outerHeight(el) {
        return el.offsetHeight;
    }

    function outerHeightWithMargin(el) {
        var h = el.offsetHeight;
        var style = getComputedStyle(el);

        h += parseInt(style.marginTop) + parseInt(style.marginBottom);
        return h;
    }

    // outer width
    function Parent(el) {
        return el.parentNode;
    }

    function Position(el) {
        return {
            left: el.offsetLeft,
            top: el.offsetTop
        }
    }

    function positionRelativeToViewport(el) {
        return el.getBoundingClientRect();
    }

    function Prepend(parent, el) {
        parent.insertBefore(el, parent.firstChild);
    }

    function Prev(el) {
        el.previousElementSibling;
    }

    function Remove(el) {
        el.parentNode.removeChild(el);
    }

    function replaceFromHTML(el, string) {
        el.outerHTML = string;
    }

    function setAttribute(el, attrName, attrValue) {
        el.setAttribute(attrName, attrValue);
    }

    function setHTML(el, string) {
        el.innerHTML = string;
    }

    function setStyle(el, styleName, value) {
        el.style[styleName] = value;
    }

    function setText(el, string) {
        el.textContent = string;
    }

    function Siblings(el) {
        return Array.prototype.filter(el.parentNode.children, function (child) {
            return child !== el;
        })
    }

    function toggleClass(el, className) {
        if (el.classList) {
            el.classList.toggle(className);
        } else {
            var classes = el.className.split(' ');
            var existingIndex = classes.indexOf(className);

            if (existingIndex >= 0) {
                classes.splice(existingIndex, 1);
            } else {
                classes.push(className);
            }

            el.className = classes.join(' ');
        }
    }


    /* Events */
    function Off(el, eventName, eventHandler) {
        el.removeEventListener(eventName, eventHandler);
    }

    function On(el, eventName, eventHandler) {
        el.addEventListener(eventName, eventHandler);
    }

    function Ready(fn) {
        if (document.attachEvent ? document.readyState === "complete" : document.readyState !== "loading") {
            fn();
        } else {
            document.addEventListener('DOMContentLoaded', fn);
        }
    }

    function triggerCustom(el, eventName, data) {
        var event;
        if (window.CustomEvent) {
            event = new CustomEvent(eventName, {detail: data});
        } else {
            event = document.createEvent('CustomEvent');

            /*( in DOMString type, in boolean canBubble, in boolean cancelable, in any detail )*/
            event.initCustomEvent(eventName, true, true, {some: data});
        }
        el.dispatchEvent(event);
    }
    
    function triggerNative(el) {
        var event = document.createEvent('HTMLEvents');
        event.initEvent('change',true,false);
        el.dispatchEvent(event);
    }

    /*Utils*/
    function Bind(fn,context) {
        fn.bind(context);
    }

    function arrayEach(arr,fn) {
        arr.forEach(fn);
    }

    function deepExtend(out) {
        out = out||{};
        for(var i=0; i<arguments.length;++i){
             if(!arguments[i]){
                 continue;
             }
             var obj = arguments[i];
             for(var key in obj){
                 if(obj.hasOwnProperty(key)){
                     if(typeof  obj[key] === 'object'){
                         out[key] = deepExtend(out[key],obj[key]);
                     }else{
                         out[key] = arguments[i][key];
                     }
                 }
             }
        }
        return out;
    }

    function Extend(out) {
         out = out||{};
        for(var i=0; i<arguments.length;++i){
            if(!arguments[i]){
                continue;
            }
            for(var key in arguments[i]){
                if(arguments[i].hasOwnProperty(key)){
                    out[key] = arguments[i][key];
                }
            }
        }
        return out;
    }

    function indexOf(array,item) {
        return array.indexOf(item);
    }

    function isArray(arr) {
        return Array.isArray(arr);
    }


    /* UTILS */
    function Map(arr,fn) {
        return arr.map(fn);
    }

    function Now() {
        return Date.now();
    }

    function parseHTML(htmlString) {
        var temp = document.implementation.createHTMLDocument();
        temp.body.innerHTML = htmlString;
        return temp.body.children;
    }

    function parseJSON( jsonString ) {
        return JSON.parse(jsonString);
    }

    function Trim(string) {
        string.trim();
    }

    function Type(obj) {
        Object.prototype.toString.call(obj).replace(/^\[object (.+)\]$/, '$1').toLowerCase();
    }

    


    return {
        /*AJAX*/
        getJSON: getJSON,
        Post: Post,
        Request: Request,

        /*EFFECTS*/
        fadeIn: fadeIn,
        Hide: Hide,
        Show: Show,

        /*ELEMENTS*/
        AddClass: AddClass,
        After: After,
        Append: Append,
        Before: Before,
        Children: Children,
        Clone: Clone,
        Contains: Contains,
        ContainsSelector: ContainsSelector,
        Each: Each,
        Empty: Empty,
        Filter: Filter,
        FindChildren: FindChildren,
        FindElements: FindElements,
        getAttribute: getAttribute,
        getHTML: getHTML,
        getStyle: getStyle,
        getText: getText,
        hasClass: hasClass,
        Matches: Matches,
        MatchesSelector: MatchesSelector,
        Next: Next,
        Offset: Offset,
        OffsetParent: OffsetParent,
        outerHeight: outerHeight,
        outerHeightWithMargin: outerHeightWithMargin,
        Parent: Parent,
        Position: Position,
        positionRelativeToViewport: positionRelativeToViewport,
        Prepend: Prepend,
        Prev: Prev,
        Remove: Remove,
        replaceFromHTML: replaceFromHTML,
        setAttribute: setAttribute,
        setHTML: setHTML,
        setStyle: setStyle,
        setText: setText,
        Siblings: Siblings,
        toggleClass: toggleClass,

        /* EVENTS */
        Off: Off,
        On: On,
        Ready: Ready,
        triggerCustom: triggerCustom,
        triggerNative:triggerNative,
        Extend:Extend,
        deepExtend:deepExtend,
        indexOf:indexOf,
        isArray:isArray,

        /* UTILS */
        Map:Map,
        Now:Now,
        parseHTML:parseHTML,
        parseJSON:parseJSON,
        Trim:Trim
    }
}


