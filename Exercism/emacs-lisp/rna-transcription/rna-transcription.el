;;; rna-transcription.el -- RNA Transcription (exercism)

;;; Commentary:

(setq valid-dna '("C" "G" "A" "T"))
(setq dna '(("C" . "G") ("G" . "C") ("A" . "U") ("T" . "A")))

(defun transcribe (char)
  "Transcribes CHAR into its RNA."
  (cdr (assoc char dna)))

(defun to-rna (input)
  "Transcribes INPUT into RNA."
  (dotimes (i (length input))
    (if (not (member (byte-to-string (aref input i)) valid-dna) )
        (error nil)))

  (mapconcat
   'identity (mapcar 'transcribe (mapcar 'byte-to-string (append input nil)))
   ""))

;;; Code:

(provide 'rna-transcription)
;;; rna-transcription.el ends here

;; Local Variables:
;; byte-compile-warnings: (not free-vars mapcar)
;; End:
