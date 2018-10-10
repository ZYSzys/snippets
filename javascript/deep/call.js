// call的模拟实现
Function.prototype.simcall = function(context) {
  context = context || global; // 浏览器端用 window
  context.fn = this;

  const args = [];
  for (let i = 1; i < arguments.length; i++) {
    args.push('arguments[' + i + ']');
  }

  const result = eval('context.fn(' + args + ')');

  delete context.fn;
  return result;
};

val = 1; // node环境下不应该用 var
var obj = {
  val: 100
};

function f(name, age) {
  console.log(this.val);
  return {
    val: this.val,
    name: name,
    age: age
  };
}

f.simcall(null);

console.log(f.simcall(obj, 'ZYSzys', 20));
