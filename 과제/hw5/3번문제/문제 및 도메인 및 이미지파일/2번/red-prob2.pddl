;; problem file: red-prob2.pddl

(define (problem red-prob2)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf flower)
    (:init (alive red) (alive granny) (alive wolf)
           (at red home) (like red flower)
           (at wolf woods) (path_know wolf) (stop wolf)
           (at granny grannyhouse) (stop grannyhouse)
           (foodchine wolf granny)
           (forward home woods) (forward woods grannyhouse))  
    (:goal (and (path_know red) (have red flower) (not (hungry wolf)))))