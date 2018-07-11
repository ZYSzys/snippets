#!/usr/bin/env node
var http = require('http')

http.createServer(function (request, response) {
  response.writeHead(200, {'Content-Type': 'text/plain', 'Access-Control-Allow-Origin': '*'})
  response.end('Hello, ZYSzys\n')
}).listen(3000)

console.log('Server running at http://127.0.0.1:3000/')
console.log('Hello, ZYSzys')
