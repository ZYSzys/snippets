// apply的模拟实现
Function.prototype.simapply = function (context, arr) {
  context = Object(context) || global // Object(context) => 严格模式下；浏览器端用 window
  context.fn = this

  var result
  if (!arr) {
    result = context.fn()
  } else {
    var args = []
    for (var i = 0; i < arr.length; i++) {
      args.push('arr[' + i + ']')
    }
    result = eval('context.fn(' + args + ')')
  }

  delete context.fn
  return result
}

val = 1 // node环境下不应该用var声明
var obj = {
  val: 100
}

function f(name, age) {
  console.log(this.val)
  return {
    val: this.val,
    name: name,
    age: age
  }
}

f.simapply(global)

console.log(f.simapply(obj, ['ZYSzys', 20]))