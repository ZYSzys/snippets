'use strict';

const vm = require('vm');

const x = 1;
const sandbox = { x: 2 };

// 创建上下文
vm.createContext(sandbox);

const code = 'x += 40; var y = 17;';

// 在创建的上下文 (sandbox) 中执行代码(code)
vm.runInContext(code, sandbox);

console.log(sandbox.x);
console.log(sandbox.y);

console.log(x);

// 上下文中的全局变量已改变
console.log(sandbox)
