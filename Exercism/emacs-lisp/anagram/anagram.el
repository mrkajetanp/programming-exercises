;;; anagram.el --- Anagram (exercism)

;;; Commentary:

;;; Code:

(require 'cl-lib)

(defun is-anagram (word input)
  "Check if WORD and INPUT are anagrams."
  (and (= (length word) (length input))
           (equal (sort (append (downcase word) nil) '<)
                  (sort (append (downcase input) nil) '<)))

)

(defun anagrams-for (word inputs)
  "Loop over INPUTS and return a list of anagrams of WORD."
  (cl-loop for input in inputs
           when (not (string= word input))
           when (is-anagram word input)
           collect input
  )
)


(provide 'anagram)
;;; anagram.el ends here
