;; problem file: red-prob6.pddl

(define (problem red-prob6)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf huntsman flower cakes)
    (:init (alive red) (alive granny) (alive wolf) (alive huntsman)
           (at red home) (like red flower) 
           (at wolf woods) (path_know wolf) (stop wolf)
           (foodchain wolf red) (foodchain wolf granny)
           (at granny grannyhouse) (path_know granny) (timing granny)
           (at huntsman grannyhouse) (path_know huntsman)
           (forward home woods) (forward woods grannyhouse))  
    (:goal (and (have red flower) (at wolf grannyhouse) (not (alive wolf)))))