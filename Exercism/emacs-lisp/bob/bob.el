;;; bob.el --- Bob exercise (exercism)

;;; Commentary:

;;; Code:

(require 'subr-x)

(defun response-for (input)
  "Provide response for INPUT."
  (setq input (string-trim input))
  (cond ((string= "" input) "Fine. Be that way!")
        ((and (not (string-match "[a-z]" input)) (string-match-p "\?\\'" input))
             "Sure.")
        ((and (string= input (upcase input)) (string-match-p "\?\\'" input))
          "Calm down, I know what I\'m doing!")
        ((let ((case-fold-search nil))
           (and (not (string-match-p "[a-z]" input)) (string-match-p "[A-Z]" input))
           ) "Whoa, chill out!")
        ((string-match-p "\?\\'" input) "Sure.")
        (t "Whatever.")))

(provide 'bob)
;;; bob.el ends here
