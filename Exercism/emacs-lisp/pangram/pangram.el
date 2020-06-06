;;; pangram.el --- Pangram (exercism)

;;; Commentary:

;;; Code:

(defun is-pangram (input)
  "Check if INPUT is a pangram."
  (setq input (downcase input))
  (setq table (make-hash-table :test 'equal))

  (dotimes (i (length input))
    (if (and (>= (aref input i) 97) (<= (aref input i) 122))
        (puthash (byte-to-string (aref input i)) t table)))

  (= (hash-table-count table) 26))

(provide 'pangram)
;;; pangram.el ends here

;; Local Variables:
;; byte-compile-warnings: (not free-vars mapcar)
;; End:
