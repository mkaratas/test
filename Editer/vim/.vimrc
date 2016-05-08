set fileencodings=utf-8,ucs-bom,gb18030,gbk,gb2312,cp936
set termencoding=utf-8
set encoding=utf-8
set hlsearch
"set mouse=a

set tabstop=4
set shiftwidth=4
"set expandtab

let Tlist_Show_One_File=1
let Tlist_Exit_OnlyWindow=1
let Tlist_WinWidth=50

let g:NERDTree_title='NERD Tree'

"let g:winManagerWindowLayout='NERDTree|TagList'

function! NERDTree_Start()
    exec 'NERDTree'
endfunction

function! NERDTree_IsValid()
    return 1
endfunction

let g:winManagerWindowLayout='FileExplorer|TagList'
let g:winManagerWidth = 50 
nmap wm :WMToggle<cr>

let g:miniBufExplMapCTabSwitchBufs = 1
let g:miniBufExplMapWindowNavVim = 1
let g:miniBufExplMapWindowNavArrows = 1
let g:miniBufExplorerMoreThanOne = 0
nnoremap <silent> <F12> :A<CR>

nnoremap <silent> <F3> :Grep<CR>

"filetype plugin indent on
set completeopt=longest,menu

let g:SuperTabRetainCompletionType=2
let g:SuperTabDefaultCompletionType="<C-X><C-O>"

set path+=/home/CORPUSERS/xp014721/Downloads/linux-3.13.5/arch/arm/include
set path+=/home/CORPUSERS/xp014721/Downloads/linux-3.13.5/include

"""""""""""""""""""""""cscope设置""""""""""""""""""      
set cscopequickfix=s-,c-,d-,i-,t-,e-    
if has("cscope")    
set csprg=/usr/bin/cscope    
set csto=1    
set cst    
set nocsverb    
" add any database in current directory     
if filereadable("cscope.out")    
   cs add cscope.out    
endif    
set csverb    
endif    
  
nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>  
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>  
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>  
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>  
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>  
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>  
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>  
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>  
""""""""""""""""""""""""""""""""""""""""""""""""""""
