// cluster 模块允许简单容易的创建共享服务器端口的子进程。
'use strict';

const cluster = require('cluster');
const http = require('http');
const { cpus } = require('os');

// 主进程
if (cluster.isMaster) {
  console.log(`主进程 ${process.pid} 正在运行`);

  for (let i = 0; i < cpus().length; i++) {
    cluster.fork();
  }

  cluster.on('exit', (worker, code, signal) => {
    console.log(`工作进程 ${worker.process.pid} 已退出`);
  });
} else {
  // 工作进程
  http.createServer((req, res) => {
    res.writeHead(200);
    res.end('Hello, world');
  }).listen(8000);

  console.log(`工作进程 ${process.pid} 已启动`)
}
