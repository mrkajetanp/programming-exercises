;;; word-count.el --- word-count Exercise (exercism)

;;; Commentary:

;;; Code:

(defun word-count (input)
  "Compute an assoc list of words in INPUT."
  (setq input (replace-regexp-in-string "," " " input))
  (setq input (replace-regexp-in-string "[\\^!&@$%^:.]" "" input))

  (let ((result '())
        (words (split-string (downcase input))))

    (dotimes (i (length words))
      (if (not (assoc (nth i words) result))
          (push (cons (nth i words) 1) result)
        (setcdr (assoc (nth i words) result) (1+ (cdr (assoc (nth i words) result))))))

    result))

(provide 'word-count)
;;; word-count.el ends here
