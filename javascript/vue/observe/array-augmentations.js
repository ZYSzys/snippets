/* https://github.com/youngwind/blog/issues/85 */

const aryMethods = [
  'push',
  'pop',
  'shift',
  'unshift',
  'splice',
  'sort',
  'reverse'
]
const arrayAugmentations = []

aryMethods.forEach((method) => {
  // 原生Array的原型方法
  let original = Array.prototype[method]

  // 将push, pop等封装好的方法定义在对象arrayAugmentations的属性上
  // 注意：是属性而非原型属性
  arrayAugmentations[method] = function () {
    console.log('我被改变了')
    // console.log(this, typeof this)

    // 调用对应的原生方法并返回结果
    return original.apply(this, arguments)
  }
})

let list = ['a', 'b', 'c']
// 将我们要监听的数组的原型指向空数组对象arrayAugmentations
// 属性上定义了经过封装的push等方法
list.__proto__ = arrayAugmentations
list.push('d')
console.log(list)

// 未被重新定义，正常输出
let list2 = [1, 2, 3]
list2.push(4)
console.log(list2)
