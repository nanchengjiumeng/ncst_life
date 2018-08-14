function f() {


    /* json

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


    /* effects */

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

    function getStyle(el,ruleName) {
        return getComputedStyle(el)[ruleName];
    }

    function getText(el) {
        return el.textContent;
    }

    function hasClass( el,className ) {
        if(el.classList){
            el.classList.contains(className);
        }else {
            new RegExp('(^| )'+className+'( |$)','gi').test(el.Name);
        }
    }

    function Matches( el, otherEl ) {
        return el === otherEl;
    }

    function MatchesSelector(el,selector) {
        var matches = function(el, selector) {
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
        var h  = el.offsetHeight;
        var style = getComputedStyle(el);

        h += parseInt(style.marginTop) + parseInt(style.marginBottom);
        return h;
    }

    // outer width


    return {
        getJSON: getJSON,
        Post: Post,
        Request: Request,
        fadeIn: fadeIn,
        Hide: Hide,
        Show: Show,
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
        FindChildren:FindChildren,
        FindElements:FindElements,
        getAttribute:getAttribute,
        getHTML:getHTML,
        getStyle:getStyle,
        getText:getText,
        hasClass:hasClass,
        Matches:Matches,
        MatchesSelector:MatchesSelector,
        Next:Next,
        Offset:Offset,
        OffsetParent:OffsetParent,
        outerHeight:outerHeight,
        outerHeightWithMargin:outerHeightWithMargin,

    }
}


