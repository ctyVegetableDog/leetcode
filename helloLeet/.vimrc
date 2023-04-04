" for Chinese
set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8

" for plug-in

set nocompatible
set backspace=indent,eol,start
filetype on
filetype indent on
filetype plugin on
filetype plugin indent on

" basic

set nu
set cursorline
set wildmenu
set wrap
set smartcase
set laststatus=2

" for tab

set shiftwidth=4
set tabstop=4
set softtabstop=4
set scrolloff=5
set smartindent

" key

map S :w<CR>
map Q :q<CR>
map R :source $MYVIMRC<CR>

map sh :set nosplitright<CR>:vsplit<CR>
map sj :set splitbelow<CR>:split<CR>
map sk :set nosplitbelow<CR>:split<CR>
map sl :set splitright<CR>:vsplit<CR>

map tn :tabn<CR>
map tp :tabp<CR>

map gh <C-W>h
map gj <C-W>j
map gk <C-W>k
map gl <C-W>l


" install plug-in

call plug#begin('~/.vim/plugged')
Plug 'vim-airline/vim-airline'
Plug 'preservim/nerdtree'
Plug 'lervag/vimtex'
Plug 'connorholyday/vim-snazzy'
Plug 'sirver/ultisnips'
Plug 'dense-analysis/ale'
Plug 'ycm-core/YouCompleteMe'
Plug 'gcmt/wildfire.vim'
call plug#end()

" ale

let g:ale_linters = {
\   'c++': ['clang'],
\   'c': ['clang'],
\   'python': ['pylint'],
\}

let g:ycm_global_ycm_extra_conf='~/.vim/plugged/YouCompleteMe/third_party/ycmd/.ycm_extra_conf.py'
" let g:ycm_python_binary_path = '/Users/cuitaiyu/anaconda3/envs/NN/bin/python3.6'
let g:ycm_python_binary_path = '/usr/bin/python3'



" for Vimtex
syntax enable
let g:tex_flavor='latex'
let g:vimtex_view_method='zathura'
let g:vimtex_quickfix_mode=1
set conceallevel=1
let g:tex_conceal='abdmg'

let g:vimtex_compiler_latexmk_engines = {'_':'-xelatex'}
let g:vimtex_compiler_latexrun_engines ={'_':'xelatex'}

" for UltSnips
let g:UltiSnipsExpandTrigger = '<tab><tab>'
let g:UltiSnipsJumpForwardTrigger = '<tab><tab>'
let g:UltiSnipsJumpBackwardTrigger = '<s-tab>'
