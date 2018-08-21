# html标签的属性

参考链接:
-	[htmlreference](https://htmlreference.io/element/a/)

[TOC]

## A
### a 
2018/8/13 

- href
  - http url
  - /a/b relative to the root domain
  - # 
  - @ mailto protocaol,clicking the link will open a mail
- target
  - _blank : open a new tab
  - _self : opens in the current tab
  - _parent : Opens in the parent browsing context, or _self is there is none.
  - _top : Opens in the top browsing context, or _self is there is none.
- rel 

### abbr 
定义一个**缩进词**，隐藏完全描述，当鼠标经过该DOM时显示
	- tittle    = "HyoerText Markup Language"
### address
defines a block for contact information

### area
defines an interactive area within a **map**

- title  = "North America" 
- shape 
  1. ""rect" : requires 4 coordinates 
  2. ""circle" : requires 2 coordinates an 1 radius
  3. ""polygon" : a polygon with unlimited points
- coords
- href 

### article
定义一块独立的内容会，它可以存在于任意上下文中
it can have its own **leader, footer, sections...Useful** for a list of blog posts.

### aside
定义一个与<main>相关的内容块，并经常被当做sidebar展示。

### audio
- src
- volume
- autoplay
- controls 展示浏览器的内置的音频控制器
- loop 循环播放
- muted 静音
- preload : the track will be preloaded when the page loads


## B
### b
Makes an element bold :  emphasis on **style**

### base
- href : Defines the base target of all links of the web page.
- target 
  1. "_black"
  2. "_self"
  3. "_parent"
  4. "_top"

### bdi


### body
The container for a web page's content. Must be a direct child of <html>, and must be an ancestor of all HTML elements (except where noted).


### html
Opens in the top browsing context, or _self is there is none.






## TODO
- [x] a
- [x] html
- [x] body
- [x] abbr
- [x] address
- [x] area
- [x] article
- [x] audio
- [x] b
- [x] base
- [x] bdi
- [x] bdo