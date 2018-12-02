/* https://github.com/youngwind/blog/issues/84 */

// 观察者构造函数
function Observer (data) {
  this.data = data
  this.walk(data)
}

const p = Observer.prototype

// 递归遍历对象的各个属性
// 为每个对象的每个属性绑定getter和setter
p.walk = function (obj) {
  let val
  for (let key in obj) {
    // for...in 循环会把对象原型链上的所有可枚举属性都循环出来
    // 我们只想要这个对象本身拥有的属性，所以用hasOwnProperty过滤
    if (obj.hasOwnProperty(key)) {
      val = obj[key]

      // 判断值，如果还是对象则继续用new Observer遍历
      if (typeof val === 'object') {
        new Observer(val)
      }

      // 为当前对象的key属性设置getter和setter
      this.convert(key, val)
    }
  }
}

// 设置getter和setter
p.convert = function (key, val) {
  Object.defineProperty(this.data, key, {
    enumerable: true,
    configurable: true,
    get: function () {
      console.log('getter: 访问了' + key)
      return val
    },
    set: function (newVal) {
      console.log('setter: 访问了' + key)
      console.log('新' + key + '=' + newVal)
      if (newVal === val) {
        return
      }
      val = newVal
    }
  })
}

const data = {
  user: {
    name: 'ZYSzys',
    age: '20'
  },
  address: {
    city: 'Hangzhou'
  }
}

const app = new Observer(data)

// 测试
console.log(app.data.user)
console.log(app.data.user.age)

app.data.user.age = 21
app.data.address = {
  city: 'zz'
}
app.data.address.city

/* bug
1. 只监听了对象的变化，无法监听数组的变化
2. 重新set的属性是对象的话，新set对象的属性无法被监听，即不再带有getter和setter了
*/
