;;description: This scheme program is a functional approach to matrix multiplication
;;		for cse320. 

;;This borrowed function reads the entire text file into a single list
(define input (lambda (name) (let ((p (open-input-file name)))
     (let f ((x (read p)))
      (if (eof-object? x)
        (begin
          (close-input-port p)
          '())
        (cons x (f (read p))))))))

;; borrowed function returns nth member of a list		
(define (nth list n)
  (let iter ((n n) (result list))
    (if (= n 0)
        (car result)
        (iter (- n 1)
              (cdr result)))))

;; borrowed function returns the nth column of a matrix
(define (matrix-col M n)
  (let iter ((i (length M)) (result '()))
    (if (= i 0)
        result
        (iter (- i 1)
              (cons (nth (nth M (- i 1)) n) result)))))

;;converts a single list to a matrix where inner lists are rows
;;parameters:	lis := list to be converted
;;		sublist := temporary list to be added when done
;;		nrows := # of rows
;;		ncolumns : # of columns
;;		cs := iterator goes from ncolumns to 0
(define make-matrix (lambda (lis sublist nrows ncolumns cs)  
    (if (= nrows 0)
	'() ;;if no more columns return nothing
	(if (> cs 0)
 	     (make-matrix (cdr lis) (cons (car lis) sublist) nrows ncolumns (- cs 1))
	     (cons (reverse sublist) (make-matrix lis '() (- nrows 1) ncolumns ncolumns))))))


;;cross products row of A and column of B and returns a single number
(define X-Prod (lambda (aRow bCol) 
			(apply + 0 (map * aRow bCol) )))

;;executes cross product for each column of matrix b to chosen row then concatenate to list
;;parameters: 	a := chosen row of Matrix A
;;		bMatrix := Matrix B
;;		cols := # of columns in Matrix B
;;		c := iterator goes from 0 -> cols
(define makeRow (lambda (a bMatrix cols c)
	;;i must start at zero
	 (if (= c cols)
		'()
	 	(cons (X-Prod a (matrix-col bMatrix c)) (makeRow a bMatrix cols (+ c 1))))))


;;execute makeRow for each row of A then concatenates resulting rows
(define mat-mul (lambda (A B bCols) 
    (if (null? A)
	'()	
	(cons   (makeRow (car A) B bCols 0)
		(mat-mul (cdr A) B bCols)))))
(define A (input "A.txt"))
(define B (input "B.txt"))

;;first 2 numbers are row and column indicators
(display "Contents of A: ")
(display A)
(newline)
(newline)
(display "Contents of B:")
(display B)
(newline)
(newline)
(display "Contents of A*B:")
    (let ([aRows (car A)]
	  [aCols (car (cdr A))]
	  [bRows (car B)]
	  [bCols (car (cdr B))]
	  [L1 (cdr (cdr A))]
	  [L2 (cdr (cdr B))])
	  (let ([makeMatrixA (lambda () (make-matrix L1 '() aRows aCols aCols))]
		[makeMatrixB (lambda () (make-matrix L2 '() bRows bCols bCols))])
		(display (mat-mul (makeMatrixA) (makeMatrixB) bCols))))
(newline)
