function Scope() {
    this.$$watchers=[];

}
Scope.prototype.$watch=function (exp,fn) {
    // $watch 中应该有保留的内容有函数，还有当前的老值，保留一个表达式
    this.$$watchers.push({
        fn,
        last:this[exp],
        exp:exp
    })
};
Scope.prototype.$apply=function () {
    this.$digest();
};
Scope.prototype.$digest = function () {
    let dirty = true; //默认执行一次
    let counter = 9;
    do{
        dirty = this.$digestOne();
        console.log(counter);
    }while (dirty&&counter--);
};
Scope.prototype.$digestOne=function () {
    let  dirty = false;
    this.$$watchers.forEach(watcher=>{
        let oldValue = watcher.last;
        let newValue = this[watcher.exp];
        if(newValue !== oldValue ){
            watcher.fn(newValue,oldValue);
            dirty = true;
            watcher.last = newValue; //更新老值， 变为最新更改的值， 方便下次更新
        }
    })
    return dirty;
};

let scope = new Scope();

scope.name='wang!';
scope.age=9;
scope.$watch('name',function (newValue,oldValue) {
    console.log(newValue, oldValue);
    scope.name=Math.random();

});
scope.$watch('age',function (newValue,oldValue) {
    scope.name='ooooooooooooooooooo';
});
scope.name='wang yu biao';
scope.age=10;
scope.$apply();