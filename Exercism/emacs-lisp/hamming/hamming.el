;;; hamming.el --- Hamming (exercism)

;;; Commentary:

;;; Code:

;; (dotimes (i (length str))
  ;; (print (aref str i)))

(defun hamming-distance (a b)
  "Calculate hamming distance between A and B."
  (if (not (= (length a) (length b)))
      (error nil))

  (setq result 0)
  (dotimes (i (length a))
    (if (not (= (aref a i) (aref b i)))
        (setq result (1+ result))
        )
    )
  result)

(hamming-distance "AAB" "AAA")
(hamming-distance "AAA" "AAA")
(hamming-distance "GGACTGA" "GGACTGA")

(provide 'hamming)
;;; hamming.el ends here
