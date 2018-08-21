# 蕾蕾的花儿 每日前端文章整理

[TOC]

## 2018/8/13 
Hi all，
下面是今日的文章推荐：

### Get fast, stay fast. An article to cost of js.
[《The Cost Of JavaScript In 2018》](https://medium.com/@addyosmani/the-cost-of-javascript-in-2018-7d8950fbb5d4)
 - to stay fast, only load JS needed for current page
 - embrace performance budgets and learn to live whthin them
 - learn how to audit and trim ( 审计和修剪 ) your JS bundles
 - Every interaction is the start of anew "Time-toInteractive"; consider optimizations in this context
 - If client-side JavaScript isn`t benefiting the user-experience, ask yourself if really necessary
 - consider [code-splitting](https://webpack.js.org/guides/code-splitting/) to break up bundles or [reducing JS payloads using tree-shaking](https://developers.google.com/web/fundamentals/performance/optimizing-javascript/tree-shaking/)

- Sites ofen send the following:
  1. a client-side framework or UI library
  2. a state management solution (like: Redux,Vux...)
  3. Polyfills ( often for modern browsers that don`t need them )
  4. Full libs xv. only that they use
  5. a suite of UI components
    This code adds up, is too large too time longer for loading this page.

- A small js payload can ensure this happens fast.
- Use [React Loadable](https://github.com/jamiebuilds/react-loadable)
- [Why Web Developers Need to Care about Interactivity](https://philipwalton.com/articles/why-web-developers-need-to-care-about-interactivity/)
- Action plan for performance 
  1. Create a performance vision
  2. Set a performance bugets
  3. Create regular reports on KPIs.

- tools to help with bundle analysis: [link](https://www.npmjs.com/package/webpack-bundle-analyzer)
- [Optimize your libraries with webpack](https://github.com/GoogleChromeLabs/webpack-libs-optimizations)

[《Strategies for dealing with poor code in limited time》](https://chrismm.com/blog/strategies-for-dealing-with-poor-code-in-limited-time/)

[《前后端必备Linux基础知识大科普》](https://juejin.im/post/5b6c3bbae51d4533f5286aff)

[《浅析图片懒加载技术 》](https://mp.weixin.qq.com/s/JYglEGYN9tnGpDg7ARPx7w?)

[《Node.js API to control Firefox 》](https://github.com/deepsweet/foxr)

[《阿里巴巴宣布开源限流降级中间件——Sentinel 》](https://mp.wixin.qq.com/s/s-4JeeATl9NpkxUIeBHvSw)


## 2018/8/15

[《How to write a good coding article》](//zellwk.com/blog/writing-good-coding-articles/)

 [《图解高内聚与低耦合》](//www.cnblogs.com/xdecode/p/9393885.html)

**各模块间的引用应是单向依赖**

好的接口应当满足设计模式六大原则, 很多设计模式, 框架都是基于高内聚低耦合这个出发点的.

1. 单一职责原则: 一个类只负责一个功能领域中的相应职责.
2. 开闭原则: 一个软件实体应当对扩展开放，对修改关闭.
  里氏代换原则: 所有引用基类（父类）的地方必须能透明地使用其子类的对象.
3. 依赖倒转原则: 抽象不应该依赖于细节, 细节应当依赖于抽象. 换言之, 要针对接口编程, 而不是针对实现编程.
4. 接口隔离原则: 使用多个专门的接口, 而不使用单一的总接口, 即客户端不应该依赖那些它不需要的接口.
5. 迪米特法则: 一个软件实体应当尽可能少地与其他实体发生相互作用, 例如外观模式, 对外暴露统一接口.

**外观模式：**为系统中多个子系统提供一致的对外调用, 对客户端隐藏子系统细节, 降低其与子系统的耦合.

**桥接模式：**JDBC中的把面向厂商的接口(Driver)和面向使用者的API(DriverManager)做了拆分隔离.

**适配器模式：**引入第三方库(hibernate, log4j), 不应该直接在代码中继承或者使用其实体类.
需要抽出上层统一接口, 然后增加实现类, 对外暴露接口.

[《如何成为一位「不那么差」的程序员》](//juejin.im/post/5b70cdf6e51d456665220632)

[《聊聊Chrome DevTools中你可能不知道的调试技巧》](//zhuanlan.zhihu.com/p/42059158)
[《最火移动端跨平台方案盘点：React Native、weex、Flutter 》](www.52im.net/thread-1870-1-1.html)

[《大公司为什么还在采用过时的技术》](www.cnblogs.com/rjzheng/p/9463577.html)

[《Facebook：当ZooKeeper遇瓶颈，我们如何规模化配置服务器 》](//mp.weixin.qq.com/s/QByd_6eQ0LS8Qqx7A5uNqA)


## 2018/8/16

[《回流VS重绘》](https://juejin.im/post/5b72dbdb518825614f00576e)

1. DOM tree 
2. CSS rule tree
3. Render tree (exclude elements that has "display:none", head node. but include "visibility:hidden" node) 
4. layout
5. painting

reflow和repaint的概念；

**回流必将引起重绘，重绘不一定会引起回流**

引发回流的操作
如何避免回流和重置

 display:none 会触发 reflow，而 visibility:hidden 只会触发 repaint，因为没有发现位置变化。




[《高效开发与高性能并存的UI框架——携程Flutter实践 》](https://mp.weixin.qq.com/s/l6xvmnLE6HfRtw6upo6yUA)