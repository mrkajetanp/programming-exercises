;;; grains.el --- Grains exercise (exercism)

;;; Commentary:

;;; Code:

(defun square (input)
  "Compute number of grains on square INPUT."
  (expt 2.0 (1- input)))

(defun total ()
  "Return total number of grains."
  (seq-reduce (lambda (a b)
                (+ a (square b)))
              (number-sequence 1 64)
              0))

(provide 'grains)
;;; grains.el ends here
