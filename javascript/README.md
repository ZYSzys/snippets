# javascript snippets

- [算法](algorithms)
- [浏览器端](browser)
- [js 深入](deep)
- [服务器端(nodejs)](node)
- [Vue 源码学习](vue)
- [webpack](webpack)

## 细节

> new 的构造函数后跟括号优先级会提升。

> 判断回文字符串:
```js
const judge = (str) => str.split('').reverse().join('') === str
```````

> for in:
遍历对象本身的所有 **可枚举属性** ，以及对象从其构造函数原型中继承的属性（更接近原型链中对象的属性覆盖原型属性）。

> for of:
在 **可迭代** 对象（包括 Array，Map，Set，String，TypedArray，arguments 对象等等）上创建一个迭代循环，调用自定义迭代钩子，并为每个不同属性的值执行语句。

> Object.hasOwnProperty():
返回一个布尔值，指示对象 **自身** 属性中是否具有指定的属性，(不包括原型链上的)。

> Object.keys():
返回一个由一个给定对象的 **自身** **可枚举属性** 组成的数组, 数组中属性名的排列顺序和使用 for...in 循环遍历该对象时返回的顺序一致 。

> Object.getOwnPropertyNames(): 返回一个数组，该数组对元素是 obj 自身拥有的枚举或不可枚举属性名称字符串。

> Reflect.ownKeys(): 返回一个由目标对象自身的属性键组成的数组。它的返回值等同于 **Object.getOwnPropertyNames(target).concat(Object.getOwnPropertySymbols(target))** 。
