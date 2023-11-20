;; problem file: red-prob4.pddl

(define (problem red-prob4)
    (:domain redridinghood)
    (:objects home grannyhouse woods red granny wolf flower)
    (:init (alive red) (alive granny) (alive wolf)
           (at red home) (like red flower)
           (at wolf woods) (path_know wolf) (stop wolf) 
           (foodchain wolf red) (foodchain wolf granny)
           (at granny grannyhouse) (path_know granny) (timing granny)
           (forward home woods) (forward woods grannyhouse))  
    (:goal (and (have red flower) (eaten red) (eaten granny) 
           (at wolf grannyhouse) (not (hungry wolf)))))