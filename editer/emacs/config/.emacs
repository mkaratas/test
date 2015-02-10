;;add search path

(require 'package)
(add-to-list 'package-archives
	     '("melpa" . "http://melpa.org/packages/") t)
(package-initialize)

(setq gdb-many-windows t)

(require 'eieio)
(require 'cedet)
(require 'semantic)
(require 'ede)
(require 'srecode)
;(global-ede-mode t)
;;(semantic-load-enable-code-helpers)
;;(global-srecode-minor-mode 1)

(global-set-key (kbd "C-x v") 'emacs-version)
(global-set-key (kbd "C-x p") 'cedet-version)
(custom-set-variables
 ;; custom-set-variables was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 '(ansi-color-faces-vector
   [default default default italic underline success warning error])
 '(ansi-color-names-vector
   ["#242424" "#e5786d" "#95e454" "#cae682" "#8ac6f2" "#333366" "#ccaa8f" "#f6f3e8"])
 '(custom-enabled-themes (quote (wheatgrass)))
 '(ecb-options-version "2.40"))
(custom-set-faces
 ;; custom-set-faces was added by Custom.
 ;; If you edit it by hand, you could mess it up, so be careful.
 ;; Your init file should contain only one such instance.
 ;; If there is more than one, they won't work right.
 )

(global-set-key [f12] 'ecb-minor-mode)

