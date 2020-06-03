;;; roman-numerals.el --- roman-numerals Exercise (exercism)

;;; Commentary:

;;; Code:

(defun to-roman (input)
  "Convert INPUT to a Roman number."
  (setq table '((1 . "I") (4 . "IV") (5 . "V") (9 . "IX") (10 . "X")
                (40 . "XL") (50 . "L") (90 . "XC") (100 . "C") (400 . "CD")
                (500 . "D") (900 . "CM") (1000 . "M")))

  (setq result "")
  (while (> input 0)
    (setq idx 12)

    (while (> (car (nth idx table)) input)
      (setq idx (1- idx)))

    (setq input (- input (car (nth idx table))))
    (setq result (concat result (cdr (nth idx table)))))
  result)

(provide 'roman-numerals)
;;; roman-numerals.el ends here
;; Local Variables:
;; byte-compile-warnings: (not free-vars)
;; End:
