;; problem file: red-prob1.pddl

(define (problem red-prob1)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf)
    (:init (at red home) 
           (at wolf woods) (path_know wolf)
           (at granny grannyhouse)
           (forward home woods) (forward woods grannyhouse))  
    (:goal (and (path_know red))))