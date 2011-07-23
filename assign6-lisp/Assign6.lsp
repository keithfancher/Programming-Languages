; *********************************************************************
; File   : Assign6.lsp
; Author : Keith T. Fancher
; Class  : CS3490
; Date   : 03-29-04
; Purpose: Five functions that make learning lisp fun... sorta.
; *********************************************************************


; Function : allbutnth
; Arguments: a list, an integer
; Returns  : the passed list with the Nth element omitted
; Examples : 
;   (allbutnth '(a b a d e) 0)    ---> (b a d e) 
;   (allbutnth '(a b (a b) e) 2)  ---> (a b e) 
;   (allbutnth '(a b (a b) e) 5)  ---> (a b (a b) e) 
;   (allbutnth '(a b (a b) e) 'a) ---> NIL       // because 'a is not an integer 
;   (allbutnth 'a 3)              ---> NIL       // because 'a is not a list 
(defun allbutnth (l n)
  (cond
    ((null l) nil)          ; empty list
    ((not (listp l)) nil)   ; not a list
    ((not (numberp n)) nil) ; not a number
    ((= n 0) (cdr l))       ; base case
    (t (cons (car l) (allbutnth (cdr l) (- n 1))))
  )
)


; Function : myreverse
; Arguments: the list to reverse
; Returns  : the list in reverse order
; Examples :
;   (myreverse '(a b a d e))   ---> (e d a b a) 
;   (myreverse '(a b (a b) e)) ---> (e (a b) b a) 
;   (myreverse 'a)             ---> NIL       //because 'a is not a list 
(defun myreverse (l)
  (cond
    ((null l) nil)        ; empty list
    ((not (listp l)) nil) ; not a list
    ((= (length l) 1) l)  ; base case
    (t (append (last l) (myreverse (allbutnth l (- (length l) 1)))))
  )
)


; Function : elementof
; Arguments: the element to search for, the list to search
; Returns  : true if the element is in the list, NIL otherwise
; Examples :
;   (elementof 'a '(a b c))     ---> T 
;   (elementof 'a '(b b c))     ---> NIL 
;   (elementof '(a) '(b (a) c)) ---> T 
;   (elementof '(a) '(b a c))   ---> NIL 
;   (elementof 'a 'a)           ---> NIL      //because second argument is not a list 
(defun elementof (e l)
  (cond
    ((null l) nil)        ; empty list
    ((not (listp l)) nil) ; not a list
    ((equal (car l) e) t) ; base case
    (t (elementof e (cdr l)))
  )
)


; Function : intersect
; Arguments: a list, another list
; Returns  : the intersection of those two lists
; Examples :
;   (intersect '(a b c) '(c b d))     ---> (b c)
;   (intersect '(a (b) c) '(c (b) d)) ---> ((b) c) 
;   (intersect '(a c) '(b d))         ---> NIL 
;   (intersect 'a 'b)                 ---> NIL 
;   (intersect '(a a b) '(a b d))     ---> (b a) 
(defun intersect (l1 l2)
  (cond
    ((null l1) nil) ; empty?
    ((null l2) nil) ; empty?
    ((not (listp l1)) nil) ; l1 not a list
    ((not (listp l2)) nil) ; l2 not a list
    ((equal l1 l2) l1) ; they're equal
    ((elementof (car l1) l2) (cons (car l1) (intersect (cdr l1) (remove (car l1) l2))))
    (t (intersect (cdr l1) l2))
  )
)


; Function : embedremove
; Arguments: the element to remove, the list to remove the element from
; Returns  : the list minus every occurance of e (even embedded ones)
; Examples :
;   (embedremove 'a '(a (a) b (c a) a))               ---> (nil b (c)) 
;   (embedremove '(a b) '(a b (a b) c (a b (a b)) e)) ---> (a b c (a b) e) 
;   (embedremove 'a '(a b c (b a d)))                 ---> (b c (b d))
;   (embedremove 'a 'b)                               ---> NIL   // second argument is not a list 
(defun embedremove (e l)
  (cond
    ((not (listp l)) nil) ; l isn't a list
    ((equal e l) nil) ; they are the same, return nil!
    ((null l) nil) ; list is empty
    ((equal (car l) e) (embedremove e (cdr l))) ; if item is first, remove it and go deeper
    ((listp (car l))  (cons (embedremove e (car l)) (embedremove e (cdr l)))) ; el1 a list
    ((= (length l) 1) l) ; size 1, not equal, not a list
    ((not (equal (car l) e)) (cons (car l) (embedremove e (cdr l)))) ; recurse!
  )
)

