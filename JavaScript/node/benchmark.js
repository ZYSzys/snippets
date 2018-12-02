#!/usr/bin/env node
function charCodes(str) {
  if (str.length === 0) return [];
  if (str.length === 1) return [str.charCodeAt(0)];
  const ret = [...str];
  return ret;
}

function test(func, name) {
  var startTime = Date.now()
  var N = 1000 * 1000 * 10
  for (var i = 0; i < N; i++) {
    func()
  }
  var endTime = Date.now()
  console.log(`${name}: ${endTime - startTime}`)
}

test(() => charCodes('abcdefghijklmnopqrstuvwxyz'), 'charCodes');

