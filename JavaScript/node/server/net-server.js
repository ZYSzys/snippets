const net = require('net');
const server = net.createServer();
server.on('connection', handleConnection);
server.listen(3000);

function handleConnection(socket) {
  socket.on('data', (chunk) => {
    console.log('Received chunk:\n', chunk.toString());
  });
  socket.write('HTTP/1.1 200 OK\r\nServer: my-web-server\r\nContent-Length: 0\r\n\r\n');
}

/*
Put this code in a file called server.js and
execute it from your command line with node server.js.
In another terminal, use curl to make a simple request to your server:

curl -v localhost:3000/some/url
curl -v -XPOST -d'hello=world' localhost:3000/some/url

*/
