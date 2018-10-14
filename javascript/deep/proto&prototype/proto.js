// https://github.com/mqyqingfeng/Blog/issues/2
// 总结：实例.proto === 其构造函数.prototype，构造函数.prototype.constructor === 构造函数，一路向上找


// 每个函数都有prototype属性，除了被bind方法返回的函数以及箭头函数
function f() {}
const ff = f.bind();
const fff = () => {};
console.log(f.prototype); // => f {}
console.log(ff.prototype); // => undefined
console.log(fff.prototype); // => undefined


// f.prototype表示f的实例的原型 __proto__,
// __proto__ 指向构造函数f的prototype
const instance = new f();
console.log(f.prototype === instance.__proto__); // => true


// 每一个JavaScript对象(除了 null(再说null不是对象) )都具有的一个属性，叫__proto__，这个属性会指向该对象的原型
try {
  console.log(null.__proto__);
} catch (e) {
  console.log('null没有__proto__属性');
}


//每个原型都有一个 constructor 属性指向关联的构造函数 constructor
console.log(f === f.prototype.constructor); // => true
console.log(f === instance.__proto__.constructor); // => true
console.log(Object.getPrototypeOf(instance) === f.prototype); // => true


//当读取实例的属性时,
//如果找不到，就会查找与对象关联的原型中的属性，
//如果还查不到，就去找原型的原型，一直找到最顶层为止。
f.prototype.name = 'ZYSzys';
const F = new f();
F.name = 'World';
console.log(F.name); // => World
delete F.name;
console.log(F.name); // => ZYSzys


// Object.prototype 的原型为null,
// null 表示“没有对象”，即该处不应该有值。
// 所以在原型链上查找属性，查到 Object.prototype 就停止了
console.log(Object.prototype.__proto__);


// 原型链, 通过__proto__链接起来。
console.log(instance);
console.log(instance.__proto__);
console.log(instance.__proto__.__proto__);
console.log(instance.__proto__.__proto__.__proto__);


// 当获取实例的构造函数constructor时，
// 其实实例中并没有constructor属性，
// 会从实例的原型instance.__proto__中查找
// 而原型中有该属性
console.log(instance.constructor === f);
console.log(instance.__proto__.constructor === f);
console.log(f.prototype.constructor === f);


/*
__proto__ 是来自于 Object.prototype，
与其说是一个属性，不如说是一个 getter/setter，
当使用 obj.__proto__ 时，可以理解成返回了 Object.getPrototypeOf(obj)。
*/

// 所有函数的__proto__ 都等于 Function.prototype
console.log(Function.__proto__ === Function.prototype); // => true
console.log(f.__proto__ === Function.prototype);


