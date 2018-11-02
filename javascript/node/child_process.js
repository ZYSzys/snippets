const { promisify } = require('util');
const { exec, spawn } = require('child_process');

exec('node -v', (error, stdout, stderr) => {
  if (error) {
    console.error(`exec error: ${error}`);
    return;
  }
  console.log(`stdout: ${stdout}`);
  console.log(`stderr: ${stderr}`);
});


const pexec = promisify(exec);
async function lsExample() {
  const { stdout, stderr } = await pexec('ls');
  console.log('stdout:', stdout);
  console.log('stderr:', stderr);
}
lsExample();


const ls = spawn('ls', ['-lh', '/usr']);

ls.stdout.on('data', (data) => {
  console.log(`stdout: ${data}`);
});

ls.stderr.on('data', (data) => {
  console.log(`stderr: ${data}`);
});

ls.on('close', (code) => {
  console.log(`子进程退出码：${code}`);
});
