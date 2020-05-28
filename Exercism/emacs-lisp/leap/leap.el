;;; leap.el --- Leap exercise (exercism)

;;; Commentary:

;;; Code:

(defun leap-year-p (year)
  "Check if YEAR is a leap year."

  (defun factor (x)
    "Check if x is a factor of YEAR."
    (zerop (% year x)))

  (and (factor 4)
       (or (not (factor 100)) (factor 400)))
)


(provide 'leap-year-p)
;;; leap.el ends here
