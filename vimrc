set modelines=0                          " 禁用模式行（安全措施）
syntax on                                " 语法高亮
filetype on                              " 开启文件类型检测

set encoding=utf-8                       " 编码设置
set number                               " 显示行号
set relativenumber                       " 显示相对行号
set smartindent                          " 智能缩进
set autoindent                           " 自动对齐

set smarttab
set tabstop=4                            " tab缩进
set shiftwidth=4                         " 设定自动缩进为4个字符
set expandtab                            " 用space替代tab的输入
set splitright                           " 设置左右分割窗口时，新窗口出现在右侧
set splitbelow                           " 设置水平分割窗口时，新窗口出现在底部

set nobackup                             " 不需要备份
set noswapfile                           " 禁止生成临时文件
set autoread                             " 文件自动检测外部更改
set clipboard=unnamed                    " 共享剪切板

set nocompatible                         " 去除vi一致性
set ambiwidth=double                     " 解决中文标点显示的问题
"set nowrap                               " 不自动折行
set mouse=a                              " 使用鼠标
set mousehide                            " 输入时隐藏光标
set sidescroll=10                        " 移动到看不见的字符时，自动向右滚动是个字符

set sm!                                  " 高亮显示匹配括号
set hlsearch                             " 高亮查找匹配

set showmatch                            " 显示匹配
set ruler                                " 显示标尺，在右下角显示光标位置
set novisualbell                         " 不要闪烁
set showcmd                              " 显示输入的命令

set completeopt=longest,menu             " 自动补全配置让Vim补全菜单行为跟IDE一致
set backspace=indent,eol,start           " 允许用退格键删除字符

set laststatus=2
set statusline=%1*%F%m%r%h%w%=\|
set statusline+=%2*\ %Y\ \|
set statusline+=%3*\ [%l:%v]\ \|   
set statusline+=%4*\ %p%%\ \ \| 
set statusline+=%5*\ %LL\ 
hi User1 cterm=none ctermfg=none ctermbg=none
hi User2 cterm=none ctermfg=none ctermbg=none
hi User3 cterm=bold ctermfg=none ctermbg=none
hi User4 cterm=bold ctermfg=yellow ctermbg=none
hi User5 cterm=none ctermfg=none ctermbg=none
