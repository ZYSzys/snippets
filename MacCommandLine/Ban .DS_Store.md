1，禁止.DS_store生成：
打开   “终端” ，复制黏贴下面的命令，回车执行，重启Mac即可生效。

>defaults write com.apple.desktopservices DSDontWriteNetworkStores -bool TRUE

2，恢复.DS_store生成：

>defaults delete com.apple.desktopservices DSDontWriteNetworkStores


对已经生成的文件还需要你手动删除：

>sudo find / -name ".DS_Store" -depth -exec rm {} \;
