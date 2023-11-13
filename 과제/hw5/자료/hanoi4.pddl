(define (problem hanoi3)
  (:domain hanoi)
  (:objects pole1 pole2 pole3 d1 d2 d3 d4)
  (:init 
   (smaller d1 pole1) (smaller d2 pole1) (smaller d3 pole1) (smaller d4 pole1)
   (smaller d1 pole2) (smaller d2 pole2) (smaller d3 pole2) (smaller d4 pole2)
   (smaller d1 pole3) (smaller d2 pole3) (smaller d3 pole3) (smaller d4 pole3)
   (smaller d1 d2) (smaller d1 d3) (smaller d1 d4) (smaller d2 d3) 
   (smaller d2 d4) (smaller d3 d4)
   (clear pole2) (clear pole3) (clear d1)
   (on d4 pole1) (on d3 d4) (on d2 d3) (on d1 d2))
  (:goal (and (on d4 pole3) (on d3 d4) (on d2 d3) (on d1 d2)))
  )

