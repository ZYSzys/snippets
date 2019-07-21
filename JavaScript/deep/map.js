'use strict';

Array.prototype._map = function _map(fn, callbackThis) {
  const result = [];

  callbackThis = callbackThis || null;

  this.reduce((before, after, index, arr) => {
    // console.log(before, after, index, arr);

    // 把每一项的执行结果push进res中
    result.push(fn.call(callbackThis, after, index, arr));
    return null;
  }, null);
  return result;
}

console.log([1,2,3].map(i => i * i));
console.log([1,2,3]._map(i => i * i));
