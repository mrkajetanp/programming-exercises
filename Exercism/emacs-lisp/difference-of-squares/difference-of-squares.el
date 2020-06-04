;;; difference-of-squares.el --- Difference of Squares (exercism)

;;; Commentary:

;;; Code:

(defun square (x)
  "Square X."
  (* x x))

(defun square-of-sum (x)
  "Calculate the square of sum of digits of X."
  (square (apply '+ (number-sequence 1 x))))

(defun sum-of-squares (x)
  "Calculate the sum of squares of digits of X."
  (apply '+ (mapcar 'square (number-sequence 1 x))) )

(defun difference(x)
  "Calculate the difference of X."
  (- (square-of-sum x) (sum-of-squares x)))

(provide 'difference-of-squares)
;;; difference-of-squares.el ends here
