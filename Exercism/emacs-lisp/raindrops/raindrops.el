;;; raindrops.el --- Raindrops (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun convert (n)
  "Convert integer N to its raindrops string."
  (setq result "")
  (if (= (% n 3) 0)
      (setq result (concat result "Pling")))
  (if (= (% n 5) 0)
      (setq result (concat result "Plang")))
  (if (= (% n 7) 0)
      (setq result (concat result "Plong")))
  (if (string= result "")
      (setq result (concat result (number-to-string n))))
  result)

(provide 'raindrops)
;;; raindrops.el ends here
