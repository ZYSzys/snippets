### 1. 进入用户根目录:
>cd ~

### 2. git初始化:
>git init

### 3. 创建~/.gitignore_global文件:
>vim .gitignore_global

#### .gitignore_global中输入要忽略的文件名:
>>.DS_Store</br>
*/.DS_Store

### 4. 在~/.gitconfig中引入.gitignore_global:(直接在文件中加入)
>[core]</br>excludesfile = /Users/zhangyongsheng/.gitignore_global
