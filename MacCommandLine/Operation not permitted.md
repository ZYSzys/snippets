## Operation not permitted:</br>
Mac OS X EI Capitan有个叫sip的机制。 你暂时不能直接在终端进行 csrutil disable 会出现错误提示，引导你去mac osx的恢复模式进行操作。 

由于El Capitan引入了SIP机制(System Integrity Protection)，默认下系统启用SIP系统完整性保护机制，无论是对于硬盘还是运行时的进程限制对系统目录的写操作。 这也是我们安装ipython失败的原因….


现在的解决办法是取消SIP机制，具体做法是：

**重启电脑，按住Command+R(直到出现苹果标志)进入Recovery Mode(恢复模式)
左上角菜单里找到实用工具 -> 终端
输入csrutil disable回车，重启Mac即可**

>csrutil disable</br>

如果想重新启动SIP机制重复上述步骤改用csrutil enable即可

>csrutil enable</br>

我们现在再看看sip的状态, 这样再安装ipython、gevent再也不会提示无法写入的权限提示了

>csrutil status</br>
System Integrity Protection status: disabled.


如果在mac下碰到OSError: [Errno 1] Operation not permitted:的问题，就算用sudo 也无法解决，那肯定是sip在作怪了.
</br></br>
一个优雅的方案，大家可以使用下. 基于用户的权限来安装模块包显得更加合理:</br> 
pip install ipython --user -U
